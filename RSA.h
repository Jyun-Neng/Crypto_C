/*	RSA cryptography.

	date: 2017/06/02
*/
#ifndef RSA_H
#define	RSA_H

#include <string>

using namespace std;

class RSA
{
public:
	RSA();
	int PK_e, PK_n;
	int *M_block, *C_block;
	int *Encrypt(string plaintext);	// RSA encryption.
	char *Decrypt(int *C_block);	// RSA decryption.
};
#endif