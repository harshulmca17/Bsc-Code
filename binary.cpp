#include<iostream>
#include<cstdlib>

using namespace std;

float avg_linear_comparison_count=0,avg_binary_comparison_count=0;
int linear_comparison_count=0,binary_comparison_count=0;
int *array;

int linear_search(int* array,int size,int ele){

	for(int i=0;i<size;i++){
		
		if(array[i] == ele)
		{
			return i;
		}

	}
	return -1;

}
int binary_search(int* array,int size,int ele ){



}

void bubble_sort(int* arr, int size)
{
	for(int i = 1; i < size ; i++)
	{
	   for (int j = 0; j< size-i; j++)
	   {
		if(arr[j] > arr[j+1])
		{
		    int temp = arr[j];
		    arr[j] = arr[j+1];
		    arr[j+1] = temp;
		}
	   }
	 }  
}


int main(){
	int size ;
	cout<<"\nEnter size for the array : ";
	cin>>size;
	array = new int[size];

	for(int i =0; i< size ; i++){
		array[i] = rand()%(size*2) ;
	}

	for(int i =0; i< size ; i++){
		cout<<array[i]<<" ";
	}

}