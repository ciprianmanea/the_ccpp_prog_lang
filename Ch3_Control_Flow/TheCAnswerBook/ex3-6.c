/*
 * Author   : Dennis M. Ritchie
 * Date     : 08-03-2015
 * ----------------------------
 *  Write a version of itoa that accepts three arguments instead of two. 
 * The third argument is a minimum field width; the converted number must be
 * padded with blanks on the left if nexessary to make it wide enough.
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define abs(x)  ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w);

int main()
{
    char s[22];
    int n = INT_MIN;

    itoa(n, s, 6);
    printf("n value as: %s\n", s);

    return 0;
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int w)
{
    int i, sign;

    sign = n;               /* record sign */
    i = 0;
    do {                    /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';   /* get next digit */
    } while ((n /= 10) != 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        si[++] = ' ';
    s[i] = '\0';
    reverse(s);
}
