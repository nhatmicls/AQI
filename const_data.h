/*******************************
 *          __                   
 *         /\ \                  
 *  __  _  \_\ \     __    ___   
 * /\ \/'\ /'_' \  /'__'\ /'___\ 
 * \/>  <//\ \ \ \/\  __//\ \__/ 
 *  /\_/\_\ \___,_\ \____\ \____\
 *  \//\/_/\/__,_ /\/____/\/____/
 * 
 *  Author: declis (xdec.de)
 ********************************/ 

#ifndef CONST_DATA_H_
#define CONST_DATA_H_

#define C_LEN		30

const schar obj_3d[][3]={
-C_LEN,-C_LEN,-C_LEN,			// Cube 00
+C_LEN,-C_LEN,-C_LEN,			// Cube 01
+C_LEN,-C_LEN,+C_LEN,			// Cube 02
-C_LEN,-C_LEN,+C_LEN,			// Cube 03
-C_LEN,+C_LEN,-C_LEN,			// Cube 04
+C_LEN,+C_LEN,-C_LEN,			// Cube 05
+C_LEN,+C_LEN,+C_LEN,			// Cube 06
-C_LEN,+C_LEN,+C_LEN,			// Cube 07
-C_LEN+25,-C_LEN+15,-C_LEN,		// X 08
-C_LEN+40,-C_LEN+40,-C_LEN,		// X 09
-C_LEN+25,-C_LEN+40,-C_LEN,		// X 10
-C_LEN+40,-C_LEN+15,-C_LEN,		// X 11
-C_LEN+25,-C_LEN+15,-C_LEN,		// D 12
-C_LEN+25,-C_LEN+40,-C_LEN,		// D 13
-C_LEN+40,-C_LEN+27,-C_LEN,		// D 14
-C_LEN+25,-C_LEN+15,-C_LEN,		// E 15
-C_LEN+25,-C_LEN+40,-C_LEN,		// E 16
-C_LEN+40,-C_LEN+15,-C_LEN,		// E 17
-C_LEN+40,-C_LEN+27,-C_LEN,		// E 18
-C_LEN+40,-C_LEN+40,-C_LEN,		// E 19
-C_LEN+25,-C_LEN+27,-C_LEN,		// E 20
-C_LEN+25,-C_LEN+15,-C_LEN,		// C 21
-C_LEN+25,-C_LEN+40,-C_LEN,		// C 22
-C_LEN+40,-C_LEN+15,-C_LEN,		// C 23
-C_LEN+40,-C_LEN+40,-C_LEN		// C 24
};	

const uchar obj_edges[][2]={
0,1,	// Cube 00
1,2,	// Cube 01
2,3,	// Cube 02
3,0,	// Cube 03
4,5,	// Cube 04
5,6,	// Cube 05
6,7,	// Cube 06
7,4,	// Cube 07
0,4,	// Cube 08
1,5,	// Cube 09
2,6,	// Cube 10
3,7,	// Cube 11
8,9,	// X	12
10,11,	// X	13
12,13,	// D	14
12,14,	// D	15
13,14,	// D	16
15,16,	// E	17
15,17,	// E	18
20,18,	// E	19
16,19,	// E	20
21,22,	// C	21
21,23,	// C	22
22,24	// C	23
};

// offset in dots array
const uchar letter_dots_pos[][2]={
8,11,
12,14,
15,20,
21,24
};

// offset in edges array
const uchar letter_edges_pos[][2]={
12,13,
14,16,
17,20,
21,23
};

const uchar scroller_00[]={"You're watching a new **xdec** production! MSP430G2553 and ILI9341 TFT-Display! pwn t3h code"};
const uchar scroller_01[][11]={"* declis *","*presents*"};
const uchar scroller_02[]={"**** JJAM.de - Java & JS ** || ** HUGO ELIAS - Computer Graphics ****"};
const uchar string_00[]={"Time: "};
const uchar string_01[]={"PM2.5: "};
const uchar string_02[]={"Air: "};
const uchar string_03[]={"Warning!"};
const uchar string_04[]={"smile again! (:"};
const uchar string_05[][40]={"MSP430G2553 (16k Flash/512B RAM/16MHz)",
							 " ILI9341 TFT-Display (16bit,240x320) ",
							 "      CODE: declis (www.xdec.de)     "};
const uchar string_06[]={"THE END"};


const uint color_pal[]={0xFFE0,0xF800,0xFFFF,0x07E0,0xF81F,0x001F};

// 60x60
const uchar pd2[]= {
0xFF,0xFF,0xFF,0xFF,0xFF,0xEF,0xFE,0xFF,0xEF,0xFE,0xFF,0xFF,0xE7,0xE7,0xFF,0xFF,0xFF,0xF7,0x77,0xFF,0xFE,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1F,0x1F,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF9,0xFF,0xFF,0xFF,0x7C,0x7F,0xFF,0xFF,0xFF,0x7C,0x3C,0x7F,0x7F,0xFF,0xC0,0x00,0x00,0x00,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0xC0,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xC0,0x00,0x00,0x00,0x00,0xC0,0xF8,0xC0,0x3C,0x7C,0x3C,0x3E,0x3E,0x3F,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0x8F,0x3F,0xFF,0xCF,0xDF,0xFF,0xEF,0xCF,0x8F,0x0E,0x0F,0x7F,0xEF,0x8F,0x8D,0x06,0x00,0x00,0x00,0x00,0x01,0x01,0x07,0x07,0x07,0xEF,0xC7,0x87,0x83,0x81,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xC0,0xC1,0xF3,0xC0,0xC0,0xE0,0xE0,0xF0,0xFC,0xF0,0xF8,0xFC,0xFC,0xF0,0x70,0xF8,0xFC,0x3F,0xFF,0xFF,
0xFF,0xFF,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x3F,0x3F,0x3F,0x1F,0x1F,0x1F,0x3F,0x3F,0x3F,0x3F,0x3F,0x1E,0x1E,0x9E,0xDF,0xFF,0xFF,0x3F,0x09,0x09,0x00,0x01,0x01,0x0D,0x1F,0x3F,0x3F,0x6F,0x0F,0x07,0x07,0x0F,0x8F,0x87,0x87,0xC7,0xC7,0xDB,0xD3,0xC3,0xC3,0xC3,0xC1,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xF7,
0xFF,0xFF,0xFF,0xFC,0xFC,0xFC,0xFC,0xFE,0xFE,0xFE,0xFE,0xFF,0xDF,0xCF,0x8F,0x8F,0x07,0x07,0x07,0x0F,0x0E,0x3F,0x7F,0x7F,0xFF,0xFE,0xF8,0xF8,0xF8,0xF8,0xF8,0xF8,0xF0,0xF8,0xF8,0x7C,0x7E,0x3F,0x3E,0x1F,0x07,0x01,0x01,0x81,0xC0,0xC0,0xE0,0xF0,0xF0,0xF8,0x7C,0x7C,0x3E,0x0E,0xDE,0xFE,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3E,0x7E,0xFE,0xFC,0xFC,0xFC,0xF8,0xF8,0xF8,0xF8,0xF8,0xFF,0xFF,0xFB,0xFB,0x7B,0xF8,0xB8,0xFC,0xDC,0xFC,0xFE,0xFE,0x7F,0x3F,0x1F,0x1F,0x07,0x07,0x03,0x01,0x80,0x80,0xC0,0xE0,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0xE0,0xC1,0x81,0x01,0x01,0x03,0x03,0x03,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF8,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFC,0xFE,0xFE,0xFE,0xFE,0xFC,0xFC,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};


#endif /*CONST_DATA_H_*/
