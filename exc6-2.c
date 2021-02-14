#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100

int matchingchar = 6;

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *,int);

int main(int argc, char *argv[])
{
    struct tnode *root;
    char word[MAXWORD];

    if (*++argv)
        matchingchar = atoi(*argv);
    
    

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup1(char *);

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if(p == NULL)
    {
        p->word = strdup1(w);// a new word has arrived
        p->count = 1;// make a new node 
        p->left = p->right = NULL;
    }
    else if((cond = strncmp(w,p->word, matchingchar)) == 0)
        p->count++; // repeated word
    else if (cond<0) // less than into left subtree
        p->left = addtree(p->left, w);
    else        // greater than into right subtree
        p->right = addtree(p->right, w);
    return p;
}

/*treeprint: in-order print of tree p*/
void treeprint(struct tnode *p)
{
    if(p != NULL)
    {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a node*/
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/*strdup1: copies merely the string given by its argument into a safe place, obtained by a malloc:*/
char *strdup1(char *s)
{
    char *p;

    p = (char *) malloc(strlen(s)+1);
    if(p != NULL)
        strcpy(p, s);
    return p;
}

/*getword: get next word or charecter from input*/
int getword(char *word,int lim)
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
