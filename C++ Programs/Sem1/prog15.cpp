/*
 Create a file that contains records of 'n' employees. Each record contains an employee's salary details. Print the information 
 retrieved from the file in the following format : EId  Name Basic HRA DA Extra Allowance
*/
#include<iostream>
#include<fstream>
using namespace std;

void getdata();
void showdata();

class employee
{
  int  EId;
  char Name[20];
  int  Basic;
  int  HRA;
  int  DA;
  int  extra_allowance;
public:
  void getdata();
  void showdata();
}emp;

int main()
{
  
  int n;
  fstream f("emp1.txt",ios::out);
  cout<<"\nHow many entries you want to do..?? \n";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    emp.getdata();
    f.write((char*)&emp,sizeof(emp));
  }
  f.close();
  ifstream fin("emp1.txt",ios::in);
  cout<<"\n\nThe details for the Employee :\n\n";
  cout<<"EId\tName\tBasic\tHRA\tDA\tExtra_allowance\n";    
  for(int i=0;i<n;i++)
  {
    fin.read((char*)&emp,sizeof(emp));
    emp.showdata();
  }
  fin.close();
return 0;
}
void employee :: getdata()
{
    cout<<"\n\nEnter the details for the Employee :\n";
    cout<<"\nEnter Employee id :\n";
    cin>>EId;
    cout<<"\nEnter the name of the Employee :\n";
    cin>>Name;
    cout<<"\nEnter the Basic income of the Employee :\n";
    cin>>Basic;
    cout<<"\nEnter the HRA for the Employee :\n";
    cin>>HRA;
    cout<<"\nEnter the DA for the Employee :\n";
    cin>>DA;
    cout<<"\nEnter the Extra Allowance for the employee :\n";
    cin>>extra_allowance;
    cout<<"\n\n";
}
void employee :: showdata()
{
    cout<<EId<<"\t"<<Name<<"\t"<<Basic<<"\t"<<HRA<<"\t"<<DA<<"\t"<<extra_allowance<<"\n";
}