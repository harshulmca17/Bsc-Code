#include<iostream>
#include<cstdlib>
using namespace std;
float lsearch(int*,int);
float bsearch(int*,int);
int linearsearch(int*,int,int);
int binarysearch(int*,int,int);
void insert(int*,int);
int lcount=0, bcount=0;
int main()
{
  int size=500,*arr;
/*  cout<<"Enter the size:\t";
  cin>>size;*/
  arr= new int[size];
  insert(arr,size);
  cout<<"\n---------------------Table Search---------------------\n";
  cout<<"\n\nElements(Size)\t\tLinear\t\tBinary\n\n";

  for(int i=50; i<=500; i+=50) 
  { 
    lcount=0;
    bcount=0;
    cout<<i<<"\t\t\t"<<lsearch(arr,i)<<"\t\t"<<bsearch(arr,i)<<"\n\n";
  }
  return 0;
}
void insert(int *arr,int size)
{
  cout<<"Enter "<<size<<" values:\n";
  for(int i=0; i<size; i++)
    arr[i]=(rand());
  return;
}
float lsearch(int *arr,int size)
{
  for(int i=0; i<size; i++)
  {
    int a=linearsearch(arr,size,arr[i]);
  }
  return ((float)lcount/size);
}
float bsearch(int *arr,int size)
{
  for(int i=0; i<size; i++)
  {
    int a=binarysearch(arr,size,arr[i]);
  }  
  return ((float)bcount/size);
}
int linearsearch(int *arr,int size,int element)
{
  int i;
  for(i=0; i<size && arr[i]!=element; i++)
    lcount++;
  return i;
}
int binarysearch(int *arr,int size,int element)
{
  int l=0, u=size-1,mid;
  while(l<=u)
  {
    bcount++;
    mid=(l+u)/2;
    if(arr[mid]==element)
      return mid;
    else if(arr[mid]>element)
      u=mid-1;
    else
      l=mid+1;
  }
  return -1;
}
