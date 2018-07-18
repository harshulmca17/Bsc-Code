#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int heapsize;
int h_count = 0;

void swap(int& a, int& b)
{
  	int temp = a;
	a = b;
	b = temp;
}

void maxHeapify(int* arr, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = 0;
	h_count++;
	if((left <= (heapsize - 1)) && (arr[left] > arr[i]))
		largest = left;
	else
		largest = i;
	h_count++;
	if ((right <= (heapsize - 1)) && (arr[right] > arr[largest]))
		largest = right;

	if (largest!=i)
	{
		swap(arr[i], arr[largest]);
		maxHeapify(arr, largest);
	}
}


void buildHeap(int* arr)
{
	for(int i = (heapsize-1)/2; i >= 0; i--)
		maxHeapify(arr, i);
}


void heapSort(int* arr)
{
	//cout << "HEAPSORT\n";
	int n = heapsize;
	buildHeap(arr);
	for(int i = heapsize - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);
		heapsize--;
		maxHeapify(arr, 0);
	}

	heapsize = n;
}

int main()
{
	h_count = 0;	
	srand(time(NULL));
	cout << "---------------------------------------\n";
	cout << "| Size |" << "\t" << "| Heap Sort |" << endl;   
	cout << "---------------------------------------\n";	
	for (int size = 50; size <=500; size+=50)
	{
	heapsize = size;
	int* arr = new int[size];
	for(int i = 0; i < size; i++)
		arr[i] = random() % 100;

	heapSort(arr);

	cout << size << "\t\t" << h_count << endl;
	}

return 0;
}
