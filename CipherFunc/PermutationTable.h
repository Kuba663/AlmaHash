#ifndef __PERMUTATION_TABLE_H_
#define __PERMUTATION_TABLE_H_
unsigned char pTable[16][256] = {
	{ 18,232,218,248,241,91,136,123,88,37,48,180,51,246,230,141,135,130,165,50,185,156,142,69,95,52,15,94,26,163,201,254,68,220,233,40,25,170,197,196,16,104,243,213,106,176,174,160,222,208,221,72,181,19,179,39,219,20,158,53,103,121,178,182,96,151,83,183,110,17,101,171,147,189,161,98,79,150,27,84,99,214,187,132,206,143,108,155,3,41,133,191,64,23,217,10,169,31,227,251,80,192,57,34,24,194,6,70,225,112,12,205,236,138,109,167,242,85,239,59,152,235,211,131,42,157,35,49,86,81,102,212,36,207,188,46,56,92,177,28,244,148,159,186,97,90,193,145,120,162,184,105,118,45,58,62,175,238,43,124,47,76,77,5,63,240,144,33,38,129,204,29,164,13,107,210,67,1,111,139,250,126,229,216,11,119,2,202,247,134,9,154,61,14,65,74,32,113,200,82,172,78,153,223,114,54,209,116,198,60,128,125,253,93,228,137,73,249,173,190,140,146,127,149,66,234,203,231,255,55,87,115,117,195,0,122,8,75,237,215,245,166,44,100,224,4,252,199,7,226,168,30,71,89,22,21 },
	{0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
	,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
	 ,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
	 ,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
	 ,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
	 ,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
	 ,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
	 ,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
	 ,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
	 ,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
	 ,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
	 ,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
	 ,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
	 ,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
	 ,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
	 ,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16} ,
	{ 205,50,176,244,243,182,34,166,208,167,3,164,192,202,126,233,237,214,147,239,73,178,15,230,1,193,134,38,49,55,108,104,212,37,98,139,26,152,200,24,224,189,17,121,153,28,94,32,81,181,240,145,8,11,217,168,107,238,191,80,115,95,83,6,113,76,64,169,91,29,223,226,45,207,155,218,187,74,141,130,79,23,149,10,117,59,111,9,70,72,135,125,21,248,199,133,209,127,216,12,204,159,116,31,63,89,53,163,105,174,99,203,14,110,58,18,184,101,231,56,20,151,54,66,180,219,87,124,220,61,46,245,251,185,78,30,88,154,197,97,148,129,160,27,52,137,198,227,210,142,41,19,158,122,162,60,165,195,128,146,211,234,47,2,93,120,82,16,190,140,144,114,57,7,5,85,86,67,13,136,173,123,106,4,103,71,62,201,131,150,255,92,75,188,249,138,90,246,206,250,109,51,156,232,22,77,143,229,102,84,42,175,177,132,194,170,33,179,236,36,65,48,25,118,172,112,119,44,96,252,35,242,221,43,235,40,253,196,171,157,39,161,100,186,213,215,225,247,68,0,241,69,254,228,183,222 },
	{ 63,62,177,77,104,176,27,246,84,240,123,130,151,75,65,34,86,237,17,186,10,81,91,89,200,219,165,159,32,100,52,208,224,67,158,49,230,47,9,23,207,162,182,35,128,161,11,20,97,13,48,98,145,8,174,85,79,228,78,114,4,181,164,226,56,173,41,191,180,43,90,101,36,111,135,115,179,25,94,53,247,155,188,199,61,124,21,154,185,134,242,216,153,119,138,202,125,160,131,210,38,189,142,233,150,203,2,58,196,7,254,28,113,33,183,141,193,223,57,238,187,209,14,92,3,166,212,139,229,127,225,31,82,5,16,243,204,190,60,99,110,93,30,0,55,1,80,140,6,18,211,241,66,214,12,221,39,68,71,213,227,54,157,222,50,102,105,170,250,248,168,44,42,132,24,83,195,148,96,87,239,109,146,70,144,45,167,95,184,51,236,147,175,107,116,74,249,22,244,19,231,26,106,136,218,76,172,29,133,217,40,192,205,220,251,73,120,235,59,156,129,255,152,232,122,163,46,121,253,198,117,149,72,245,37,252,143,15,64,169,103,88,126,215,118,137,206,197,69,201,112,108,234,194,171,178 },
	{ 117,100,26,187,109,41,33,255,148,67,133,153,69,125,242,113,240,90,78,129,23,68,165,1,112,176,124,155,45,29,213,197,51,195,186,217,191,108,160,179,72,219,5,235,216,88,99,17,3,87,2,48,169,178,24,208,44,103,36,14,239,35,157,170,180,76,65,118,252,32,193,145,246,115,227,60,95,128,232,149,223,31,251,19,171,182,89,91,234,107,71,207,143,27,63,40,214,30,105,162,47,75,20,9,254,18,192,247,73,56,12,218,228,183,119,98,172,61,174,151,135,209,190,236,224,201,58,225,123,79,229,80,57,15,173,230,222,11,38,6,127,13,126,106,97,120,204,104,10,84,102,132,188,134,245,66,244,189,199,64,138,7,8,131,205,198,196,46,248,202,241,163,243,141,86,62,54,121,0,144,152,52,94,158,82,136,83,70,221,150,74,154,238,25,206,16,249,140,101,22,184,4,147,220,215,237,175,167,59,85,203,253,28,96,92,55,146,194,142,42,185,211,34,137,164,159,161,250,81,49,226,77,114,122,233,21,200,156,37,111,53,130,212,39,166,177,93,139,110,168,210,50,181,116,231,43 },
	{ 9,118,230,3,110,188,12,113,108,240,50,91,124,29,102,219,69,206,195,178,37,21,218,251,139,152,49,109,196,156,160,182,2,39,183,15,119,234,176,111,224,38,226,16,174,96,100,151,58,60,77,115,117,32,170,189,173,46,252,239,172,70,241,81,216,40,25,200,22,13,254,229,225,158,17,215,129,35,180,181,247,7,167,244,154,121,45,116,86,171,122,177,75,199,82,55,237,11,134,179,205,238,248,120,10,137,155,28,253,233,175,80,201,97,8,89,26,105,19,185,41,63,14,73,166,165,66,24,136,186,33,153,141,242,222,112,54,228,208,42,126,220,20,125,223,169,191,255,168,159,184,245,59,6,84,164,106,53,162,221,227,94,65,147,204,90,150,0,235,192,88,48,138,68,74,132,44,34,98,128,246,64,145,107,4,79,31,135,36,133,57,131,30,211,236,163,92,187,51,213,78,202,62,193,157,67,210,243,161,95,101,52,47,99,56,104,142,190,232,207,127,198,209,148,217,23,212,18,114,231,143,87,72,1,203,27,194,123,140,5,214,149,130,61,76,250,85,43,71,93,146,103,144,197,249,83 },
	{114,213,35,242,98,161,204,201,159,238,186,189,164,190,84,56,246,43,232,3,59,146,125,209,21,2,194,132,118,61,55,229,158,67,62,223,78,167,109,1,153,99,93,173,69,123,205,8,181,82,160,120,13,156,63,18,140,25,168,11,34,226,42,203,211,197,142,207,231,176,216,5,130,57,252,228,38,47,144,225,90,241,187,124,248,143,148,172,58,89,121,14,0,157,243,136,72,188,10,169,196,178,33,105,214,44,51,39,17,116,83,94,4,113,154,74,112,183,15,249,111,40,150,171,65,71,79,145,255,184,239,224,52,166,54,91,218,253,233,73,250,102,175,32,245,219,117,199,81,180,141,162,66,220,50,88,28,46,126,101,26,206,30,92,237,135,193,221,155,48,192,222,244,208,85,240,19,29,133,179,36,185,27,251,151,170,100,236,107,230,134,49,75,122,247,16,119,68,234,163,20,45,31,139,217,115,60,103,53,76,200,202,7,254,23,195,64,137,97,182,110,177,131,174,210,128,41,24,22,96,127,104,9,95,215,129,147,165,138,87,149,227,80,108,212,86,37,106,198,12,77,152,6,191,235,70},
	{ 249,209,2,188,143,223,207,51,26,161,243,171,94,252,218,100,154,189,1,227,133,242,195,22,67,3,47,21,120,177,71,4,65,233,211,34,139,85,156,253,131,167,220,92,181,29,99,15,35,56,251,5,194,13,104,153,173,28,221,109,73,112,135,6,42,216,116,18,150,166,97,247,31,8,45,202,213,111,165,169,217,232,239,98,84,198,246,230,229,149,224,54,30,74,115,214,16,237,124,40,91,197,36,0,37,199,14,228,106,12,46,66,146,215,69,9,43,118,126,89,44,158,225,95,110,204,33,64,168,113,55,174,101,248,184,235,159,234,122,11,178,240,210,77,117,63,145,136,79,7,128,140,53,179,70,32,152,147,108,48,114,245,24,138,39,23,155,226,175,231,125,60,38,241,244,193,87,176,134,107,75,119,162,130,25,127,238,170,255,62,236,96,102,148,61,187,57,254,142,129,200,222,103,50,105,201,86,59,141,151,49,163,17,80,186,27,81,144,182,157,68,88,192,190,93,90,212,132,160,185,19,219,76,52,20,203,208,58,206,10,121,172,183,137,72,78,164,191,180,41,205,250,82,196,123,83 },
	{ 199,82,110,165,71,118,151,234,64,22,208,66,254,244,17,133,141,41,192,181,119,224,187,157,6,28,108,116,149,20,97,247,210,164,128,46,31,125,155,160,2,228,14,248,175,145,219,180,70,96,132,182,178,173,68,52,105,121,29,84,135,233,191,58,98,146,102,161,112,226,26,38,124,65,63,127,85,54,255,51,222,162,4,137,1,170,123,148,80,216,114,0,56,229,34,60,45,201,57,156,44,251,73,101,194,223,176,42,240,100,136,171,104,238,55,3,202,213,48,36,138,150,206,230,246,15,59,242,61,215,143,117,189,92,113,184,140,217,107,159,174,142,74,95,253,158,88,193,91,106,76,225,197,232,87,147,27,94,75,196,241,209,203,5,16,183,154,179,37,235,103,9,144,168,10,172,77,195,39,89,120,163,245,86,79,35,72,200,198,231,177,81,130,62,129,25,169,53,43,8,33,252,111,23,126,186,21,30,67,249,250,83,214,167,212,152,50,32,99,153,220,205,190,90,185,237,19,221,12,11,13,109,239,122,7,218,93,115,139,207,166,134,24,47,204,49,227,211,78,236,188,243,69,18,131,40 },
	{9,16,49,90,128,121,232,119,114,217,200,189,160,1,47,48,148,208,37,218,62,143,102,171,240,6,186,169,199,74,211,147,13,239,103,175,215,184,44,4,36,213,54,61,170,67,87,126,178,65,212,75,122,151,41,18,34,156,24,136,251,253,71,68,118,88,105,91,22,230,235,193,124,233,231,166,101,78,150,72,107,112,255,195,220,165,120,226,142,79,46,225,210,21,8,85,99,206,17,159,237,174,134,158,3,56,29,26,167,173,141,97,31,83,77,209,63,192,207,116,241,28,55,81,40,125,252,205,228,163,73,110,66,27,221,179,227,45,129,117,94,248,187,161,100,132,137,84,53,152,202,198,249,96,139,80,60,104,140,188,93,38,95,109,203,201,204,59,219,243,32,89,177,50,194,214,236,106,111,146,123,135,155,130,245,145,12,229,57,144,0,52,33,86,20,5,234,127,191,70,64,19,108,30,92,164,113,190,51,176,115,10,82,2,7,98,183,39,131,244,25,138,223,14,23,246,247,224,250,42,168,182,43,238,162,35,11,172,180,154,15,242,254,58,216,196,153,222,76,149,69,181,157,197,133,185},
	{70,109,119,129,233,238,229,63,17,45,181,86,246,130,255,166,168,85,135,55,201,150,56,121,200,133,16,68,176,165,180,108,95,185,170,179,52,75,243,24,196,171,174,247,123,111,173,241,60,197,66,222,218,79,97,126,43,149,59,35,163,41,203,21,249,106,172,192,182,132,138,139,213,127,77,242,46,214,7,67,115,116,228,160,88,39,251,145,98,80,151,193,220,36,226,114,120,103,53,230,244,3,18,91,90,6,57,216,212,61,25,143,42,219,202,62,158,178,22,209,107,227,71,236,225,14,136,144,198,113,186,102,189,184,1,94,155,207,161,231,122,187,169,128,32,205,239,206,51,100,240,49,64,191,232,118,208,147,0,54,40,248,2,84,50,73,37,81,38,78,195,20,89,137,27,223,175,221,157,112,215,253,87,19,210,162,164,74,252,8,34,237,83,125,156,99,224,47,110,26,65,142,140,105,15,204,177,9,44,154,76,4,72,167,217,11,254,92,124,245,82,101,199,194,134,30,12,31,96,23,10,29,159,69,211,190,250,13,141,28,188,183,104,235,93,58,131,146,148,33,153,234,152,48,117,5},
	{92,247,235,182,33,48,124,254,176,240,87,22,231,186,120,63,119,234,5,246,239,69,78,133,153,13,233,111,190,203,212,218,129,167,211,157,138,139,17,57,79,95,109,171,228,252,132,184,116,131,15,82,147,213,108,117,10,206,97,32,144,71,68,104,208,29,81,175,160,135,100,223,73,14,151,91,187,55,58,27,245,83,44,101,88,7,34,180,21,45,1,230,106,229,226,195,16,118,249,155,174,196,154,177,90,158,110,103,243,96,148,238,201,52,205,237,42,244,61,76,75,18,56,59,72,134,145,37,107,224,40,114,159,0,43,137,11,149,156,146,94,86,3,8,179,23,24,128,122,20,189,173,36,25,31,26,41,197,225,200,178,142,12,251,217,164,170,215,47,143,51,89,77,74,39,130,65,199,210,28,54,30,204,102,220,169,172,2,227,80,250,84,183,70,198,49,136,141,207,123,152,161,202,64,112,192,216,163,127,214,181,50,241,67,125,60,162,62,6,194,219,35,185,236,46,166,165,113,222,191,98,115,99,150,19,4,232,248,105,242,253,9,221,193,66,188,85,126,209,255,38,140,93,53,121,168},
	{198,197,252,103,140,218,24,126,7,168,61,71,133,15,151,161,17,235,155,156,132,152,19,45,248,241,233,232,220,108,135,30,213,113,52,44,78,118,87,85,74,201,114,194,129,255,157,223,2,33,180,36,209,242,53,175,147,28,107,253,93,0,199,246,1,60,34,142,110,137,32,8,177,145,56,40,251,184,138,195,183,187,247,160,222,92,210,128,136,211,170,154,125,68,221,20,109,127,166,196,190,6,104,239,234,95,72,116,115,204,5,94,59,89,99,97,178,169,173,244,101,4,3,46,31,163,51,100,10,77,122,250,245,55,69,144,105,13,96,120,185,214,230,70,75,80,153,90,66,9,216,237,79,81,65,27,179,182,37,174,181,11,62,219,43,119,231,106,67,57,91,35,225,165,203,50,86,123,191,73,167,84,240,38,206,193,162,212,192,112,21,42,186,254,83,12,200,39,224,236,226,82,141,102,111,229,143,158,207,54,18,217,148,150,243,227,88,49,47,16,58,14,131,249,172,171,164,208,189,146,238,22,228,117,130,26,149,202,41,121,124,205,76,64,23,188,63,98,25,134,29,159,215,139,48,176},
	{183,241,189,36,215,63,43,163,178,224,143,60,13,205,82,119,121,161,10,46,91,103,229,151,188,145,16,26,45,191,209,58,54,61,128,193,192,177,39,168,214,7,72,78,171,246,117,0,237,126,49,148,30,22,67,144,131,28,3,253,170,109,217,244,255,75,27,243,105,51,190,108,220,211,203,76,44,24,219,102,112,70,198,201,40,35,236,20,57,21,182,47,240,90,87,249,101,226,111,130,81,135,173,14,231,238,4,174,245,96,230,242,169,25,233,93,196,29,152,137,33,99,149,250,5,127,164,17,74,56,204,251,146,84,172,115,2,86,113,166,181,184,59,98,175,159,116,80,223,97,140,227,124,50,213,120,129,6,222,42,221,185,136,15,100,155,107,176,89,68,71,123,186,228,139,19,197,179,212,216,158,122,252,132,167,200,165,11,65,110,206,208,125,202,66,55,247,95,232,106,157,48,133,12,1,154,134,94,180,9,37,138,8,34,104,88,254,187,64,77,73,83,62,23,142,194,92,160,195,207,210,79,69,225,162,248,239,38,118,218,31,156,147,18,53,199,153,141,52,32,85,235,41,150,234,114},
	{153,107,250,114,87,105,61,235,203,148,231,165,189,182,159,67,176,190,100,99,155,209,9,81,1,183,139,162,83,41,109,20,142,85,233,90,49,88,164,177,199,194,180,240,42,193,82,154,197,170,218,202,236,54,198,63,119,78,11,22,244,247,166,146,222,75,184,145,66,51,163,72,188,223,196,213,5,239,65,200,27,94,40,206,192,19,64,201,210,124,175,158,52,179,86,161,23,39,255,242,138,232,253,103,229,157,245,55,58,102,254,174,7,93,125,230,217,156,24,120,36,129,57,3,71,13,178,53,10,224,207,136,79,46,216,246,33,211,18,8,144,135,131,150,50,97,84,28,89,186,12,30,147,132,2,32,118,48,134,116,37,243,74,252,69,112,106,143,227,220,15,225,111,43,17,248,249,221,104,77,101,160,152,215,110,172,0,34,38,68,21,251,117,149,95,92,31,130,234,169,35,241,214,141,204,191,62,121,45,212,44,238,96,60,122,80,205,128,76,91,29,26,137,185,126,173,195,73,70,181,140,25,208,59,237,113,133,127,4,115,228,98,123,14,56,219,151,171,167,226,6,168,187,108,47,16},
	{142,245,11,129,204,191,17,166,92,145,213,116,27,26,236,133,106,98,67,42,228,22,160,209,50,239,227,7,174,154,210,203,85,243,200,199,161,250,30,194,172,101,19,34,190,247,100,93,136,226,15,110,83,251,137,176,66,164,61,254,111,39,143,214,215,81,146,163,99,208,31,156,253,134,104,244,105,255,246,69,45,112,237,38,64,28,91,86,80,108,152,175,252,4,223,120,18,8,189,20,131,68,25,48,192,169,151,97,82,84,167,40,1,47,128,3,220,122,71,158,94,249,124,150,70,140,126,90,205,46,59,185,206,52,9,130,149,77,75,231,65,222,248,195,10,193,123,221,113,121,184,238,29,197,240,177,196,219,32,103,144,87,201,95,173,62,73,211,229,217,76,53,165,198,233,118,44,216,138,170,5,148,182,79,35,51,102,141,127,13,235,157,58,23,207,139,132,74,78,117,155,178,168,37,224,159,232,186,54,153,60,135,202,43,6,147,188,212,183,180,230,114,41,33,179,24,125,88,14,109,89,2,107,21,218,96,187,36,0,57,119,242,55,115,171,63,56,241,162,234,181,225,72,16,49,12}
};
#endif