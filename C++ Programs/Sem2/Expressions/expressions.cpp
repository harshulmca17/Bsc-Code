#include<iostream>
#include<string.h>
#include<conio.h>
#include"int_stack.h"

using namespace std;

char * infix_to_prefix(char* , int);
char * prefix_to_infix(char* , int);
char * infix_to_postfix(char* , int);
char * postfix_to_infix(char* , int);
void evaluate(char* , int);
bool isoperand( char );
bool isoperator(char );
bool checkhigher(char , char );

class Stack
{
	char *array;
	int length;
	public :
		int top;
		Stack(int length1 = 0)
		{
				top = -1;
				length = length1;
				array = new char[length];
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
		void push(char element)
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
		
		char pop()
		{
			int i ;
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
		char elementAtTop()
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
	char * infix = new char[20];
	char * prefix = new char[20];
	char * postfix = new char[20];
	char ch,choice;
	int length;
	do
	{
	cout<<"\nMENU : \n1 ) Infix to Prefix.\n2 ) Prefix to Infix.\n3 ) Infix to Postfix.\n4 ) Postfix to Infix.\n5 ) Postfix evaluation.\n";
	cout<<"\nEnter the choice : ";
	choice = getch();
	switch(choice)
	{
		case '1' :	cout<<"Enter the infix expreesion :  ";
					cin>>infix;
					length = strlen(infix);
					cout<<"Prefix is :  "<<infix_to_prefix( infix ,length );
					break;
		case '2' :    cout<<"\nEnter the prefix expression :  ";
					cin>>prefix;
					length = strlen(prefix);
					cout<<"Infix is :  "<<prefix_to_infix( prefix , length );
					break;
		case '3' :    cout<<"\nEnter the infix expression :  ";
					cin>>infix;
					length = strlen(infix);
					cout<<"Postfix is :  "<<infix_to_postfix( infix , length );
					break;
		case '4' :    cout<<"\nEnter the postfix expression :  ";
					cin>>postfix;
					length = strlen(postfix);
					cout<<"Infix is :  "<<postfix_to_infix( postfix , length );
					break;
		case '5' :	cout<<"\nEnter the postfix expression :  ";
					cin>>postfix;
					length = strlen(postfix);
					cout<<"\nEntered expression is :  "<<postfix;
					evaluate( postfix , length );
					break;
		default :	cout<<"\nYou have entered a wrong choice..!\n";
	}
		cout<<"\nDo you want to continue..?\n";
		cin>>ch;
	}while((ch == 'y')||(ch == 'Y'));
	return 0;
}
char * infix_to_prefix(char* infix, int length)
{
	Stack operandObj(length);
	Stack operatorObj(length/2);
	for(int i = length-1; i >=0 ; i-- )
	{
		if(isoperand(infix[i]))
		{
			operandObj.push(infix[i]);
		}
		else 
		{
			if(isoperator(infix[i]))
			{
				if(operatorObj.isEmpty())
				{
					operatorObj.push(infix[i]);
				}
				else 
				{
					if(checkhigher(infix[i],operatorObj.elementAtTop()))
					{
						operatorObj.push(infix[i]);
					}
					else
					{
						do
						{
							operandObj.push(operatorObj.pop());
						}
						while((!operatorObj.isEmpty()) && (!checkhigher(infix[i], operatorObj.elementAtTop())));
						operatorObj.push(infix[i]);
					}
				}
			}
		}
	}
	while(!operatorObj.isEmpty())
	{
		operandObj.push(operatorObj.pop());
	}
	char* prefix = new char[length];
	int i = 0;
	while(!operandObj.isEmpty())
	{
		prefix[i++] = operandObj.pop();
	}
	prefix[i] = '\0';
	return prefix;
}
char * prefix_to_infix(char* prefix, int length )
{
	Stack operandObj(length);
	Stack operatorObj(length/2);
	for(int i = 0 ; i < length ; i++)
	{
		if(isoperand(prefix[i]))
		{
			operandObj.push(prefix[i]);
			if(!operatorObj.isEmpty())
			{
				operandObj.push(operatorObj.pop());
			}
		}
		else
		{
			operatorObj.push(prefix[i]);
		}
	}
	while(!operatorObj.isEmpty())
	{
		operandObj.push(operatorObj.pop());
	}
	char* infix = new char[length];
	int i = length-1;
	while(!operandObj.isEmpty())
	{
		infix[i--] = operandObj.pop();
	}
	infix[length] = '\0';
	return infix;
}
char * infix_to_postfix(char* infix, int length)
{
	Stack operandObj(length);
	Stack operatorObj(length/2);
	for(int i = 0 ; i < length ; i++)
	{
		if(isoperand(infix[i]))
		{
			operandObj.push(infix[i]);
		}
		else
		{
			if(operatorObj.isEmpty())
			{
				operatorObj.push(infix[i]);
			}
			else
			{
				if(checkhigher(infix[i],operatorObj.elementAtTop()))
				{
					do
					{
						operandObj.push(operatorObj.pop());
					}
					while((!operatorObj.isEmpty()) && (!checkhigher(infix[i], operatorObj.elementAtTop())));
					operatorObj.push(infix[i]);
				}
				else
					{
						operatorObj.push(infix[i]);
					}
			}
		}
	}
	while(!operatorObj.isEmpty())
	{
		operandObj.push(operatorObj.pop());
	}
	char* postfix = new char[length];
	int i = length-1;
	while(!operandObj.isEmpty())
	{
		postfix[i--] = operandObj.pop();
	}
	postfix[length] = '\0';
	return postfix;
}
char * postfix_to_infix(char* postfix, int length )
{
	Stack operandObj(length);
	Stack operatorObj(length/2);
	for(int i = length-1 ; i >= 0 ; i--)
	{
		if(isoperand(postfix[i]))
		{
			operandObj.push(postfix[i]);
			if(!operatorObj.isEmpty())
			{
				operandObj.push(operatorObj.pop());
			}
		}
		else
		{
			operatorObj.push(postfix[i]);
		}
	}
	while(!operatorObj.isEmpty())
	{
		operandObj.push(operatorObj.pop());
	}
	char* infix = new char[length];
	int i = 0;
	while(!operandObj.isEmpty())
	{
		infix[i++] = operandObj.pop();
	}
	infix[i] = '\0';
	return infix;
}
void evaluate(char* postfix, int length)
{
	int i,j,k,l;
	int result = 0;
	Stack operandObj(length);
	intStack Obj(length);
	for(int i =0 ; i < length ; i++)
	{
		if(isoperand(postfix[i]))
		{
			cout<<"\nEnter an value : ";
			cin>>l;
			Obj.push(l);
		}
		else
		{
			j = Obj.pop();
			k = Obj.pop();
			if(postfix[i] == '+')
			{
				result = j + k;
				Obj.push(result);
			}
			else if(postfix[i] == '-')
			{
				result = j - k;
				Obj.push(result);
			}
			else if(postfix[i] == '*')
			{
				result = j * k;
				Obj.push(result);
			}
			else if(postfix[i] == '/')
			{
				result = j / k;
				Obj.push(result);
			}
		}
	}
	cout<<"\nResult is : "<<Obj.pop();
}
bool isoperand( char c )
{
	if((c>='a' && c<='z')||(c>='A' && c<='Z'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool isoperator(char c)
{
	if((c == '+')||(c == '-')||(c == '/')||(c == '*'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool checkhigher(char op1, char op2)
{
	if(((op1 == '+')||(op1 == '-')) && ((op2 == '+')||(op2 == '-')))
	{
		return true;
	}
	else if(((op1 == '*')||(op1 == '/')) && ((op2 == '*')||(op2 == '/')))
	{
		return true;
	}
	else if(((op1 == '+')||(op1 == '-')) && ((op2 == '*')||(op2 == '/')))
	{
		return false;
	}
	else 
	{
		return true;
	}
}
/*
{
	if(op1 == '*' || op1 == '/')
	retrun true;
	else if((op2 == '+')||(op2 == '-'))
	return true;
	else 
	return true;
}
*/

