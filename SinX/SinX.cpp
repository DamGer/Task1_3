#include "SinX.h"
#include<iostream>
#include "stdint.h"
#include <cmath>


double factorial(int input)
{
    if (input == 0)
        return 1;
    else
        return input * factorial(input - 1);
}

double exp(double input, int deg)
{
	double out = 1;
	if (deg == 0)
		out = 1;
	else
	{
		for (int i = 1; i <= deg; i++)
			out *= input;
	}
	return out;
}

double SinX(int arg)
{
	const double PI = 3.1415926535;
	const int N = 9;
	double angle, out = 0;
	angle = (arg % 360) * PI / 180;
	for (int i = 0; i <= N; i++)
		out += exp(-1, i) * exp(angle, 2 * i + 1) / factorial(2 * i + 1);
	return out;
}