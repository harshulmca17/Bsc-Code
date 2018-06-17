/* To print the sum and product of the digit if the given integer  */
#include<iostream>
using namespace std;

void digitsum(int number)
{ int digit,sum=0,product=1;
  while(number>0)
  {
    digit=number%10;
    sum=sum+digit;
    product=product*digit;
    number=number/10;
  }
  cout<<"\nThe sum of the digits of given integer is "<<sum<<" and product is "<<product;
}

int main()
{
 int n;
 cout<<"\nThis program is to print the sum and product of the given integer \n";
 cout<<"\nEnter the number : ";
 cin>>n;
 cout<<"\nYou entered : "<<n;
 digitsum(n);
 //cout<<"The sum of the series is : "<<sum;
 cout<<"\n";
 return 0;
}

