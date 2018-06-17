/* This program is to swap the two given values */
#include<iostream>
using namespace std;
/*
Function name : swap
Parameters    : *p and *q are the pointers variable of type int which are accepting the address of the variables
Purpose      : To swap the two given values using pointers
*/
void swap(int *p,int *q)		
{
  int temp;
  temp=*p;
  *p=*q;
  *q=temp;
  cout<<"\nSwapped values are   : "<<*p<<"\t"<<*q<<"\n\n"; 
  return;
}
int main()
{
  int a,b;
  cout<<"\nEnter the two values :\n";
  cin>>a>>b;
  cout<<"\nThe given values are : "<<a<<"\t"<<b;
  swap(&a,&b);				
  cout<<"\n";
  return 0;
}
  