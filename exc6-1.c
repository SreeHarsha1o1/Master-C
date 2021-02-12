#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXWORD 1000

struct key{
    char *word;
    int count;
};

struct key keytab[] = { 
    {"auto", 0},
    {"break", 0},
    {"case",0},
    {"char",0},
    {"continue",0},
    {"default",0},
    {"unsigned",0},
    {"void",0},
    {"volatial",0},
    {"while",0}                        
};

#define NKEYS (sizeof keytab / sizeof(struct key))

int getword1(char *, int);
int binsearch(char *, struct key *, int);

int main()
{
    int n;
    char word[MAXWORD];

    while(getword1(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            if((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    for(n = 0; n < NKEYS; n++)
        if(keytab[n].count > 0)
            printf("%4d %s\n",keytab[n].count, keytab[n].word);
    return 0;
}

int binsearch(char *word, struct key tab[], int n)
{
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    //printf("low value = %d, high value = %d\n",low,high);
    while(low <= high)
    {
        mid = (low + high) / 2;
        //printf("mid value = %d\n",mid);
        
        cond = strcmp(word, tab[mid].word);
        //printf("the cond (strcmp returned) value:%d\n",cond);
        
        if((cond) < 0)
        {
            //printf("inside if (bin) the cond (strcmp returned) value:%d\n",cond);
            high = mid - 1;
        }
        else if (cond > 0)
            low = mid + 1;
        else 
            return mid;
    }
    return -1;
}

int getword1(char *word,int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getch()))
        ;
    if(c != EOF)
        *w++ = c;
    
       //string constants are ignored
    if (c == '"') 
    {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '"')
                break;
        *++w = '\0';
        return word[0];
    }
    //comments are ignored
    if (c == '/') 
    {
        c = getch();
        //Single line comments are ignored
        if (c == '/')
        {
            for ((*w++ = c) && (--lim > 0); --lim > 0; w++)
                if ((*w = getch()) == '\n')
                {
                    *++w = '\0';
                    return word[0];
                }
        } 
        else if (c == '*') 
        {
            for ((*w++ = c) && (--lim > 0); --lim > 0; w++)
                if ((*w = getch()) == '/')
                    if (*(w - 1) == '*') 
                    {
                        *++w = '\0';
                        return word[0];
                    }
        } 
        else 
        {
            ungetch(c);
            *w = '\0';
            return '/';
        }
    }
    // preprocessor #define
    if (c == '#') 
    {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\n')
                break;

    }
    if (!isalpha(c) && c != '_') 
    {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) 
    {
        if (!isalnum(*w = getch()) && *w != '_') 
        {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for unget
int bufp = 0;   //next free position in buff

int getch(void) // get a (popssibly pushed back) charecter
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) //push charecter back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many charecters\n");
    else
        buf[bufp++] = c;
}
