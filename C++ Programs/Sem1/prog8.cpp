#include<iostream>
using namespace std;
void pattern(int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i;j<n;j++)
    cout<<" ";
    for(int k=0;k<=(2*i);k++)
    cout<<"*";
    cout<<"\n";
  }
}  
int main()
{
  int n;
  cout<<"\nEnter the number of lines you want to print : ";
  cin>>n;
  pattern(n);
  cout<<"\n";
  return 0;
}
  
  