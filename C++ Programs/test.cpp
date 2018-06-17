#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void encrypt(char msg[])
{
	int i;
  for( i=0;msg[i]!='\0';i++)
  {
  	msg[i] = msg[i]+3;
	  }	
	  msg[i]='\0';
	cout<<"\nEncrypted message is : "<<msg;
	  
}
void decrypt(char msg[])
{
	int i;
  for( i=0;msg[i]!='\0';i++)
  {
  	msg[i] = msg[i]-3;
	  }	
	  msg[i]='\0';
	 // cout<<"\nDecrypted message is : "<<msg;
	  return;
}
int main()
{
	int i = 0;
	char* input = new char[7];
	char pass[] = "wsjibo";
	cout<<"Enter password : ";
	input[i] = getch();
	while(input[i] != 13)
	{
		i++;
		cout<<"*";
		input[i] = getch();
	}
	input[i]='\0';
	encrypt(pass);
	if(strcmp(input,pass)==0)  cout<<"\nDone !";
	else cout<<"\nWrong";
	return 0;
}
