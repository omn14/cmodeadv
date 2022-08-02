
//{{BLOCK(f2out)

//======================================================================
//
//	f2out, 512x512@4, 
//	+ palette 256 entries, not compressed
//	+ 512 tiles (t|f reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 512 + 16384 + 8192 = 25088
//
//	Time-stamp: 2022-08-02, 21:09:08
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.16
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_F2OUT_H
#define GRIT_F2OUT_H

#define f2outTilesLen 16384
extern const unsigned int f2outTiles[4096];

#define f2outMapLen 8192
extern const unsigned short f2outMap[4096];

#define f2outPalLen 512
extern const unsigned short f2outPal[256];

#endif // GRIT_F2OUT_H

//}}BLOCK(f2out)
