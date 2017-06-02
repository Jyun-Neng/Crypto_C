/*	RSA cryptosystem test.

	date: 2017/06/02
*/
#include <iostream>
#include <string>
#include "RSA.h"

using namespace std;

int main(int argc, char const *argv[])
{
	RSA RSA;
	
	int *ciphertext = RSA.Encrypt("Hi! Happy Birthday!");	// encryption.
	int i = 0;

	while(ciphertext[i] != '\0')	// print ciphertext.
	{
		printf("%X", ciphertext[i]);
		i++;
	}
	printf("\n");

	char *dec_message = RSA.Decrypt(ciphertext);	// decryption.

	printf("%s\n", dec_message);	// print plaintext.

	return 0;
}	// main