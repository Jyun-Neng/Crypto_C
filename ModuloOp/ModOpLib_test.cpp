//ModOpLib test file.
#include <iostream>
#include "ModOpLib.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ModOpLib *mod;
	int gcd;
	int number = 10;
	int a = 10, b = 20;
	gcd = mod -> GCD(a, b);

	printf("%d\n", gcd);
	printf("%d\n", mod -> Inverse(2,3));
	printf("%d\n", mod -> IsCongruence(3, 5, 2));

	int *congr = mod -> FindCongruence(2, 3, number);

	for (int i = 0; i < number; ++i)
	{
		printf("%d\t", congr[i]);
	}
	printf("\n");

	int modexp = mod -> ModExponent(644, 645, 3);

	printf("%d\n", modexp);

	int X = 20, p1 = 3, p2 = 7;
	int x1, x2, ICRT_X;	


	x1 = mod -> CRT(X, p1);
	x2 = mod -> CRT(X, p2);
	ICRT_X = mod -> ICRTnode(x1, x2, p1, p2);

	printf("%d mod %d = %d, and %d mod %d = %d\n", X, p1, x1, X, p2, x2);
	printf("After ICRT X is %d\n", ICRT_X);

	return 0;
}