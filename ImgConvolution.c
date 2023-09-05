#include <stdio.h>
#include <stdlib.h>
#include "ConvDataStructure.h"

void ImgConvolution(unsigned char *IPImg_bPixel, unsigned char *OPImg_bPixel, int Imgwidth, int Imgheight, float *MaskCoe, int Mask_W, int Mask_H)
{
	Conv_Shrink(IPImg_bPixel, OPImg_bPixel, Imgwidth, Imgheight, MaskCoe, Mask_W, Mask_H);
}

void Conv_Shrink(unsigned char *IPImg_bPixel, unsigned char *OPImg_bPixel, int Imgwidth, int Imgheight, float *MaskCoe, int Mask_W, int Mask_H)
{
	int w, h, x, y;
	int *ImgProcessTemp = (int*)malloc(sizeof(int)*Imgwidth*Imgheight); 
	
	for(h = 0; h < Imgheight; h++)
		for(w = 0; w < Imgwidth; w++)
			ImgProcessTemp[w + h*Imgwidth]=0; 
	
	int OPImg_PixelStart_x = (Mask_W-1)/2;
	int OPImg_PixelStart_y = (Mask_H-1)/2;
	int C_cal;
		
	for(h = OPImg_PixelStart_y; h < (Imgheight - OPImg_PixelStart_y); h++)
	{
		for(w = OPImg_PixelStart_x; w < (Imgwidth - OPImg_PixelStart_x); w++)
		{
			C_cal = 0;
			
			for(y = 0; y < Mask_H; y++)
				for(x = 0; x < Mask_W; x++)
					C_cal = C_cal + IPImg_bPixel[(w - OPImg_PixelStart_x + x) + (h - OPImg_PixelStart_y + y)*Imgwidth]*MaskCoe[x + (Mask_H - y - 1)*Mask_W]; 

			
			if(C_cal < 0)
				C_cal = -C_cal;
			else if(C_cal > 255)
				C_cal = 255;
			
			ImgProcessTemp[w + h*Imgwidth] = C_cal;
		}
	}
	
	for(h = 0; h<Imgheight; h++)
		for(w = 0; w<Imgwidth; w++)
			OPImg_bPixel[w + h*Imgwidth] = ImgProcessTemp[w + h*Imgwidth];
	
	free(ImgProcessTemp);
}
