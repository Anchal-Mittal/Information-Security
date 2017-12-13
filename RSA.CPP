#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
int phi,n,d,e,FLAG,k=0;
int M[30]={88};int C[30];

int check()
{
	int i;
	for(i=3;e%i==0 && phi%i==0;i+2)
	{
		FLAG = 1;
		return 0;
	}

	FLAG = 0;
	return 0;
}

void encrypt()
{
	int i,j;
	for(i=0;i<30;i++)
	C[i]=1;
	int var=0;
	while(M[var]!=0)
	{var++;
	}
	cout<< "\n\n\t Encrypted TEXT: ";
	for(j=0;j<var ;j++)
	{
	for(i=0;i< e;i++)
	C[j]=C[j]*M[j]%n;
	C[j] = C[j]%n;


	cout << C[j] << endl;
	}

	k=var;
}


void decrypt()
{
	int i,j;
	for(i=0;i<30;i++)
	M[i]=1;
	cout << "\n\n\t Decrypted TEXT : ";
	for(j=0;j<k;j++)
	{
	 for(i=0;i< d;i++)
		M[j]=M[j]*C[j]%n;
		M[j] = M[j]%n;
		cout << M[j] << endl;}

}

int main()
{       clrscr();
	cout <<"     		INFORMATION SECURITY                         "<<endl;
	cout <<"    	        ANCHAL MITTAL                                "<<endl;
	cout <<"     	        ROLL NO-4                                    "<<endl;

	cout <<"      		RSA ALGORITHM"<<endl;

	int p,q,s;
	p=17;
	q=11;
	e=7;

	cout << "\n\n\t Two Relatively Prime Numbers\t: ";
	cout << "\n\n\tP= "<< p <<"  Q="<< q;
	n = p*q;
	phi=(p-1)*(q-1);
	cout << "\n\n\t F(n) phi value\t"<< phi<<endl;

	do
	{
		cout << "\n\n\t A number  e which is prime number and less than phi \t:n= " << n;
		cout <<"\te =" << e;
		check();
	}
	while(FLAG==1);
	d = 1;

	do
	{
		s = (d*e)%phi;
		d++;
	}
	while(s!=1);


	d = d-1;
	cout <<"\n\n\t Public Key\t:" << "e=" << e<<"  n="<< n;
	cout << "\n\n\t Private Key\t:"<<"d="<< d <<"  n="<<n;


	cout << "\n\n\t The Plaintext is "<< M[0]<< endl;
	encrypt();
	decrypt();
	getchar();
	getch();
	return 0;
}
