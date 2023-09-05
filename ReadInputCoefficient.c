#include <stdio.h>
#include <stdlib.h>
#include "ConvDataStructure.h"

void ReadIOPCoefficient(char *IPtxtfilename, char IPbmpfilename[], char OPbmpfilename[], BMPHeaderData *BMP8b_HDptr, MaskStructure *MaskData)
{
	FILE *fin;
	fin = fopen(IPtxtfilename, "r+");
	while(fin == NULL)
	{
		printf("%s is no exist.\n", IPtxtfilename);
		printf("Input IOPtxt file name:\n");
		scanf("%s\n", &IPtxtfilename);
		fin = fopen(IPtxtfilename, "r+");
	}
	
	char buffer[350];
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%s\n", IPbmpfilename); //BMP Input filename
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%s\n", OPbmpfilename); //BMP Input filename
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%d\n", &BMP8b_HDptr->biWidth_integer); //BMP Image Width
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%d\n", &BMP8b_HDptr->biHeight_integer); //BMP Image Height
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%d\n", &MaskData->MaskWidth); //Mask Width
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%d\n", &MaskData->MaskHeight); //Mask Height
	
	MaskData->MaskCoefficient = (float*)malloc(sizeof(float)*(MaskData->MaskWidth)*(MaskData->MaskHeight));
	
	float *MaskCoe = (float*) MaskData->MaskCoefficient;
	int i, k=0;
	
	fgets(buffer, 350, fin);
	for(i = 1; i <= MaskData->MaskHeight; i++)
	{
		fscanf(fin, "%f,%f,%f\n", &MaskCoe[k], &MaskCoe[k+1], &MaskCoe[k+2]);
		k = k + (MaskData->MaskWidth);
	}
	
	fclose(fin);
}
