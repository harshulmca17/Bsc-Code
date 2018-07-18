#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int s_count = 0;
int i_count = 0;
int b_count = 0;


void bubbleSort(int* arr, int size)
{
	for(int i = 1; i < size ; i++)
	{
	   for (int j = 0; j< size-i; j++)
	   {
		b_count++;		
  		if(arr[j] > arr[j+1])
		{ 
		  swap(arr[j], arr[j+1]);
		}
	   }
	 }  
}


void selectionSort(int* arr, int size)
{
	for(int i = 0; i < size; i++)
	{
	   int min = i;
	   for (int j = i + 1; j < size; j++)
	   {
		s_count++;
		if(arr[j] < arr[min])
		{
		  min = j;
		}
	   }
	swap(arr[i], arr[min]);
	}
}

void insertionSort(int* arr, int size)
{
	for(int i = 1; i < size; i++)
	{
	   int j = i;
	   int temp = arr[j];
          while(j > 0 && temp < arr[j-1])
	   {
	        i_count++;
		arr[j] = arr[j-1];
		j--;
	   }

	   arr[j] = temp;
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
   cout << "---------------------------------------------------------------------------------------------------------\n";
   cout << "| Size |" << "\t" << "| Insertion Sort |" << " \t " << "| Selection Sort |" << " \t " << "| Bubble Sort | " << endl;   
   cout << "---------------------------------------------------------------------------------------------------------\n";

   srand(time(NULL));
   for(int size = 50; size <= 500; size += 50)
   {
	i_count = 0;
	b_count = 0;
	s_count = 0;
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	arr[i] = rand();

	int* arr2 = new int[size];
	int* arr3 = new int[size];

	for (int i = 0; i < size; i++)
	{
	  arr2[i] = arr[i];
	  arr3[i] = arr[i];
	}

	insertionSort(arr, size);
 	bubbleSort(arr2, size);
	selectionSort(arr3, size);

	cout << " " << size << "\t\t" << i_count << "\t\t\t\t" << s_count << "\t\t" << b_count << endl;										 
    }
	cout << endl;
 return 0;
}
