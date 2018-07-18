#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;


int i,j;
void quick(int *a,int l,int u)
{
    int p,temp;
    if(l<u)
    {
        p=a[l];
        i=l;
        j=u;
        while(i<j)
        {
            while(a[i] <= p && i<j )
                i++;
            while(a[j]>p && i<=j )
                j--;
            if(i<=j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[j];
        a[j]=a[l];
        a[l]=temp;
        cout <<"\n";
        //for(i=0;i<10;i++)
         //   cout <<a[i]<<" ";
        quick(a,l,j-1);
        quick(a,j+1,u); 
    }
}
int main()
{
    int *a,l,u,n;
    system("clear");
    
    cout<<"\nEnter size of the array:";
    cin>>n;
    a = new int [n];
    cout <<"\nEnter elements";
    for(i=0;i<n;i++)
        cin >> a[i];
    l=0;
    u=n-1;
    quick(a,l,u);
    cout <<"\nsorted elements\n
    ";
    for(i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
 
