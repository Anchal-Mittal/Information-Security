#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void encrypt(char p[],char ci[],int k)
{
 int i,c;
 for(i=0;p[i]!='\0';i++)
 {
  c=p[i];
  if(isupper(c))
  {
    c=c-65;
    ci[i]=(((c+k)%26)+65);
  }
  else if(islower(c))
  {
   c=c-97;
   ci[i]=((c+k)%26)+97;
  }
  else if(!isalnum(c))
  {  ci[i]=p[i];
  }
  else if(isalnum(c))
   { c=c-48;
  ci[i]=((c+k)%26)+48;
   }
  }
  ci[i]='\0';
}
void decrypt(char ci[],char p[],int k)
{
 int i,c;
 for(i=0;ci[i]!='\0';i++)
 {
  c=ci[i];
  if(isupper(c))
  {
    c=c-65;
    p[i]=(((c-k)+26)%26)+65;
  }
  else if(islower(c))
  {
   c=c-97;
   p[i]=(((c-k)+26)%26)+97;
  }
  else if(!isalnum(c))
   p[i]=ci[i];
  }
  p[i]='\0';
}

void display(char ci[])
{
  int i;
  for(i=0;ci[i]!='\0';i++)
  cout<<ci[i];
}
void main()
{
clrscr();
 char p[100],ci[100],ans;
 int ch,k;
 cout <<"	                      INFORAMATION SECURITY                        "<<endl;
 cout <<"       	              ANCHAL MITTAL                                "<<endl;
 cout <<"              	              ROLL NO -4                                   "<<endl;
 cout <<"                      	      ADDITIVE CIPHERES                            "<<endl;

 cout<<"\nEnter Plaintext to be encrypted:";
 gets(p);
 cout << endl;
 cout<<"\nEnter the key for additive cipher:";
 cin>>k;

 do{
 cout<<" MENU ";
 cout << endl;
 cout<<"\n1)ENCRYPTION !!!!!";
 cout<<endl;
 cout<<"\n2)DECRYPTION !!!!!";
 cout<<endl;
 cout<<"\nEnter choice:";
 cin>>ch;
 switch(ch)
 {
  case 1: encrypt(p,ci,k);
	  cout<<"Encrypted Ciphertext Message:"<<endl;
	  cout << endl;
	  display(ci);
	  break;

  case 2: decrypt(ci,p,k);
	  cout<<"Decrypted Plaintext Message:"<<endl;
	  cout << endl;
	  display(p);
	  break;

  default: cout<<"Invalid Option"<<endl;
	   cout<< endl;
	   break;
 }
 cout<<"\nWant to continue? y|n :";
 cout << endl;
 cin>>ans;

 }while(ans=='y'||ans =='Y');
 getch();
}