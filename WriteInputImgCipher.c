#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ConvDataStructure.h"

void WriteIPImgTxt(char *InputImgTextfilename, BMPHeaderData *AllCipher_ptr, RGBQUAD *AllCM_ptr)
{
	FILE *fin;
	fin = fopen(InputImgTextfilename, "w+");
	while(fin == NULL)
	{
		printf("%s is no exist.\n", InputImgTextfilename);
		printf("Input file name:\n");
		scanf("%s\n", &InputImgTextfilename);
		fin = fopen(InputImgTextfilename, "w+");
	}
	
	int i, j;
	
	//----------File Header--------------//
	fprintf(fin, "--File Header--\n");
	fprintf(fin, "//bfType:");
	for(i = 0; i < 2; i++)
		fprintf(fin, "%c  ", AllCipher_ptr->bfType[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//bfSize:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->bfSize[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//bfReserved1:");
	for(i = 0; i < 2; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->bfReserved1[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//bfReserved2:");
	for(i = 0; i < 2; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->bfReserved2[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//bfOffBits:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->bfOffBits[i]);
	fprintf(fin, "\n\n");
	
	//----------Info Header--------------//
	fprintf(fin, "--Info Header--\n");
	fprintf(fin, "//biSize:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biSize[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biWidth:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biWidth[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biHeight:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biHeight[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biPlanes:");
	for(i = 0; i < 2; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biPlanes[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biBitCount:");
	for(i = 0; i < 2; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biBitCount[i]);
	fprintf(fin, "\n\n");
	fprintf(fin, "//biCompression:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biCompression[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biSizeImage:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biSizeImage[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biXPelsPerMeter:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biXPelsPerMeter[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biYPelsPerMeter:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biYPelsPerMeter[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biClrUsed:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biClrUsed[i]);
	fprintf(fin, "\n");
	fprintf(fin, "//biClrImportant:");
	for(i = 0; i < 4; i++)
		fprintf(fin, "%02x  ", AllCipher_ptr->biClrImportant[i]);
	fprintf(fin, "\n\n");
	
	//----------Color Map--------------//
	fprintf(fin, "--Color Map--\n");
	for(i = 0; i < 256; i++)
		fprintf(fin, "(%d,%d,%d,%d)	 ", AllCM_ptr[i].rgbRed, AllCM_ptr[i].rgbGreen, AllCM_ptr[i].rgbBlue, AllCM_ptr[i].reserved);
	fprintf(fin, "\n\n");
	
	//----------Bitmap Data Block--------------//
	fprintf(fin, "--Bitmap Data Block--\n");
	for(j = 0; j < AllCipher_ptr->biHeight_integer; j++)
	{
		for(i = 0; i < AllCipher_ptr->biWidth_integer; i++)
		{
			if(i == (AllCipher_ptr->biWidth_integer-1))
				fprintf(fin, "\n");
			else
				fprintf(fin, "%d	", AllCipher_ptr->bPixel[i+j*(AllCipher_ptr->biWidth_integer)]);
		}
	}
	
	fprintf(fin, "\n\n");
	
	fclose(fin);
}
