/* This program is to reverse the given number  */
#include<iostream>
using namespace std;
/* Function name : reverse
   Parameters    : number of type int
   Purpose       : to calculate the sum of the series  */
void reverse(int number)
{ int digit,reverse=0;
 while(number>0)
  {
    digit=number%10;
    reverse=(reverse*10)+digit;
    number=number/10;
  }
  cout<<"\nThe reverse of the given number is : "<<reverse;
}
/* Pupose : To call the function reverse */
int main()
{
 int n;
 cout<<"\nThis program is to print the reverse of the given number \n";
 cout<<"\nEnter the number : ";
 cin>>n;
 cout<<"\nYou entered : "<<n;
 reverse(n);
 cout<<"\n";
 return 0;
}
