/*	Build a modulo operation library, 
	which include:
		congruence, modular inverse, modular expoentiation, gcd, ICRT, CRT...

	date: 2017/05/27
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
	int ModExponent(int exp, int modulus, int base);	// Do modulo exponetial operation.
	int ICRTnode(int x1, int x2, int p1, int p2);	// Do the inverse CRT.
	int CRT(int X, int p) { return (X % p); }	// Do the CRT with modulus p.
};
#endif