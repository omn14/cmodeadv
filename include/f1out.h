
//{{BLOCK(f1out)

//======================================================================
//
//	f1out, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 538 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 17216 + 8192 = 25920
//
//	Time-stamp: 2022-07-11, 11:06:44
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_F1OUT_H
#define GRIT_F1OUT_H

#define f1outTilesLen 17216
extern const unsigned int f1outTiles[4304];

#define f1outMapLen 8192
extern const unsigned short f1outMap[4096];

#define f1outPalLen 512
extern const unsigned short f1outPal[256];

#endif // GRIT_F1OUT_H

//}}BLOCK(f1out)
