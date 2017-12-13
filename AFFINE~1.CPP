#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
int modinverse(int a,int b) {
	for(int i=1;i<b;i++) {
		if((a*i)%b==1)
			return i;
	}
	return -1;
}

void encrypt(char *msg,int key,int akey,char *enc) {
	char al[26],a;
	int temp[26],i;
	for(a='A',i=0;a<='Z',i<26;a++,i++) {
		al[i]=a;
	}
	int l=strlen(msg);
	for(i=0;i<l;i++) {
		if(msg[i]==' ' || (msg[i]>='0' && msg[i]<='9')) {
			enc[i]=msg[i];
			continue;
		}
		temp[i]=(int)toupper(msg[i])-65;
		temp[i]=temp[i]*key+akey;
		temp[i]=temp[i]%26;
		enc[i]=al[temp[i]];
	}
	enc[i]='\0';
}

void decrypt(char *enc,int key,int akey,char *dec) {
	char al[26],a;
	int temp[26],i;
	int inverse=modinverse(key,26);
	for(a='A',i=0;a<='Z',i<26;a++,i++) {
		al[i]=a;
	}
	int l=strlen(enc);
	for(i=0;i<l;i++) {
		if(enc[i]==' ' || (enc[i]>='0' && enc[i]<='9')) {
			dec[i]=enc[i];
			continue;
		}
		int t=(int)enc[i]-65 -akey;
		if(t>=0) {
			temp[i]= ( t *inverse  )%26;
		}
		else {
			temp[i]=((t+26)*inverse)%26;

		}
		dec[i]=al[temp[i]];
	}
	dec[i]='\0';
}

int factors(int key,int akey) {
	int small=(key<=akey)?key:akey;
	int large=(key>akey)?key:akey;
	for(int i=2;i<=small;i++) {
		if(small%i==0  && large%i==0)
			return -1;
	}
	return 1;
}

int main() {
clrscr();
	cout <<"     		INFORMATION SECURITY                         "<<endl;
	cout <<"    	        ANCHAL MITTAL                                "<<endl;
	cout <<"     	        ROLL NO-4                                    "<<endl;

	cout <<"      		AFFINE CIPHER"<<endl;
	int key,i,akey;
	char a;
	char msg[100],enc[100],dec[100];
	cout<<"Enter the message to be encrypted :"<<endl;
	gets(msg);
	cout << endl;
	cout<<"Enter the multiplicative key :"<< endl;
	cin>>key;
	int inverse=modinverse(key,26);
	while(inverse==-1) {
		cout<< endl;
		cout<<"Mod inverse of "<<key<<" does not exist "<<endl;
		cout<< endl;
		cout<<"Enter the key again :"<< endl;
		cin>>key;
		inverse=modinverse(key,26);
	}
	cout<<"Enter the additive key :"<< endl;
	cout << endl;
	cin>>akey;
	while(factors(key,akey)!=1) {
		cout<<"Additive Key rejected"<<endl;
		cout << endl;
		cout<<"Note :Multiplicative key and additive key should not have common factors"<<endl;
		cout << endl;
		cout<<"Enter the additive key :"<< endl;
		cin>>akey;
	}
	encrypt(msg,key,akey,enc);
	cout<<"The encrypted message is :"<<enc<<endl;
	cout << endl;
	decrypt(enc,key,akey,dec);
	int l=strlen(dec);
	for(i=0;i<l;i++) {
		dec[i]=tolower(dec[i]);
	}
	cout << endl;
	cout<<"The decrypted message is :"<<dec<<endl;
	cout << endl;
	getch();
	return 0;
}
