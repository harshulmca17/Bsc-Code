#include<iostream>

using namespace std;

template <class T>
class Stack
{
	T *array;
	int top;
	int length;
	public :
		Stack(int length1 = 0)
		{
				top = -1;
				length = length1;
				array = new T[length];
		}
		bool isEmpty()
		{
			if(top != -1)
				return false;
			else
				return true;
		}
		bool isFull()
		{
			if( top != (length-1))
				return false;
			else
				return true;
		}
		T get()
		{
			T m;
			cin>>m;
			return m;
		}
		void push(T element)
		{
			if(isFull())
			{
				cout<<"Stack is full.";
			}
			else
			{
				top++;
				array[top] = element;
			}
		}
		
		T pop()
		{
			T i ;
			char* msg;
			if(isEmpty())
			{
			  msg = " Stack is Empty. ";
			  throw msg;
			}
			else
			{
				i = array[top];
				top--;
			}
			return i;
		}
		T elementAtTop()
		{
			char* msg;
			if(isEmpty())
			{
			 msg = " Stack is Empty. ";
			 throw msg;
			}
			else
			{
			 	return array[top];
			}
		}
		void clearStack()
		{
			top = -1;
			cout<<"\nStack Cleared..!\n";
		}
		void display()
		{
			if(isEmpty())
			{
				cout<<"\nStack is Empty.";
			}
			else
			{
				cout<<"\nSTACK IS :\n";
				for(int i = top ; i >= 0 ; i--)
				{
					cout<<array[i]<<"\n";
				}
			}
		}
};
int main()
{
	int choice,len;
	char ch;
	do
	{
	
	cout<<"\nEnter the length of the Stack :";
	cin>>len;
	if(len < 1)
	 {
	 	cout<<"\nEnter valid length.";
	 }
	}while(len<1);
	Stack <int> s1(len);
	do{
	cout<<"\nMENU:\n1 )Push the element.\n2 )Pop the element.\n3 )Element at top.\n4 )Display the elements of Stack.\n5 )Clear the Stack.\n";
	cout<<"\nEnter the choice :\n";
	cin>>choice;
	switch(choice)
	{
		case 1 :
				cout<<"\nEnter the element : ";
				s1.push(s1.get());
			break;
		case 2 :
			try
			{
				cout<<"Popped element is : "<<s1.pop();
			}
			catch(char* a)
			{
				cout<<a;
			}
		    break;
		case 3 :
			try
			{
				cout<<"\nThe element at top is : "<<s1.elementAtTop();
			}
			catch(char* a)
			{
				cout<<a;
			}
			break;
		case 4 :
			s1.display();
			break;
		case 5 :
			s1.clearStack();
			break;
		default : 
		cout<<"\nWrong Choice...!";
	}
	cout<<"\nDo you want to continue..?(Y/N)\n";
	cin>>ch;
	}
	while(( ch == 'Y' )||( ch == 'y'));
	return 0;
}
