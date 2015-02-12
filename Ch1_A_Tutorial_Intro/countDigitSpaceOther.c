/*
 * Author   : Dennis M. Ritchie
 * Date     : 12-02-2015
 * ----------------------------
 *  Count digits, white space, others
 */
#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else 
            ++nother;

    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", 
            nwhite, nother);

    return 0;
}
