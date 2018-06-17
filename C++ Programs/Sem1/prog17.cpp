#include<iostream>
#include<fstream>
using namespace std;
void readdata()
{
    char str[90];
    fstream f1("file1.txt",ios::out);
    cin.getline(str,90);
    f1<<str;
    f1.close();
}

int main()
{
   readdata();
  ifstream fin;
  ofstream fout ;
  char ch;
	fin.open( "file1.txt");
	fout.open( "file2.txt", ios::trunc );
		while(fin >> ch)
			{
				
				if( ch != ' ' )
				{
					fout << ch;
				}
			}
	fin.close();
	fout.close();
	cout<<"\n";
	return 0;
}
