//This program aims to use spline function to interpolate. To use this function, the values and slopes
//at start and end points should be gaven. 

//#include "stdafx.h"
#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int spline_Interp(int interN, float y0, float yk, float y_0, float y_k);

int main()
{
	int		i = 0;
	float	y0, yk, y_0, y_k;
	float	*Interpolation = NULL;
	int		interN=438;

	Interpolation = (float*)malloc(sizeof(float)*interN);

	spline_Interp(interN, 0.5, -0.6953, 1.0 / 512, 1.0 / 512,Interpolation);
	for (i = 0; i < interN; i++)
	{
		printf("Interpolation[%d]=%f\n", i, Interpolation[i]);
	}
	getchar();
	return (0);
	
}

int spline_Interp(int interN, float y0, float yk, float y_0, float y_k,float Interpolation[])
{
	float	c[4];
	int		N = interN + 1;
	int		i;

	//Interpolation = (float*)malloc(sizeof(float)*interN);

	c[0] = y_0 / (N*N) + 2.0 / (N*N*N)*y0 + y_k / (N*N) - 2.0 / (N*N*N)*yk;
	c[1] = 3.0 / (N*N)*yk - y_k / N - 2.0 / N*y_0 - 3.0 / (N*N)*y0;
	c[2] = y_0;
	c[3] = y0;

	printf("c0=%f,c1=%f,c2=%f,c3=%f\n", c[0], c[1], c[2], c[3]);
	for (i = 0; i < N; i++)
	{
		Interpolation[i] = c[0] * i*i*i + c[1] * i*i + c[2] * i + c[3];
	}

	return (0);
}

