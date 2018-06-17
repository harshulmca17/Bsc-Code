#include<iostream>

using namespace std;

void send(char , char , char , int );

int main()
{
	char a,b,c,ch;
	int disk;
	do
	{
		cout<<"\nEnter the no. of Disk : ";
		cin>>disk;
		cout<<"\nEnter the names of 3 poles :\n";
		cin>>a>>b>>c;
		send( a , b , c , disk );
		cout<<"\n**************************\n";
		cout<<"\nDo you want to continue..?\n";
		cin>>ch;
	}
	while((ch == 'y')||(ch == 'Y'));
	return 0;
}

void send(char from, char via, char to, int disks)
{
	if( disks == 1 )
	{
		cout<<"\nDisk no. 1 sent from "<<from<<" to "<<to<<".\n";
	}
	else
	{
		send(from, to, via, disks-1);
		cout<<"\nDisk no. "<<disks<<" sent from "<<from<<" to "<<to<<".\n";
		send(via, from, to, disks-1);
	}
}
