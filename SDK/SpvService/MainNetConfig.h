// Copyright (c) 2012-2019 The Elastos Open Source Project
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef __ELASTOS_SDK_MAINNET_H__
#define __ELASTOS_SDK_MAINNET_H__

#include <nlohmann/json.hpp>

namespace Elastos {
	namespace ElaWallet {
		const nlohmann::json DefaultMainNetConfig = R"(
{
	"NetType": "MainNet",
	"ELA": {
		"Index": 0,
		"MinFee": 10000,
		"FeePerKB": 10000,
		"GenesisAddress": "",
		"DisconnectionTime": 300,
		"ChainParameters": {
			"Services": 0,
			"MagicNumber": 2017001,
			"StandardPort": 20338,
			"TargetTimeSpan": 86400,
			"TargetTimePerBlock": 120,
			"DNSSeeds": [
				"node-mainnet-002.elastos.org",
				"node-mainnet-006.elastos.org",
				"node-mainnet-014.elastos.org",
				"node-mainnet-016.elastos.org",
				"node-mainnet-021.elastos.org",
				"node-mainnet-003.elastos.org",
				"node-mainnet-007.elastos.org",
				"node-mainnet-017.elastos.org",
				"node-mainnet-022.elastos.org",
				"node-mainnet-004.elastos.org",
				"node-mainnet-023.elastos.org"
			],
			"CheckPoints": [
				[0,      "05f458a5522851622cae2bb138498dec60a8f0b233802c97a1ca41f9f214708d", 1513936800, 486801407],
				[2016,   "333d9a0e874cf1b165a998c061c2f8be8e03ce31712046d001823d528e1fec84", 1513999567, 503353328],
				[12096,  "6347d62e227dbf74c8a4c478fa4f8d351f24a3db3f5a01aad32ea262b6e6f6aa", 1515218030, 492349017],
				[22176,  "a32a6a82af8eb8e25543ed09671e52f7a54b4adf2cc703134bc122010f1f73af", 1516694131, 503433043],
				[32256,  "3c6f75a2a6f9d37918036b912cb341ccd687d04ff354df4afe4aa83a3a97f0eb", 1517916962, 503438901],
				[42336,  "5512e09b1cc98893969a3801f5f02de7b5146748b99142162803d3fc65b094a1", 1519125604, 503440501],
				[52416,  "2c3c8ebd558387a59880046b1f7dea9f55ec2d2525811806ab673411de078896", 1520340390, 503442853],
				[62496,  "8c6d9086e3944cc56bef87eaafb6d2cca23e7e7b8ae637bc390e6ae61bcd0fa8", 1521478059, 493673302],
				[72576,  "a25db21f09d01ac77bfa3c88eb4ca25d87b357333721a07c1d4d568bc7dddaa4", 1522696898, 493968530],
				[82656,  "d3238d44fcaa42ec51f9314185eb57950f00184152ccc38ff94c99eaba27ac32", 1523909845, 494238365],
				[92736,  "9f2e7f0c8668cb37e7e249123ba5436239245c3a582aac2cfa00e63f84fd7259", 1525118590, 494040753],
				[102816, "21fbf33a8ac97d4da0660fc8cf1d4b42ced6cd39cb6ff9f81aa4ed898b4adfb2", 1526317611, 492534043],
				[112896, "db22a1202b815fbc483a6a34f7faca80286351599082b1beb1c9155a6fb35b03", 1527524832, 492355105],
				[122976, "4755a56fa7a9bfa12125d573bf4c47af1caaf3b749de890bf1881d9de04778e2", 1528725950, 491428429],
				[133056, "668fcd9479fff7bbd267746046ad9fe1875be00d34fa67e300d83d199e9e5624", 1530001812, 503350194],
				[143136, "c7890d31f73b85c03593f7c6dace0a7604e6709519cff75cf945b7c83b0f7aee", 1531153562, 490135368],
				[153216, "1bc095d2c47131e1a4e1d08ca533b9caac30008e319441b7d202ddfe75e263cb", 1532368202, 490129493],
				[163296, "dc35e7815ba7f2def7fb656cca1bde709ebe99cd4f66c39ac573a2763be559d9", 1533576903, 490408901],
				[173376, "ce52eca3db14476ae7b01faa0258bc21b4b93fe0b0364342785cf479f213f851", 1534787121, 489990925],
				[183456, "03665026718f02ccb9c764aafe20ab5c1f4963cf7eac6931a300d40b28343f59", 1535433865, 457157190],
				[193536, "ad48cf72bbee8634044ac24dd5ea207c0ba8d6e0dec9b97a64b3eea55c73aa79", 1535895095, 407453180],
				[203616, "5e230d36db48b3951bd7d4979d25aa18a83c24941b083d63bfef286489acce36", 1537105427, 407173769],
				[213696, "d01abf397fd29c2ba66da728c35834aa0c8a21a7d1c9e6f2e7db4c90059ddd26", 1538328848, 407607682],
				[223776, "ffc80b94b160752fcb89e3d021f65040f5c0861d23625d7437930215ecc11b48", 1539537072, 407725582],
				[233856, "5ace1133b6a861b20a4b3885c686b3f6d54829504105019d28b51358721e12e8", 1540749706, 407616602],
				[243936, "e14e533e6d6640ef026f29cc1ab14eaeaa4cd999072ca11d8d15e066665c688f", 1541951161, 407273974],
				[254016, "6803d7f909508a3d36704edffc5acfbf87e02d1fc2250257d862f173aca9ed0d", 1543162984, 407276433],
				[264096, "9c8a9edac6bc8c53e6210e3c994f171d5904a2709af78279196b53c584b21f86", 1544376477, 406878848],
				[274176, "9d80d127af6138ccc7ff5de638e15dbfbf9253d5e6c3041263e2fd634ed7a8d0", 1545585364, 407176107],
				[284256, "ca31b85a93eb1cd00cdb015d4a9e9b772b081b32e8e22a784d904fcadc7ee7bd", 1546804475, 407306385],
				[294336, "7dd4e7c122b4879a8a1daaab0b85d00f017ceded606c66fe3a4efb558ddd10b6", 1548016365, 407078205],
				[304416, "2a42c80ea67068a02053fba95ed147c4eb5e22b3af4ed40f7e6112cf6c67f941", 1549227264, 407495379],
				[314496, "bba5bc0a3bbf3d714e8f414d096440eb18586ce9bed9a006e91e79745ea12566", 1550434616, 407071079],
				[324576, "aea8458dfafe6e6ce7a325220cd9c2ef422a41cc8a90aa0364699dbda62183d7", 1551631041, 406048162],
				[334656, "e13a065674b677a4f9d1f44d9559b7c25254b216ee719919c6eb67198196b0c3", 1552843215, 406198821],
				[344736, "bd24f4c56980a7cd38df0d7c25a0f1cc9b15555a95ddadcb404f53d034dc3b16", 1554063832, 406305857],
				[354816, "7bad9fff3e61999fc7aaf89818961c37cd010a7a6a6356f5bc80911f43b86451", 1555057366, 402854529],
				[364896, "6c5b0482cb530b782d34a68a2cf76327899cc564d2d86eb373930726354c062b", 1556264996, 402834613],
				[374976, "10354cd88a40a834e5074a5a086d32278dfff4be49320d537e0896aa410bc184", 1557475422, 402828591],
				[383040, "59e2b5adb979f8c17d34695f39a778ddb9a506603d34e64ee2ff3ed07cc9d8d3", 1558431682, 402796805],
				[391104, "84e842ddeffceb5b23adcb6ccddd809268f5c5bde5b4527780e9ac0e62c6e5cd", 1559378042, 402762373],
				[399168, "7f130466e2d54b2174adad8e471f0c8665ee38caceb006404c7eb0ec91ec2256", 1560344213, 402755687],
				[401184, "499f65b1d3a4b2f9693ffc56510611e2c8b16b8ee7b9e98abaca29e0fa52d8d5", 1560582699, 402746326],
				[405216, "8aa9a03a0a2d6de4fa892481e56f7b2fec7ce08053fa903328f21c62823c7a20", 1561066618, 402741422],
				[409248, "a8b4956aa92a5c28cedda73557cc563fd8bb6c4e2127f04ec0d7adaded08b7da", 1561561445, 402756555],
				[411264, "21a74b30fb9111f87fa3f9e83a5b3c8bdb1d314a44f2902450dbc2c6f013fc25", 1561788368, 402740383],
				[415296, "8e2c85e445a7a753e13e4e430db2da9f1b1f8e2de66126ed8aff35b4f3cddf6f", 1562277933, 402735255],
				[419328, "234caa30c9a18d70207e933543c9ab617cbcf346eb4a97dd95d82c6011988fe6", 1562753420, 402734084],
				[423360, "3f1248d2db31e910639e5ce35b2523d2bdc72e1c08594a3d19f4a8852e689483", 1563239650, 402735601],
				[427392, "cd943bfa0b1854075e3c98bd7039072c5039de6441710e357749d4cfd681ffc5", 1563726061, 402735390],
				[431424, "d368f483abb8f390589bdc3368d082c696a19460102dec3857bba83fb6fd8142", 1564208559, 402732389],
				[435456, "9092476e73add9bd790f0edf460f75287b8ab326b9eb216b2cc554d3d075ac2b", 1564696209, 402746843],
				[437472, "1de058cbf3bd75fef7f87ecd340b3c08e67190bfacd0561bafc454a906d7114b", 1564929273, 402725976],
				[439488, "ca35075c1f592c4d3ecef631e3fff4cb22d317fbfd3e264b0f4797b8ec37455f", 1565169174, 402725494],
				[441504, "86ccc1c4b4aef475be9e0bff51cdb1fe0c13b7fcb0a9ea6048d09feacb6a4c25", 1565505465, 402724217],
				[443520, "28bf2247248e44ad3bb0ce276a20f2b9d16d9924b7a7bc1fdf3eed8d11120168", 1565740432, 402717721],
				[445536, "7f26d560cfe8748f16fed9e6fcde82552e27276199349b03fa6da6dd0e7c3d4f", 1565986968, 402720177],
				[447552, "995cbec0e7a1b1f2d20a950cd88b2b1ac6663d56377a8f4cc035a2db5e0132fb", 1566252797, 402743338],
				[449568, "a2413b52b04e041a7bb721525af58178c8e034cc6d7940e2c86f0a333241c146", 1566487364, 402729003],
				[451584, "77a89e8b2174940382cbec5aa0f9925ca05ed616136856f64abd6607d7b06491", 1566719450, 402720387],
				[453600, "7f6912e9d570b148af670fb7a3075581f7fb6fc96c1933482879903b701fb506", 1566967739, 402724706],
				[455616, "1710ed3a4e249fcceb33a4c5a62494b324e8d545c72c8d4a9c3357df3a6256c1", 1567210492, 402727254],
				[457632, "d1ec3d1858210de2246548aa1907503fb89ef664556207d97ae79cee11c17bcc", 1567452089, 402724326],
				[459648, "98c0f2985ea50f4ba49e02eabe3bb99171dbceb7c9b1c4d5e4004c228d2674ca", 1567689963, 402720836],
				[461664, "b9fdbb769a1b7f11b0132901b94f1bc0dea1eb08d1d6d630374ec393d3be872e", 1567936111, 402722887],
				[463680, "34ea6df6bfd175b50dee1889e705af4b576248151d763c4003fc97124ad66921", 1568176623, 402721498],
				[465696, "64468edcc736f11aa33c41d0f5e5266420c9fdad37279745e82cce0b681b8420", 1568415494, 402719568],
				[467712, "e164d15b1fd7e02c04f889490c8f0af77a6c2e8b9203ee885da5a17bda614096", 1568654524, 402720781]
			]
		}
	},
	"IDChain": {
		"Index": 1,
		"MinFee": 10000,
		"FeePerKB": 10000,
		"DisconnectionTime": 300,
		"GenesisAddress": "XKUh4GLhFJiqAMTF6HyWQrV9pK9HcGUdfJ",
		"ChainParameters": {
			"Services": 0,
			"MagicNumber": 2017002,
			"StandardPort": 20608,
			"TargetTimeSpan": 86400,
			"TargetTimePerBlock": 120,
			"DNSSeeds": [
				"node-mainnet-026.elastos.org",
				"node-mainnet-027.elastos.org",
				"node-mainnet-028.elastos.org",
				"node-mainnet-029.elastos.org",
				"node-mainnet-030.elastos.org",
				"node-mainnet-031.elastos.org",
				"node-mainnet-032.elastos.org",
				"node-mainnet-033.elastos.org",
				"node-mainnet-034.elastos.org",
				"node-mainnet-035.elastos.org"
			],
			"CheckPoints": [
				[0,      "56be936978c261b2e649d58dbfaf3f23d4a868274f5522cd2adb4308a955c4a3", 1530360000, 486801407],
				[2016,   "df060a6475ace78657e1ec945cebb37f2ffb6367b185f9ba5edfa987f16b84f4", 1531426582, 520126740],
				[6048,   "4e6a53d3e3e61d4883a10d62fb42afb62ad6f10807bcc3791db284f43b063671", 1532395676, 522028475],
				[10080,  "00ac65927dcf741e87b0560b9676a35abc5d1ab74afc6144f4159315f15561d2", 1535069960, 539089007],
				[14112,  "d342ee0817e30a57a515ccfaaf836e7314aac1235d0659d5e6ffc46671ae4979", 1535367638, 527395580],
				[18144,  "fc4e7ba460e38964faeb33873418c9fcd3ae2648a543cc1e8f5c47806b593ac8", 1535503457, 504235070],
				[22176,  "9ef0a2d21af1f1ebba5b092ce0f672b221ea7d1f2e765790c0741aaff7667da2", 1535640920, 486964831],
				[26208,  "a9eb520903f5f1ec1a11a3f5040791d59ae63b8e16846a994bbd303ba43b50db", 1536008684, 475415774],
				[30240,  "470d858db326df0e738248ac5f5811f1b31a0c1ca1892f17a93673efefde3a45", 1536500538, 476055185],
				[34272,  "f78fc41c0d2ba1c0c133ebcb351ecfedc42324a31201b6c207d0165016430a74", 1536991969, 476548897],
				[38304,  "9592ad50c220ea2900d0c3659df470b4e8e459ac6ee2d43ddc9b6ddd15166645", 1537492347, 477909524],
				[42336,  "548c15f8daede3d85aed4a6ad8bf013c6cb2b3c7ea7aba0134ffb2adc450850a", 1537976718, 478079428],
				[46368,  "f9e8780e4df7eeecf80f8cb8fcdd2f08f2357da9f50557235373c20123e9fa45", 1538494105, 486580306],
				[50400,  "b877aa70a40ec714b211c19d0f00060f86e659acf2766bd2a3d6a2fc24f29a6d", 1539105182, 486700362],
				[54432,  "e40aab4302d385b0ec4cc85ca8a1c1a8c338e2b01d0a67c70e7f9bc0b7e4995b", 1539618297, 486739142],
				[58464,  "800c33ab6faf802559f94106f9012f734ff08a2f183f6eccebc3016735557602", 1540197515, 487108954],
				[62496,  "760a11232f9fcf83dd30a17f9feac767c3a1158371fa0e051b1f2956e8b96ecc", 1540686763, 487128669],
				[66528,  "886813b522b8ed25b5ed49a466a60dabc9ec873505f6febf650013d0de8ff760", 1541180178, 487200624],
				[70560,  "a8efba9d67b13d05b1037b8a53ee917c19e1f0505808b8ba345ee6dd29fb2f5e", 1541773076, 488572069],
				[74592,  "63ba136d741cdc27fa7c03ce438c1d2b9caf7540a3be801c967c09697f0458dc", 1542924090, 503654166],
				[78624,  "5ca5f44be2515483c55db47b905a440565475c63327dfab2d105833f4720f593", 1544008452, 520140813],
				[82656,  "0e38cfc8af645a171591105cde90640287d606fcb891c10c6c1e1204b8577dc6", 1544541545, 520173465],
				[86688,  "441d3794627823a55cf8ec3c300bb10c8f63651dbc76db8c22739ac8a5336b3e", 1544974030, 520127197],
				[90720,  "5155b5bdb51127669b7f7e456f60aa0ae4c69611d3ebeb51e4fada9f61aeca9f", 1545465318, 520129181],
				[94752,  "fe07a86668c85d1f21a84d927ef2a29dfc74d6493c7b322b74f6f2b1cb9bad87", 1545959855, 520132942],
				[98784,  "4b27e003117fb0efff1067b5cd836667c11bb8d4ae2ea52976e8b2dd1dbfd34c", 1546453702, 520138602],
				[102816, "ac97cd435b57970796b7da001572c557b0df2d2a3ae796f3154f57f09f4eec5b", 1546945490, 520140369],
				[106848, "38f1a45e6f9d449c75c416589b02c621ae54e29602e9a98ebb9d81522ba7bedb", 1547817708, 520292304],
				[110880, "4a97daaecfc733dfc5bd42b541d024c4958730be2c04f0b47f809360e80f6683", 1548751322, 520926822],
				[114912, "a4c77139bdeede023f9482378342767b76912864f35a84032fe37c368196fed9", 1549258718, 521141875],
				[118944, "5c655b712e018afc6258fba5a89b4c170c41447776a7bb2eb07cf24eafd128a5", 1549810295, 522270620],
				[122976, "b21e49d2db45beedb724fbbae731d65f4978424ab14145087e2b3323c004a0cc", 1550298695, 522434944],
				[127008, "ede353da9b252d2f40827260317b757b456e3a2b0c852a947b44a4e3a1169ed7", 1550820077, 523414197],
				[131040, "d82242161807d283f0cf7b23d958e8d976a042ba4f76be9690d8daf5b3d72749", 1551286214, 522744768],
				[135072, "452dee26b8ccf4d7dcb814f79b0a4c8a063410f4c905225c017e44ca713b77ec", 1551787216, 523287865],
				[139104, "71250ef5f1b3148356f3203af5818b8b87e433df450c398332ae12d9658258dd", 1552295776, 524206706],
				[143136, "fb08912f624ef0bfe1a2cdf2966d7ac2c6ac3aba7f82bfa8993b983a2d66ced2", 1552780272, 524222237],
				[147168, "96874a8fe125480f949952afbe369c044fa9c979354fd999117be9a5eb5e2f78", 1553478082, 536950698],
				[151200, "f54c84e12cc490e69102a3c0bea00e19f007f71ea438fa38e2260e4159bfe0f1", 1554182600, 537615411],
				[155232, "b60ffe855183f56edf49e505010172a409e075d2ac32daaa2e2a1faf0c23bab7", 1554636477, 537294997],
				[159264, "5ce76e8c86547e406d68ab4fc0eb5827fcc9d120f8a7e9d4f1f80d40fb005c6f", 1555144808, 537423087],
				[163296, "e05f7abba0c9b6b524a26eebe5f26f1cd8094796a2c76a45beefd38d32d1f244", 1555804160, 539269565],
				[167328, "23bbeb2b74254d34a23c0302f5f49b33e877c544ad876a13caef85a2b902cd92", 1556522977, 545259519],
				[171360, "81401e2ad18367d2c4544e08c4fac074e8f2370f62cd5f7f2197d30dabeb9d0a", 1557544077, 545259519],
				[175392, "d1fc7806da2df1928c98f10a20f264365f52cf552883579d384f979c0d05963b", 1558627712, 545259519],
				[179424, "346994001d1d21ba135dacbcb91a92391c4fbfed6f4eac0f321b9601d9f308fe", 1559426952, 545259519],
				[183456, "2ff981a6848c91256dcc87941d25ef5abafe4a83f37a7f8462b2cb45553c0044", 1560179179, 545259519],
				[187488, "2fdabff7d74887d345448d834af60ff8b059b03087fec40f3fd59f22452de432", 1560950415, 545259519],
				[191520, "79009121215b4c1df28d8a332b00a5e4be5a7a3729860496c901d898ca59bd36", 1561686549, 545259519],
				[195552, "5ff7a8ff6b8415f3d266cb11570964940e24f465bae018580b4fd1367e1d5217", 1562404157, 545259519],
				[199584, "3ce8a28a7987e9521ccd8faa95bfa01a8a1a9b2c6214ea3a9da4c1a5de567152", 1563167896, 545259519],
				[203616, "6c30dbefa7ed5a5ec1b5aa96a78f65857814a84fd90a5a8ad06d25df311afa2b", 1564016005, 545259519],
				[205632, "427462f6235d75abccab0f52e0f1c0fad3e370292363b80b2eb65f95bbbd894a", 1564428074, 545259519],
				[207648, "f55ceef66d91701aa08884c0c02d1090b9bfec4adecd1177dd80bbc4a1598132", 1564824641, 545259519]
			]
		}
	},
	"TokenChain": {
		"Index": 2,
		"MinFee": 10000,
		"FeePerKB": 10000,
		"DisconnectionTime": 300,
		"GenesisAddress": "XVfmhjxGxBKgzYxyXCJTb6YmaRfWPVunj4",
		"ChainParameters": {
			"Services": 0,
			"MagicNumber": 2019004,
			"StandardPort": 20618,
			"TargetTimeSpan": 86400,
			"TargetTimePerBlock": 120,
			"DNSSeeds": [
				"node-mainnet-002.elastos.org",
				"node-mainnet-003.elastos.org",
				"node-mainnet-004.elastos.org",
				"node-mainnet-005.elastos.org",
				"node-mainnet-006.elastos.org",
				"node-mainnet-007.elastos.org",
				"node-mainnet-008.elastos.org",
				"node-mainnet-009.elastos.org"
			],
			"CheckPoints": [
				[0,      "b569111dfb5e12d40be5cf09e42f7301128e9ac7ab3c6a26f24e77872b9a730e", 1551744000, 486801407],
				[2016,   "0949da8d34d37f632873d6ecec64ebe340787443438ac164920bfb9cf3650360", 1551995934, 504001839],
				[4032,   "215e27cca0a758d2ee945ca11bc22a1c3b3bf2f2ddcaf167c45d84360e89c0f5", 1552260265, 504117745],
				[6048,   "15a8d8a9e58d64d70c606e39311445a4dafcf38d66cc8009c1bac77004161d18", 1552507087, 504126382],
				[8064,   "ca8df7f2004dc5ff3b500967a24fc1f1d709ff804119ea86f9fc05d85de9dec6", 1552812350, 504906547],
				[10080,  "58b25e8f4aed9346b8e23b224242ddb2f42d8d6c7d00077beaf97684ca02474e", 1553562824, 520236599],
				[12096,  "34c72c0de800ef4d7d9ff21ece83ba20285a94452271f04e1686ef51b94e84d4", 1553952619, 520563544],
				[14112,  "b952635276e1c5ea326021687eef0a5adc389cbaef627c0cb5f0be60037bf5f6", 1554221590, 520741881],
				[16128,  "9be174adcaef6c7f6a1bb4a4e43c8bfd3922c9598d6508a6e0ac17fdd688d452", 1554431091, 520593990],
				[18144,  "8af5a645c8da42a84824f5a9ffe05ba283070303defc851ed3013288e2e52a91", 1554662463, 520448351],
				[20160,  "0898c4287ea0c23f9079d495d2594246a852ce1f6b800adb1d594599978cd0b4", 1554877734, 520360576],
				[22176,  "ed6509ea794b8e35c38d2c5d4de6ed756ac3b5be012f8ff998a1a98020f926f3", 1555144521, 520410302]
			]
		}
	}
}
		)"_json;
	}
}

#endif //__ELASTOS_SDK_MAINNET_H__