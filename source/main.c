//
// main.c
// cmodeadv - pso ep1 challange mode route test
//
//

#include <string.h>
#include <tonc.h>

#include "f1out.h"
#include "sp.h"
#include "sp2.h"
#include "polygon.h"


OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

u16 affornot[128];

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

	// oaff_curr = oaff_base * oaff_new
	// oaff_base changes when the aff-state changes
	// oaff_new is updated when it doesn't
	obj_aff_identity(oaff_curr);
	obj_aff_identity(oaff_base);
	obj_aff_identity(oaff_new);
	obj_aff_identity(oaff_newf6);

	int x= 120, y= 80;
	int x2= 0, y2= 0;
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

	OBJ_ATTR *fence= &obj_buffer[1];
	obj_set_attr(fence,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence, x2+f1x, y2+f1y);

	OBJ_ATTR *button1= &obj_buffer[2];
	obj_set_attr(button1,
		ATTR0_SQUARE,				// Square, regular sprite
		ATTR1_SIZE_8,					// 16x8p,
		ATTR2_PALBANK(0) | 5);		// palbank 0, tile 0

	obj_set_pos(button1, x2+b1x, y2+b1y);

	OBJ_ATTR *warp1= &obj_buffer[3];
	obj_set_attr(warp1,
		ATTR0_SQUARE | ATTR0_4BPP,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 10);		// palbank 0, tile 0

	obj_set_pos(warp1, x2+w1x, y2+w1y);


	OBJ_ATTR *fence2= &obj_buffer[4];
	obj_set_attr(fence2,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(0),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0


	obj_set_pos(fence2, x2+f2x, y2+f2y);
	obj_aff_identity(&obj_aff_buffer[0]);
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

	OBJ_ATTR *fence3= &obj_buffer[6];
	obj_set_attr(fence3,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(0),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence3, x2+f2x+8, y2+f2y);
	OBJ_ATTR *fence4= &obj_buffer[7];
	obj_set_attr(fence4,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(0),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence4, x2+f2x+8+8, y2+f2y);
	u16 alpha = 16364;
	obj_aff_rotate(oaff_new, alpha);
	//obj_aff_rotscale(oaff_new, (1<<8)-88, (1<<8)-88,alpha);
	obj_aff_copy(oaff_curr, oaff_base, 1);
	obj_aff_postmul(oaff_curr, oaff_new);

	OBJ_ATTR *fence5= &obj_buffer[8];
	obj_set_attr(fence5,
		ATTR0_SQUARE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_8 | ATTR1_AFF_ID(1),					// 16x8p,
		ATTR2_PALBANK(0) | 4);		// palbank 0, tile 0

	obj_set_pos(fence5, x2+f2x+8+8, y2+f2y);

	obj_aff_identity(&obj_aff_buffer[1]);
	alpha = 8000;
	obj_aff_rotate(oaff_new, alpha);
	//obj_aff_scale(oaff_new, (1<<8), (1<<8)-64);
	//obj_aff_copy(oaff_curr, oaff_base, 1);
	obj_aff_postmul(oaff_base, oaff_new);
	//fence5->attr0 ^= ATTR0_AFF_DBL_BIT;

	OBJ_ATTR *fence6= &obj_buffer[9];
	obj_set_attr(fence6,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_16x8 | ATTR1_AFF_ID(3),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	fence6->attr0 ^= ATTR0_AFF_DBL_BIT;
	obj_set_pos(fence6, x2+f2x+8+8, y2+f2y);
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

	OBJ_ATTR *fence7= &obj_buffer[11];
	obj_set_attr(fence7,
		ATTR0_WIDE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_32x8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	
	OBJ_ATTR *fence8= &obj_buffer[12];
	obj_set_attr(fence8,
		ATTR0_WIDE | ATTR0_4BPP | ATTR0_AFF,				// Square, regular sprite
		ATTR1_SIZE_32x8 | ATTR1_AFF_ID(4),					// 16x8p,
		ATTR2_PALBANK(0) | 6);		// palbank 0, tile 0
	fence8->attr0 ^= ATTR0_AFF_DBL_BIT;
	alpha = 8000;
	obj_aff_identity(&obj_aff_buffer[4]);
	obj_aff_rotate(oaff_new, alpha);
	obj_aff_postmul(oaff_newf8, oaff_new);
	
	OBJ_ATTR *switch1= &obj_buffer[13];
	obj_set_attr(switch1,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 11);		// palbank 0, tile 0
	
	OBJ_ATTR *door1L= &obj_buffer[14];
	obj_set_attr(door1L,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0
	
	OBJ_ATTR *door1R= &obj_buffer[15];
	obj_set_attr(door1R,
		ATTR0_SQUARE | ATTR0_4BPP ,				// Square, regular sprite
		ATTR1_SIZE_8 ,					// 16x8p,
		ATTR2_PALBANK(0) | 12);		// palbank 0, tile 0

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
		
		//gjemme ting fra å pakke rundt
		for (int i=1; i<15; i++){
			OBJ_ATTR *objj= &obj_buffer[i];
			if(y-BFN_GET2(objj->attr0,ATTR0_Y)>40){
				affornot[i]=BFN_GET(objj->attr0,ATTR0_MODE);
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
		}
		
		if(pnpoly(s1coln,s1col,p) && !s1press){
			if(key_hit(KEY_A)){
				s1press=1;
				d1x -= 8;
				switch1->attr2= ATTR2_BUILD(11, 1, 0);
			}
		}
		if(pnpoly(n1,polygon1,p) && !pnpoly(n2,polygon2,p)){
			if (pnpoly(fence1n,fence1,p) && !b1press){

			}
			else if(pnpoly(fence2n,fence2p,p) && !b2press){

			}
			else
				{
				dx = 2*key_tri_horz();
				x += dx;
				x2 -= dx;


				// move up/down
				dy = 2*key_tri_vert();
				y += dy;
				y2 -= dy;

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
		if(key_hit(KEY_START))
			REG_DISPCNT ^= DCNT_OBJ_1D;

		// Hey look, it's one of them build macros!
		metr->attr2= ATTR2_BUILD(tid, pb, 0);

		REG_BG0HOFS= x-120;
		REG_BG0VOFS= y-80;
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
		oam_copy(oam_mem, obj_buffer, 16);	// only need to update one
		obj_aff_copy(obj_aff_mem, obj_aff_buffer, 5);

	}

}
int main()
{
	// Load palette
	memcpy(pal_bg_mem, f1outPal, f1outPalLen);
	// Load tiles into CBB 0
	memcpy(&tile_mem[0][0], f1outTiles, f1outTilesLen);
	// Load map into SBB 30
	memcpy(&se_mem[28][0], f1outMap, f1outMapLen);

	// set up BG0 for a 4bpp 64x32t map, using
	//   using charblock 0 and screenblock 31
	REG_BG0CNT= BG_CBB(0) | BG_SBB(28) | BG_4BPP | BG_REG_64x64;
	REG_DISPCNT= DCNT_MODE0 | DCNT_BG0 | DCNT_OBJ | DCNT_OBJ_1D;

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
