
//{{BLOCK(f3out)

//======================================================================
//
//	f3out, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 113 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 3616 + 8192 = 12320
//
//	Time-stamp: 2022-08-09, 14:37:18
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_F3OUT_H
#define GRIT_F3OUT_H

#define f3outTilesLen 3616
extern const unsigned int f3outTiles[904];

#define f3outMapLen 8192
extern const unsigned short f3outMap[4096];

#define f3outPalLen 512
extern const unsigned short f3outPal[256];

#endif // GRIT_F3OUT_H

//}}BLOCK(f3out)
