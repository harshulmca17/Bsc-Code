/*This program is to 1)print fibonacci series
		     2)calculate factorial
		     3)calculate GCD of given two numbers   */
#include<iostream>
using namespace std;
void fibonacci(int);
int factorial(int);
int gcd(int,int);
int main()
{
  int choice,v,m,n;
  cout<<"\n\n\t\tMENU :\n\n";
  cout<<"1 ) To print the fibonacci series.\n";
  cout<<"2 ) To calculate the factorial of the given number.\n";
  cout<<"3 ) To calculate the GCD of the given two numbers.\n";
  cout<<"\nEnter the choice : ";
  cin>>choice;
  switch(choice)
  {
    case 1 : 
	      cout<<"\nEnter the number upto which you want to print the series :";
	      cin>>n;
	      fibonacci(n);
	      break;
    case 2 : 
	      cout<<"\nEnter the number :";
	      cin>>n;
	      factorial(n);
              break;
    case 3 : 
	      cout<<"\nEnter the two number whose GCD has to be calculate :";
	      cin>>m>>n;
	      v=gcd(m,n);
	      cout<<"\nThe GCD of "<<m<<" and "<<n<<" is "<<v;
	      break;
    default: cout<<"\nYou have entered a wrong choice ...  ";
  }
  cout<<"\n";
  return 0;
}
/*Function name : Fibonacci
  parameters    : num of type int, the count of numbers in fibonacci series
  Purpose       : To print the Fibonacci series  */
void fibonacci(int num)
{
  int first=0,second=1,next;
  cout<<"\nThe fibonacci series upto "<<num<<" is :\n";
  for(int i=0;i<num;i++)
  {
    if(i<=1)
      next=i;
    else
    {
      next=first+second;
      first=second;
      second=next;
    }
    cout<<next<<" ";
  }
}
/*Function name : Factorial
  parameters    : num of type int, the number of which the factorial has to be calculate
  Purpose       : To calculate the factorial of the given number  */
int factorial(int num)
{
  int factorial=1;
  for(int i=1;i<=num;i++)
    factorial=factorial*i;
  cout<<"\nThe factorial of the given number is "<<factorial;
}
/*Function name : gcd
  parameters    : num1 and num2 are of type int, the numbers of which the GCD has to be calculate
  Purpose       : To calculate the GCD of the given two numbers */
int gcd(int num1,int num2)
{
  if(num2==0)
   return num1;
  else
    return gcd(num2,num1%num2);
}