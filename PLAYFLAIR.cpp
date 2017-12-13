#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
void encode(string s,char k[5][5])
{
	int c1_r,c1_c,c2_r,c2_c;
	char ch,ch1;
	for(int l=0;l<s.length();l+=2)
    {
        
        ch=s[l];
		ch1=s[l+1];   
    
    for(int i=0;i<5;i++)
    {
    	for(int j=0;j<5;j++)
    	{
    		if(k[i][j]==ch)
    		 {
    		 	c1_r=i;
    		 	c1_c=j;
			 }
			if(k[i][j]==ch1)
			{
				c2_r=i;
    		 	c2_c=j;
			}
		}
	}
	  if(c1_r==c2_r)
	  {
	     s[l]= k[c1_r][(c1_c+1)%5];
		 s[l+1]=k[c1_r][(c2_c+1)%5];	
	  }
	  else if(c1_c==c2_c)
	  {
	  	s[l]= k[(c1_r+1)%5][c1_c];
		 s[l+1]=k[(c2_r+1)%5][c2_c];	
	  }
	  else{
          s[l]=k[c1_r][c2_c];
		  s[l+1]=k[c2_r][c1_c];	  
	  }
	
    } 
    cout<<"\nENCRYPTED STRING IS:  "<<s;
}
void decode(string s,char k[5][5])
{
 int c1_r,c1_c,c2_r,c2_c;
	char ch,ch1;
	for(int l=0;l<s.length();l+=2)
    {
        
        ch=s[l];
		ch1=s[l+1];   
    
    for(int i=0;i<5;i++)
    {
    	for(int j=0;j<5;j++)
    	{
    		if(k[i][j]==ch)
    		 {
    		 	c1_r=i;
    		 	c1_c=j;
			 }
			if(k[i][j]==ch1)
			{
				c2_r=i;
    		 	c2_c=j;
			}
		}
	}
	  
	  if(c1_r==c2_r)
	  {
	  	 if(c1_c==0)
	  	  c1_c=5;
	  	  if(c2_c==0)
	  	  c2_c=5;
	     s[l]= k[c1_r][(c1_c-1)];
		 s[l+1]=k[c1_r][(c2_c-1)];	
	  }
	  else if(c1_c==c2_c)
	  {
	  	if(c1_r==0)
	  	 c1_r=5;
	  	 if(c2_r==0)
	  	 c2_r=5;
	  	s[l]= k[(c1_r-1)%5][c1_c];
		 s[l+1]=k[(c2_r-1)%5][c2_c];	
	  }
	  else{
          s[l]=k[c1_r][c2_c];
		  s[l+1]=k[c2_r][c1_c];	  
	  }
	
    } 
    cout<<"\nDECRYPTED string:  "<<s;
}

int main()
{
	cout<<      "								INFORMATION SECURITY";
	cout<<endl<<"                               ANCHAL MITTAL";
	cout<<endl<<"                               ROLL NO -4";
	
	cout<<endl<<"                               PLAYFLIAR";
	string s;
   	char cha='y';
	int z;
	char key[5][5];
	do
	{
		cout<<"\n1.ENCRYPTION";
		cout<<"\n2.DECRYPTION\n";
		cout<<"ENTER UR CHOICE:";
		cin>>z;
		if(z==1)
		{
		 string s;
         cout<<"\nENTER THE KEY FOR ENCRYPTION EXCEPT j ";
	     for(int k=0;k<5;k++)
	     {
	     	for(int j=0;j<5;j++)
	     	  cin>>key[k][j];
		 }
		 
	     cout<<"\n ENTER THE MESSAGE ";
         cin.ignore();
	     getline(cin,s);
    	 int n= s.length();
    	 string app_s;
		 for(int l=0;l<n;l++) 
   		    if(s[l]=='j')
			  s[l]='i';
			for(int m=0;m<n;m++)
			{
				
				app_s.insert(app_s.end(),s[m]);
				if(s[m]==s[m+1])
				{
				  app_s.insert(app_s.end(),'x');
				}
			} 
			for(int m=0;m<(app_s.length()%2);m++)
			  app_s.insert(app_s.end(),'x');
		    cout<<"\nAPPENDED STRING: "<<app_s;
		 	encode(app_s,key);
		}
		else
		{
	    string s;
	    cout<<"\n ENTER THE KEY FOR DECRYPTION EXCEPT j: ";
	    for(int k=0;k<5;k++)
	     {
	     	for(int j=0;j<5;j++)
	     	  cin>>key[k][j];
		 }
		 
        cout<<"\nENTER THE MESSAGE ";
    	cin.ignore();
		getline(cin,s);
    	decode(s,key);
		}
		cout<<"\n IF U WANT TO CONTINUE THEN PRESS Y";
		cin>>cha;
	}while(cha=='y'||cha =='Y');
    
	
}

