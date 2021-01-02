/*write an alternative version of squeeze(s1,s2) that deletes each charecter 
in s1 that matches any charecter int the string s2*/
#include<stdio.h>

#define MAX 100
#define LIM 100

int getline1(char s[],int lim);
void squeeze(char s1[], char s2[]);

int main()
{
	char s1[MAX];
	char s2[MAX];
	int len1,len2;
	
	printf("Please enter a string\n");
	len1 = getline1(s1, LIM);
	printf("Please enter a string of same length as above\n");
	len2 = getline1(s2, LIM);
	
	squeeze(s1 ,s2 );
	
	return 0;
}

int getline1(char s[], int lim)
{
	int c,i;
	
	for(i = 0; i < lim-- && (c=getchar()) != EOF && c !='\n' ;i++)
	{
		s[i] = c;
	}
	if(s[i] == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	
	return i;
}

void squeeze(char s1[],char s2[])
{
	int i,j;
	for(j=0; s2[j] != '\0'; j++)
	{
		for(i=0; s1[i] != '\0'; i++)
		{
			if(s1[i] == s2[j])
			{
				s1[i] = '0';
			}
		}				
	}
	printf("the charecters left in string s1 are %s and s2 are %s\n",s1,s2);
}
		
