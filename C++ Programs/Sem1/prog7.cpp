//To print the factors of given number
#include<iostream>
using namespace std;
void factors(int);
int main()
{
 int num1; 
 cout<<"\nEnter any number : ";
 cin>>num1;
 factors(num1);
 return 0;
}
/*
Function name :Factors
Parameters : number of type int whose factors has to be compute
Purpose : To compute the factors of the given numbers
*/
void factors(int number)
 {
   cout<<"\nThe factors of given number are : ";
    for(int i=1;i<=(number/2);i++)
    { 
      if(number%i==0)
      cout<<i<<" ";
    }
    cout<<"\n\n";
 }

