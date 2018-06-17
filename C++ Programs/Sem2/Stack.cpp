#include<iostream>

using namespace std;

class Stack
{
	int *array;
	int top;
	int length;
	public :
		Stack(int length1 = 0)
		{
				top = -1;
				length = length1;
				array = new int[length];
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
		void push(int element)
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
		
		int pop()
		{
			int i;
			if(isEmpty())
			{
				i = -111;
			}
			else
			{
				i = array[top];
				top--;
			}
			return i;
		}
		int elementAtTop()
		{
			int i;
			if(isEmpty())
			{
				i = 111;
			}
			else
			{
				i = array[top];
			}
			return i;
		}
		void clearStack()
		{
			top = -1;
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
	int choice,ele,len,i,j;
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
    Stack s1(len);
	do{
	cout<<"\nMENU:\n1 )Push the element.\n2 )Pop the element.\n3 )Element at top.\n4 )Display the elements of Stack.\n5 )Clear the Stack.\n";
	cout<<"\nEnter the choice :\n";
	cin>>choice;
	switch(choice)
	{
		case 1 :
			cout<<"\nEnter the element : ";
			cin>>ele;
			s1.push(ele);
			break;
		case 2 :
			a = s1.pop();
			 if(a!=-111)
					cout<<"Popped element is : "<<a;
		     else 
					cout<<"\nStack is Empty.";
			break;
		case 3 :
			 j = s1.elementAtTop();
			cout<<"\nThe element at top is : "<<j;
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
