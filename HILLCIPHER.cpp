/********************************** 		MCS 103 		*******************************/
/********************************** 	  Information Security 	  *************************************/
/********************************** HILL CIPHER ENCRYPTION AND DECRYPTION *************************************/

/*           Submitted by   	    */

/*  ANCHAL MITTAL         ROLL NO: 4		    */



#include<iostream>
#include<string>
using namespace std;
int finv[3][3];
void inverse(int key[3][3])
{
	int i=0,j,val=0;
    int det;
	int inv[3][3];
	det=((key[0][0]*((key[2][2]*key[1][1])-(key[1][2]*key[2][1])))-(key[0][1]*((key[2][2]*key[1][0])-(key[1][2]*key[2][0])))+(key[0][2]*((key[2][1]*key[1][0])-(key[1][1]*key[2][0]))));
	cout<<"Determinant of matrix is  "<<det<<"\n";


	// to find adjoint of this matrix
	if(det>0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i+j %2 ==0)
				{
					inv[i][j]= (key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
				}
				else
				{
					inv[i][j]= (key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
				}
			}
		}
	}
    else if(det<0)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(i+j %2 ==0)
				{
					inv[i][j]= -(key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
				}
				else
				{
					inv[i][j]= -(key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3] - key[(i+1)%3][(j+2)%3]*key[(i+2)%3][(j+1)%3]);
				}
			}
		}
	}


	//instead of dividing by det. we will multiply the matrix with its multiplicative inverse
	//multiplicative inverse
	int detinv;
	det%=26;
	for(i=1;i<26;i++)
	{
		if((det*i)%26==1)
		{
			detinv=i;
			cout<<"\nMultiplicative inverse of determinant is  "<<detinv<<"\n";
		}
	}

	//and to handle negative no.s we will apply (+26)
	//we will apply mod so that no.s are from 0-26

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			inv[i][j]=inv[i][j]%26;
			if(inv[i][j]<0)
			{
				inv[i][j]=inv[i][j]+26;
			}
			inv[i][j]=(inv[i][j]*detinv); // multiplying adjoint and inverse of det
			inv[i][j]=inv[i][j]%26;
		}
	}
	// tranpose of the final matrix will give us inverse
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			finv[j][i]=inv[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<finv[i][j]<<" ";
		}
		cout<<"\n";
	}


}
// simplfied multiplication because we know that entered string will be always 3x1
string matrixmult(int key[3][3],int a[3])
{
	string ctxt;
	int ans[3];
	int i;
	for(i=0;i<3;i++)
	{
		ans[i]=0;
	}
	for(i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans[i]+= key[i][j] * a[j];
		}
	}
	for(i=0;i<3;i++)
	{
		ans[i] = (ans[i]%26);
		if(ans[i]<0)
			ans[i] = ans[i]+26;
		ctxt+=(char)(ans[i] + 'A'); // int to ascii
	}
return ctxt;
}

int main()
{
	string in,entxt;
	int key[3][3] = {{3,5,6},{8,1,2},{4,17,9}};
	int a[3];
	int i;
	cout<<"enter string (CAPITAL LETTERS ONLY)";
	cin>>in;
	cout<<"Encyrpted text : ";
	for(i=0;i<=in.length();i++)
	{
		{
		a[i%3] = (in[i] - 'A');
		if((i+1)%3==0 && i!=0)           // to break in group of 3,to deal with at a time
			entxt+=matrixmult(key,a);    // multiplying key with string of 3
		}

	}
	cout<<entxt;
	cout<<"\n";

	cout<<"\ninverse key : \n";
	inverse(key);
    string detxt;
    cout<<"Decyrpted text : ";
	for(i=0;i<=entxt.length();i++)
	{
		a[i%3] = (entxt[i] - 'A');
		if((i+1)%3==0 && i!=0)
		{
			detxt+=matrixmult(finv,a);  // multiplying inverse of key with string of 3
		}

	}
    cout<<detxt;
	cout<<"\n";
	return 0;
}

