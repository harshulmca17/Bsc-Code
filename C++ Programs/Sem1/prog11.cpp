/* This program is to perform operations on array : 1)Print the even-valued 
						    2)Print the odd-valued 
                                                    3)Calculate and print the sum and average of the elements
                                                    4)Print the maximum and minimum elements of array
                                                    5)Remove the duplicants from the array
                                                    6)Print the array in reverse order */
#include<iostream>
#include<stdio.h>
using namespace std;
void print_even(int array[],int);
void print_odd(int array[],int);
void print_sum_avg(int array[],int);
void print_min_max(int array[],int);
void remove_duplicants(int array[],int);
void reverse(int array[],int);
int main()
{
  int choice,size,arr[50];
  cout<<"\n\n\t\tMENU";
  cout<<"\n\nThis program is to perform operations on array :\n1)Print the even-valued"; 
  cout<<"\n2)Print the odd-valued";
  cout<<"\n3)Calculate and print the sum and average of the elements";
  cout<<"\n4)Print the maximum and minimum elements of array";
  cout<<"\n5)Remove the duplicants from the array";
  cout<<"\n6)Print the array in reverse order";
  cout<<"\n7)Exit";
  cout<<"\nEnter the choice : ";
  cin>>choice;
  if(choice>=1 && choice<=6)
  {
    cout<<"\nEnter the size of array : \n";
    cin>>size;
    cout<<"\nNow enter the elements for the array :\n";
    for(int i=0;i<size;i++)
    {
      cin>>arr[i];
    }
    cout<<"\nThe entered array is :\n";
    for(int i=0;i<size;i++)
    {
      cout<<arr[i]<<"  ";
    }
  }
  cout<<"\n";
  switch(choice)
  {
    case 1:
	    print_even(arr,size);
	    break;
    case 2:
	    print_odd(arr,size);
	    break;
    case 3:
	    print_sum_avg(arr,size);
	    break;
    case 4:
	    print_min_max(arr,size);
	    break;
    case 5:
	    remove_duplicants(arr,size);
	    break;
    case 6:
	    reverse(arr,size);
	    break;
    case 7:
	    break;
  }
  cout<<"\n\n";
  return 0;
}
/* Function name : print_even
   Parameters    : array[] , n where array[] stores the elements entered by user and 'n' is the size of array.
   Purpose       : To print the even elements in array */ 
void print_even(int array[],int n)
{
  cout<<"\nThe even elements of array are :\n";
  for(int i=0;i<n;i++)
  {
    if(array[i]%2==0)
      cout<<array[i]<<"  ";
  }
}
/* Function name : print_odd
   Parameters    : array[] , n where array[] stores the elements entered by user and 'n' is the size of array.
   Purpose       : To print the odd elements in array */
void print_odd(int array[],int n)
{
  cout<<"\nThe odd elements of array are :\n";
  for(int i=0;i<n;i++)
  {
    if(array[i]%2==0);
    else
      cout<<array[i]<<"  ";
  }
}
/* Function name : print_sum_avg
   Parameters    : array[] , n where array[] stores the elements entered by user and 'n' is the size of array.
   Purpose       : To print the sum and average of the elements in array */
void print_sum_avg(int array[],int n)
{
  int sum=0,average=0;
  for(int i=0;i<n;i++)
  {
    sum=sum+array[i];
  }
  average=sum/n;
  cout<<"\nThe sum and average of the elements of the array are "<<sum<<" and "<<average<<" .";
}
/* Function name : print_min_max
   Parameters    : array[] , n where array[] stores the elements entered by user and 'n' is the size of array.
   Purpose       : To print the minimum and maximum element in array */
void print_min_max(int array[],int n)
{
  int minimum=array[0],maximum=array[0];
  for(int i=0;i<n;i++)
  {
    if(minimum>=array[i])
      minimum=array[i];
  }
    for(int i=0;i<n;i++)
  {
    if(maximum<=array[i])
      maximum=array[i];
  }
  cout<<"\nThe minimum and maximum of the elements of the array are "<<minimum<<" and "<<maximum<<" .";
}
/* Function name : remove_duplicants
   Parameters    : array[] , n where array[] stores the elements entered by user and 'n' is the size of array.
   Purpose       : To remove the duplicate elements from array */
void remove_duplicants(int array[],int n)
{  
    for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(array[i]==array[j])
      {
	for(int k=j;k<n;k++)
	    array[k]=array[k+1];
	    n--;
	    j--;
      }
    }
  }
  cout<<"\nThe required array is :\n";
  for(int k=0;k<n;k++)
    cout<<array[k]<<" ";
}                                                                                
/* Function name : reverse
   Parameters    : array[] , n where array[] stores the elements entered by user and 'n' is the size of array.
   Purpose       : To print the array in reverse order */
void reverse(int array[],int n)
{
  cout<<"\nThe array in reverse order is :\n";
  for(int i=n-1;i>=0;i--)
  {
    cout<<array[i]<<"  ";
  }
}