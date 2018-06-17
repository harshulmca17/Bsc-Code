#include<iostream>

using namespace std;

class Box
{
  float length,breadth,height;
  float volume;
  
  public:
	  int input()
	  {
				cout <<   "Please enter length of the box: ";
				cin >> length;
				cout << "\nPlease enter breadth of the box: ";
				cin >> breadth;
				cout << "\nPlease enter height of the box: ";
				cin >> height;
				if( ( length < 0 ) || ( breadth < 0 ) || ( height < 0 ) )
				{
					cout << "Dimensions of a box cannot be less than 0!\n";
					return 0;
				}
				else
					return 1; 
	  }
	  void output()
	  {
	    			cout<<"Length  = "<<length<<endl;
				cout<<"Breadth = "<<breadth<<endl;
				cout<<"Height  = "<<height<<endl;
	  }
	  int calc_vol( float sd1, float sd2, float sd3 ) 
		{
			volume = sd1*sd2*sd3;
			return volume;
		}
	Box operator+( Box obj )
		{
			Box tmp;
			tmp.length = length + obj.length;
			tmp.breadth = breadth + obj.breadth;
			tmp.height = height + obj.height;
			return tmp;
		}
	int operator==( Box obj )
		{
			if ( ( length == obj.length ) && ( breadth == obj.breadth ) && ( height == obj.height ) )
			{
				return 1;
			}
				return 0;
		}
	Box operator=( Box obj )
		{
			length = obj.length;
			breadth = obj.breadth;
			height = obj.height;
			return *this;
		}
	int Check( float sd1, float sd2, float sd3 )
		{
			if ( ( sd1 == sd2 ) && ( sd2 == sd3 ) && ( sd1 == sd3 ) )
			{
				return 1;
			}
				return 0;
		}
};

int main()
{
  	Box var1,var2,add;
	int Choice;
	float side1, side2, side3,vol;
 
	while( 1 )
	{	
		cout << "\n\n\t\t\t\t***** MENU *****\n\n\t1 - Calculate volume of a given box.\n\t2 - Add the length, breadth, height of two boxes using operator overloading.\n";
		cout<<"\t3 - To check the Equality of two boxes using operator overloading.\n\t4 - Assignment Operator.\n\t5 - Check if the box is cube or cuboid.\n\t6 - Exit."; 
		cout << "\n\nPlease enter your choice....\n";
		cin >> Choice;
	
		switch( Choice )
		{
			case 1:
				cout <<   "Please enter length of the box: ";
				cin >> side1;
				cout << "\nPlease enter breadth of the box: ";
				cin >> side2;
				cout << "\nPlease enter height of the box: ";
				cin >> side3;
				if( ( side1 < 0 ) || ( side2 < 0 ) || ( side3 < 0 ) )
				{
					cout << "Dimensions of a box cannot be less than 0!\n";
					break;
				}
				else
				{
					vol=var1.calc_vol( side1, side2, side3 );
					cout << "Volume of box is: " << vol << "\n";
				}
				break;
			case 2:
				cout<<"Enter the dimensions for the first box.\n\n";
			        var1.input();
				cout<<"Enter the dimensions for the second box.\n\n";
			        var2.input();
				add = var1 + var2;
				cout<<"The Data after addition.\n";
				add.output();
				break;
			case 3:
				cout<<"Enter the dimensions for the first box.\n\n";
				var1.input();
				cout<<"Enter the dimensions for the second box.\n\n";
			        var2.input();
				if(var1==var2)
				{
				  cout<<"\nBoxes are Equal.";
				}
				else
				{
				  cout<<"\nBoxes are NOT Equal.";
				}
				break;
			case 4:
				cout<<"\nEnter the dimensions for the first box.\n\n";
			        var1.input();
				var2=var1;
				cout<<"\nData of second BOX after using the assignment operator.\n";
				var2.output();
				break;  
			case 5:
				cout <<   "Please enter length of the box: ";
				cin >> side1;
				cout << "\nPlease enter breadth of the box: ";
				cin >> side2;
				cout << "\nPlease enter height of the box: ";
				cin >> side3;
				if( ( side1 < 0 ) || ( side2 < 0 ) || ( side3 < 0 ) )
				{
					cout << "Dimensions of a box cannot be less than 0!\n";
					break;
				}
				if( var1.Check( side1, side2, side3 ) ) 
				{
				  cout << "Box is a cube.\n"; 
				}
				else
				{
				  cout << "Box is a cuboid.\n";
				}
				break;
			case 6:
			{
				return 0;
			}
		}
	}
	return 0;
}
