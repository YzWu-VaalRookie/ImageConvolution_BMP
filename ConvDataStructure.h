typedef struct
{
	//BMP_FILE HEADER
	unsigned char	bfType[2];
	unsigned char	bfSize[4];
	unsigned char	bfReserved1[2];
	unsigned char	bfReserved2[2];
	unsigned char	bfOffBits[4];
	//BMP_INFO HEADER (array)
	unsigned char	biSize[4];
	unsigned char	biWidth[4];
	unsigned char	biHeight[4];
	unsigned char	biPlanes[2];
	unsigned char	biBitCount[2];
	unsigned char	biCompression[4];
	unsigned char	biSizeImage[4];
	unsigned char	biXPelsPerMeter[4];
	unsigned char	biYPelsPerMeter[4];
	unsigned char	biClrUsed[4];
	unsigned char	biClrImportant[4];
	//BMP_INFO HEADER (int)
	int	biWidth_integer;
	int biHeight_integer;
	//BMP_Bitmap Data
	unsigned char *bPixel;
	//Output Image's bpixel
	unsigned char *bPixel_OP;
	
}BMPHeaderData;

typedef struct
{
	int rgbBlue;
	int rgbGreen;
	int rgbRed;
	int reserved;
}RGBQUAD; //BMP_Colormap

typedef struct
{
	int MaskWidth;
	int MaskHeight;
	float *MaskCoefficient;
}MaskStructure;

typedef struct
{
	BMPHeaderData *BMPHeaderDataPtr;
	RGBQUAD *ColorMap;
	MaskStructure *MaskStructure_ptr; 
}Conv_DataStructure;

void ReadIOPCoefficient(char *IPtxtfilename, char IPbmpfilename[], char OPbmpfilename[], BMPHeaderData *BMP8b_HDptr, MaskStructure *MaskData);
void ReadBMPCipher(char *IPbmpfilename, BMPHeaderData *FH_ptr, BMPHeaderData *IH_ptr, RGBQUAD *CM_ptr, int Imgwidth, int Imgheight, unsigned char *bpixel);
void ReadBMPCipher_FH(char *IPbmpfilename, BMPHeaderData *FH_ptr);
void ReadBMPCipher_IH(char *IPbmpfilename, BMPHeaderData *IH_ptr, int Imgwidth, int Imgheight);
void ReadBMPCipher_CM(char *IPbmpfilename, RGBQUAD *CM_ptr);
void ReadBMPCipher_DB(char *IPbmpfilename, int Imgwidth, int Imgheight, unsigned char *bpixel);
void WriteIPImgTxt(char *InputImgTextfilename, BMPHeaderData *AllCipher_ptr, RGBQUAD *AllCM_ptr);
void ImgConvolution(unsigned char *IPImg_bPixel, unsigned char *OPImg_bPixel, int Imgwidth, int Imgheight, float *MaskCoe, int Mask_W, int Mask_H);
void Conv_Shrink(unsigned char *IPImg_bPixel, unsigned char *OPImg_bPixel, int Imgwidth, int Imgheight, float *MaskCoe, int Mask_W, int Mask_H);
void WriteOutputBMP(char *OPbmpfilename, BMPHeaderData *fh_ptr, BMPHeaderData *ih_ptr, RGBQUAD *cm_ptr, unsigned char *OPpixel, int Imgwidth, int Imgheight);
