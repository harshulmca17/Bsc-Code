#include<iostream>
using namespace std;
int enter()
{
     int binary;
     cin>>binary;
     return binary;
}
void add(int i, int j)
{
     int result[4],k = 3, carry = 0;
     while(k>=0)
     {
             result[k] = i%10 + j%10 + carry;
             if(result[k]<=1)
             {
                         carry = 0;
             }
             else if(result[k]%2 == 0)
             {
                     result[k] = 0;
                         carry = 1;
             }
             else 
             {
                     result[k] = 1;
                         carry = 1;
             }
             i = i / 10;
             j = j / 10;
             k-- ;
     }
     cout<<"\nResult is :\t";
     for(int v=0 ;v<4; v++)
     cout<<result[v]<<"\t";
     cout<<"\n\nCarry     :\t"<<carry;
}
void subtract(int i,int j)
{
     int result[4],ones[4], newnum[4], k= 3, carry = 0;
     while(k>=0)                                                //for 1's complement
     {
             if(j%10 == 1)
             ones[k] = 0;
             else
             ones[k] = 1;
             i = i / 10;
             j = j / 10;
             k-- ;
     }
     cout<<"\n1's complement : ";
     for(int v=0; v<4; v++)
     cout<<ones[v]<<"\t";
     
}
int main()
{
    int ch,sum,sub,choice,binary1,binary2;
    cout<<"\nMenu :\n";
    cout<<"\n1.) ADD\n2.) SUBTRACT";
    cout<<"\nEnter the choice :";
    cin>>choice;
    switch(choice)
    {
                  case 1: 
                            cout<<"\n*********ADDITION*********\n";
                            cout<<"\nEnter the 1st binary number(of 4 digits) :";
                            binary1 = enter();
                            cout<<"\nEnter the 2nd binary number(of 4 digits) :";
                            binary2 = enter();
                            add( binary1 , binary2 );
                            break;
                  case 2: 
                            cout<<"\n*********SUBTRACTION*********\n";
                            cout<<"\nEnter the 1st binary number(of 4 digits) :";
                            binary1 = enter();
                            cout<<"\nEnter the 2nd binary number(of 4 digits) :";
                            binary2 = enter();
                            subtract( binary1 , binary2 );
                            break;
                  default:        
                            cout<<"\n\nYou have entered a wrong choice..!!!\n";
    }
    cin>>ch;
    return 0 ;
}
