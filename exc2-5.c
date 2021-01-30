/*write the function any(s1,s2) which returns the first location in the string s1
where any charecter from the string s2 occurs, or -1 if s1 contains no charecters from*/
#include<stdio.h>

#define MAX 100
#define LIM 100


int getline1(char s[],int lim);
int any(char s1[], char s2[]);

int main()
{
	char s1[MAX];
	char s2[MAX];
	int len1,len2;
	int a;
	
	printf("Please enter a string\n");
	len1 = getline1(s1, LIM);
	printf("Please enter another string \n");
	len2 = getline1(s2, LIM);
	
	//printf("len1=%d and len2=%d\n",len1,len2);
	
	a = any(s1 ,s2 );
	if(a != -1)
	{	
		printf("The position of first occerence of the letters in first string is %d\n",a);
	}
	else
	{
		printf("the first occarence of matching letter in the two strings is %d\n",a);
	}
	
	
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

int any(char s1[],char s2[])
{
	int i,j;
	//int a,b;
	
	//b = NO;
	
	for(i=0; s1[i] != '\0';i++)
	{
		for(j=0; s2[j] != '\0'; j++)
		{
			if(s2[j] == s1[i])
			{
				//a = i;
				//b = YES;
				return i;
				
			}
			
		}	
					
	}
	//if(b == YES)
	//	return a;
	//else
		return -1;	
	//printf("the charecters left in string s1 are %s and s2 are %s\n",s1,s2);
}

