#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXWORD 100

struct linklist {
    int lnum;
    struct linklist *ptr;
};

struct tnode {  //the tree node
    char *word; //points to the text
    struct linklist *lines; //line numbers
    struct tnode *left; //left child
    struct tnode *right; //right child
};

struct tnode *addtree(struct tnode *, char *,int);
void treeprint(struct tnode *);
int getword(char *,int);
int noiseword(char *);

int main()
{
    struct tnode *root;
    char word[MAXWORD];
    int linenum = 1;

    root = NULL;
    while(getword(word, MAXWORD) != EOF)
        if(isalpha(word[0]) && noiseword(word) == -1)
            root = addtree(root, word, linenum);
        else if(word[0] == '\n')
            linenum++;
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
char *strdup1(char *);
struct linklist *lalloc(void);
void addln(struct tnode *, int);

struct tnode *addtree(struct tnode *p, char *w, int linenum)
{
    int cond;

    if(p == NULL)
    {
        p = talloc();// a new word has arrived
        p->word = strdup1(w);// make a new node
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->lines->ptr = NULL; 
        p->left = p->right = NULL;
    }
    else if((cond = strcmp(w,p->word)) == 0)
        addln(p,linenum); 
    else if (cond < 0) // less than into left subtree
        p->left = addtree(p->left, w, linenum);
    else        // greater than into right subtree
        p->right = addtree(p->right, w, linenum);
    return p;
}

/*addln: add line number to the linked list*/
void addln(struct tnode *p, int linenum)
{
    struct linklist *temp;

    temp = p->lines;
    while(temp->ptr != NULL && temp->lnum != linenum)
        temp = temp->ptr;
    if(temp->lnum != linenum)
    {
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}

/*getword: get next word or charecter from input*/
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while(isspace(c = getch()))
        ;
    if(c != EOF)
    {
        *w = '\0';
        return c;
    }
    for( ; --lim > 0; w++)
        if(!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
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

/*treeprint: in-order print of tree p*/
void treeprint(struct tnode *p)
{
    struct linklist *temp;
    if(p != NULL)
    {
        treeprint(p->left);
        printf("%10d\n",p->word);
        for(temp = p->lines; temp != NULL; temp->ptr)
            printf("%4d ",temp->lnum);
        printf("\n");
        treeprint(p->right);
    }
}

/*lalloc: make a linklist node*/
struct linklist *lalloc(void)
{
    return (struct linklist *) malloc(sizeof(struct linklist));
}

/*noisewords: identify word as noise word*/
int noiseword(char *w)
{
    static char *nw[] = { "a","an","and","are","so","in","is","of","or","that","the","this","to"};
    int cond; int mid; int low; int high;
    low = 0;
    high = sizeof(nw) / sizeof(char *) - 1;
    while(low <= high)
    {
        mid = (low +high) / 2;
        cond = strcmp(w, nw[mid]);
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
