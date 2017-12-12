
#include<conio.h>
#include <stdio.h>
#include <iostream.h>

#define r 10 			// number of rounds
#define t (2*r+2) 		// number of sub-keys needed
unsigned long S[t]; 		// array used for key expansion
#define b 16 			// number of bytes in key
#define c 1 			// number of words in key
unsigned long Pw = 0xb7e15293; 	// constant used for key expansion
unsigned long Qw = 0x9e3771b1; 	// constant used for key expansion
#define max(i,j) (i>=j?i:j)
class int_record
{
	public:
	unsigned long data0;
	unsigned long data1;
};



/*left rotate function, rotates LE by RE bits.  */
unsigned long left_rotate( unsigned long LE, unsigned long RE)
{
		return ((LE << (RE & (32-1))) | (LE >> (32 -(RE & (32-1)))));
}


/*right rotate function, rotates LE by RE bits.*/
unsigned long right_rotate( unsigned long LE, unsigned long RE)
{
	return ((LE >> (RE & (32-1))) | (LE << (32 -(RE & (32-1)))));
}


/*The encryption process encrypts a given plaintext to a
ciphertext by using the expanded array key, S, of length 2r + 2.
Returns the ciphertext*/
int_record * encryption(int_record &inputs)
{
	unsigned long i, LE, RE;
	int_record * val = new int_record();
	LE = inputs.data0 + S[0];
	/* Initial value of first data block added to S[0] subkey */

	RE = inputs.data1 + S[1];
	/* Initial value of second data block added to S[1] subkey*/

	i=1;
	/* The ecryption rounds which generate the final ciphertext,r=12 */
	while ( i <= r )
	{
		LE = left_rotate(LE^RE, RE) + S[2 * i];
		RE = left_rotate(RE^LE, LE) + S[2 * i + 1];
		i++;
	}

	// Final value of ciphertext blocks
	val->data0 = LE;
	val->data1 = RE;
	return val;
}

int_record * decryption(int_record * crypted_data)
{
	unsigned long i, LD, RD;
	int_record * val = new int_record();
	RD = crypted_data->data1; 	//First ciphertext block
	LD = crypted_data->data0; 	//Second ciphertext block
					// The Decryption rounds , r=12
	for (i = r; i > 0; i--)
	{
		RD = right_rotate(RD - S[2*i+1], LD) ^ LD;
		LD = right_rotate(LD - S[2*i], RD) ^ RD;
	}
	val->data0 = LD - S[0];		/*First block of final decrypted plaintext value */
	val->data1 = RD - S[1];		/* Second block of final decrypted plaintext value */
	return val;
}


//Key Expansion process has two parts
// Array initialization
// Key mixing

void key_expansion(unsigned char *key)
{
	unsigned long w, i, j, key_round, X, Y, L[c];
	//Initialization of L array
	for (i=0; i<c; i++)
	L[i] = 0;
	//Convertion of b byte key array to c word L array
	for (i=0; i<b; i++)
	{
		w = i/c;
		L[w] = L[w] << 4;
		L[w] = L[w] | key[i];
	}
	S[0] = Pw;

	//Initialization of S Array with constant Pw and Qw
	for (i = 1; i < t; i++)
	S[i] = S[i - 1] + Qw;

	/* The mixing of the S array and L array to produce the final S array of subkeys */
	i = j = X = Y = 0;
	for (key_round = 0; key_round < 3 * max(t,c) ; key_round++)
	{
		S[i] = left_rotate(S[i] + X + Y, 3);
		X = S[i];
		i = (i + 1) % t;
		L[j] = left_rotate(L[j] + X + Y, X + Y);
		Y = L[j];
		j = (j + 1) % c;
	}
}


/* Function to check that decrypted plaintext matches original plaintext */
void check_data_validity(int_record &inputs, int_record * decrypted)
{
	if (inputs.data0 != decrypted->data0 || inputs.data1 !=
	decrypted->data1)
	cout << "ERROR in algorithm, data differ" << endl;
}


//Function to input the two blocks of plaintext to be encrypted
int get_inputs( int_record &inputs)
{
	cout << "\n Input first data block = 4 ";
	inputs.data0=4;

	cout << "\n Input second data block = 6 ";
	inputs.data1=6;

}


int main()
{
	int_record inputs;
	int_record *encrypted;
	int_record *decrypted;
	unsigned long random = 500; /* Random number used to generate initial key */

	get_inputs(inputs);

	unsigned long i;
	unsigned char key[b];
	// Creation of b byte key array
	for (i = 0; i < b; i++)
	key[i] = (unsigned char) (random ^ i);

	key_expansion(key);
	encrypted = encryption(inputs);
	decrypted = decryption(encrypted);
	cout << "TOTAL NUMBER OF ROUNDS USED HERE "<< r << endl;
	printf("\n The generated cipher text is: %.8lX %.8lX",
	encrypted->data0, encrypted->data1);
	cout << endl;
	check_data_validity(inputs, decrypted);

	cout << "\n The first data block after decryption is: " <<
	decrypted->data0 << endl;

	cout << "\n The second data block after decryption is: " <<
	decrypted->data1 << endl;

	cout << " The final expanded key used for encryption was: " << endl;
	for (i = 0; i < b; i++)
	printf("%.2X ", key[i]);
	cout << endl;
	delete(decrypted);
	delete(encrypted);

	getchar();
	getch();
	return 0;
}



