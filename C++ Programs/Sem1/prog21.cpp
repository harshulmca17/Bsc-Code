#include<iostream>

using namespace std;

class Person
{

	protected:
		char name[25];
		int age;
	public:
		virtual void printData()
		{
			cout << "Name: " << name << "\n";
			cout << "Age: " << age << "\n";
			return;
		}
		virtual void inputData()
		{
			cout << "Please enter your name: ";
			cin >> name;
			cout << "Please enter your age: ";
			cin >> age;
			return;
		}
};


class Teacher : public Person
{
	protected:
		int tID;
	public:
		void printData()
		{
			Person :: printData();
			cout << "Teacher ID: " << tID << "\n";
			return;
		}
		void inputData()
		{
			Person :: inputData();
			cout << "Please enter teacher ID: ";
			cin >> tID;
			return;
		}
};

class Student : public Person
{
	protected:
		int sID;
	public:
		void printData()
		{
			Person :: printData();
			cout << "Student ID: " << sID << "\n";
			return;
		}
		void inputData()
		{
			Person :: inputData();
			cout << "Please enter student ID: ";
			cin >> sID;
			return;
		}
};


int main()
{
	Person *ptr;
	int Choice;

	while( 1 )
	{
		cout << "\n\nPlease enter your choice....\n\t1 - Enter details of a person.\n\t2 - Enter details of a teacher.\n\t3 - Enter details of a student.\n\n";
		cin >> Choice;
		
		switch( Choice )
		{
			case 1:
			{
				ptr = new Person;
				ptr -> inputData();
				cout << "\nEntered data:-\n";
				ptr -> printData();
				delete ptr;
				break;
			}
			case 2:
			{
				ptr = new Teacher;
				ptr -> inputData();
				cout << "\nEntered data:-\n";
				ptr -> printData();
				delete ptr;
				break;
			}
			case 3:
			{
				ptr = new Student;
				ptr -> inputData();
				cout << "\nEntered data:-\n";
				ptr -> printData();
				delete ptr;
				break;
			}
		}
	}
	return 0;
}
