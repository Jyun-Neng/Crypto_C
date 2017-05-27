/*	The function of ModOpLib.h

	date: 2017/05/27
*/
#include "ModOpLib.h"

int ExtendedEuclideanAlgo(int a, int b)	// find the inverse of b mod a.
{
	int q, r, x, x1, x2, y, y1, y2, ori_a;

	x2 = 1;
	x1 = 0;
	y2 = 0;
	y1 = 1;
	ori_a = a;

	while(b > 0)
	{
		q = a / b;
		r = a % b;
		x = x2 - q * x1;
		y = y2 - q * y1;
		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;
		a = b;
		b = r;
	}
	y = y2;
	y = (y < 0) ? ori_a + y : y;	// let the inverse is between 0 to a. 
	return y;
}

bool ModOpLib::IsCongruence(int a, int b, int modulus)
{
	bool result;
	
	result = (((a - b) % modulus) == 0) ? true : false;
	return result;
}

int *ModOpLib::FindCongruence(int a, int modulus, int numbers)
{
	int *ArrayPtr = new int [numbers];
	for (int i = 1; i <= numbers; ++i)
	{
		ArrayPtr[i-1] = (a % modulus) + (modulus * i);
	}
	return ArrayPtr;
}

int ModOpLib::GCD(int a, int b)
{
	int big_num, small_num;
	int q, r;

	big_num = (a > b) ? a : b;
	small_num = (big_num == a) ? b : a;

	// Euclidean algorithm
	while(small_num > 0){
		r = big_num % small_num;
		big_num = small_num;
		small_num = r;
	}

	return big_num;
}

int ModOpLib::Inverse(int a, int modulus)
{
	int inverse = ExtendedEuclideanAlgo(modulus, a);

	return inverse;
}

int ModOpLib::ModExponent(int exp, int modulus, int base)
{
	int r, q = exp;
	int x = 1;
	int power = base;

	while(q != 0)
	{
		r = q % 2;	// base 2 expansion.
		q  = q / 2;

		// Modular Exponentiation algorithm.
		if (r == 1)	
		{
			x = (x * power) % modulus;
		}
		power = (power * power) % modulus;
	}
	return x;
}



