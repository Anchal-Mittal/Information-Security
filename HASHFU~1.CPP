#include<iostream.h>
#include<string.h>
#include<conio.h>
class hashcipher
{
char data[100];
char hdata[100];
int len;
int hlen;
int h1;
int h2;

public:
hashcipher()
{
h1=0;
h2=0;

}
void input();
void senderhash();
void receiverhash();
void change();
void check();
void display();
};
void hashcipher:: input()
{
int i;
cout<<"ENTER DATA"<<endl;
cin>>data;
len=strlen(data);

hlen=len;
for(i=0;i<len;i++)
{
  if(data[i]>='A' &&data[i]<='Z')
	  {
		hdata[i]=data[i]-65;
	  }
  else
	  {
		hdata[i]=data[i]-97;
	  }
}
}


void hashcipher:: senderhash()
{

int a,b,i;
int num =31;
for(i = 0; i<len; i++)
{

h1 = (h1 * num) + hdata[i];

}

h1=h1%100;
cout<<"H1:"<<h1<<endl;
}


void hashcipher:: receiverhash()
{
int a,b,i;
int num =31;
for(i = 0; i<len; i++)
{

h2 = (h2 * num) + hdata[i];

}
h2=h2%100;
cout<<"H2:"<<h2<<endl;

}

void hashcipher::change()
{
int i;
cout<<"ENTER CHANGED MESSAGE"<<endl;
cin>>hdata;

hlen=strlen(hdata);
for(i=0;i<len;i++)
{
if(hdata[i]>='A' &&hdata[i]<='Z')
{
hdata[i]=hdata[i]-65;
}
else
{
hdata[i]=hdata[i]-97;
}
}
}


void hashcipher::check()
{

if(h1==h2)
cout<<"MESSAGE INTACT"<<endl;
else
cout<<"MESSAGE TAMPERED"<<endl;
}


void hashcipher:: display()
{
cout<<"DATA IS:"<<data<<endl;
}


int main()
{
clrscr();
cout<<endl<<"                INFORMATION SECURITY     ";
cout<<endl<<"                ANCHAL MITTAL";
cout<<endl<<"                ROLL NO 4";
cout<<endl<<"HASH FUNCTION FOR CIPHER";
hashcipher c;
char ch='y';
char n;
while(ch=='y')
{
	c.input();
	c.senderhash();

	cout<<"if u want to change the message then press y?"<<endl;
	cin>>n;
	if(n=='y'||n=='Y')
	c.change();
	c.receiverhash();
	c.check();
	c.display();
	cout<<"IF U WANT TO CONTINUE THEN PRESS y?"<<endl;
	cin>>ch;

}
return 0;

}

