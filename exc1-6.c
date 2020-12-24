/* Exercise 1-6
verify that the expressoin getchar() != EOF is 0 or 1 */
#include <stdio.h>

main()// main function
{
    int c; //vaiable C of type integer

    c = getchar() != EOF;//getchar contains next charecter of inputs and 
                         //here it is assigned to c and comared with EoF that is end of file 
    
    /*we can make EOF to get ASCII Value by adding "()" to c= getchar()
    that is replace line 9 with this (c = getchar()) != EOF; 
    then excecute you will get corresponding ASCII values as EOF to the input you give */

    printf("getchar() != EOF is: %d\n", c);//print staement that prints the EOF value
}                                          //My Gcc gave EoF as 1

