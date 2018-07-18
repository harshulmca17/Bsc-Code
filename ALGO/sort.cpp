#include<iostream>
#include<cstdlib>
#include<random>
#include<cstdio>
#define int bsort 0
#define int ssort 0
#define int isort 0
using namespace std;


int bubble_Sort(int *arr,int s)
{
    bsort=0;
    for(int i=0;i<=s-1;i++)
    {   
            bsort++;
            if(arr[i]<arr[i+1])
            {
             
                    int temp;
                    temp=arr[i+1];
                    arr[i+1]=arr[i];
                    arr[i]=temp;
            }
        
    }
    return bsort;
}
int selection_Sort(int *a,int n)
{
    ssort=0;
    for(int i=0;i<=n-1;i++)
    {
        int min_index=i;
        int min=a[i];
        for(int j=i+1;j<=n-1;j++)
        {
            ssort++;
                if(a[j]<min)
                {
                    min=a[j];
                    min_index=j;
                }
        }
        int temp=a[i];
        a[i]=a[min_index];
        a[min_index]=temp;            
    }
    return ssort;
}

int insertion_Sort(int *a,int n)
{        
    isort=0;
    for (i = 1; i < 16; i++)
        {
            
            for (j = i; j >= 1; j--)
            {
                isort++;
                if (a[j] < a[j-1])
                {
                    temp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = temp;
                }
                else
                    break;
            }
        }
        return isort;
}
int main()
{
    srand();
    int size=50,*arr,*arr1,*arr2,*arr3,*arr4,*arr5,*arr6;
    cout<<"\nEnter the run cycles of the program:-";
    cin>>n;
    for (int i=0;i<=n;i++)
    {
        
        arr = new int [size];
        arr1 = new int [size];
        arr2 = new int [size];
        arr3 = new int [size];
        arr4 = new int [size];
        arr5 = new int [size];
        arr6 = new int [size];
        
        for(int k=0;k<6;k++)
        {
            for(int j=0;j<size;j++)
            {
                    arr[j]=rand()%(rand()%50);
            }
            switch (k)
            {
                case 1 : arr1=arr;
                            break;
                case 2 : arr2=arr;
                            break;
                case 3 : arr3=arr;
                            break;
                case 4 : arr4=arr;
                            break;
                case 5 : arr5=arr;
                            break;
                case 6 : arr6=arr;
                            break;
            }
        }
        
        bubble_Sort(arr1,size);
        insertion_Sort(arr2,size);
        selection_Sort(arr3,size);
        heap_Sort(arr4,size);
        merge_sort(arr5,size);
        quick_Sort(arr6,size);
        
    }
    
}
