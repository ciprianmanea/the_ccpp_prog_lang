/*
 * Author   : Dennis M. Ritchie
 * Date     : 19-03-2015
 * ------------------------
 *  Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
    char s[] = "alibaba";

    reverse(s);
    printf("reversed s: %s\n", s);

    return 0;
}

void reverser(char s[], int i, int len);

/* reverse: reverse string s in place */
void reverse(char s[])
{
    reverser(s, 0, strlen(s));
}

/* reverser: reverse string s in place; recursive */
void reverser(char s[], int i, int len)
{
    int c, j;

    j = len - (i + 1);
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}
