/*	Build a modulo operation library, 
	which include:
		congruence, modular inverse, modular expoentiation, gcd...

	date: 2017/05/24
*/
#ifndef MOD_OP_LIB_H
#define MOD_OP_LIB_H

class ModOpLib
{
public:
	bool IsCongruence(int int1, int int2, int modulus);	// whether two integers are congruence.
	int *FindCongruence(int int1, int modulus, int numbers);	// Find the congruence of integer a.
	int GCD(int int1, int int2);	// Find the greatest common integer.	
	int Inverse(int int1, int modulus);	// Find the modular inverse.
};
#endif