#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<process.h>

using namespace std;

class D_Queue
{
	int *array;
	int length;
	int front;
	int rear;
  public :
  	D_Queue(int length);
  	void Enqueue(int element);
  	int Dequeue();
  	bool isFull();
  	bool isEmpty();
  	void Display();
};

D_Queue :: D_Queue(int len)
{
	length = len;
	array = new int[length];
	front = -1;
	rear = -1;
}

void D_Queue :: Enqueue(int element)
{
	int add,temp;
	cout<<"\nWhere you want to add..?\n1 )Front\n2 )Rear\n";
	cout<<"Enter the choice : ";
	cin>>add;
	char* msg;
	if(isFull())
	{
		msg = "Queue is Full.";
		throw msg;
	}
	else if(add == 2)
	{
		if(rear == length-1)
		{
			cout<<"\nElement can not be insert ( YOU ARE AT LAST LOCATION OF QUEUE ).\n";
		}
		else
		{
			rear++;
			array[rear] = element;
		}
	}
	else if(add == 1)
	{
		if(isEmpty())
		{
			front++;
			rear++;
			array[front] = element;
		}
		else
		{
			if(front == 0)
			{
				cout<<"\nElement can not insert ( YOU ARE AT FIRST LOCATION OF QUEUE ).\n";
			}
			else
			{
				front--;
				array[front] = element;
			}
		}
	}
}

int D_Queue :: Dequeue()
{
	int temp,del;
	cout<<"\nWhere you want to delete..?\n1 )Front\n2 )Rear\n";
	cout<<"Enter the choice : ";
	cin>>del;
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
	else if(del == 1)
	{
		temp = array[front];
		front++;
		return temp;
	}
	else
	{
		temp = array[rear];
		rear--;
		return temp;
	}
}

bool D_Queue :: isFull()
{
	if((rear == length-1)&&(front == -1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool D_Queue :: isEmpty()
{
	if((front == -1)&&(rear == -1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void D_Queue :: Display()
{
	cout<<"\nThe elements of Queue is :\n";
	for(int i = front ; i <= rear ; i++)
	{
		cout<<array[i]<<"\n";
	}
}
int main()
{
	int ele,size,t;
	char choice,ch;
	cout<<"\nEnter the size of Queue : ";
	cin>>size;
	D_Queue Q(size);
	do
	{
	cout<<"\n1 )ADD\n2 )DELETE\n3 )Display\n4 )Exit\n";
	cout<<"\nEnter the choice : ";
	choice = getche();
	switch(choice)
	{
		case '1' :
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
		case '2' :
				try
				{
					cout<<"\nDeleted element is : "<<Q.Dequeue();
				}
				catch(char* a)
				{
					cout<<a;
				}
		    	break;
		case '3' :
				Q.Display();
				break;
		case '4' : 
				exit(0);
		default : 
				cout<<"\nYou have entered a wrong choice..!\n";
	}
	cout<<"\nDo you want to continue..?\t";
	ch = getche();
	cout<<"\n";
	}
	while((ch == 'y')||(ch == 'Y'));
	return 0;
}
