/* This program is to perform operations on strings : 1)Concatenate two strings
						    2)Compare two strings
                                                    3)Calculate the length of the string
                                                    4)Convert all lowercase characters to uppercase
                                                    5)Convert all uppercase characters to lowercase
                                                    6)Calculate the number of vowels
                                                    7)Find the substring in a given string */
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<cstdio>
using namespace std;
void concatenate();
void compare();
void length();
void low_to_up();
void up_to_low();
void no_of_vowels();
void substring();
int main()
{
  int choice;
  cout<<"\n\n\t\tMENU\n";
  cout<<"\nWhich operation you want to perform on strings : \n1)Concatenate two strings.";
  cout<<"\n2)Compare two strings.";
  cout<<"\n3)Calculate the length of the string.";
  cout<<"\n4)Convert all lowercase characters to uppercase.";
  cout<<"\n5)Convert all uppercase characters to lowercase.";
  cout<<"\n6)Calculate the number of vowels.";
  cout<<"\n7)Find the substring in a given string.";
  cout<<"\n8)Exit";
  cout<<"\n\nEnter the choice : ";
  cin>>choice;
  switch(choice)
  {
    case 1:
	   concatenate();
	   break;
    case 2:
	   compare();
	   break;
    case 3:	
	   length();
	   break;
    case 4:
	   low_to_up();
	   break;
    case 5:
	   up_to_low();
	   break;
    case 6:
	   no_of_vowels();
	   break;
    case 7:
	   substring();
	   break;
    case 8:
	   break;
    default : cout<<"\nYou have entered a wrong choice.";
  }
  cout<<"\n";
  return 0;
}
/*
Function name : concatenate
Variable : string1[50] is to store the first string and string2[50] is to store second string
Purpose : To concatenate the two strings
*/
void concatenate()
{ 
  int i,j,len=0;
  char string1[50],string2[50];
  cout<<"\nEnter first string : ";
  cin.ignore();
  cin.getline(string1,50);
  cout<<"\nEnter second string : ";
  cin.getline(string2,50); 
  while(string1[i]!='\0')
  {
      i++;
  }
  while(string2[j]!='\0')
  {
      string1[i++]=string2[j++];
  }
  string1[i]='\0';
  cout<<"\nStrings after concatenation :\n";
  cout<<string1;
}
/*
Function name : Compare
Variable : string1[50] is to store the first string and string2[50] is to store second string
Purpose : To compare the two strings
*/
void compare()
{
  char string1[50],string2[50];
  cout<<"\nEnter first string : ";
  cin.ignore();
  cin.getline(string1,50);
  cout<<"\nEnter second string : ";
  cin.getline(string2,50);
  if((strcmp(string1,string2))==0)
    cout<<"\nStrings are same. ";
  else
    cout<<"\nStrings are not same.";
}
/*{
    int i=0,flag=0;
   
    while(str1[i]!='\0' && str2[i]!='\0'){
         if(str1[i]!=str2[i]){
             flag=1;
             break;
         }
         i++;
    }

    if (flag==0 && str1[i]=='\0' && str2[i]=='\0')
         v=1;
    else
         v=0;
    if(v== 1)
         printf("Both strings are equal.");
    else
         printf("Both strings are not equal");
 }*/
/*
Function name : Length
Variable : len to store the length of the string and string[50] to store the string
Purpose : To calculate the length of the given string
*/
void length()
{
  int len=0;
  char string[50];
  cout<<"\nEnter the string : ";
  cin.ignore();
  cin.getline(string,50);
  len=strlen(string);
  cout<<"\nThe length of the given string is "<<len;
}
/*
Function name : low_to_up
Variable : string[50] to store the string
Purpose : To convert lowercase characters to uppercase characters of the given string
*/
void low_to_up()
{
  char string[50];
  cout<<"\nEnter the string : ";
  cin.ignore();
  cin.getline(string,50);
   for(int i=0;i<=strlen(string);i++)
   {
       if(string[i]>=97&&string[i]<=122)
       string[i]=string[i]-32;
   }
  cout<<"\nThe string in upper case is "<<string;
}
/*
Function name : up_to_low
Variable : string[50] to store the string
Purpose : To convert uppercase characters to lowercase characters of the given string
*/
void up_to_low()
{
  char string[50];
  cout<<"\nEnter the string : ";
  cin.ignore();
  cin.getline(string,50);
  for(int i=0;i<=strlen(string);i++)
  {
      if(string[i]>=65&&string[i]<=90)
       string[i]=string[i]+32;
  }
  cout<<"\nThe string in lower case is "<<string;
}
/*
Function name : low_to_up
Variables : a,e,i,o,u to count the number of their repective vowels
Purpose : To count the number of vowels in the given string
*/
void no_of_vowels()
{
  int a=0,e=0,v=0,o=0,u=0,t=0;
  char string[50];
  cout<<"\nEnter the string : ";
  cin.ignore();
  cin.getline(string,50);
   for(int i=0;i<=strlen(string);i++)
   {
     if((string[i]=='a')||(string[i]=='A'))
       a++;
     else if((string[i]=='e')||(string[i]=='E'))  
       e++;
     else if((string[i]=='i')||(string[i]=='I'))
       v++;
     else if((string[i]=='o')||(string[i]=='O'))
       o++;
     else if((string[i]=='u')||(string[i]=='U'))
       u++;
   }
   t=a+e+v+o+u;
   cout<<"\nStrings contains :\nNumber of A = "<<a<<"\nNumber of E = "<<e<<"\nNumber of I = "<<v<<"\nNumber of O = "<<o<<"\nNumber of U = "<<u;
   cout<<"\nTotal number of vowels in given string is : "<<t;
}
/*
Function name : substring
Variables : main[30] to store the main string, sub[30] to store the substring
Purpose : To check the string1 is present in the given string or not
*/
void substring()
{ 
  cout<<"\n\t\n*....To search a substring in a given string...*";
  char x;
  do
  {
  char main[30];
  cout<<"\nEnter main string \n";
  cin.ignore();
  cin.getline(main,30);
  char sub[30];
  cout<<"\nEnter sub string you want to search \n";
  cin.getline(sub,30);
  int flag=0;
  for(int i=0,j=0;main[i]!='\0';i++,j++)
  {
    if(main[i]!=sub[j])  j--;
    else
    {
      int k=i , l= j;
      while(sub[l]!='\0')
      {
	if(main[k]==sub[l])
	{
	  flag++;
	}
	else if(main[k]!=sub[l]) flag=0;
	k++;
	l++;
      }
    }
  }
  if(flag)
  cout<<"\n\""<<sub<<"\" found in \""<<main<<"\".\n";
  else cout<<"\n\""<<sub<<"\" not found in \""<<main<<"\".\n";
  cout<<"\nEnter '#' to continue or '*' to exit.\n";
  cin>>x;
  }
  while(x=='#');
}
		       