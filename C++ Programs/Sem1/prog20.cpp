#include<iostream>

using namespace std;

class Length
{
	float feet, inch;

	public:

		void Input()
		{

			cout << "Please enter length in feet: ";
			cin >> feet;
			cout << "Plase enter length in inches: ";
			cin >> inch;
			if ( ( feet < 0 ) || ( inch < 0 ) )
			{
				cout << "Length should not be less than 0..!!\n";
				Input();
			}
			return;
		}
		void Print()
		{
			cout << "\nFeet: " << feet ;
			cout << "\nInches: " << inch << "\n";
		}
		Length operator+( Length obj )
		{
			Length tmp;
			tmp.feet = feet + obj.feet;
			tmp.inch = inch + obj.inch;
			return tmp;
		}
		Length operator-( Length obj )
		{
			Length tmp;
			tmp.feet = feet - obj.feet;
			tmp.inch = inch - obj.inch;
			if( tmp.inch < 0.0 )
			{
				
				tmp.feet = tmp.feet - 1.0;
				tmp.inch = 12 - obj.inch;
				if( tmp.feet < 0 )
				{	
					tmp.feet = 0;
					tmp.inch = 0;
				} 
			}
			return tmp;
		}
};

int main()
{
	Length obj1, obj2;
	int Choice;
	while( 1 )
	{
		cout << "\n\nPlease enter your choice....\n\t1 - Add lengths using operator overloading.\n\t2 - Subtract lengths using operator overloading.\n\t3 - Exit program\n";
		cin >> Choice;

		switch( Choice )
		{
			case 1:
			{
				cout << "Input length 1\n";
				obj1.Input();
				cout << "Input length 2\n";
				obj2.Input();
				Length obj3 = obj1 + obj2;
				cout << "\nLength 1 + length 2 = \n";
				obj3.Print();
				break;
			}
			case 2:
			{
				cout << "Input length 1\n";
				obj1.Input();
				cout << "Input length 2\n";
				obj2.Input();
				Length obj3 = obj1 - obj2;
				cout << "\nLength 1 - length 2 = \n";
				obj3.Print();
				break;
			}
			case 3:
			
				return 0;
			
			default:
		
				cout << "Wrong choice! Try again...\n";
			
		}
	}
	return 0;
}