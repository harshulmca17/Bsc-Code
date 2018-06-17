#include<iostream>

using namespace std;

/**************************************************** main *****************************************************************
   Variables Used :   argc   - integer type
		      argv[] - pointer to character array type
		      str    - integer array type
		      i      - integer type
		      j      - integer type
   Return type : int
   Purpose : To print a table indicating the number of occurences of each alphabet in the text entered as command line arguments.
 *******************************************************************************************************************************/
int main(int argc,char*argv[])
{
   int str[26]={0},i,j;
   for(i=1;i<argc;i++)
   {  for(j=0;argv[i][j]!='\0';j++)
	{
	  if(argv[i][j]>='a'&&argv[i][j]<='z')
	   str[int(argv[i][j])-97]++;
	  if(argv[i][j]>='A'&&argv[i][j]<='Z')
	   str[int(argv[i][j])-65]++;
	}
   }

   for(i=0;i<26;i++)
   cout<<char(i+65)<<"    "<<str[i]<<endl;
  return 0;
}
