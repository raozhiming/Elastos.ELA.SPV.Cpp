#!/bin/sh

# archs="iphoneos iphonesimulator"
#archs="iphonesimulator"
archs="iphoneos"

output_dir=ios_output
dest_rootpath="/Users/raozhiming/workspace/elastos/ELA/spvsdk"

if [ $# -gt 0 ]; then
    archs=$1
    echo "archs :" $archs
    packageSuffix="ios-${archs}"
else
    packageSuffix="ios"
fi

copy_only=OFF
if [ "$copy_only" = "ON" ] && [ -d "$dest_rootpath" ]; then
	cp -frv $output_dir/lib/* "$dest_rootpath/lib/"
	cp -frv $output_dir/include/* "$dest_rootpath/include/"
	exit 0
fi

pattern_match() {
	echo "$2" | grep -q -E -e "$1"
}

install_dir=install
arch_count=0
for arch in $archs;
do
	mkdir -p "$arch" && cd "$arch" || exit 1
	#make -j 8 || \
		cmake -DCMAKE_VERBOSE_MAKEFILE=OFF \
		-DSPV_ENABLE_SHARED=OFF \
		-DCMAKE_BUILD_TYPE=Release \
		-DSPV_CONSOLE_LOG=ON \
		-DSPVLOG_LEVEL=SPDLOG_LEVEL_INFO \
		-DSPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO \
		-DCMAKE_INSTALL_PREFIX=$install_dir \
		-DSPV_BUILD_APPS=OFF \
		-DIOS_PLATFORM="$arch" \
		-DCMAKE_TOOLCHAIN_FILE=../../CMake/iOSToolchain.cmake ../.. && make -j 8 || exit 1
	make install || exit 1
	cd - || exit 1
	arch_count=$(($arch_count + 1))
done

rm -rvf ${output_dir:?}/lib ${output_dir:?}/include
mkdir -p $output_dir
mkdir -p $output_dir/lib
mkdir -p $output_dir/include

generate_fat_uber() {
	osx_sysroot=`xcodebuild -version -sdk iphoneos | grep -E "^Path:" | sed 's#Path: ##g'`
	ios_ar=`xcrun -sdk ${osx_sysroot} -find ar`
	ios_libtool=`xcrun -sdk ${osx_sysroot} -find libtool`
	for arch in $archs; do
		for lib in `ls $arch/$install_dir/lib/lib*.a`; do
			lib_name=`basename $lib`
			obj_dir=`echo $lib_name | cut -d . -f1`
			rm -rf $arch/$install_dir/lib/$obj_dir
			mkdir -p $arch/$install_dir/lib/$obj_dir
			cd $arch/$install_dir/lib/$obj_dir
			$ios_ar -x ../$lib_name
			for file_name in *.o; do
				new_name="${obj_dir}_${file_name}"
				mv $file_name $new_name
			done
			cd -
		done
	done

	all_arch_libs=
	for arch in $archs; do
		cd $arch/$install_dir/lib
		all_objs=`find . -name "*.o"`
		$ios_libtool -static -o libspvsdk_uber.a $all_objs
		cd -
		all_arch_libs="$arch/$install_dir/lib/libspvsdk_uber.a $all_arch_libs"
	done

	xcrun lipo -create $all_arch_libs -o $output_dir/lib/libspvsdk_uber_fat.a
}

#generate_fat_uber

arch0=$(echo $archs | sed 's/[[:space:]].*$//g')
if [ $arch_count -gt 1 ]; then
	echo "multi arch: $archs"
	for file_name in `ls $arch0/$install_dir/lib/lib*.a | grep -v -e 'libspvsdk_uber.a'`; do
		base_name=`basename $file_name`
		input_files=""
		for arch in $archs; do
			input_files="$arch/$install_dir/lib/$base_name $input_files"
		done
		lipo -create $input_files -o "$output_dir/lib/$base_name" || exit 1
	done
	cp -fvr "$arch0/$install_dir/include" "$output_dir/" || exit 1
else
	echo "single arch: $archs"
	cp -fvr "$arch0/$install_dir/lib" "$output_dir/" || exit 1
	cp -fvr "$arch0/$install_dir/include" "$output_dir/" || exit 1
fi

if [ -d "$dest_rootpath" ]; then
	cp -fvr "$output_dir/lib" "$dest_rootpath/" || exit 1
	cp -fvr "$output_dir/include" "$dest_rootpath/" || exit 1
fi

(cd "$output_dir" && tar czvf "../libspvsdk-${packageSuffix}.tar.gz" ./include ./lib)

echo "Output directory: $PWD/$output_dir/"
ls $PWD/$output_dir -l
echo "Done"
