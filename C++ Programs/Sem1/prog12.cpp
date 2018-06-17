/*
This program is to perform operations on matrix:1.)Sum of two given matrices.
						2.)Difference of two given matrices.
						3.)Product of two given matrices.
						4.)Transpose of given matrix.
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class matrix
{
  int a[10][10],b[10][10],m,n,o,p,c[10][10];
public :
 void sum();
 void difference();  
 void product();
 void transpose();
}obj;
/*
Function name : Sum
Variables : m,n,o,p are the rows and columns of the matrices 'a' and 'b' respectively.
Purpose : To print the sum of the given matrices.
*/
void matrix::sum()
{ 
  cout<<"\nEnter the no. of rows and columns for the first matrix :\n";
  cin>>m>>n;
  cout<<"\nEnter the no. of rows and columns for the second matrix :\n";
  cin>>o>>p;
  if((m==o)&&(n=p))
  {
    cout<<"\nEnter the elememts for first matrix :\n";
    for(int i=0;i<m;i++)
     {   for(int j=0;j<n;j++)
	 cin>>a[i][j];
	 
     }
    cout<<"\n\nEnter the elements for second matrix :\n";
    for(int i=0;i<o;i++)
     {   
	 for(int j=0;j<p;j++)
	 cin>>b[i][j];
     }
  cout<<"\n\nThe elememts of first matrix :\n";
    for(int i=0;i<m;i++)
     {   cout<<"\n";
	 for(int j=0;j<n;j++)
	 cout<<a[i][j]<<"\t";
     }
    cout<<"\n\nThe elements of second matrix :\n";
    for(int i=0;i<o;i++)
     {   cout<<"\n";
	 for(int j=0;j<p;j++)
	 cout<<b[i][j]<<"\t";
     }
     cout<<"\n\nThe sum of given matrix is :\n";
    for(int i=0;i<o;i++)
     {   cout<<"\n";
	 for(int j=0;j<p;j++)
	 cout<<(c[i][j]=a[i][j]+b[i][j])<<"\t";
     }
  cout<<"\n"; }
  else
    cout<<"\n ** The rows and columns of both the matrices should be same..! **\n";
}
/*
Function name : Difference
Variables     : m,n,o,p are the rows and columns of the matrices 'a' and 'b' respectively.
Purpose       : To print the difference of the given matrices.
*/
void matrix::difference()
{ 
  cout<<"\nEnter the no. of rows and columns for the first matrix :\n";
  cin>>m>>n;
  cout<<"\nEnter the no. of rows and columns for the second matrix :\n";
  cin>>o>>p;
  if((m==o)&&(n=p))
  {
    cout<<"\nEnter the elememts for first matrix :\n";
    for(int i=0;i<m;i++)
     {   for(int j=0;j<n;j++)
	 cin>>a[i][j];
	 
     }
    cout<<"\n\nEnter the elements for second matrix :\n";
    for(int i=0;i<o;i++)
     {   
	 for(int j=0;j<p;j++)
	 cin>>b[i][j];
     }
  cout<<"\n\nThe elememts of first matrix :\n";
    for(int i=0;i<m;i++)
     {   cout<<"\n";
	 for(int j=0;j<n;j++)
	 cout<<a[i][j]<<"\t";
     }
    cout<<"\n\nThe elements of second matrix :\n";
    for(int i=0;i<o;i++)
     {   cout<<"\n";
	 for(int j=0;j<p;j++)
	 cout<<b[i][j]<<"\t";
     }
     cout<<"\n\nThe difference of given matrix is :\n";
    for(int i=0;i<o;i++)
     {   cout<<"\n";
	 for(int j=0;j<p;j++)
	 cout<<(c[i][j]=a[i][j]-b[i][j])<<"\t";
     }
  cout<<"\n";}
  else
    cout<<"\n ** The rows and columns of both the matrices should be same..! **\n";
}
/*
Function name : Product
Variables     : m,n,o,p are the rows and columns of the matrices 'a' and 'b' respectively.
Purpose       : To print the multiplication of the given matrices.
*/
void matrix::product()
{ 
  cout<<"\nEnter the no. of rows and columns for the first matrix :\n";
  cin>>m>>n;
  cout<<"\nEnter the no. of rows and columns for the second matrix :\n";
  cin>>o>>p;
  if(n==o)
  {
    cout<<"\nEnter the elememts for first matrix :\n";
    for(int i=0;i<m;i++)
     {   for(int j=0;j<n;j++)
	 cin>>a[i][j];
	 
     }
    cout<<"\n\nEnter the elements for second matrix :\n";
    for(int i=0;i<o;i++)
     {   
	 for(int j=0;j<p;j++)
	 cin>>b[i][j];
     }
  cout<<"\n\nThe elememts of first matrix :\n";
    for(int i=0;i<m;i++)
     {   cout<<"\n";
	 for(int j=0;j<n;j++)
	 cout<<a[i][j]<<"\t";
     }
    cout<<"\n\nThe elements of second matrix :\n";
    for(int i=0;i<o;i++)
     {   cout<<"\n";
	 for(int j=0;j<p;j++)
	 cout<<b[i][j]<<"\t";
     }
/*      for(int i=0;i<n;i++)
     {   cout<<"\n";
	 for(int j=0;j<o;j++)
	 c[i][j]=0;
     } */
     cout<<"\n\nThe multiplication of given matrix is :\n";
    for(int i=0;i<m;i++)
     {   cout<<"\n";
	 for(int j=0;j<p;j++)
	   for(int k=0;k<n;k++)
	 c[i][j]+=a[i][k]*b[k][j];
     }
     for(int i=0;i<m;i++)
     { for(int j=0;j<p;j++)
	 cout<<c[i][j]<<"\t";
       cout<<endl;
     }
  cout<<"\n";}
  else
    cout<<"\n ** The column of the first matrix should be equals to rows of the second matrix..! **\n";
}
/*
Function name : Transpose
Variables     : m,n are the row and column of the matrix.
Purpose       : To print the transpose of the given matrix.
*/
void matrix::transpose()
{
  cout<<"\nEnter the no. of rows and columns for the matrix :\n";
  cin>>m>>n;
  cout<<"\n\nEnter the elements for the matrix :\n";
    for(int i=0;i<m;i++)
     {   
	 for(int j=0;j<n;j++)
	 cin>>a[i][j];
     }
  cout<<"\n\nThe given matrix is :\n";
    for(int i=0;i<m;i++)
     {   cout<<"\n";
	 for(int j=0;j<n;j++)
	 cout<<a[i][j]<<"\t";
     }
  cout<<"\n\nThe transpose of given matrix is :\n";
    for(int i=0;i<n;i++)
     {   cout<<"\n";
	 for(int j=0;j<m;j++)
	 cout<<a[j][i]<<"\t";
     } cout<<"\n";
}
int main()
{ int choice,p;
  cout<<"\n\t*\t*\t*\tMENU\t*\t*\t*\t:\n";
  cout<<"\nOperations you can apply on matrix:\n1.)Sum of two given matrices.\n2.)Difference of two given matrices.";
  cout<<"\n3.)Product of two given matrices.\n4.)Transpose of given matrix.\n5.)Exit\n";
  cout<<"Enter your choice : ";
  cin>>choice; 
  switch(choice)
  {
    case 1:
	   obj.sum();
	   break;
    case 2:
	   obj.difference();
	   break;
    case 3:	   
	   obj.product();
	   break;
    case 4:
	   obj.transpose();
	   break;
  /*  case 5:
	  exit();
	  break; */
    default : cout<<"\nYou have entered a wrong choice..!\n";
  }    
  return 0;
}
	   