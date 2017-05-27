/*	Implement a simple RSA cryptography.

	date: 2017/05/27
*/
#include <iostream>
#include "ModuloOp/ModOpLib.h"

using namespace std;

#define PK_n 2537
#define PK_e 13

int RSA_encrypt(int plaintext)
{
	ModOpLib mod;
	int ciphertext = mod.ModExponent(PK_e, PK_n, plaintext);

	return ciphertext; 
}	// RSA_encrypt

int RSA_decrypt(int ciphertext)
{
	ModOpLib mod;
	int p = 43, q = 59;	// private key, n = p*q;
	int d = mod.Inverse(PK_e, ((p-1)*(q-1)));
	int plaintext = mod.ModExponent(d, PK_n, ciphertext);

	return plaintext;
}	// RSA_decrypt

int main(int argc, char const *argv[])
{
	int plaintext = 1819;
	int ciphertext = RSA_encrypt(plaintext);
	int decryption = RSA_decrypt(ciphertext);

	printf("%d\n", ciphertext);
	printf("%d\n", decryption);
	return 0;
}	// main