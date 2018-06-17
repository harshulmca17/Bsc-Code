#include<iostream>
#include"Cqueue.h"
#include"double_ended.h"
#include"Queue.h"

using namespace std;

void queue();
void Cqueue();
void Dqueue();

int main()
{
	int choice;
	char ch;
	do
	{
		cout<<"\nMENU :\n1 )Simple Queue.\n2 )Circular Queue.\n3 )Double-ended Queue.\nEnter the choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1 : 
					queue();
					break;
			case 2 :
					Cqueue();
					break;
			case 3 :
					Dqueue();
					break;
			default : 
					cout<<"\nWrong choice..!";
		}
		cout<<"\nDo you want to continue..? ( Y/N )\n";
		cin>>ch;
	}
	while((ch == 'y')||(ch == 'Y'));
	return 0;
}

void queue()
{
	int choice,size,t;
	char ch,ele;
	cout<<"\nEnter the size of Queue : ";
	cin>>size;
	Queue <char> Q(size);
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
}
void Cqueue()
{
	int choice,size,t;
	char ch,ele;
	cout<<"\nEnter the size of Queue : ";
	cin>>size;
	CircularQueue <char> Q(size);
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
}

void Dqueue()
{
	int choice,size,t;
	char ch,ele;
	cout<<"\nEnter the size of Queue : ";
	cin>>size;
	D_Queue <char> Q(size);
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
}
