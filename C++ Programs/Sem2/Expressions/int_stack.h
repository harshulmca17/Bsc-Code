#include<iostream>

using namespace std;

class intStack
{
	int *array;
	int top;
	int length;
	public :
		intStack(int length1 = 0)
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
