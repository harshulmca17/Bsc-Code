/* This program is to find the sum of the series : 1 - 2 + 3 - 4 +.....n  */
#include<iostream>
using namespace std;
/* Function name : seriessum
   Parameters    : n of type int , accpets the value upto which the sum of the series is to be print
   Purpose       : to calculate the sum of the series  */
int seriessum(int n)
{ int sum=0,sum1=0,sum2=0;
  for(int i=0;i<=n;i++)
 {
   if(i%2==0)
     sum1=sum1+i;
   else
     sum2=sum2+i;
 }
 sum=sum2-sum1;
 return sum;
}
/* Pupose : To call the function seriessum */
int main()
{
 int n;
 float sum=0;
 cout<<"\nThis program is to find the sum of the series : 1 - 2 + 3 - 4 +.....n \n";
 cout<<"\nEnter the value of n : ";
 cin>>n;
 sum=seriessum(n);
 cout<<"The sum of the series is : "<<sum;
 cout<<"\n";
 return 0;
}
