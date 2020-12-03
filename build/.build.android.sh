#!/bin/sh
# archs="arm64-v8a armeabi-v7a x86 x86_64"
archs="arm64-v8a"
#archs="x86 x86_64"
#archs="x86"
# archs="arm64-v8a armeabi-v7a"

if [ $# -gt 0 ]; then
    archs=$1
    echo "archs :" $archs
    packageSuffix="android-${archs}"
else
    packageSuffix="android"
fi

output_dir=android_output

pattern_match() {
    echo "$2" | grep -q -E -e "$1"
}

install_dir=install
arch_count=0
for arch in $archs;
do
    mkdir -p "$arch" && cd "$arch" || exit 1
    cmake -DCMAKE_VERBOSE_MAKEFILE=OFF \
        -DSPV_ENABLE_STATIC=OFF \
        -DCMAKE_BUILD_TYPE=Release \
        -DSPV_CONSOLE_LOG=ON \
        -DSPVLOG_LEVEL=SPDLOG_LEVEL_INFO \
        -DSPDLOG_ACTIVE_LEVEL=SPDLOG_LEVEL_INFO \
        -DCMAKE_INSTALL_PREFIX=$install_dir \
        -DSPV_BUILD_APPS=OFF \
        -DANDROID_ABI=$arch \
        -DANDROID_NDK_HOME=$ANDROID_NDK \
        -DCMAKE_TOOLCHAIN_FILE=../../CMake/AndroidToolchain.cmake ../.. && make -j 8 || exit 1
    make install || exit 1
    cd - || exit 1
    arch_count=$(($arch_count + 1))
done

rm -rvf ${output_dir:?}/libs ${output_dir:?}/include
mkdir -p $output_dir
mkdir -p $output_dir/libs
mkdir -p $output_dir/include

arch0=$(echo $archs | sed 's/[[:space:]].*$//g')
cp -fvr $arch0/$install_dir/include $output_dir/
for arch in $archs;
do
    mkdir -p $output_dir/libs/$arch
    cp -fvr $arch/$install_dir/lib/* $output_dir/libs/$arch
done

if [ -d "$dest_rootpath" ]; then
    cp -fvr "$output_dir/libs" "$dest_rootpath/" || exit 1
    cp -fvr "$output_dir/include" "$dest_rootpath/" || exit 1
fi

(cd "$output_dir" && tar czvf "../libspvsdk-${packageSuffix}.tar.gz" ./include ./libs)

echo "Output directory: $PWD/$output_dir/"
ls $PWD/$output_dir -l
echo "Done"
