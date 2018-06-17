
#include<iostream>
#include<fstream>
using namespace std;

class student
{
  
  int  roll_no;
  char Name[20];
  int  cls;
  int  marks;
public:
  void getdata();
  void showdata();
}stud;

int main()
{
  
  int n;
  fstream f("student.txt",ios::out);
  cout<<"\nHow many entries you want to do..?? \n";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    stud.getdata();
    f.write((char*)&stud,sizeof(stud));
  }
  f.close();
  ifstream fin("student.txt",ios::in);
  cout<<"\n\nThe details for the Employee :\n\n";
  cout<<"Roll No.\tName\tClass\tMarks\n";    
  for(int i=0;i<n;i++)
  {
    fin.read((char*)&stud,sizeof(stud));
    stud.showdata();
  }
  fin.close();
return 0;
}
void student :: getdata()
{
    cout<<"\n\nEnter the details for the Student :\n";
    cout<<"\nEnter Roll Number of the student:\n";
    cin>>roll_no;
    cout<<"\nEnter the Name of the student :\n";
    cin>>Name;
    cout<<"\nEnter the Class of the student :\n";
    cin>>cls;
    cout<<"\nEnter the Marks of the student:\n";
    cin>>marks;
    cout<<"\n\n";
}
void student :: showdata()
{
    cout<<roll_no<<"\t\t "<<Name<<"\t"<<cls<<"\t"<<marks<<"\n";
}