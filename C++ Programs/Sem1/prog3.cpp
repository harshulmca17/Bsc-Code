/* This program is to find the sum of the series : 1 + 1/2 + 1/3 + 1/4.....+ 1/n  */
#include<iostream>
using namespace std;
/* Function name : seriessum
   Parameters    : n of int type, accepts the value upto which the sum of the series is to be print
   Purpose       : to calculate the sum of the series  */
float seriessum(int n)
{ float sum=0;
  for(int i=1;i<=n;i++)
 {
    sum=sum+(1.0/i);
 }
 return sum;
}
/* Pupose : To call the function seriessum */
int main()
{
 int n;
 float sum=0;
 cout<<"\nThis program is to find the sum of the series : 1 + 1/2 + 1/3 + 1/4.....+ 1/n \n";
 cout<<"\nEnter the value of n : ";
 cin>>n;
 sum=seriessum(n);
 cout<<"The sum of the series is : "<<sum;
 cout<<"\n";
 return 0;
}
