//This program is to check whether the given string is palindrome or not.
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  char a[10];
  int flag=0,len;
  cout<<"\n\n Enter the string.\n";
  cin>>a;
  len=strlen(a);
  for(int i=0,j=len-1;i<=(len-1),j>=0;i++,j--)
	{ if(a[i]!=a[j])
	   flag=1;
 	}
if(flag)
cout<<"\nString is not palindrome..!";
else
cout<<"\nString is palindrome..!";
cout<<"\n\n";
return 0;
}
