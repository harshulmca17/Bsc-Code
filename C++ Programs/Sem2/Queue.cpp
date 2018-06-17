#include<iostream>
#include<stdio.h>

using namespace std;

class Queue
{
	int *array;
	int length;
	int front;
	int rear;
  public :
  	Queue(int length);
  	void Enqueue(int element);
  	int Dequeue();
  	bool isFull();
  	bool isEmpty();
  	void Display();
};

Queue :: Queue(int len)
{
	length = len;
	array = new int[length];
	front = -1;
	rear = -1;
}

void Queue :: Enqueue(int element)
{
	char* msg;
	if(isFull())
	{
		msg = "Queue is Full.";
		throw msg;
	}
	else if(front == -1)
	{
		front = 0;
		rear = 0;
		array[rear] = element;
	}
	else
	{
		rear++;
		array[rear] = element;
	}
}

int Queue :: Dequeue()
{
	int temp;
	char* msg;
	if(isEmpty())
	{
		msg = "Queue is Empty.";
		throw msg;
	}
	else if(front == rear)
	{
		temp = array[rear];
		front = -1;
		rear = -1;
		return temp;
	}
	else
	{
		temp = array[front];
		front++;
		return temp;
	}
}

bool Queue :: isFull()
{
	if(rear == length-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Queue :: isEmpty()
{
	if(front == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Queue :: Display()
{
	cout<<"\nThe elements of Queue is :\n";
	for(int i = front ; i <= rear ; i++)
	{
		cout<<array[i]<<"\n";
	}
}
int main()
{
	int choice,ele,size,t;
	char ch;
	cout<<"\nEnter the size of Queue : ";
	cin>>size;
	Queue Q(size);
	do
	{
	cout<<"\n1 )ADD\n2 )DELETE\n3 )Display\n4 )Exit\n";
	cout<<"\nEnter the choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1 :
				try
				{
					cout<<"\nEnter the element : ";
					cin>>ele;
					Q.Enqueue(ele);
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 2 :
				try
				{
					cout<<"\nDeleted element is : "<<Q.Dequeue();
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case 3 :
				Q.Display();
				break;
		case 4 : 
				break;
		default : 
				cout<<"\nYou have entered a wrong choice..!\n";
	}
	cout<<"\nDo you want to continue..?\n";
	cin>>ch; }
	while((ch == 'y')||(ch == 'Y'));
	return 0;
}
