#include<iostream>

using namespace std;

int Xor(int a,int b)
{
	if(a==b)
		return 0;
	else
		return 1;
			
}

int Divide(int * divisor,int* dividend,int m,int n)
{
	int l=0;

	while((n-l)>=m)
	 {
	 		for(int i=l,j=0;i<m+l,j<m;i++,j++)
			{
				dividend[i]=Xor(divisor[j],dividend[i]);
			}
			
			l=0;
			for(int i=0;i<n;i++)
			{	
				if(dividend[i]==1)
					break;
				else
					l++;
			}
	}
	
	return l;
}

int GPchecker(int* GP,int Gsize)
{
	int* divisor;
	int l;
	divisor=new int[2];
	divisor[0]=1;
	divisor[1]=1;
	int * Dividend=new int[Gsize];
	for(int i=0;i<Gsize;i++)
		Dividend[i]=GP[i];
	
	l=Divide(divisor,Dividend,2,Gsize);
	
	if(l>=Gsize&&GP[0]==1&&GP[Gsize-1]==1)
		return 1;
	else
		return 0;	
}

int main()
{
	int *GP,*MSG;
	int Gsize,Msize,c;
	
	do
	{
		cout<<"Enter the size of Generator Polynomial \n";
		cin>>Gsize;
	
		GP=new int[Gsize];
	
		cout<<"Enter the generator polynomial \n";
		for(int i=0;i<Gsize;i++)
		cin>>GP[i];
	
	 	c=GPchecker(GP,Gsize);
	 	if(c==0)
	 	{
	 		cout<<"Generator Polynomial is Incorrect \n";
		}
	
	}while(c==0);
	
	cout<<"Generator Polynomial is valid \n";
	cout<<"Enter the size of Message \n";
	cin>>Msize;
	
	MSG=new int[Msize];
	
	cout<<"Enter the Message \n";
	for(int i=0;i<Msize;i++)
	cin>>MSG[i];	
	
	
	for(int i=Msize;i<Msize+Gsize-1;i++)
		MSG[i]=0;
		
	Msize=Msize+Gsize-1;

	int R=Divide(GP,MSG,Gsize,Msize);
		
	cout<<"Remainder is \n";
	for(int i=R;i<Msize;i++) 
		cout<<MSG[i]<<" ";
	cout<<"\n";
	
	return 0;
	
}

