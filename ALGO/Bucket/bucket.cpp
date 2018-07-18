#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;
 
int maxl(int *arr,int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
            if(max<arr[i])
            {
                max = arr[i];
            }
    }
    return (max+1);
}
void bucket_sort (int *arr, int n)
{
  int m = maxl(arr,n);
  int buckets[m];
  for (int i = 0; i < m; ++i)
    buckets[i] = 0;
  
  for (int i = 0; i < n; ++i)
    ++buckets[arr[i]];
 
  for (int i = 0, j = 0; j < m; ++j)
    for (int k = buckets[j]; k > 0; --k)
      arr[i++] = j;
}

int main()
{
    system("clear");
    int *arr,n;
    cout<<"\nEnter the size of the array:";
    cin>>n;
    arr = new int [n];
    cout<<"\nEnter the elements in the array:";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    bucket_sort (arr,n);
 
    cout << "Sorted Array : " << endl;	
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";	 
    return 0;
}