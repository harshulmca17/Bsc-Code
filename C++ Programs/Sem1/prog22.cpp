#include<iostream>

using namespace std;

class Box
{
   float length;
   float breadth;
   float height;
   double volume;
  public:
   Box();
   Box(float);
   Box(float,float,float);
   void get();
   void show();
   void calc();
   Box operator+(Box);
   friend int operator==(Box,Box);
   Box operator=(Box);
   void check();
   ~Box()      
   {
   }
};
/*
   Variables Used :  length  - float type
		     breadth - float type
		     height  - float type
		     volume  - double type
   Type : Constructor
   Purpose : To initialize the class variables.
*/
Box::Box()
{
  length=breadth=height=0.0;
  volume=0.0;
}
/*
   Variables Used :  length  - float type
		     breadth - float type
		     height  - float type
		     volume  - double type
		     x       - float type
   Type : Paramaterized Constructor
   Purpose : To initialize the class variables.
*/
Box::Box(float x)
{
   length=breadth=height=x;
   volume=x*x*x;
}
/*
   Variables Used :  length  - float type
		     breadth - float type
		     height  - float type
		     volume  - double type
		     l       - float type
		     b       - float type
		     h       - float type
   Type :  Paramaterized Constructor
   Purpose : To initialize the class variables.
*/
Box::Box(float l,float b,float h)
{
   length=l;
   breadth=b;
   height=h;
   volume=l*b*h;
}
/*
   Variables Used  :   length  - float type
		       breadth - float type
		       height  - float type
   Return type : void
   Purpose : To get the dimensions of a box.
*/
void Box::get()
{ cout<<"\tEnter dimensions of the box \n";
  cout<<"Length ";
  cin>>length;
  cout<<"Breadth ";
  cin>>breadth;
  cout<<"Height ";
  cin>>height;
}
/*
    Variables Used  :   volume - double type
			length - float type
			breadth- float type
			height - float type
    Return type : void
    Purpose : To calculate and show the volume of a given box.
*/
void Box::calc()
{
  volume=length*breadth*height;
  cout<<"Volume of the box  :"<<volume<<endl;
}//calc

/************************* show **************************
   Variables Used  :   length  - float type
		       breadth - float type
		       height  - float type
   Return type : void
   Purpose : To show the dimensions of a box.
*********************************************************/
void Box::show()
{
  cout<<"\nLength of the box :"<<length;
  cout<<"\nBreadth of the box :"<<breadth;
  cout<<"\nHeight of the box :"<<height<<endl;
}//show

/******************** operator+ ***************************
    Variables Used :   b    - Box type
		       b1   - Box type
		       length-Box type
		       breadth-Box type
		       height- Box type
    Return type : Box
    Purpose :  To add the dimensions of two boxes
***********************************************************/
Box Box::operator+(Box b1)
{
  Box b;
  b.length  =  b1.length  + length;
  b.breadth =  b1.breadth + breadth;
  b.height  =  b1.height  + height;
  return b;
}//operator+

/*********************** operator== *********************************
    Variables Used :   b1     - Box type
		       b2     - Box type
		       length - float type
		       breadth- float type
		       height - float type
    Return type : int
    Purpose : To compare the dimensions of two boxes. If they are equal return 1 else return 0.
*********************************************************************/
int operator==(Box b1,Box b2)
{
  if((b1.length==b2.length) && (b1.breadth==b2.breadth) && (b1.height==b2.height))
    return 1;
  else
    return 0;
}//operator==

/************************* operator= ********************************
   Variables Used :  b1     - Box type
		     length - float type
		     breadth- float type
		     height - float type
   Return type : Box
   Purpose : To assign values to length ,breadth and height variables
*********************************************************************/
Box Box::operator=(Box b1)
{
   length=b1.length;
   breadth=b1.breadth;
   height=b1.height;
   return *this;
}//operator=

/***************************** check ***********************************
      Variables Used  :   length  - float type
			  breadth - float type
			  height  - float type
      Return type : void
      Purpose : To check whether the given box is cube or cuboid
************************************************************************/
void Box::check()
{
   if(length==breadth==height)
     cout<<"It is a cube \n";
   else
     cout<<"It is a cuboid \n";
}//check

/************************** main ********************************
     Variables Used  :   obj   - Box type
			 obj1  - Box type
			 obj2  - Box type
			 ch    - character type
     Return type : int
     Purpose : To display a menu to the user and work according to the choice of the user.
*******************************************************************/
int main()
{
  char ch;
  Box obj,obj1(5.0),obj2(5.0,4.0,3.0);
  do
 {
  cout<<"\t\t\tMENU";
  cout<<"\na) Calculate Volume ";
  cout<<"\nb) To add two boxes ";
  cout<<"\nc) To check equality of two boxes ";
  cout<<"\nd) Overload assignment operator ";
  cout<<"\ne) To check whether a box is cube or cuboid";
  cout<<"\n Enter your choice\n ";
  cin>>ch;
  switch(ch)
  {
     case 'a' : obj.get();
		obj.show();
		obj.calc();
		break;
     case 'b' : obj.get();
		obj1.get();
		obj2=obj+obj1;
		obj2.show();
		break;
     case 'c' : obj.get();
		obj1.get();
		if(obj==obj1)
		   cout<<"Boxes are equal\n";
		else
		   cout<<"\n Boxes are not equal \n";
		 break;
     case 'd' : obj.get();
		obj1=obj;
		obj1.show();
		break;
     case 'e' : obj.get();
		obj.check();
		break;
     default :  cout<<"Wrong choice ";
		 break;
   }
  cout<<"Want to enter more .......(y/n)???\n";
  cin>>ch;
  }while(ch=='y'||ch=='Y');
  return 0;
}//main
