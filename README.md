# ImageConvolution_BMP

以上一個程式"8bitsBMP_CipherToPlainText"為基礎，再進一步加入影像卷積的函式功能
讀取ReadInputCoefficient.c內的參數，對特定的影像進行所需的影像遮罩處理


※這支程式沒有對BMP影像的輸出入進行補0或除0的處理，所以輸入進去的BMP影像之解析度須為4的倍數

- 《Sobel_X》
```
-1,0,1
-2,0,2
-1,0,1
```

- 《Sobel_Y》
```
-1,-2,-1
0,0,0
1,2,1
```

- 《Laplacian》
```
0,-1,0
-1,4,-1
0,-1,0
```

- 《Laplacian Enhancement(Sharpen)》
```
0,-1,0
-1,5,-1
0,-1,0
```

- 《3*3 Gaussian_Smoothing》
```
	┌1,2,1┐
1/16 *	│2,4,2│
	└1,2,1┘

0.0625,0.125,0.0625
0.125,0.25,0.125
0.0625,0.125,0.0625
```
