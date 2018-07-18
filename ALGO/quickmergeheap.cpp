#include<iostream>
#include<cstdlib>
#include<time.h>

int m_count = 0;
int q_count = 0;
int h_count = 0;
int heapsize;

using namespace std;

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
	buildHeap(arr);
	for(int i = heapsize - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);
		heapsize--;
		maxHeapify(arr, 0);
	}
}


void merge(int*, int, int, int);
int partition(int*, int, int);

void mergeSort(int* arr, int left, int right)
{
   if(left < right)
   {
	int mid = (left + right)/2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
   }
}

void merge(int* arr, int left, int mid, int right)
{
    int size = right-left+1;
    int* arr2 = new int[size];
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right)
    {
	m_count++;
	if (arr[i] <= arr[j])
	{
		arr2[k] = arr[i];
		i++;
		k++;
	}
	else
	{
		arr2[k] = arr[j];
		j++;
		k++;
	}
    }

    while(i<=mid)
    {
	arr2[k] = arr[i];
	i++;
	k++;
    }

    while(j<=right)
    {
	arr2[k] = arr[j];
	j++;
	k++;
    }

    for(int k = 0, i = left; i <= right; i++, k++)
    {
	arr[i] = arr2[k];
    }
}

void quickSort(int* arr, int low, int high)
{
   if(low < high)
   {
	int p = partition(arr, low, high);
	quickSort(arr, low, p-1);
	quickSort(arr, p+1, high);
   }
}

int partition(int* arr, int left, int right)
{
	int pivot_index = (rand()%(right-left))+left;
	swap(arr[pivot_index], arr[left]);
	int pivot = arr[left];
	for(int i = pivot_index; i < right; i++)
	{
		q_count++;
		if(arr[i] < pivot)
		{
			swap(arr[i], arr[pivot_index]);
			pivot_index++;
		}
	}

	swap(arr[right], arr[pivot_index]);
   return pivot_index;
}

void swap(int& a, int& b)
{
  	int temp = a;
	a = b;
	b = temp;
}

int main()
{
   cout << "---------------------------------------------------------------------\n";
   cout << "| Size |" << "\t" << "| Merge Sort |" << " \t " << "| Quick Sort |" << "   " << "| Heap Sort |" <<  endl;   
   cout << "---------------------------------------------------------------------\n";	
	srand(time(NULL));
	
    for(int size = 50; size <= 500; size += 50)
    {
	heapsize = size;
	m_count = 0;
	q_count = 0;
	h_count = 0;
	int* arr = new int[size];
	int* arr2 = new int[size];
	int* arr3 = new int[size];
	for(int i = 0; i < size; i++)
	    arr[i] = rand()%100;
	//cout << "Generated Array : ";
	//for(int i = 0; i < size; i++)
	//	cout << arr[i] << " ";
	for(int i = 0; i < size; i++)
	    arr2[i] = arr[i];
	for(int i = 0; i < size; i++)
	    arr3[i] = arr[i];
	quickSort(arr, 0, size-1);
	mergeSort(arr2, 0, size-1);
	heapSort(arr3);
	//cout << "\nSorted Array : ";
	//for(int i = 0; i < size; i++)
	//	cout << arr[i] << " ";
	cout << size << " \t\t " << m_count << "\t\t " << q_count << " \t\t  " << h_count << endl;
    }
  return 0;
}
