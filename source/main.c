//
// main.c
// cmodeadv - pso ep1 challange mode route test
//
//

#include <string.h>
#include <stdlib.h>
#include <tonc.h>

#include "f1out.h"
#include "f2out.h"
#include "f3out.h"
#include "sp.h"
#include "sp2.h"
#include "bossW.h"
#include "dragon.h"
#include "polygon.h"

u32 hsec= 3600;
u32 sec= -1;

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

u16 affornot[128];
int spritex[128];
int spritey[128];
Point polygon1[] =
{
{31,1},
{55,1},
{55,26},
{68,26},
{105,8},
{122,4},
{149,4},
{174,16},
{181,37},
{187,60},
{184,74},
{189,88},
{194,95},
{198,97},
{214,96},
{225,108},
{235,141},
{253,140},
{264,134},
{268,122},
{287,108},
{296,95},
{320,93},
{334,88},
{338,80},
{339,74},
{337,71},
{341,30},
{361,17},
{386,17},
{412,3},
{451,0},
{489,11},
{505,32},
{503,54},
{484,78},
{477,96},
{472,101},
{473,107},
{480,110},
{493,121},
{493,153},
{501,174},
{512,235},
{509,256},
{500,275},
{473,288},
{450,280},
{451,267},
{432,255},
{438,235},
{438,215},
{443,190},
{456,176},
{464,163},
{460,154},
{443,153},
{443,137},
{464,136},
{465,122},
{459,110},
{455,105},
{422,78},
{411,57},
{399,42},
{385,38},
{365,42},
{358,55},
{356,74},
{354,77},
{353,82},
{358,87},
{377,122},
{369,131},
{355,138},
{351,155},
{363,175},
{386,196},
{391,203},
{394,228},
{386,256},
{371,273},
{367,291},
{366,299},
{375,324},
{386,330},
{414,332},
{427,358},
{419,389},
{410,400},
{422,415},
{407,432},
{386,432},
{373,430},
{358,435},
{350,451},
{355,469},
{371,477},
{400,481},
{419,466},
{429,445},
{440,426},
{458,412},
{479,412},
{499,422},
{510,447},
{504,490},
{484,504},
{479,512},
{460,510},
{424,494},
{402,495},
{386,498},
{365,499},
{351,491},
{340,477},
{339,462},
{328,442},
{296,437},
{296,423},
{290,401},
{281,385},
{272,385},
{254,422},
{237,456},
{204,445},
{202,423},
{193,390},
{190,379},
{193,356},
{198,332},
{190,315},
{179,306},
{172,306},
{164,309},
{152,313},
{145,328},
{139,352},
{135,390},
{136,407},
{131,424},
{122,427},
{98,432},
{97,486},
{81,486},
{81,469},
{61,469},
{61,448},
{81,448},
{77,390},
{58,373},
{21,353},
{17,339},
{24,335},
{23,326},
{12,324},
{6,304},
{12,256},
{5,209},
{0,191},
{11,163},
{22,135},
{40,122},
{42,119},
{43,113},
{48,86},
{68,63},
{68,43},
{14,43},
{14,26},
{31,26},
{31,1}
};
int n1 = sizeof(polygon1)/sizeof(polygon1[0]);

Point polygon2[] =
{
{81,84},
{86,86},
{91,88},
{96,90},
{99,94},
{102,99},
{104,104},
{106,109},
{109,113},
{115,112},
{120,111},
{125,112},
{130,114},
{135,116},
{140,117},
{146,117},
{151,118},
{156,116},
{161,113},
{166,111},
{171,109},
{176,106},
{181,107},
{186,108},
{191,110},
{195,114},
{198,119},
{202,123},
{204,128},
{206,133},
{209,138},
{210,143},
{212,148},
{213,154},
{215,159},
{218,163},
{222,167},
{226,170},
{231,174},
{235,177},
{239,181},
{243,184},
{247,188},
{251,192},
{255,195},
{259,199},
{263,203},
{267,207},
{271,210},
{275,214},
{279,218},
{283,221},
{286,226},
{289,230},
{292,235},
{295,240},
{298,244},
{301,249},
{304,253},
{309,256},
{314,258},
{319,259},
{324,261},
{329,263},
{335,264},
{340,266},
{345,267},
{347,272},
{348,277},
{348,283},
{349,288},
{350,294},
{350,299},
{347,303},
{343,308},
{339,311},
{334,313},
{329,315},
{324,318},
{319,320},
{314,321},
{309,323},
{304,324},
{298,326},
{295,329},
{294,335},
{294,340},
{295,346},
{295,351},
{292,356},
{289,360},
{285,365},
{281,368},
{276,369},
{271,370},
{265,370},
{261,372},
{257,376},
{254,381},
{251,386},
{249,391},
{247,396},
{244,401},
{242,406},
{239,410},
{237,415},
{235,420},
{231,424},
{226,425},
{222,424},
{221,418},
{220,413},
{219,407},
{218,402},
{216,397},
{215,391},
{213,386},
{211,381},
{209,376},
{205,372},
{206,366},
{210,363},
{211,358},
{211,352},
{213,348},
{218,346},
{223,343},
{228,340},
{233,340},
{238,341},
{244,342},
{249,343},
{254,343},
{258,339},
{262,335},
{263,330},
{264,324},
{265,319},
{265,313},
{266,308},
{267,302},
{267,297},
{268,292},
{269,286},
{270,281},
{270,275},
{271,270},
{272,264},
{273,259},
{275,254},
{279,251},
{282,247},
{279,243},
{275,239},
{272,235},
{268,231},
{264,227},
{260,230},
{256,233},
{251,235},
{246,236},
{240,236},
{235,237},
{229,237},
{224,239},
{220,242},
{216,246},
{211,249},
{207,252},
{203,256},
{201,261},
{199,266},
{197,271},
{195,276},
{193,281},
{191,286},
{186,287},
{180,289},
{175,290},
{170,291},
{164,290},
{159,289},
{154,288},
{149,291},
{145,294},
{141,298},
{137,302},
{133,305},
{129,309},
{125,313},
{122,317},
{122,323},
{122,328},
{122,334},
{122,339},
{122,345},
{122,350},
{121,355},
{119,361},
{118,366},
{117,371},
{117,377},
{117,382},
{117,388},
{116,393},
{114,398},
{112,403},
{107,406},
{103,405},
{98,401},
{95,397},
{92,392},
{91,387},
{91,381},
{91,376},
{91,370},
{91,365},
{87,361},
{83,358},
{78,354},
{73,354},
{68,354},
{62,354},
{58,351},
{53,348},
{48,346},
{44,342},
{43,337},
{39,334},
{40,328},
{43,324},
{46,319},
{48,314},
{51,310},
{54,305},
{58,301},
{59,296},
{59,291},
{60,285},
{60,280},
{61,274},
{61,269},
{64,264},
{67,260},
{71,255},
{74,251},
{77,247},
{81,242},
{84,238},
{87,234},
{91,229},
{94,225},
{97,220},
{98,216},
{95,212},
{91,207},
{88,203},
{88,198},
{91,194},
{97,194},
{102,193},
{107,193},
{107,187},
{107,182},
{106,177},
{101,177},
{96,177},
{90,177},
{87,173},
{84,168},
{81,164},
{79,159},
{76,154},
{74,149},
{72,144},
{70,139},
{68,134},
{66,129},
{64,123},
{60,120},
{58,116},
{59,111},
{63,107},
{66,102},
{69,98},
{73,94},
{76,89},
{79,85}
};
int n2 = sizeof(polygon2)/sizeof(polygon2[0]);

bool southHemi = 0;

