#include<iostream>
#include<cstdlib>

using namespace std;

float avg_l_count = 0;
float avg_b_count = 0;   
int l_count = 0;
int b_count = 0;

int linearSearch(int* arr, int size, int ele)
{
	for(int i = 0; i < size; i++)
	{
	   l_count++;
	   if (arr[i] == ele)
	   return i;
	}
	   return -1;	
}

void bubbleSort(int* arr, int size)
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

int binarySearch(int* arr, int size, int ele)
{
	int low = 0;
	int high = size-1;
	int mid;

	while(low <= high)
	{
	   b_count++;
	   mid = (low + high)/2;
	   if(arr[mid] == ele)
		return mid;
	   
	   else if(arr[mid] < ele)
		low = mid+1;

	   else
		high = mid-1;
	 }
        return -1;
}

int main()
{
   cout << "---------------------------------------------------------\n";
   cout << "| Size |" << "\t" << "| Linear Search |" << " \t " << "| Binary Search |" << endl;   
   cout << "---------------------------------------------------------\n";

   for(int size = 50; size <= 500; size += 50)
   {
	l_count = 0;
	b_count = 0;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	  arr[i] = rand();

	for(int i = 0; i < size; i++)
	  linearSearch(arr, size, arr[i]);
	  avg_l_count = (float)(l_count)/size;
 	 
	 bubbleSort(arr, size);

	for( int j = 0; j < size; j++)
	  binarySearch(arr, size, arr[j]);
	  avg_b_count = (float)b_count/size;

	cout << " " << size << "\t\t" << avg_l_count << "\t\t\t\t" << avg_b_count << endl;
    }
	cout << endl;
 return 0;
}
