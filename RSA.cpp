#include <string>
#include "ModuloOp/ModOpLib.h"
#include "RSA.h"

using namespace std;

RSA::RSA()
{
	// initialize public key.
	PK_e = 13;
	PK_n = 130931;
}	// RSA

int *RSA::Encrypt(string plaintext)
{
	ModOpLib mod;

	int length = plaintext.length();
	const char *chr = plaintext.c_str();

	M_block = new int[(length + 1) / 2];
	C_block = new int[(length + 1) / 2];

	for (int i = 0; i < length; i+=2)	// combine two characters in a block.
	{
		M_block[i/2] = 1000 * (int)chr[i] + (int)chr[i+1]; 
	
		C_block[i/2] = mod.ModExponent(PK_e, PK_n, M_block[i/2]);	// C = M^e mod n

	}

	return C_block; // return ciphertext array.
}	// Encrypt

char *RSA::Decrypt(int *C_block)
{
	ModOpLib mod;
	int p = 311, q = 421;	// private key, n = p*q;
	int d = mod.Inverse(PK_e, ((p-1)*(q-1)));

	int j = 0;
	while(C_block[j] != '\0')	// Find the size of C_block and do decryption.
	{
		M_block[j/2] = mod.ModExponent(d, PK_n, C_block[j/2]);	// M = C^d mod n
		j++;
	}
	int length = j * 2;	// a block has two character.
	
	char *new_chr = new char[length];
	
	for (int i = 0; i < length; i+=2)	// convert to character.
	{
		new_chr[i] = (char)(M_block[i/2] / 1000);
		new_chr[i+1] = (char)(M_block[i/2] % 1000);
	}
	new_chr[length] = '\0';

	return new_chr;	// return plaintext array.
}	// Decrypt