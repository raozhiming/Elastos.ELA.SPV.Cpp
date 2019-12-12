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
		"DisconnectionTime": 300,
		"ChainParameters": {
			"Services": 0,
			"MagicNumber": 2017001,
			"StandardPort": 20338,
			"TargetTimeSpan": 86400,
			"TargetTimePerBlock": 120,
			"DNSSeeds": [
				"node-mainnet-005.elastos.org",
				"node-mainnet-010.elastos.org",
				"node-mainnet-015.elastos.org",
				"node-mainnet-020.elastos.org",
				"node-mainnet-025.elastos.org"
			],
			"CheckPoints": [
				[0, "05f458a5522851622cae2bb138498dec60a8f0b233802c97a1ca41f9f214708d", 1513936800, 486801407],
				[2016, "333d9a0e874cf1b165a998c061c2f8be8e03ce31712046d001823d528e1fec84", 1513999567, 503353328],
				[14112, "5e2820cc0f6fa4e73fb9cba4c9545d9cca83c8b2ecc0bbe93dd2b02739ac1ccf", 1515717109, 503425843],
				[30240, "b07a36273b890f236a4bc1f76eacb4887b98dc91ae6aac029f103ee005142c6b", 1517660585, 503424760],
				[46368, "394c20217b9a5cb6b313ea505b5addce706530efebd807d303a13cb081b80288", 1519613691, 503441261],
				[62496, "8c6d9086e3944cc56bef87eaafb6d2cca23e7e7b8ae637bc390e6ae61bcd0fa8", 1521478059, 493673302],
				[78624, "6d656e3779ed512d2dc2dcf2c409fe2d25fa2f31317dbaaced0b65e1e890a8c8", 1523423918, 493896532],
				[94752, "e6de6c24d85c365a9e87f1eccc843c8fec40485c3567b088b3b3ebd9419fdab4", 1525362338, 493998710],
				[110880, "2b73b2a9c38ef81a65df91529082e44c32a64b4ff94e9a2096520553d62ba75f", 1527287623, 492595836],
				[127008, "e6ac013fe5fb1a19df564e7246f30416c3396cb182bc6c4d3a550bf880ee2877", 1529238500, 492897549],
				[143136, "c7890d31f73b85c03593f7c6dace0a7604e6709519cff75cf945b7c83b0f7aee", 1531153562, 490135368],
				[159264, "767b2e226cf0e6f2805fbeb6d74122ec6f7ad7b7ab68556417709bafc532a8ba", 1533090476, 490037606],
				[175392, "c0e0d7a787dfb3f963350586d43ae01756952bfdab180b3c3cf66370c3e537bb", 1535033091, 489971771],
				[189504, "0fe3e924e32d5285d7efea3c3d291e55cb536774fcc3d6a76db802cabe19f48e", 1535618301, 420627388],
				[207648, "348cab05f293ce1b4848c30a0f89b8b6932b2dabf4bf96a6a0c54aedf0862769", 1537598310, 407742976],
				[223776, "ffc80b94b160752fcb89e3d021f65040f5c0861d23625d7437930215ecc11b48", 1539537072, 407725582],
				[239904, "4027be004b5bf16f4c070242cfbc0fbe6087efcb286ea6bcf737d344e822854f", 1541472460, 407582885],
				[256032, "3780dbd7caaa5464b9782e017c4fc8a69fdb01cfc1f3500de71d20c515663828", 1543410742, 407366114],
				[272160, "f7f70e84ec7d06a5a871ccb1a2c20763b4223e89c5fc1c9f9045cefa196e683f", 1545348976, 407355151],
				[288288, "16636c6d51d06f168ad2c8435ad5b0f409987b2143e8822fdd17f82cdcda8db5", 1547286115, 407102471],
				[304416, "2a42c80ea67068a02053fba95ed147c4eb5e22b3af4ed40f7e6112cf6c67f941", 1549227264, 407495379],
				[320544, "068d4b30e120a9c7c56280a04911a67f87ea727997258a0f606e970316b3d1c2", 1551159158, 407064414],
				[336672, "8d789655799d2ed6f5ae0584e9b736f359d1b75ed73f5a920f1106595aefbdf3", 1553091196, 406382126],
				[352800, "114d788df09ab2d8f4b4c3cb10b549bc6255185aecc670bf017207febbce53ab", 1554843078, 402915400],
				[368928, "dfcb5d397041d3eb222425c6bdc1e4013da4b635e3d241538bb216c22415080c", 1556754664, 402833604],
				[383040, "59e2b5adb979f8c17d34695f39a778ddb9a506603d34e64ee2ff3ed07cc9d8d3", 1558431682, 402796805],
				[399168, "7f130466e2d54b2174adad8e471f0c8665ee38caceb006404c7eb0ec91ec2256", 1560344213, 402755687],
				[415296, "8e2c85e445a7a753e13e4e430db2da9f1b1f8e2de66126ed8aff35b4f3cddf6f", 1562277933, 402735255],
				[431424, "d368f483abb8f390589bdc3368d082c696a19460102dec3857bba83fb6fd8142", 1564208559, 402732389],
				[447552, "995cbec0e7a1b1f2d20a950cd88b2b1ac6663d56377a8f4cc035a2db5e0132fb", 1566252797, 402743338],
				[463680, "34ea6df6bfd175b50dee1889e705af4b576248151d763c4003fc97124ad66921", 1568176623, 402721498],
				[479808, "eb3338b5cfa1fddd91109662061ea5bd2784e876feb9f6d7bdcf9abd7542df82", 1570106326, 402712249],
				[495936, "4638e45d3a844f0224f44dc68667372ad499570434e61e632e1a8788e8bcd6f7", 1572059926, 402718879],
				[512064, "b92f736cff9f06c63497d33c5897f4e70e6e40e653d40807018c279c5df00107", 1574009153, 402720108],
				[524160, "7f569a0fcb31e346568df1bfc53484e30787836c1297884f9de68464722df073", 1575455793, 402707021],
				[526176, "5eebb037197bc185da7b3071d12dc2913e2e7a89284a49d952577208bacf235f", 1575695897, 402705609],
				[528192, "83aee1f95a3d9e8e0d3f111401fec79e4ca6da85c0a1b309c675dbf20b4163d7", 1575947486, 402706384]
			]
		}
	},
	"IDChain": {
		"Index": 1,
		"MinFee": 10000,
		"FeePerKB": 10000,
		"DisconnectionTime": 300,
		"ChainParameters": {
			"Services": 0,
			"MagicNumber": 2017002,
			"StandardPort": 20608,
			"TargetTimeSpan": 86400,
			"TargetTimePerBlock": 120,
			"DNSSeeds": [
				"node-mainnet-005.elastos.org",
				"node-mainnet-010.elastos.org",
				"node-mainnet-015.elastos.org",
				"node-mainnet-020.elastos.org",
				"node-mainnet-025.elastos.org"
			],
			"CheckPoints": [
				[0, "56be936978c261b2e649d58dbfaf3f23d4a868274f5522cd2adb4308a955c4a3", 1530360000, 486801407],
				[2016, "df060a6475ace78657e1ec945cebb37f2ffb6367b185f9ba5edfa987f16b84f4", 1531426582, 520126740],
				[4032, "b731b13902f3f2d275589828504b4bc2a8d67d78dbb08e323925282d27fac755", 1531907920, 520341697],
				[10080, "00ac65927dcf741e87b0560b9676a35abc5d1ab74afc6144f4159315f15561d2", 1535069960, 539089007],
				[16128, "2106fe8000c01eecba9d5396f26c401dc5f4a1a90dd9f3f728e3a770afbc842b", 1535435331, 520256486],
				[22176, "9ef0a2d21af1f1ebba5b092ce0f672b221ea7d1f2e765790c0741aaff7667da2", 1535640920, 486964831],
				[28224, "682a75e280934562bd92e219581dc61fc347b1bc6e5381371397c5202db81e53", 1536252045, 475473438],
				[34272, "f78fc41c0d2ba1c0c133ebcb351ecfedc42324a31201b6c207d0165016430a74", 1536991969, 476548897],
				[40320, "7cd2999991ad8d9145035a1506a97d29641cde4d44f78533715cf469e19755ee", 1537730755, 477389634],
				[46368, "f9e8780e4df7eeecf80f8cb8fcdd2f08f2357da9f50557235373c20123e9fa45", 1538494105, 486580306],
				[52416, "9f98014309184fb90d54a9705d97ce54925ff9e549258edf3dc0bea427a34b40", 1539367116, 486730155],
				[58464, "800c33ab6faf802559f94106f9012f734ff08a2f183f6eccebc3016735557602", 1540197515, 487108954],
				[64512, "d4ea71e84a19e7b9851f1923da1170a9c32f87cf53dda7703e3bdb90d4337e29", 1540931557, 487166612],
				[70560, "a8efba9d67b13d05b1037b8a53ee917c19e1f0505808b8ba345ee6dd29fb2f5e", 1541773076, 488572069],
				[76608, "5936928083508074454609d054f1da99b1b9342b5df46dcf1af87347382f9d3e", 1543749293, 520134229],
				[82656, "0e38cfc8af645a171591105cde90640287d606fcb891c10c6c1e1204b8577dc6", 1544541545, 520173465],
				[88704, "7d5048c2f1639ad1743cbf340f0006e03cc194b9e1bc732e4c3e71a1aa599160", 1545220162, 520128038],
				[94752, "fe07a86668c85d1f21a84d927ef2a29dfc74d6493c7b322b74f6f2b1cb9bad87", 1545959855, 520132942],
				[100800, "9d8f322841672c45f46ebd699551764a7d349e8f002982d21e84063e3f82bad3", 1546700197, 520140135],
				[106848, "38f1a45e6f9d449c75c416589b02c621ae54e29602e9a98ebb9d81522ba7bedb", 1547817708, 520292304],
				[112896, "1da20f89b914016e44e4d09bc30e85e7eb7aa5b2e6116a34aebcf764adc81556", 1548999909, 520999282],
				[118944, "5c655b712e018afc6258fba5a89b4c170c41447776a7bb2eb07cf24eafd128a5", 1549810295, 522270620],
				[124992, "e04faca7a4f4c39154f13c4afb5a39c0ec92c29810e230ca5cf088c54afdf730", 1550551272, 522606384],
				[131040, "d82242161807d283f0cf7b23d958e8d976a042ba4f76be9690d8daf5b3d72749", 1551286214, 522744768],
				[137088, "39dec128089c8f3527da72694fc55675df4daa75142d301c7578489a47e86eff", 1552035304, 523322318],
				[143136, "fb08912f624ef0bfe1a2cdf2966d7ac2c6ac3aba7f82bfa8993b983a2d66ced2", 1552780272, 524222237],
				[149184, "b6cb66bf62d90593dc6d96c3dcd9cfab5c47228c05557b0e49a3bf563ff6362d", 1553907062, 537377438],
				[155232, "b60ffe855183f56edf49e505010172a409e075d2ac32daaa2e2a1faf0c23bab7", 1554636477, 537294997],
				[161280, "0cde5f8c7dd9ccd30439613ffddcecc46e1fe4ec19b06037de3e54c020683d9b", 1555483354, 538359243],
				[167328, "23bbeb2b74254d34a23c0302f5f49b33e877c544ad876a13caef85a2b902cd92", 1556522977, 545259519],
				[173376, "f9e6d026b5c17238f98a3c89974437ce110ac3dc9ca1b636bb35f71ac0106af0", 1558119198, 545259519],
				[179424, "346994001d1d21ba135dacbcb91a92391c4fbfed6f4eac0f321b9601d9f308fe", 1559426952, 545259519],
				[185472, "03ec831a08713328edd801468fc982b8eb4face6aec42b5a44ec22160627513a", 1560564985, 545259519],
				[191520, "79009121215b4c1df28d8a332b00a5e4be5a7a3729860496c901d898ca59bd36", 1561686549, 545259519],
				[197568, "c3772c88f7cfa3f2be1cfa584e9527ba910ad6fc817bde19c0e168168856f667", 1562760286, 545259519],
				[203616, "6c30dbefa7ed5a5ec1b5aa96a78f65857814a84fd90a5a8ad06d25df311afa2b", 1564016005, 545259519],
				[209664, "4f885dcdc2fa5b83e80626dbd9536b466193d1fd207f6a72c764b4fa60011512", 1565386089, 545259519],
				[215712, "917c0ba762af315b8a9ca30ff7f9384716b8c129d7e0ac88a9fcada392befe33", 1566461876, 545259519],
				[219744, "e054db426706a67a899c26655a28890ab654a72ee5aa5871a776824e9856185a", 1567196954, 545259519],
				[221760, "37420e26ecb110f5d42c5cc692d0d9f7d5d4aaab2e644e4af67e4590c00c6581", 1567569692, 545259519]
			]
		}
	},
	"TokenChain": {
		"Index": 2,
		"MinFee": 10000,
		"FeePerKB": 10000,
		"DisconnectionTime": 300,
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