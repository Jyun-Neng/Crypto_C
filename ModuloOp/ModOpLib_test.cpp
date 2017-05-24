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

	return 0;
}