void obj_test()
{
	OBJ_AFFINE *oaff_curr= &obj_aff_buffer[0];
	OBJ_AFFINE *oaff_base= &obj_aff_buffer[1];
	OBJ_AFFINE *oaff_new= &obj_aff_buffer[2];
	OBJ_AFFINE *oaff_newf6= &obj_aff_buffer[3];
	OBJ_AFFINE *oaff_newf8= &obj_aff_buffer[4];
	OBJ_AFFINE *oaff_newf10= &obj_aff_buffer[5];

	// oaff_curr = oaff_base * oaff_new
	// oaff_base changes when the aff-state changes
	// oaff_new is updated when it doesn't
	obj_aff_identity(oaff_curr);
	obj_aff_identity(oaff_base);
	obj_aff_identity(oaff_new);
	obj_aff_identity(oaff_newf6);

	int x= 120, y= 80;
	//int x= 92, y= 410;
	int x2= 0, y2= 0;
	int x2o=0, y2o=0;
	int f1x= 342, f1y= 117;
	int b1x=300, b1y=127;
	int w1x=39, w1y=10;
	int f2x= 31, f2y= 21;
	bool b1press=0;
	int b2x=356, b2y=120;
	bool b2press=0;
	int f5x= 352-8, f5y= 135-8;
	int b3x=450, b3y=480;
	bool b3press=0;
	int f7x= 468, f7y= 433;
	int f8x= 446, f8y= 416;
	int s1x= 476, s1y= 446;
	int d1x= 338, d1y=76 ;
	bool s1press=0;
	Point door1p[] ={{332,72},{332+40,72},{332+40,82},{332,82},{332,72}};
	int door1n = sizeof(door1p)/sizeof(door1p[0]);
	Point b1col[] ={{x2+b1x,y2+b1y},{x2+b1x+8,y2+b1y},{x2+b1x+8,y2+b1y+8},{x2+b1x,y2+b1y+8},{x2+b1x,y2+b1y}};
	int b1coln = sizeof(b1col)/sizeof(b1col[0]);
	//Point fence1[] ={{x2+f1x,y2+f1y},{x2+f1x+8,y2+f1y},{x2+f1x+8,y2+f1y+8},{x2+f1x,y2+f1y+8},{x2+f1x,y2+f1y}};
	Point fence1[] ={{355,137},{341,117},{365,94},{395,122},{355,137}};
	int fence1n = sizeof(fence1)/sizeof(fence1[0]);
	Point warp1p[] ={{x2+w1x,y2+w1y},{x2+w1x+8,y2+w1y},{x2+w1x+8,y2+w1y+8},{x2+w1x,y2+w1y+8},{x2+w1x,y2+w1y}};
	int warp1n = sizeof(warp1p)/sizeof(warp1p[0]);
	//Point fence2p[] ={{x2+f2x,y2+f2y},{x2+f2x+8,y2+f2y},{x2+f2x+8,y2+f2y+8},{x2+f2x,y2+f2y+8},{x2+f2x,y2+f2y}};
	Point fence2p[] ={{29,1},{55,1},{55,25},{29,25},{29,1}};
	int fence2n = sizeof(fence2p)/sizeof(fence2p[0]);
	Point b2col[] ={{x2+b2x,y2+b2y},{x2+b2x+8,y2+b2y},{x2+b2x+8,y2+b2y+8},{x2+b2x,y2+b2y+8},{x2+b2x,y2+b2y}};
	int b2coln = sizeof(b2col)/sizeof(b2col[0]);
	Point s1col[] ={{x2+s1x-8,y2+s1y-8},{x2+s1x+8+8,y2+s1y-8},{x2+s1x+8+8,y2+s1y+8+8},{x2+s1x-8,y2+s1y+8+8},{x2+s1x-8,y2+s1y-8}};
	int s1coln = sizeof(s1col)/sizeof(s1col[0]);
	Point b3col[] ={{x2+b3x,y2+b3y},{x2+b3x+8,y2+b3y},{x2+b3x+8,y2+b3y+8},{x2+b3x,y2+b3y+8},{x2+b3x,y2+b3y}};
	int b3coln = sizeof(b3col)/sizeof(b3col[0]);
	Point fence3p[] ={{510,440},{464,440},{482,410},{510,440}};
	int fence3n = sizeof(fence3p)/sizeof(fence3p[0]);
	int w2x=484, w2y=424;
	Point warp2p[] ={{x2+w2x,y2+w2y},{x2+w2x+8,y2+w2y},{x2+w2x+8,y2+w2y+8},{x2+w2x,y2+w2y+8},{x2+w2x,y2+w2y}};
	int warp2n = sizeof(warp2p)/sizeof(warp2p[0]);
	int w3x=490, w3y=32;
	Point warp3p[] ={{x2+w3x,y2+w3y},{x2+w3x+8,y2+w3y},{x2+w3x+8,y2+w3y+8},{x2+w3x,y2+w3y+8},{x2+w3x,y2+w3y}};
	int warp3n = sizeof(warp3p)/sizeof(warp3p[0]);
	int f9x=476 , f9y= 46;
	int f10x=476-32 , f10y= 46-16;
	int d2x= 351, d2y=288;
	int s2x= 416, s2y= 52;
	bool s2press=0;
	Point s2col[] ={{x2+s2x-8,y2+s2y-8},{x2+s2x+8+8,y2+s2y-8},{x2+s2x+8+8,y2+s2y+8+8},{x2+s2x-8,y2+s2y+8+8},{x2+s2x-8,y2+s2y-8}};
	int s2coln = sizeof(s2col)/sizeof(s2col[0]);
	Point door2p[] ={{d2x,d2y},{d2x+40,d2y},{d2x+40,d2y+10},{d2x,d2y+10},{d2x,d2y}};
	int door2n = sizeof(door2p)/sizeof(door2p[0]);
	int b4x=464, b4y=264;
	bool b4press=0;
	Point b4col[] ={{x2+b4x,y2+b4y},{x2+b4x+8,y2+b4y},{x2+b4x+8,y2+b4y+8},{x2+b4x,y2+b4y+8},{x2+b4x,y2+b4y}};
	int b4coln = sizeof(b4col)/sizeof(b4col[0]);
	Point fence4p[] ={{474,10},{474+40,10},{474+40,10+40},{474,10+40},{474,10}};
	int fence4n = sizeof(fence4p)/sizeof(fence4p[0]);
	int f12x=430 , f12y= 139;
	Point fence5p[] ={{436,136},{436+30,136},{436+30,136+20},{436,136+20},{436,136}};
	int fence5n = sizeof(fence5p)/sizeof(fence5p[0]);
	int f13x=51 , f13y= 451;
	Point fence6p[] ={{58,446},{58+30,446},{58+30,446+25},{58,446+25},{58,446}};
	int fence6n = sizeof(fence6p)/sizeof(fence6p[0]);
	int s3x= 206, s3y= 432;
	bool s3press=0;
	Point s3col[] ={{x2+s3x-8,y2+s3y-8},{x2+s3x+8+8,y2+s3y-8},{x2+s3x+8+8,y2+s3y+8+8},{x2+s3x-8,y2+s3y+8+8},{x2+s3x-8,y2+s3y-8}};
	int s3coln = sizeof(s3col)/sizeof(s3col[0]);
	int b5x=12, b5y=186;
	bool b5press=0;
	Point b5col[] ={{x2+b5x,y2+b5y},{x2+b5x+8,y2+b5y},{x2+b5x+8,y2+b5y+8},{x2+b5x,y2+b5y+8},{x2+b5x,y2+b5y}};
	int b5coln = sizeof(b5col)/sizeof(b5col[0]);
	int f14x=58 , f14y= 178;
	Point fence7p[] ={{88,177},{88+30,177},{88+30,177+20},{88,177+20},{88,177}};
	int fence7n = sizeof(fence7p)/sizeof(fence7p[0]);
	int d3x= 271, d3y=370 ;
	Point door3p[] ={{265,365},{265+15,365},{265+15,365+20},{265,365+20},{265,365}};
	int door3n = sizeof(door3p)/sizeof(door3p[0]);
	bool w1press=0;

	int dx= 0, dy=0;
	//int x= 0, y= 0;
	u32 tid= 0, pb= 0;		// tile id, pal-bank

	OBJ_ATTR *metr= &obj_buffer[0];
	obj_set_attr(metr,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_16,					// 16x16p,
		ATTR2_PALBANK(pb) | tid);		// palbank 0, tile 0

	// position sprite (redundant here; the _real_ position
	// is set further down
	obj_set_pos(metr, x, y);
	affornot[0]=ATTR0_REG;

	OBJ_ATTR *fence= &obj_buffer[1];
	obj_set_attr(fence,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence, x2+f1x, y2+f1y);
	affornot[1]=ATTR0_REG;
	spritex[1]=f1x;
	spritey[1]=f1y;

	OBJ_ATTR *button1= &obj_buffer[2];
	obj_set_attr(button1,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button1, x2+b1x, y2+b1y);
	affornot[2]=ATTR0_REG;
	spritex[2]=b1x;
	spritey[2]=b1y;

	OBJ_ATTR *warp1= &obj_buffer[3];
	obj_set_attr(warp1,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 10);		// palbank 0, tile 0

	obj_set_pos(warp1, x2+w1x, y2+w1y);
	affornot[3]=ATTR0_REG;
	spritex[3]=w1x;
	spritey[3]=w1y;

	OBJ_ATTR *fence2= &obj_buffer[4];
	obj_set_attr(fence2,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(0),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0


	obj_set_pos(fence2, x2+f2x, y2+f2y);
	spritex[4]=f2x;
	spritey[4]=f2y;
	obj_aff_identity(&obj_aff_buffer[0]);
	affornot[4]=ATTR0_AFF;
	//int aff_value = 0;
	//obj_aff_scale_inv(oaff_new, (1<<8)-aff_value, 1<<8);
	//aff_value &= SIN_MASK;
	//int diff= 128;
	//aff_value += (1 ? diff : -diff);
	//aff_value &= 511;


	OBJ_ATTR *button2= &obj_buffer[5];
	obj_set_attr(button2,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button2, x2+b2x, y2+b2y);
	affornot[5]=ATTR0_REG;
	spritex[5]=b2x;
	spritey[5]=b2y;

	OBJ_ATTR *fence3= &obj_buffer[6];
	obj_set_attr(fence3,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(0),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence3, x2+f2x+8, y2+f2y);
	affornot[6]=ATTR0_AFF;
	spritex[6]=f2x+8;
	spritey[6]=f2y;


	OBJ_ATTR *fence4= &obj_buffer[7];
	obj_set_attr(fence4,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(0),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence4, x2+f2x+8+8, y2+f2y);
	spritex[7]=f2x+8+8;
	spritey[7]=f2y;
	u16 alpha = 16364;
	obj_aff_rotate(oaff_new, alpha);
	//obj_aff_rotscale(oaff_new, (1<<8)-88, (1<<8)-88,alpha);
	obj_aff_copy(oaff_curr, oaff_base, 1);
	obj_aff_postmul(oaff_curr, oaff_new);
	affornot[7]=ATTR0_AFF;

	OBJ_ATTR *fence5= &obj_buffer[8];
	obj_set_attr(fence5,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(1),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence5, x2+f2x+8+8, y2+f2y);
	affornot[8]=ATTR0_AFF;
	spritex[8]=f5x;
	spritey[8]=f5y;
	obj_aff_identity(&obj_aff_buffer[1]);
	alpha = 8000;
	obj_aff_rotate(oaff_new, alpha);
	//obj_aff_scale(oaff_new, (1<<8), (1<<8)-64);
	//obj_aff_copy(oaff_curr, oaff_base, 1);
	obj_aff_postmul(oaff_base, oaff_new);
	//fence5->attr0 ^= ATTR0_AFF_DBL_BIT;

	OBJ_ATTR *fence6= &obj_buffer[9];
	obj_set_attr(fence6,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_16x8 | ATTR1_AFF_ID(3),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence6->attr0 ^= ATTR0_AFF_DBL;
	obj_set_pos(fence6, x2+f2x+8+8, y2+f2y);
	affornot[9]=ATTR0_AFF_DBL;
	spritex[9]=f5x-10;
	spritey[9]=f5y-25;
	obj_aff_identity(&obj_aff_buffer[3]);
	alpha = 8000;
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf6, oaff_new);

	OBJ_ATTR *button3= &obj_buffer[10];
	obj_set_attr(button3,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button3, x2+b3x, y2+b3y);
	affornot[10]=ATTR0_REG;
	spritex[10]=b3x;
	spritey[10]=b3y;

	OBJ_ATTR *fence7= &obj_buffer[11];
	obj_set_attr(fence7,
		ATTR0_WIDE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_32x8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	affornot[11]=ATTR0_REG;
	spritex[11]=f7x;
	spritey[11]=f7y;

	OBJ_ATTR *fence8= &obj_buffer[12];
	obj_set_attr(fence8,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(4),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[12]=ATTR0_AFF_DBL;
	spritex[12]=f8x;
	spritey[12]=f8y;
	alpha = 8000;
	obj_aff_identity(&obj_aff_buffer[4]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf8, oaff_new);

	OBJ_ATTR *switch1= &obj_buffer[13];
	obj_set_attr(switch1,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[13]=ATTR0_REG;
	spritex[13]=s1x;
	spritey[13]=s1y;

	OBJ_ATTR *door1L= &obj_buffer[14];
	obj_set_attr(door1L,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[14]=ATTR0_REG;
	spritex[14]=d1x;
	spritey[14]=d1y;

	OBJ_ATTR *door1R= &obj_buffer[15];
	obj_set_attr(door1R,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[15]=ATTR0_REG;
	spritex[15]=d1x+8;
	spritey[15]=d1y;

	OBJ_ATTR *warp2= &obj_buffer[16];
	obj_set_attr(warp2,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 10);		// palbank 0, tile 0

	obj_set_pos(warp2, x2+w2x, y2+w2y);
	affornot[16]=ATTR0_REG;
	spritex[16]=w2x;
	spritey[16]=w2y;

	OBJ_ATTR *warp3= &obj_buffer[17];
	obj_set_attr(warp3,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(1) | 10);		// palbank 0, tile 0

	obj_set_pos(warp3, x2+w3x, y2+w3y);
	affornot[17]=ATTR0_REG;
	spritex[17]=w3x;
	spritey[17]=w3y;

	OBJ_ATTR *fence9= &obj_buffer[18];
	obj_set_attr(fence9,
		ATTR0_WIDE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_32x8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	affornot[18]=ATTR0_REG;
	spritex[18]=f9x;
	spritey[18]=f9y;

	OBJ_ATTR *fence10= &obj_buffer[19];
	obj_set_attr(fence10,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(5),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[19]=ATTR0_AFF_DBL;
	spritex[19]=f10x;
	spritey[19]=f10y;
	alpha = 16000;
	obj_aff_identity(&obj_aff_buffer[5]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf10, oaff_new);

	OBJ_ATTR *fence11= &obj_buffer[20];
	obj_set_attr(fence11,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(5),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[20]=ATTR0_AFF_DBL;
	spritex[20]=f10x;
	spritey[20]=f10y-20;
	alpha = 16000;
	obj_aff_identity(&obj_aff_buffer[5]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf10, oaff_new);

	OBJ_ATTR *door2L= &obj_buffer[21];
	obj_set_attr(door2L,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[21]=ATTR0_REG;
	spritex[21]=d2x;
	spritey[21]=d2y;

	OBJ_ATTR *door2R= &obj_buffer[22];
	obj_set_attr(door2R,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[22]=ATTR0_REG;
	spritex[22]=d2x+8;
	spritey[22]=d2y;

	OBJ_ATTR *switch2= &obj_buffer[23];
	obj_set_attr(switch2,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[23]=ATTR0_REG;
	spritex[23]=s2x;
	spritey[23]=s2y;

	OBJ_ATTR *button4= &obj_buffer[24];
	obj_set_attr(button4,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0
	obj_set_pos(button4, x2+b4x, y2+b4y);
	affornot[24]=ATTR0_REG;
	spritex[24]=b4x;
	spritey[24]=b4y;

	OBJ_ATTR *fence12= &obj_buffer[25];
	obj_set_attr(fence12,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(5),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[25]=ATTR0_AFF_DBL;
	spritex[25]=f12x;
	spritey[25]=f12y;
	alpha = 16000;
	obj_aff_identity(&obj_aff_buffer[5]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf10, oaff_new);

	OBJ_ATTR *fence13= &obj_buffer[26];
	obj_set_attr(fence13,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(5),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[26]=ATTR0_AFF_DBL;
	spritex[26]=f13x;
	spritey[26]=f13y;
	alpha = 16000;
	obj_aff_identity(&obj_aff_buffer[5]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf10, oaff_new);

	OBJ_ATTR *switch3= &obj_buffer[27];
	obj_set_attr(switch3,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[27]=ATTR0_REG;
	spritex[27]=s3x;
	spritey[27]=s3y;

	OBJ_ATTR *button5= &obj_buffer[28];
	obj_set_attr(button5,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0
	obj_set_pos(button5, x2+b5x, y2+b5y);
	affornot[28]=ATTR0_REG;
	spritex[28]=b5x;
	spritey[28]=b5y;

	OBJ_ATTR *fence14= &obj_buffer[29];
	obj_set_attr(fence14,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(5),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[29]=ATTR0_AFF_DBL;
	spritex[29]=f14x;
	spritey[29]=f14y;
	alpha = 16000;
	obj_aff_identity(&obj_aff_buffer[5]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf10, oaff_new);

	OBJ_ATTR *door3L= &obj_buffer[30];
	obj_set_attr(door3L,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[30]=ATTR0_REG;
	spritex[30]=d3x;
	spritey[30]=d3y;

	OBJ_ATTR *door3R= &obj_buffer[31];
	obj_set_attr(door3R,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[31]=ATTR0_REG;
	spritex[31]=d3x;
	spritey[31]=d3y+8;


	dx = 121-x;
	x += dx;
	x2 -= dx;


	// move up/down
	dy = 410-y;
	y += dy;
	y2 -= dy;

	// Overflow every ~1 second:
	// 0x4000 ticks @ FREQ_1024
	REG_TM2D= -0x4000;          // 0x4000 ticks till overflow
	REG_TM2CNT= TM_FREQ_1024;   // we're using the 1024 cycle timer
	// cascade into tm3
	REG_TM3CNT= TM_ENABLE | TM_CASCADE;
	sec= -1;

	REG_TM2CNT ^= TM_ENABLE;
	while(1)
	{
		vid_vsync();
		key_poll();

		// move left/right
		Point p={x+2*key_tri_horz()+8,y+2*key_tri_vert()+8};
		//if(isInside(polygon1,n,p)){

		if(pnpoly(b1coln,b1col,p)){
			b1press = 1;
			fence->attr2= ATTR2_BUILD(4, 1, 0);
			fence5->attr2= ATTR2_BUILD(4, 1, 0);
			fence6->attr2= ATTR2_BUILD(6, 1, 0);
			button1->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(pnpoly(b2coln,b2col,p)){
			b2press = 1;
			fence2->attr2= ATTR2_BUILD(4, 1, 0);
			fence3->attr2= ATTR2_BUILD(4, 1, 0);
			fence4->attr2= ATTR2_BUILD(4, 1, 0);
			button2->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(pnpoly(b3coln,b3col,p)){
			b3press = 1;
			fence7->attr2= ATTR2_BUILD(6, 1, 0);
			fence8->attr2= ATTR2_BUILD(6, 1, 0);
			button3->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(pnpoly(b4coln,b4col,p)){
			b4press = 1;
			fence9->attr2= ATTR2_BUILD(6, 1, 0);
			fence10->attr2= ATTR2_BUILD(6, 1, 0);
			fence11->attr2= ATTR2_BUILD(6, 1, 0);
			fence12->attr2= ATTR2_BUILD(6, 1, 0);
			button4->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(pnpoly(b5coln,b5col,p)){
			b5press = 1;
			fence14->attr2= ATTR2_BUILD(6, 1, 0);
			button5->attr2= ATTR2_BUILD(5, 1, 0);
		}

		//gjemme ting fra å pakke rundt
		for (int i=1; i<32; i++){
			OBJ_ATTR *objj= &obj_buffer[i];
			//if(abs(y-(BFN_GET(objj->attr0,ATTR0_Y)-y2))>100){
			if(abs(y-spritey[i])>130){
				//affornot[i]=BFN_GET(objj->attr0,ATTR0_MODE);
				obj_hide(objj);

			}
			else{
				obj_unhide(objj,affornot[i]);
				//obj_unhide(objj,ATTR0_AFF);
				//obj_unhide(objj,ATTR0_MODE(i));
				//objj->attr0 ^=ATTR0_HIDE;
			}
			//objj->attr0 ^=ATTR0_HIDE;
		}



		if(pnpoly(warp1n,warp1p,p)){
			dx = 352-x;
			x += dx;
			x2 -= dx;


			// move up/down
			dy = 372-y;
			y += dy;
			y2 -= dy;
			if(!w1press){
				w1press = 1;
				d3y -= 8;
			}
			obj_set_pos(metr, 120, 80);

		}
		if(pnpoly(warp2n,warp2p,p)){
			dx = 136-x;
			x += dx;
			x2 -= dx;


			// move up/down
			dy = 84-y;
			y += dy;
			y2 -= dy;
			obj_set_pos(metr, 120, 80);
		}
		if(pnpoly(warp3n,warp3p,p)){
			REG_TM2CNT ^= TM_ENABLE;
			//REG_TM3CNT ^= TM_ENABLE;

			tte_printf("#{cx:0x1000}\n Hit 'A' to next level");
			while(1){
				key_poll();
				if(key_hit(KEY_A)){
					break;
				}
			}
			memcpy(&tile_mem[0][0], f2outTiles, f2outTilesLen);
			// Load map into SBB 28
			memcpy(&se_mem[20][0], f2outMap, f2outMapLen);
			//REG_BG1CNT= BG_CBB(2) | BG_SBB(20) | BG_4BPP | BG_REG_64x64;
			oam_init(obj_buffer, 128);
			/*
			if (sec<hsec){
				hsec = sec;
			}
			sec=-1;
			obj_test();
			*/
			level2();
		}

		if(pnpoly(s1coln,s1col,p) && !s1press){
			if(key_hit(KEY_A)){
				s1press=1;
				d1x -= 8;
				switch1->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(s2coln,s2col,p) && !s2press){
			if(key_hit(KEY_A)){
				s2press=1;
				d2x -= 8;
				switch2->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(s3coln,s3col,p) && !s3press){
			if(key_hit(KEY_A)){
				s3press=1;
				fence13->attr2= ATTR2_BUILD(6, 1, 0);
				switch3->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(n1,polygon1,p) && !pnpoly(n2,polygon2,p)){
			if (pnpoly(fence1n,fence1,p) && !b1press){

			}
			else if(pnpoly(fence2n,fence2p,p) && !b2press){

			}
			else if(pnpoly(fence3n,fence3p,p) && !b3press){

			}
			else if(pnpoly(fence4n,fence4p,p) && !b4press){

			}
			else if(pnpoly(fence5n,fence5p,p) && !b4press){

			}
			else if(pnpoly(fence7n,fence7p,p) && !b5press){

			}
			else if(pnpoly(fence6n,fence6p,p) && !s3press){

			}
			else if(pnpoly(door1n,door1p,p) && !s1press){

			}
			else if(pnpoly(door2n,door2p,p) && !s2press){

			}
			else if(pnpoly(door3n,door3p,p) && !w1press){

			}
			else{
				dx = 2*key_tri_horz();
				x += dx;
				x2 -= dx;


				// move up/down
				dy = 2*key_tri_vert();
				y += dy;
				y2 -= dy;
				x2o=x2;
				y2o=y2;
				if(y<80 && x<120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, x, y);


					x2=0;
					y2=0;


				}
				else if(y>512-80 && x<120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, x, 160-(512-y));


					x2=0;
					y2=y2-(512-80-y);


				}
				else if(y>512-80 && x>512-120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 240-(512-x), 160-(512-y));


					x2=x2-(512-120-x);
					y2=y2-(512-80-y);


				}
				else if(x>512-120 && y<80){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 240-(512-x), y);
					x2=x2-(512-120-x);
					y2=0;

				}
				else if(y<80){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 120, y);
					y2=0;
					REG_BG1HOFS= x-120;
				}
				else if(y>512-80){
					obj_set_pos(metr, 120, 160-(512-y));
					REG_BG1HOFS= x-120;
					y2=y2-(512-80-y);

				}

				else if(x<120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, x, 80);
					REG_BG1VOFS= y-80;
					x2=0;

				}
				else if(x>512-120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 240-(512-x), 80);
					REG_BG1VOFS= y-80;
					x2=x2-(512-120-x);

				}
				else{
					REG_BG1HOFS= x-120;
					REG_BG1VOFS= y-80;
				}

				obj_set_pos(fence, x2+f1x, y2+f1y);
				obj_set_pos(button1, x2+b1x, y2+b1y);
				obj_set_pos(warp1, x2+w1x, y2+w1y);
				obj_set_pos(fence2, x2+f2x, y2+f2y);
				obj_set_pos(button2, x2+b2x, y2+b2y);
				obj_set_pos(fence3, x2+f2x+8, y2+f2y);
				obj_set_pos(fence4, x2+f2x+8+8, y2+f2y);
				obj_set_pos(fence5, x2+f5x, y2+f5y);
				obj_set_pos(fence6, x2+f5x-10, y2+f5y-25);
				obj_set_pos(button3, x2+b3x, y2+b3y);
				obj_set_pos(fence7, x2+f7x, y2+f7y);
				obj_set_pos(fence8, x2+f8x, y2+f8y);
				obj_set_pos(switch1, x2+s1x, y2+s1y);
				obj_set_pos(door1L, x2+d1x, y2+d1y);
				obj_set_pos(door1R, x2+d1x+8, y2+d1y);
				obj_set_pos(warp2, x2+w2x, y2+w2y);
				obj_set_pos(warp3, x2+w3x, y2+w3y);
				obj_set_pos(fence9, x2+f9x, y2+f9y);
				obj_set_pos(fence10, x2+f10x, y2+f10y);
				obj_set_pos(fence11, x2+f10x, y2+f10y-20);
				obj_set_pos(door2L, x2+d2x, y2+d2y);
				obj_set_pos(door2R, x2+d2x+8, y2+d2y);
				obj_set_pos(switch2, x2+s2x, y2+s2y);
				obj_set_pos(button4, x2+b4x, y2+b4y);
				obj_set_pos(fence12, x2+f12x, y2+f12y);
				obj_set_pos(fence13, x2+f13x, y2+f13y);
				obj_set_pos(switch3, x2+s3x, y2+s3y);
				obj_set_pos(button5, x2+b5x, y2+b5y);
				obj_set_pos(fence14, x2+f14x, y2+f14y);
				obj_set_pos(door3L, x2+d3x, y2+d3y);
				obj_set_pos(door3R, x2+d3x, y2+d3y+8);
				x2=x2o;
				y2=y2o;

			}
		}

		// increment/decrement starting tile with R/L
		tid += bit_tribool(key_hit(-1), KI_R, KI_L);

		// flip
		if(key_hit(KEY_A))	// horizontally
			metr->attr1 ^= ATTR1_HFLIP;
		if(key_hit(KEY_B))	// vertically
			metr->attr1 ^= ATTR1_VFLIP;

		// make it glow (via palette swapping)
		pb= key_is_down(KEY_SELECT) ? 1 : 0;

		// toggle mapping mode
		if(key_hit(KEY_START)){
			//REG_TM2CNT ^= TM_ENABLE;
			//REG_DISPCNT ^= DCNT_OBJ_1D;
			}

		// Hey look, it's one of them build macros!
		metr->attr2= ATTR2_BUILD(tid, pb, 0);


		oam_copy(oam_mem, obj_buffer, 32);	// only need to update one
		obj_aff_copy(obj_aff_mem, obj_aff_buffer, 6);
		/*
		tte_printf("#{el}");
		tte_printf("#{X:0}");
		tte_printf("#{cx:0x1000}warp1:,%d",abs(y-(BFN_GET(warp1->attr0,ATTR0_Y)-y2)));
		//tte_printf("#{el}");
		//tte_printf("#{X:72}");
		tte_printf("#{cx:0x1000} x: ,%d",x);      // Print "Hello world!"
		tte_printf("#{cx:0x1000} y: ,%d",y);      // Print "Hello world!"
		*/
		if(REG_TM3D != sec)
		        {
		            sec= REG_TM3D;
		            tte_printf("#{es;P:24,5}Time %02d:%02d  Best %02d:%02d",
		                 (sec%3600)/60, sec%60,
									 (hsec%3600)/60, hsec%60);
		        }

	}



}

int level2(){

OBJ_AFFINE *oaff_base= &obj_aff_buffer[1];
OBJ_AFFINE *oaff_new= &obj_aff_buffer[2];

Point polygon1[] =	{
{32,0},
{81,14},
{116,11},
{124,16},
{126,22},
{136,22},
{189,70},
{195,63},
{184,40},
{198,9},
{235,11},
{258,27},
{256,72},
{236,133},
{238,161},
{252,169},
{309,106},
{307,91},
{360,87},
{388,101},
{400,115},
{397,145},
{350,159},
{300,147},
{276,169},
{273,235},
{296,232},
{309,201},
{345,218},
{332,248},
{274,251},
{266,294},
{276,361},
{271,397},
{247,440},
{255,449},
{295,436},
{338,394},
{365,338},
{386,348},
{371,384},
{375,412},
{387,432},
{469,431},
{470,456},
{449,457},
{450,465},
{470,470},
{477,498},
{449,511},
{427,496},
{430,457},
{416,455},
{410,493},
{354,512},
{319,494},
{322,468},
{308,454},
{188,508},
{131,481},
{83,477},
{65,460},
{18,441},
{0,397},
{11,375},
{55,357},
{50,349},
{8,348},
{7,328},
{24,329},
{24,322},
{18,310},
{18,294},
{35,286},
{55,307},
{42,318},
{42,328},
{64,330},
{76,346},
{85,340},
{81,302},
{46,256},
{10,238},
{10,197},
{27,165},
{52,175},
{50,221},
{63,251},
{75,247},
{81,234},
{83,213},
{74,184},
{76,135},
{47,134},
{40,71},
{74,58},
{84,64},
{86,93},
{93,94},
{94,62},
{77,45},
{32,59},
{8,46},
{7,20},
{32,0}};
int n1 = sizeof(polygon1)/sizeof(polygon1[0]);

Point polygon2[] =
{
{95,134},
{110,130},
{120,41},
{128,39},
{156,71},
{180,91},
{152,148},
{149,156},
{133,162},
{113,158},
{103,160},
{94,149},
{94,134}};
int n2 = sizeof(polygon2)/sizeof(polygon2[0]);

Point polygon3[] =
{
{159,170},
{183,170},
{191,182},
{215,175},
{240,181},
{255,203},
{255,235},
{231,270},
{227,314},
{220,350},
{210,359},
{199,351},
{208,263},
{205,238},
{196,227},
{169,226},
{158,238},
{154,265},
{170,326},
{154,334},
{133,332},
{122,355},
{119,388},
{128,421},
{148,421},
{186,381},
{198,379},
{196,399},
{157,446},
{131,461},
{90,460},
{87,451},
{112,428},
{96,387},
{106,345},
{100,320},
{100,292},
{121,291},
{134,280},
{135,251},
{115,252},
{114,271},
{91,273},
{87,264},
{133,226},
{149,221},
{154,212},
{144,195},
{152,181},
{159,170}};
int n3 = sizeof(polygon3)/sizeof(polygon3[0]);

Point polygon4[] =
{
{370,330},
{400,341},
{459,354},
{498,339},
{512,306},
{488,266},
{480,223},
{509,159},
{494,119},
{471,121},
{455,112},
{439,93},
{430,65},
{441,34},
{342,19},
{332,30},
{325,30},
{305,44},
{305,83},
{359,77},
{390,92},
{409,113},
{407,147},
{465,145},
{478,163},
{464,213},
{456,222},
{383,252},
{370,265},
{367,324},
{370,329}};
int n4 = sizeof(polygon4)/sizeof(polygon4[0]);

Point polygon5[] =
{
{382,238},
{407,229},
{416,196},
{384,177},
{363,198},
{377,234},
{383,238}};
int n5 = sizeof(polygon5)/sizeof(polygon5[0]);



	// Overflow every ~1 second:
	// 0x4000 ticks @ FREQ_1024
	REG_TM2D= -0x4000;          // 0x4000 ticks till overflow
	REG_TM2CNT= TM_FREQ_1024;   // we're using the 1024 cycle timer
	// cascade into tm3
	REG_TM3CNT= TM_ENABLE | TM_CASCADE;
	//sec= -1;

	REG_TM2CNT ^= TM_ENABLE;

	int x= 10, y= 10;
	int ox=120-x, oy=80-y;
	//int x= 92, y= 410;
	int x2= 0, y2= 0;
	int x2o=0, y2o=0;
	int dx= 0, dy=0;
	//int x= 0, y= 0;
	u32 tid= 0, pb= 0;		// tile id, pal-bank

	OBJ_ATTR *metr= &obj_buffer[0];
	obj_set_attr(metr,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_16,					// 16x16p,
		ATTR2_PALBANK(pb) | tid);		// palbank 0, tile 0

	// position sprite (redundant here; the _real_ position
	// is set further down
	obj_set_pos(metr, x, y);


	//sprites2
	int f2_1x=342+ox-18 , f2_1y= 388+oy;
	Point fence2_1p[] ={{320,400},{320+60,400},{320+60,400-10},{320,400-10},{320,400}};
	int fence2_1n = sizeof(fence2_1p)/sizeof(fence2_1p[0]);
	int s2_1x= 350+ox, s2_1y= 370+oy;
	bool s2_1press=0;
	Point s2_1col[] ={{x2+s2_1x-ox-8,y2+s2_1y-oy-8},{x2+s2_1x-ox+8+8,y2+s2_1y-oy-8},
	{x2+s2_1x-ox+8+8,y2+s2_1y-oy+8+8},{x2+s2_1x-ox-8,y2+s2_1y-oy+8+8},{x2+s2_1x-ox-8,y2+s2_1y-oy-8}};
	int s2_1coln = sizeof(s2_1col)/sizeof(s2_1col[0]);
	int w1x=456, w1y=484;
	Point warp1p[] ={{x2+w1x,y2+w1y},{x2+w1x+8,y2+w1y},{x2+w1x+8,y2+w1y+8},{x2+w1x,y2+w1y+8},{x2+w1x,y2+w1y}};
	int warp1n = sizeof(warp1p)/sizeof(warp1p[0]);
	int w2x=375, w2y=195;
	Point warp2p[] ={{x2+w2x,y2+w2y},{x2+w2x+8,y2+w2y},{x2+w2x+8,y2+w2y+8},{x2+w2x,y2+w2y+8},{x2+w2x,y2+w2y}};
	int warp2n = sizeof(warp2p)/sizeof(warp2p[0]);
	int w3x=365, w3y=348;
	Point warp3p[] ={{x2+w3x,y2+w3y},{x2+w3x+8,y2+w3y},{x2+w3x+8,y2+w3y+8},{x2+w3x,y2+w3y+8},{x2+w3x,y2+w3y}};
	int warp3n = sizeof(warp3p)/sizeof(warp3p[0]);
	int w4x=392, w4y=222;
	Point warp4p[] ={{x2+w4x,y2+w4y},{x2+w4x+8,y2+w4y},{x2+w4x+8,y2+w4y+8},{x2+w4x,y2+w4y+8},{x2+w4x,y2+w4y}};
	int warp4n = sizeof(warp4p)/sizeof(warp4p[0]);
	int b1x=347, b1y=483;
	bool b1press=0;
	Point b1col[] ={{x2+b1x,y2+b1y},{x2+b1x+8,y2+b1y},{x2+b1x+8,y2+b1y+8},{x2+b1x,y2+b1y+8},{x2+b1x,y2+b1y}};
	int b1coln = sizeof(b1col)/sizeof(b1col[0]);
	int f2_2x=421-32 , f2_2y= 437-32-8;
	Point fence2_2p[] ={{420,426},{420+3,426},{420+3,426+50},{420,426+50},{420,426}};
	int fence2_2n = sizeof(fence2_2p)/sizeof(fence2_2p[0]);
	int d1x= 75, d1y=138 ;
	Point door1p[] ={{x2+d1x,y2+d1y},{x2+d1x+20,y2+d1y},{x2+d1x+20,y2+d1y+8},{x2+d1x,y2+d1y+8},{x2+d1x,y2+d1y}};
	int door1n = sizeof(door1p)/sizeof(door1p[0]);
	int s2x= 76, s2y= 160;
	bool s2press=0;
	Point s2col[] ={{x2+s2x-8,y2+s2y-8},{x2+s2x+8+8,y2+s2y-8},{x2+s2x+8+8,y2+s2y+8+8},{x2+s2x-8,y2+s2y+8+8},{x2+s2x-8,y2+s2y-8}};
	int s2coln = sizeof(s2col)/sizeof(s2col[0]);
	int d2x= 150, d2y=154;
	Point door2p[] ={{x2+d2x,y2+d2y},{x2+d2x+8,y2+d2y},{x2+d2x+8,y2+d2y+20},{x2+d2x,y2+d2y+20},{x2+d2x,y2+d2y}};
	int door2n = sizeof(door2p)/sizeof(door2p[0]);
	int s3x= 130, s3y= 164;
	bool s3press=0;
	Point s3col[] ={{x2+s3x-8,y2+s3y-8},{x2+s3x+8+8,y2+s3y-8},{x2+s3x+8+8,y2+s3y+8+8},{x2+s3x-8,y2+s3y+8+8},{x2+s3x-8,y2+s3y-8}};
	int s3coln = sizeof(s3col)/sizeof(s3col[0]);
	int d3x= 274, d3y=235;
	Point door3p[] ={{x2+d3x,y2+d3y},{x2+d3x+8,y2+d3y},{x2+d3x+8,y2+d3y+20},{x2+d3x,y2+d3y+20},{x2+d3x,y2+d3y}};
	int door3n = sizeof(door3p)/sizeof(door3p[0]);
	int s4x= 308, s4y= 210;
	bool s4press=0;
	Point s4col[] ={{x2+s4x-8,y2+s4y-8},{x2+s4x+8+8,y2+s4y-8},{x2+s4x+8+8,y2+s4y+8+8},{x2+s4x-8,y2+s4y+8+8},{x2+s4x-8,y2+s4y-8}};
	int s4coln = sizeof(s4col)/sizeof(s4col[0]);
	int f2_3x=153-20+16 , f2_3y= 257;
	Point fence2_3p[] ={{x2+f2_3x,y2+f2_3y},{x2+f2_3x+32,y2+f2_3y},{x2+f2_3x+32,y2+f2_3y+8},{x2+f2_3x,y2+f2_3y+8},{x2+f2_3x,y2+f2_3y}};
	int fence2_3n = sizeof(fence2_3p)/sizeof(fence2_3p[0]);
	int f2_4x=f2_3x+32 , f2_4y= 257;
	Point fence2_4p[] ={{x2+f2_4x,y2+f2_4y},{x2+f2_4x+32,y2+f2_4y},{x2+f2_4x+32,y2+f2_4y+8},{x2+f2_4x,y2+f2_4y+8},{x2+f2_4x,y2+f2_4y}};
	int fence2_4n = sizeof(fence2_4p)/sizeof(fence2_4p[0]);
	int b2x=178, b2y=242;
	bool b2press=0;
	Point b2col[] ={{x2+b2x,y2+b2y},{x2+b2x+8,y2+b2y},{x2+b2x+8,y2+b2y+8},{x2+b2x,y2+b2y+8},{x2+b2x,y2+b2y}};
	int b2coln = sizeof(b2col)/sizeof(b2col[0]);
	int b3x=178, b3y=276;
	bool b3press=0;
	Point b3col[] ={{x2+b3x,y2+b3y},{x2+b3x+8,y2+b3y},{x2+b3x+8,y2+b3y+8},{x2+b3x,y2+b3y+8},{x2+b3x,y2+b3y}};
	int b3coln = sizeof(b3col)/sizeof(b3col[0]);
	int f2_5x=31 , f2_5y= 244;
	Point fence2_5p[] ={{x2+f2_5x,y2+f2_5y},{x2+f2_5x+32,y2+f2_5y},{x2+f2_5x+32,y2+f2_5y+8},{x2+f2_5x,y2+f2_5y+8},{x2+f2_5x,y2+f2_5y}};
	int fence2_5n = sizeof(fence2_5p)/sizeof(fence2_5p[0]);
	int b4x=118, b4y=258;
	bool b4press=0;
	Point b4col[] ={{x2+b4x,y2+b4y},{x2+b4x+8,y2+b4y},{x2+b4x+8,y2+b4y+8},{x2+b4x,y2+b4y+8},{x2+b4x,y2+b4y}};
	int b4coln = sizeof(b4col)/sizeof(b4col[0]);
	int f2_6x=16 , f2_6y= 324;
	Point fence2_6p[]={{x2+f2_6x,y2+f2_6y},{x2+f2_6x+32,y2+f2_6y},{x2+f2_6x+32,y2+f2_6y+8},{x2+f2_6x,y2+f2_6y+8},{x2+f2_6x,y2+f2_6y}};
	int fence2_6n = sizeof(fence2_6p)/sizeof(fence2_6p[0]);
	int s5x= 24, s5y= 178;
	bool s5press=0;
	Point s5col[]={{x2+s5x-8,y2+s5y-8},{x2+s5x+8+8,y2+s5y-8},{x2+s5x+8+8,y2+s5y+8+8},{x2+s5x-8,y2+s5y+8+8},{x2+s5x-8,y2+s5y-8}};
	int s5coln = sizeof(s5col)/sizeof(s5col[0]);
	int bwx= 320, bwy= 40;
	Point bwcol[]={{x2+bwx,y2+bwy},{x2+bwx+32,y2+bwy},{x2+bwx+32,y2+bwy+32},{x2+bwx,y2+bwy+32},{x2+bwx,y2+bwy}};
	int bwcoln = sizeof(bwcol)/sizeof(bwcol[0]);

	u32 t1 = 0;

	OBJ_ATTR *fence2_1= &obj_buffer[1];
	obj_set_attr(fence2_1,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(0),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[1]=ATTR0_AFF_DBL;
	spritex[1]=f2_1x;
	spritey[1]=f2_1y;
	//alpha = 16000;
	//obj_aff_identity(&obj_aff_buffer[5]);
	//obj_aff_rotate(oaff_new, alpha);
	//obj_aff_postmul(oaff_newf10, oaff_new);

	OBJ_ATTR *switch2_1= &obj_buffer[2];
	obj_set_attr(switch2_1,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[2]=ATTR0_REG;
	spritex[2]=s2_1x;
	spritey[2]=s2_1y;

	OBJ_ATTR *warp1= &obj_buffer[3];
	obj_set_attr(warp1,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 10);		// palbank 0, tile 0

	obj_set_pos(warp1, x2+w1x+ox, y2+w1y+oy);
	affornot[3]=ATTR0_REG;
	spritex[3]=w1x;
	spritey[3]=w1y;

	OBJ_ATTR *warp2= &obj_buffer[4];
	obj_set_attr(warp2,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 10);		// palbank 0, tile 0

	obj_set_pos(warp2, x2+w2x+ox, y2+w2y+oy);
	affornot[4]=ATTR0_REG;
	spritex[4]=w2x;
	spritey[4]=w2y;

	OBJ_ATTR *warp3= &obj_buffer[5];
	obj_set_attr(warp3,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 10);		// palbank 0, tile 0

	obj_set_pos(warp3, x2+w3x+ox, y2+w3y+oy);
	affornot[5]=ATTR0_REG;
	spritex[5]=w3x;
	spritey[5]=w3y;

	OBJ_ATTR *warp4= &obj_buffer[6];
	obj_set_attr(warp4,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 10);		// palbank 0, tile 0

	obj_set_pos(warp4, x2+w4x+ox, y2+w4y+oy);
	affornot[6]=ATTR0_REG;
	spritex[6]=w4x;
	spritey[6]=w4y;

	OBJ_ATTR *button1= &obj_buffer[7];
	obj_set_attr(button1,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button1, x2+b1x+ox, y2+b1y+oy);
	affornot[7]=ATTR0_REG;
	spritex[7]=b1x;
	spritey[7]=b1y;

	OBJ_ATTR *fence2_2= &obj_buffer[8];
	obj_set_attr(fence2_2,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF_DBL,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(1),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[8]=ATTR0_AFF_DBL;
	spritex[8]=f2_2x;
	spritey[8]=f2_2y;
	s16 alpha = 16000;
	obj_aff_identity(&obj_aff_buffer[1]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_base, oaff_new);

	OBJ_ATTR *door1L= &obj_buffer[9];
	obj_set_attr(door1L,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[9]=ATTR0_REG;
	spritex[9]=d1x;
	spritey[9]=d1y;

	OBJ_ATTR *door1R= &obj_buffer[10];
	obj_set_attr(door1R,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[10]=ATTR0_REG;
	spritex[10]=d1x+8;
	spritey[10]=d1y;

	OBJ_ATTR *switch2= &obj_buffer[11];
	obj_set_attr(switch2,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[11]=ATTR0_REG;
	spritex[11]=s2x;
	spritey[11]=s2y;

	OBJ_ATTR *door2L= &obj_buffer[12];
	obj_set_attr(door2L,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[12]=ATTR0_REG;
	spritex[12]=d2x;
	spritey[12]=d2y;

	OBJ_ATTR *door2R= &obj_buffer[13];
	obj_set_attr(door2R,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[13]=ATTR0_REG;
	spritex[13]=d2x;
	spritey[13]=d2y+8;

	OBJ_ATTR *switch3= &obj_buffer[14];
	obj_set_attr(switch3,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[14]=ATTR0_REG;
	spritex[14]=s3x;
	spritey[14]=s3y;

	OBJ_ATTR *door3L= &obj_buffer[15];
	obj_set_attr(door3L,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[15]=ATTR0_REG;
	spritex[15]=d3x;
	spritey[15]=d3y;

	OBJ_ATTR *door3R= &obj_buffer[16];
	obj_set_attr(door3R,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	affornot[16]=ATTR0_REG;
	spritex[16]=d3x;
	spritey[16]=d3y+8;

	OBJ_ATTR *switch4= &obj_buffer[17];
	obj_set_attr(switch4,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[17]=ATTR0_REG;
	spritex[17]=s4x;
	spritey[17]=s4y;

	OBJ_ATTR *fence2_3= &obj_buffer[18];
	obj_set_attr(fence2_3,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_REG,				// Square, regular sprite
		ATTR1_SIZE_32x8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[18]=ATTR0_REG;
	spritex[18]=f2_3x;
	spritey[18]=f2_3y;

	OBJ_ATTR *fence2_4= &obj_buffer[19];
	obj_set_attr(fence2_4,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_REG,				// Square, regular sprite
		ATTR1_SIZE_32x8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[19]=ATTR0_REG;
	spritex[19]=f2_4x;
	spritey[19]=f2_4y;

	OBJ_ATTR *button2= &obj_buffer[20];
	obj_set_attr(button2,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button2, x2+b2x+ox, y2+b2y+oy);
	affornot[20]=ATTR0_REG;
	spritex[20]=b2x;
	spritey[20]=b2y;

	OBJ_ATTR *button3= &obj_buffer[21];
	obj_set_attr(button3,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button3, x2+b3x+ox, y2+b3y+oy);
	affornot[21]=ATTR0_REG;
	spritex[21]=b3x;
	spritey[21]=b3y;

	OBJ_ATTR *fence2_5= &obj_buffer[22];
	obj_set_attr(fence2_5,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_REG,				// Square, regular sprite
		ATTR1_SIZE_32x8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[22]=ATTR0_REG;
	spritex[22]=f2_5x;
	spritey[22]=f2_5y;

	OBJ_ATTR *button4= &obj_buffer[23];
	obj_set_attr(button4,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button3, x2+b4x+ox, y2+b4y+oy);
	affornot[23]=ATTR0_REG;
	spritex[23]=b4x;
	spritey[23]=b4y;

	OBJ_ATTR *switch5= &obj_buffer[24];
	obj_set_attr(switch5,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	affornot[24]=ATTR0_REG;
	spritex[24]=s5x;
	spritey[24]=s5y;

	OBJ_ATTR *fence2_6= &obj_buffer[25];
	obj_set_attr(fence2_6,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_REG,				// Square, regular sprite
		ATTR1_SIZE_32x8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[25]=ATTR0_REG;
	spritex[25]=f2_6x;
	spritey[25]=f2_6y;

	OBJ_ATTR *bossW= &obj_buffer[26];
	obj_set_attr(bossW,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_REG,				// Square, regular sprite
		ATTR1_SIZE_32,					// 16x8p,
		ATTR2_PALBANK(0) | 13);		// palbank 0, tile 0
	//fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	affornot[26]=ATTR0_REG;
	spritex[26]=bwx;
	spritey[26]=bwy;

	while(1){
		vid_vsync();
		key_poll();



		if(REG_TM3D != sec)
		        {
		            sec= REG_TM3D;
		            tte_printf("#{es;P:0,5}Time %02d:%02d  Best %02d:%02d",
		                 (sec%3600)/60, sec%60,
									 (hsec%3600)/60, hsec%60);
									 //tte_printf("#{cx:0x1000}\n x: ,%d",x);      // Print "Hello world!"
							 		//tte_printf("#{cx:0x1000}\n y: ,%d",y);      // Print "Hello world!"
		        }
		// move left/right
		Point p={x+2*key_tri_horz()+8,y+2*key_tri_vert()+8};

		if(pnpoly(s2_1coln,s2_1col,p) && !s2_1press){
			if(key_hit(KEY_A)){
				s2_1press=1;
				fence2_1->attr2= ATTR2_BUILD(6, 1, 0);
				switch2_1->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(s2coln,s2col,p) && !s2press){
			if(key_hit(KEY_A)){
				s2press=1;
				d1x -= 8;
				switch2->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(s3coln,s3col,p) && !s3press){
			if(key_hit(KEY_A)){
				s3press=1;
				d2y -= 16;
				switch3->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(s4coln,s4col,p) && !s4press){
			if(key_hit(KEY_A)){
				s4press=1;
				d3y -= 16;
				switch4->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(s5coln,s5col,p) && !s5press){
			if(key_hit(KEY_A)){
				s5press=1;
				fence2_6->attr2= ATTR2_BUILD(6, 1, 0);
				switch5->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(b1coln,b1col,p) && !b1press){
			t1 =sec + 1;
			b1press=1;
			fence2_2->attr2= ATTR2_BUILD(6, 1, 0);
			button1->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(pnpoly(b2coln,b2col,p) && !b2press){
			b2press=1;
			fence2_4->attr2= ATTR2_BUILD(6, 1, 0);
			button2->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(pnpoly(b3coln,b3col,p) && !b3press){
			b3press=1;
			fence2_3->attr2= ATTR2_BUILD(6, 1, 0);
			button3->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(pnpoly(b4coln,b4col,p) && !b4press){
			b4press=1;
			fence2_5->attr2= ATTR2_BUILD(6, 1, 0);
			button4->attr2= ATTR2_BUILD(5, 1, 0);
		}
		if(b1press){
			if(sec>t1){
				b1press=0;
				fence2_2->attr2= ATTR2_BUILD(6, 0, 0);
				button1->attr2= ATTR2_BUILD(5, 0, 0);
			}
		}

		if(pnpoly(bwcoln,bwcol,p)){
			REG_TM2CNT ^= TM_ENABLE;
			//REG_TM3CNT ^= TM_ENABLE;

			tte_printf("#{cx:0x1000}\n Hit 'A' to next level");
			while(1){
				key_poll();
				if(key_hit(KEY_A)){
					break;
				}
			}
			memcpy(&tile_mem[0][0], f3outTiles, f2outTilesLen);
			// Load map into SBB 28
			memcpy(&se_mem[20][0], f3outMap, f2outMapLen);
			//REG_BG1CNT= BG_CBB(2) | BG_SBB(20) | BG_4BPP | BG_REG_64x64;
			memcpy(pal_obj_mem, dragonPal, dragonPalLen);
			oam_init(obj_buffer, 128);
			/*
			if (sec<hsec){
				hsec = sec;
			}
			sec=-1;
			obj_test();
			*/
			level3();
		}

		if(pnpoly(warp1n,warp1p,p)){
			dx = 390-x;
			x += dx;
			x2 -= dx;
			// move up/down
			dy = 197-y;
			y += dy;
			y2 -= dy;
			obj_set_pos(metr, 120, 80);
		}
		if(pnpoly(warp2n,warp2p,p)){
			dx = 365-x;
			x += dx;
			x2 -= dx;
			// move up/down
			dy = 370-y;
			y += dy;
			y2 -= dy;
			obj_set_pos(metr, 120, 80);
		}
		if(pnpoly(warp3n,warp3p,p)){
			dx = 390-x;
			x += dx;
			x2 -= dx;
			// move up/down
			dy = 312-y;
			y += dy;
			y2 -= dy;
			obj_set_pos(metr, 120, 80);
		}
		if(pnpoly(warp4n,warp4p,p)){
			dx = 315-x;
			x += dx;
			x2 -= dx;
			// move up/down
			dy = 231-y;
			y += dy;
			y2 -= dy;
			obj_set_pos(metr, 120, 80);
		}
		if((pnpoly(n1,polygon1,p) && !pnpoly(n2,polygon2,p) && !pnpoly(n3,polygon3,p)) || (pnpoly(n4,polygon4,p) || pnpoly(n5,polygon5,p)) ){
			if (pnpoly(fence2_1n,fence2_1p,p) && !s2_1press){

			}
			else if (pnpoly(fence2_2n,fence2_2p,p) && !b1press){

			}
			else if (pnpoly(fence2_3n,fence2_3p,p) && !b3press){

			}
			else if (pnpoly(fence2_4n,fence2_4p,p) && !b2press){

			}
			else if (pnpoly(fence2_5n,fence2_5p,p) && !b4press){

			}
			else if (pnpoly(fence2_6n,fence2_6p,p) && !s5press){

			}
			else if (pnpoly(door1n,door1p,p) && !s2press){

			}
			else if (pnpoly(door2n,door2p,p) && !s3press){

			}
			else if (pnpoly(door3n,door3p,p) && !s4press){

			}

			else{
				dx = 2*key_tri_horz();
				x += dx;
				x2 -= dx;


				// move up/down
				dy = 2*key_tri_vert();
				y += dy;
				y2 -= dy;
				x2o=x2;
				y2o=y2;
				if(y<80 && x<120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, x, y);
					REG_BG1HOFS= 0;
					REG_BG1VOFS= 0;

					x2=0;
					y2=0;
					ox=0;
					oy=0;


				}
				else if(y>512-80 && x<120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, x, 160-(512-y));


					x2=0;
					y2=y2-(512-80-y);


				}
				else if(y>512-80 && x>512-120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 240-(512-x), 160-(512-y));


					x2=x2-(512-120-x);
					y2=y2-(512-80-y);


				}
				else if(x>512-120 && y<80){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 240-(512-x), y);
					x2=x2-(512-120-x);
					y2=0;
					oy=0;

				}
				else if(y<80){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 120, y);
					y2=0;
					REG_BG1HOFS= x-120;
					oy=0;
				}
				else if(y>512-80){
					obj_set_pos(metr, 120, 160-(512-y));
					REG_BG1HOFS= x-120;
					y2=y2-(512-80-y);

				}

				else if(x<120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, x, 80);
					REG_BG1VOFS= y-80;
					x2=0;
					ox=0;

				}
				else if(x>512-120){
					//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
					obj_set_pos(metr, 240-(512-x), 80);
					REG_BG1VOFS= y-80;
					x2=x2-(512-120-x);

				}
				else{
					REG_BG1HOFS= x-120;
					REG_BG1VOFS= y-80;
				}
				obj_set_pos(fence2_1, x2+f2_1x, y2+f2_1y);
				obj_set_pos(switch2_1, x2+s2_1x, y2+s2_1y);
				obj_set_pos(warp1, x2+w1x+ox, y2+w1y+oy);
				obj_set_pos(warp2, x2+w2x+ox, y2+w2y+oy);
				obj_set_pos(warp3, x2+w3x+ox, y2+w3y+oy);
				obj_set_pos(warp4, x2+w4x+ox, y2+w4y+oy);
				obj_set_pos(button1, x2+b1x+ox, y2+b1y+oy);
				obj_set_pos(fence2_2, x2+f2_2x+ox, y2+f2_2y+ox);
				obj_set_pos(door1L, x2+d1x+ox, y2+d1y+oy);
				obj_set_pos(door1R, x2+d1x+8+ox, y2+d1y+oy);
				obj_set_pos(switch2, x2+s2x+ox, y2+s2y+oy);
				obj_set_pos(door2L, x2+d2x+ox, y2+d2y+oy);
				obj_set_pos(door2R, x2+d2x+ox, y2+d2y+8+oy);
				obj_set_pos(switch3, x2+s3x+ox, y2+s3y+oy);
				obj_set_pos(door3L, x2+d3x+ox, y2+d3y+oy);
				obj_set_pos(door3R, x2+d3x+ox, y2+d3y+8+oy);
				obj_set_pos(switch4, x2+s4x+ox, y2+s4y+oy);
				obj_set_pos(fence2_3, x2+f2_3x+ox, y2+f2_3y+oy);
				obj_set_pos(fence2_4, x2+f2_4x+ox, y2+f2_4y+oy);
				obj_set_pos(button2, x2+b2x+ox, y2+b2y+oy);
				obj_set_pos(button3, x2+b3x+ox, y2+b3y+oy);
				obj_set_pos(button4, x2+b4x+ox, y2+b4y+oy);
				obj_set_pos(fence2_5, x2+f2_5x+ox, y2+f2_5y+oy);
				obj_set_pos(fence2_6, x2+f2_6x+ox, y2+f2_6y+oy);
				obj_set_pos(switch5, x2+s5x+ox, y2+s5y+oy);
				obj_set_pos(bossW, x2+bwx+ox, y2+bwy+oy);

				x2=x2o;
				y2=y2o;
				oy=70;
				ox=110;

			}
		}
		oam_copy(oam_mem, obj_buffer, 27);	// only need to update one
		obj_aff_copy(obj_aff_mem, obj_aff_buffer, 1);
		//gjemme ting fra å pakke rundt
		for (int i=1; i<27; i++){
			OBJ_ATTR *objj= &obj_buffer[i];
			//if(abs(y-(BFN_GET(objj->attr0,ATTR0_Y)-y2))>100){
			if(abs(y-spritey[i])>130 ){
				//affornot[i]=BFN_GET(objj->attr0,ATTR0_MODE);
				obj_hide(objj);

			}
			else{
				obj_unhide(objj,affornot[i]);
			}
		}

	}
}

int level3(){

Point polygon5[] =
	{
	{0,242},
	{75,71},
	{258,0},
	{435,71},
	{512,241},
	{414,469},
	{308,512},
	{76,410},
	{0,244}};
int n5 = sizeof(polygon5)/sizeof(polygon5[0]);



	// Overflow every ~1 second:
	// 0x4000 ticks @ FREQ_1024
	REG_TM2D= -0x4000;          // 0x4000 ticks till overflow
	REG_TM2CNT= TM_FREQ_1024;   // we're using the 1024 cycle timer
	// cascade into tm3
	REG_TM3CNT= TM_ENABLE | TM_CASCADE;
	//sec= -1;

	REG_TM2CNT ^= TM_ENABLE;

	int x= 120, y= 80;
	int ox=120-x, oy=80-y;
	//int x= 92, y= 410;
	int x2= 0, y2= 0;
	int x2o=0, y2o=0;
	int dx= 0, dy=0;
	//int x= 0, y= 0;
	u32 tid= 0, pb= 0;		// tile id, pal-bank

	int dgx=130, dgy=90;
	Point dgcol[]={{x2+dgx,y2+dgy},{x2+dgx+64,y2+dgy},{x2+dgx+64,y2+dgy+64},{x2+dgx,y2+dgy+64},{x2+dgx,y2+dgy}};
	int dgcoln = sizeof(dgcol)/sizeof(dgcol[0]);

	OBJ_ATTR *metr= &obj_buffer[0];
	obj_set_attr(metr,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_16,					// 16x16p,
		ATTR2_PALBANK(15) | tid);		// palbank 0, tile 0

	// position sprite (redundant here; the _real_ position
	// is set further down
	obj_set_pos(metr, x, y);

	OBJ_ATTR *dragon= &obj_buffer[1];
	obj_set_attr(dragon,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_64,					// 16x16p,
		ATTR2_PALBANK(7) | 29);		// palbank 0, tile 0
	affornot[1]=ATTR0_REG;
	spritex[1]=dgx;
	spritey[1]=dgy;
	// position sprite (redundant here; the _real_ position
	// is set further down
	obj_set_pos(dragon, dgx, dgy);

	while(1){
		vid_vsync();
		key_poll();



		if(REG_TM3D != sec)
						{
								sec= REG_TM3D;
								tte_printf("#{es;P:0,5}Time %02d:%02d  Best %02d:%02d",
										 (sec%3600)/60, sec%60,
									 (hsec%3600)/60, hsec%60);
									 //tte_printf("#{cx:0x1000}\n x: ,%d",x);      // Print "Hello world!"
									//tte_printf("#{cx:0x1000}\n y: ,%d",y);      // Print "Hello world!"
						}
		// move left/right
		Point p={x+2*key_tri_horz()+8,y+2*key_tri_vert()+8};

		if(pnpoly(dgcoln,dgcol,p)){
			REG_TM2CNT ^= TM_ENABLE;
			REG_TM3CNT ^= TM_ENABLE;
			tte_printf("#{cx:0x1000}\n Congratulations, \nyou completed 1c1!");
			tte_printf("#{cx:0x1000}\n Hit 'A' to try again");
			while(1){
				key_poll();
				if(key_hit(KEY_A)){
					break;
				}
			}
			if (sec<hsec){
				hsec = sec;
			}
			sec=-1;
			memcpy(&tile_mem[0][0], f1outTiles, f1outTilesLen);
			// Load map into SBB 28
			memcpy(&se_mem[20][0], f1outMap, f1outMapLen);
			memcpy(pal_obj_mem, sp2Pal, sp2PalLen);

			obj_test();
		}

	if(pnpoly(n5,polygon5,p)){
		if (0){

		}
		else{
			dx = 2*key_tri_horz();
			x += dx;
			x2 -= dx;


			// move up/down
			dy = 2*key_tri_vert();
			y += dy;
			y2 -= dy;
			x2o=x2;
			y2o=y2;
			if(y<80 && x<120){
				//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
				obj_set_pos(metr, x, y);
				REG_BG1HOFS= 0;
				REG_BG1VOFS= 0;

				x2=0;
				y2=0;
				ox=0;
				oy=0;


			}
			else if(y>512-80 && x<120){
				//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
				obj_set_pos(metr, x, 160-(512-y));


				x2=0;
				y2=y2-(512-80-y);


			}
			else if(y>512-80 && x>512-120){
				//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
				obj_set_pos(metr, 240-(512-x), 160-(512-y));


				x2=x2-(512-120-x);
				y2=y2-(512-80-y);


			}
			else if(x>512-120 && y<80){
				//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
				obj_set_pos(metr, 240-(512-x), y);
				x2=x2-(512-120-x);
				y2=0;
				oy=0;

			}
			else if(y<80){
				//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
				obj_set_pos(metr, 120, y);
				y2=0;
				REG_BG1HOFS= x-120;
				oy=0;
			}
			else if(y>512-80){
				obj_set_pos(metr, 120, 160-(512-y));
				REG_BG1HOFS= x-120;
				y2=y2-(512-80-y);

			}

			else if(x<120){
				//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
				obj_set_pos(metr, x, 80);
				REG_BG1VOFS= y-80;
				x2=0;
				ox=0;

			}
			else if(x>512-120){
				//obj_set_pos(metr, x, BFN_GET(metr->attr0,ATTR0_Y)+2*key_tri_vert());
				obj_set_pos(metr, 240-(512-x), 80);
				REG_BG1VOFS= y-80;
				x2=x2-(512-120-x);

			}
			else{
				REG_BG1HOFS= x-120;
				REG_BG1VOFS= y-80;
			}

			//obj_set_pos(bossW, x2+bwx+ox, y2+bwy+oy);
			obj_set_pos(dragon, x2+dgx, y2+dgy);

			x2=x2o;
			y2=y2o;
			//oy=70;
			//ox=110;

		}
	}
	oam_copy(oam_mem, obj_buffer, 2);	// only need to update one
	obj_aff_copy(obj_aff_mem, obj_aff_buffer, 1);
	//gjemme ting fra å pakke rundt
	for (int i=1; i<2; i++){
		OBJ_ATTR *objj= &obj_buffer[i];
		//if(abs(y-(BFN_GET(objj->attr0,ATTR0_Y)-y2))>100){
		if(abs(y-spritey[i])>130 ){
			//affornot[i]=BFN_GET(objj->attr0,ATTR0_MODE);
			obj_hide(objj);

		}
		else{
			obj_unhide(objj,affornot[i]);
		}
	}
}
}

int main()
{
	// Load palette
	memcpy(pal_bg_mem, f1outPal, f2outPalLen);
	// Load tiles into CBB 0
	memcpy(&tile_mem[0][0], f1outTiles, f1outTilesLen);
	// Load map into SBB 28
	memcpy(&se_mem[20][0], f1outMap, f1outMapLen);

	//memcpy(&tile_mem[2][0], f2outTiles, f2outTilesLen);
	// Load map into SBB 28
	//memcpy(&se_mem[20][0], f2outMap, f2outMapLen);

	// set up BG0 for a 4bpp 64x32t map, using
	//   using charblock 0 and screenblock 31
	//REG_BG0CNT= BG_CBB(0) | BG_SBB(28) | BG_4BPP | BG_REG_64x64;
	REG_BG1CNT= BG_CBB(0) | BG_SBB(20) | BG_4BPP | BG_REG_64x64;
	//REG_BG1CNT= BG_CBB(2) | BG_SBB(20) | BG_4BPP | BG_REG_64x64;
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_OBJ | DCNT_OBJ_1D;

	// Init BG 0 for text on screen entries.
	tte_init_se_default(0, BG_CBB(3)|BG_SBB(10));
	// Enable TTE's console functionality
  tte_init_con();

  tte_printf("#{P:72,64}");        // Goto (72, 64).
  tte_printf("#{cx:0x1000}Hello World! ,%d",10);      // Print "Hello world!"
	tte_printf("#{el}");
	tte_printf("#{X:72}");
	tte_printf("#{cx:0x1000}Hello World! ,%d",9);      // Print "Hello world!"
	//prøver blending:
	//REG_BLDCNT= BLD_STD;
	//REG_BLDCNT= BLD_BUILD(
	//	BLD_OBJ | BLD_BG0, // Top layers
	//	BLD_BG1,		// Bottom layers
	//mode);// Mode





	// Places the glyphs of a 4bpp boxed metroid sprite
	//   into LOW obj memory (cbb == 4)
	memcpy(&tile_mem[4][0], spTiles, spTilesLen);
	//memcpy(pal_obj_mem, spPal, spPalLen);
	memcpy(&tile_mem[4][4], sp2Tiles, sp2TilesLen);
	memcpy(&tile_mem[4][13], bossWTiles, bossWTilesLen);
	memcpy(&tile_mem[4][29], dragonTiles, dragonTilesLen);
	memcpy(pal_obj_mem, sp2Pal, sp2PalLen);

	oam_init(obj_buffer, 128);

	//REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D;

	obj_test();

	// Scroll around some
	int x= 192, y= 64;
	//int x= 0, y= 0;
	while(1)
	{
		vid_vsync();
		key_poll();

		x += key_tri_horz();
		y += key_tri_vert();

		REG_BG0HOFS= x;
		REG_BG0VOFS= y;
	}

	return 0;
}
