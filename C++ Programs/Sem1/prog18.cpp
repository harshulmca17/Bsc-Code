#include<iostream>
#include<math.h>

using namespace std;

class Triangle
{
	float side1, side2, side3;
	float area;

	public:
		void Input();
		float Check(Triangle);
		void Area(float);
		void Area(float,float,float);
		int operator==(Triangle);

};

int main()
{
	Triangle obj;
	int Choice;

	while( 1 )
	{	
		cout<<"\n\nEnter your choice....\n\t1 - Calculate area of triangle.\n\t2 - Check congruency of given triangles.\n\t3 - Exit program.\n\n";
		cin>>Choice;
		switch( Choice )
		{
			case 1:
			{
				obj.Input();
				float area = obj.Check(obj);
				cout << "Area of given triangle is: " << area << "\n";
				break;
			}
			case 2:
			{
				Triangle obj2;
				cout << "Input sides of triangle 1....\n";
				obj.Input();
				cout << "\nInput sides of triangle 2....\n";
				obj2.Input();
				if( obj == obj2 )
				{
				  cout << "Triangles are congruent.\n" ;
				}
				else
				{
				  cout << "Triangles are not congruent.\n";
				}
				break;
			}
			case 3:
			{
				return 0;
			}
		}
	}
	return 0;
}
void Triangle::Input()
{
  cout << "Please enter side 1 of the triangle: ";
  cin >> side1;
  cout << "Please enter side 2 of the triangle: ";
  cin >> side2;
  cout << "Please enter side 3 of the triangle: ";
  cin >> side3;
}
float Triangle::Check(Triangle obj)
{
  if ( ( obj.side1 == obj.side2 ) && ( obj.side2 == obj.side3 ) && ( obj.side1 == obj.side3 ) )
	{
		Area(obj.side1);
	}
  else
	{
		Area( obj.side1, obj.side2, obj.side3 );
	}
		return area;
}
void Triangle::Area(float side)
{
  area = ( sqrt( 3 ) * side * side ) / 4;
}
void Triangle::Area(float sd1, float sd2, float sd3)
{
  float semi = ( sd1 + sd2 + sd3 ) / 2;
  area = sqrt( semi * ( semi - sd1 ) * ( semi - sd2 ) * ( semi - sd3 ) );
}
int Triangle::operator==(Triangle obj)
{
  if ( ( side1 == obj.side1 ) && ( side2 == obj.side2 ) && ( side3 == obj.side3 ) )
      {
	return 1;
      }
	return 0;
}