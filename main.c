#include <stdio.h>
#include <stdlib.h>
#include "ConvDataStructure.h"

int main(int argc, char *argv[])
{
	char InputImgName[350];
	char OutputImgName[350];
	
	Conv_DataStructure *Conv_DS = (Conv_DataStructure*)malloc(sizeof(Conv_DataStructure));
	Conv_DS->BMPHeaderDataPtr = (BMPHeaderData*)malloc(sizeof(BMPHeaderData));
	Conv_DS->ColorMap = (RGBQUAD*)malloc(sizeof(RGBQUAD)*256);
	Conv_DS->MaskStructure_ptr = (MaskStructure*)malloc(sizeof(MaskStructure));
	
	ReadIOPCoefficient("InputCoefficient.txt", InputImgName, OutputImgName, Conv_DS->BMPHeaderDataPtr, Conv_DS->MaskStructure_ptr);
	printf("Input Img : %s\n", InputImgName);
	printf("Output Img : %s\n", OutputImgName);
	printf("ImgWidth * ImgHeight : %d * %d\n", Conv_DS->BMPHeaderDataPtr->biWidth_integer, Conv_DS->BMPHeaderDataPtr->biHeight_integer);
	printf("MaskWidth * MaskHeight : %d * %d\n", Conv_DS->MaskStructure_ptr->MaskWidth, Conv_DS->MaskStructure_ptr->MaskHeight);
	printf("%f , %f , %f\n", Conv_DS->MaskStructure_ptr->MaskCoefficient[0], Conv_DS->MaskStructure_ptr->MaskCoefficient[1], Conv_DS->MaskStructure_ptr->MaskCoefficient[2]);
	printf("%f , %f , %f\n", Conv_DS->MaskStructure_ptr->MaskCoefficient[3], Conv_DS->MaskStructure_ptr->MaskCoefficient[4], Conv_DS->MaskStructure_ptr->MaskCoefficient[5]);
	printf("%f , %f , %f\n", Conv_DS->MaskStructure_ptr->MaskCoefficient[6], Conv_DS->MaskStructure_ptr->MaskCoefficient[7], Conv_DS->MaskStructure_ptr->MaskCoefficient[8]);
	printf("Read Input Coefficient Text ...OK\n\n");
	
	int ImgWidth = Conv_DS->BMPHeaderDataPtr->biWidth_integer;
	int ImgHeight = Conv_DS->BMPHeaderDataPtr->biHeight_integer;
	Conv_DS->BMPHeaderDataPtr->bPixel = (unsigned char*)malloc(sizeof(unsigned char)*ImgWidth*ImgHeight);
	Conv_DS->BMPHeaderDataPtr->bPixel_OP = (unsigned char*)malloc(sizeof(unsigned char)*ImgWidth*ImgHeight);
	
	ReadBMPCipher(InputImgName, Conv_DS->BMPHeaderDataPtr, Conv_DS->BMPHeaderDataPtr, Conv_DS->ColorMap, ImgWidth, ImgHeight, Conv_DS->BMPHeaderDataPtr->bPixel);
	printf("Read Input BMP Image Cipher ...OK\n");
	
	WriteIPImgTxt("InputBMPCipher.txt", Conv_DS->BMPHeaderDataPtr, Conv_DS->ColorMap);
	printf("Write Input BMP Image Cipher Text ...OK\n");
	
	ImgConvolution(Conv_DS->BMPHeaderDataPtr->bPixel, Conv_DS->BMPHeaderDataPtr->bPixel_OP, ImgWidth, ImgHeight, 
				   Conv_DS->MaskStructure_ptr->MaskCoefficient, Conv_DS->MaskStructure_ptr->MaskWidth, Conv_DS->MaskStructure_ptr->MaskHeight);
	printf("Img Convolution ...OK\n");
	
	WriteOutputBMP(OutputImgName, Conv_DS->BMPHeaderDataPtr, Conv_DS->BMPHeaderDataPtr, Conv_DS->ColorMap, Conv_DS->BMPHeaderDataPtr->bPixel_OP, ImgWidth, ImgHeight);
	printf("Write Output BMP Image...OK\n");
	
	free(Conv_DS->BMPHeaderDataPtr->bPixel_OP);
	free(Conv_DS->BMPHeaderDataPtr->bPixel);
	free(Conv_DS->MaskStructure_ptr);
	free(Conv_DS->ColorMap);
	free(Conv_DS->BMPHeaderDataPtr);
	free(Conv_DS);
	
	system("pause");
	return 0;
}
