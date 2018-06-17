#include<iostream>
 
using namespace std;

class Array
{
    int *arr;
public :
    int sizeofarray;
  
    Array& operator = (const Array &obj)                                  //assignment operator
    {
	for(int i=0;i<sizeofarray;++i)
	{
	  arr[i] = obj.arr[i];
	}
	return *this;
    }
    
    Array(const Array &obj)                                               //Copy Constructer
    {
      sizeofarray=obj.sizeofarray;
      arr= new int[obj.sizeofarray];
      for(int i=0;i<sizeofarray;i++)
      {
			arr[i]=obj.arr[i];
      }
    }
    
    Array(int size)                                                      //Parameterised Constructer
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
      for( int i = 0 ; i < sizeofarray ; i++ )
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
    
    int linear()
    {
         int n,r;
         r = 0;
         cout<<"\nEnter the number to be search : ";
         cin>>n;
         for(int i=0; i<sizeofarray; i++)
         {
                 if(arr[i] == n)
                 {
                           r = 1;
                           break;
                 }
         }
         return r;
    }
 
    int binary()
    {
        int n,r,f,m,l;
        r = 0;
        cout<<"\nEnter the number to be search : ";
        cin>>n;
        f = 0;
        l = sizeofarray - 1;
        while( f <= l )
        {
               m = ( f+l )/2;
               if( arr[m] == n )
               {
                   r = 1;
                   break;
               }
               else if( arr[m] < n )
               {
                    f = m+1 ;
               }
               else if( arr[m] > n )
               {
                    l = m-1;
               }
        }
        return r;
    }
    
    void selection()
    {
         int temp,minloc;
         for(int i = 0; i < (sizeofarray-1) ; i++)
         {
                 minloc = i;
                 for(int j=i+1; j<sizeofarray; j++)
                 {
                         if( arr[j] < arr[minloc])
                         minloc = j;
                 }
                         temp        = arr[i];
                         arr[i]      = arr[minloc];
                         arr[minloc] = temp;
         }
   }
    /*
    {
    int temp;
    for(int i=0; i<sizeofarray-1; i++)
    {
            for(int j=0; j<sizeofarray; j++)
            {
                    if( arr[i] > arr[j] )
                    {
                        temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
            }
    }      */
    
    void insertion()
    {
         for(int i=1; i<sizeofarray-1; i++)
         {       int temp = arr[i], j = i;
                 while((temp < arr[j-1]) && (j>0))
                 {
                        arr[j] = arr[j-1];
                        j--;
                 }
                         arr[j] = temp;
         }
    }
    /*
    {
         int i,jtemp;
         for( i=0; i<sizeofarray; i++)
         {
              j = i-1;
              temp = arr[i];
              while( ( temp<arr[j] )&&( j>=0 ) )
              {
                     arr[j+1] = arr[j];
                     j--;
              }
              arr[j+1] = temp;
         }
         for(int i=0; i<sizeofarray; i++)
         cout<<arr[i]<<"\t";
    }*/
    void bubble()
    {
         int temp;
         for(int i=0; i<sizeofarray; i++)
         {
                 for(int j=0; j<sizeofarray-1; j++)
                 {
                         if( arr[j] > arr[j+1] )
                         {
                             temp = arr[j];
                             arr[j] = arr[j+1];
                             arr[j+1] = temp;
                         }
                 }
        }
    }
    /*
    {    int temp;
         for(int i=0; i<sizeofarrray-1; i++)
         {
                 for(int j=0; j<sizeofarray-1-i; j++)
                 {
                         if( arr[j] > arr[j+1] )
                         {
                             temp = arr[j];
                             arr[j] = arr[j+1];
                             arr[j+1] = temp;
                         }
                 }
         for(int i=0; i<sizeofarray; i++)
         cout<<arr[i]<<"\t";
    }
    */
};
int main()
{
  int choice,pos,loc,index;
  char ch;
  cout<<"\n\nMENU :\n1 ) Linear Search\n2 ) Binary Search( Array should be in any order )\n3 ) Selection Sort\n4 ) Insertion Sort\n5 ) Bubble Sort\n";
  cout<<"\nEnter the choice : ";
  cin>>choice;
  cout<<"\nEnter the size :\n";
  cin>>index;
  Array a(index);                                                                //object 'a' declared
  a.fill();
  switch(choice)
  {
    case 1 :
    {
          cout<<"\n***********************Linear Search*********************\n";
          int n;
	      a.show();
	      n = a.linear();
	      if(n == 1)
	      cout<<"\nElement found..!";
	      else
	      cout<<"\nElement not found..!";
	      break;
    }
    case 2 :
    {
	      cout<<"\n\n*********************Binary Search*********************\n";
	      int n;
	      a.show();
	      n = a.binary();
	      if(n == 1)
	      cout<<"\nElement found..!";
	      else
	      cout<<"\nElement not found..!";
	      break;
    }
    case 3 :
    {
	      cout<<"\n\n********************Selection Sort**********************\n";
	      a.show();
	      a.selection();
	      Array b(index);
	      b = a;
	      b.show();
	      break;
    }
    case 4 :
    {
	      cout<<"\n\n*******************Insertion Sort************************\n";
	      a.show();
	      a.insertion();
	      Array b(index);
	      b = a;
	      b.show();
	      break;
    }
    case 5 :
    {
	      cout<<"\n\n*******************Bubble Sort***************************\n";
	      a.show();
	      a.bubble();
	      Array b(index);
	      b = a;
	      b.show();
	      break;
    }
    default :
	      cout<<"\nYou have entered a wrong choice..! \n";
  }
  cout<<"\n\n";
  return 0;
}     

