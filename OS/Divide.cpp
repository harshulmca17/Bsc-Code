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

int main()
{
	int m,n,s;
	cout<<"Enter the size of the Divisor \n";
	cin>>m;
	cout<<"Enter the size of the Dividend \n";
	cin>>n;
		
	int* divisor=new int[m];
	int* dividend=new int[n];
		
	cout<<"Enter the Divisor \n";
	for(int i=0;i<m;i++)
	cin>>divisor[i];
	
	cout<<"Enter the Dividend \n";
	for(int j=0;j<n;j++)
	cin>>dividend[j];
	
	int l=Divide(divisor,dividend,m,n);
	
	cout<<"\n";
	if(l<n)
	{
		for(s=l;s<n;s++)
		cout<<dividend[s]<<" ";
	}
	else
		cout<<0;
	return 0;	
}














