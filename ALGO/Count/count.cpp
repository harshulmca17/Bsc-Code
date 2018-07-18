
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
 
void counting_sort(int *A, int k, int n)
{
    int i, j;
    int *B, *C;
    B = new int [n];
    C = new int [k];
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    cout<<"\nThe Sorted array is : ";
    for (i = 1; i <= n; i++)
        cout<<B[i]<<" ";
}

int main()
{
    int n, max = 0, *arr, i;
    cout<<"\nEnter size of the array : ";
    cin>>n;
    arr = new int [n];
    cout<<"\nEnter the elements to be sorted :\n";
    for (i = 1; i <= n; i++)
    {
        cin>>arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    counting_sort(arr, max, n);
    cout<<"\n";
    return 0;
}