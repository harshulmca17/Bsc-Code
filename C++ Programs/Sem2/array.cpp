#include<iostream>

using namespace std;

class array
{
    int *arr;
public :
    int sizeofarray;
  
    bool operator == (const array &obj)                                  //equality operator
    {   
        for(int i=0;i<sizeofarray;++i)
	{
	  if( arr[i] != obj.arr[i])
	  {
	      return false;
	  }
	  else 
	  {
	      return true;
	  } 
	}
    }
    
    array& operator + (const array &obj)                                  //sum operator
    {
      array *temp=new array(sizeofarray);
      
      {
	for(int i=0;i<sizeofarray;++i)
	{
	  temp->arr[i] = arr[i] + obj.arr[i];  
	}
	return *temp;
      }
    }
  
    array& operator = (const array &obj)                                  //assignment operator
    {
	for(int i=0;i<sizeofarray;++i)
	{
	  arr[i] = obj.arr[i];
	}
	return *this;
    }
    
    array(const array &obj)                                               //Copy Constructer
    {
      sizeofarray=obj.sizeofarray;
      arr= new int[obj.sizeofarray];
      for(int i=0;i<sizeofarray;i++)
      {
	arr[i]=obj.arr[i];
      }
    }
    
    array(int size)                                                      //Parameterised Constructer
     {
       sizeofarray=size;
       arr= new int[size];
       for(int i=0;i<size;i++)
       {
 	arr[i]=-1;
       }
     }
     
    void fill()
    {
      cout<<"\nEnter the elements :\n";
      for(int i=0;i<sizeofarray;i++)
      {
	cin>>arr[i];
      }
    }
    
    void show()
    {
      cout<<"\nElements are :\n";
      for(int i=0;i<sizeofarray;i++)
      {
			cout<<arr[i]<<"\t";
      }
    }
    
    void single(int f)
    {
      for(int i=0;i<sizeofarray;i++)
      {
	if(i==(f-1))
	cout<<"The element having index "<<f<<" is : "<<arr[i]<<"\t";
      }
    }
    
    void doub(int loca)
    {
      cout<<"\n\nElement after multiply by '2' are :";
      for(int i=0;i<sizeofarray;i++)
      {
	if(i==(loca-1))
	cout<<2*arr[i]<<"\t";
      }
    }
    
};
int main()
{
  int choice,pos,loc,index;
  cout<<"\n\nMENU :\n1 ) Parameterised Constructor\n2 ) Copy Constructor\n3 ) Assignment operator\n4 ) Sum operator\n5 ) Equality operator\n";
  cout<<"\nEnter the choice : ";
  cin>>choice;
  cout<<"\nEnter the size :\n";
  cin>>index;
  array a(index);                                                                //object 'a' declared
  a.fill();
  switch(choice)
  {
    case 1 :
    {
              cout<<"\n***********************Parameterised Constructor*********************\n";
	      a.show();
	      cout<<"\n\nEnter the location of element : ";
	      cin>>pos;
	      a.single(pos);
	      cout<<"\n\nEnter the location of element for multiply it by '2' :  ";
	      cin>>loc;
	      a.doub(loc);
	      break;
    }
    case 2 :
    {
	      cout<<"\n\n***********************Copy Constructor******************************\n";
	      array b(a);                                                                    //object 'b' declared
	      b.show();
	      break;
    }
    case 3 :
    {
	      cout<<"\n\n***********************Assignment operator****************************\n";
	      array c(index);                                                               //object 'c' declared
	      c = a ;
	      c.show();
	      break;
    }
    case 4 :
    {
	      cout<<"\n\n***********************Sum operator***********************************\n";
	      array d(index);  								   //object 'd' declared
	      array b(index);
	      b.fill();
	      d = a + b ;
	      d.show(); 
	      array e = a + b + d ;
	      e.show();
	      break;
    }
    case 5 :
    {
	      cout<<"\n\n***********************Equality operator*******************************\n";
	      array f(index);
	      f.fill();
	      if( a == f )
	      {
		cout<<"\nArrays are same.\n";
	      }
	      else
	      {
		cout<<"\nArrays are not same.\n";
	      }
	      break;
    }
    default :
	      cout<<"\nYou have entered a wrong choice..! \n";
  }
  cout<<"\n\n";
  return 0;
  }
