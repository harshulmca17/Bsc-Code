#include<iostream>
using namespace std;
void checkprime(int);
void printprime(int);
int main()
{
 int choice,num1;
cout<<"\nChoose any one from:\n1.To check whether the given number is prime or not.\n2.To print all the prime numbers upto the given number.\n\nEnter the choice(1-2) : ";
cin>>choice;
switch(choice)
{ 
 case 1: 
 	cout<<"\nEnter the number : ";
 	cin>>num1;
	checkprime(num1);
	break;
 case 2:
	cout<<"\nEnter the number upto which prime numbers are required : ";
 	cin>>num1;
	printprime(num1);
	break;
 default: cout<<"\n\nYou have entered a wrong choice..!!";
}
cout<<"\n\n";
return 0;
}
void checkprime(int num)
{ 
  int flag;
  for(int i=2;i<num;i++)
          {    
   	    if(num%i==0)
	   	++flag;
           }
	if(!flag)
	cout<<"\nNumber is prime..!!";
	else
	cout<<"\nNumber is not prime..!!";
}
void printprime(int num)
{
  int flag;
  for(int i=2;i<=num;i++)
  {   flag=0;
      for(int j=2;j<i;j++)
      {
	if(i%j==0)
	++flag;
      } 
      if(!flag)
      cout<<i<<" ";
  }
}