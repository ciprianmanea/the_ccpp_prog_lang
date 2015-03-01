/*
 * Author   : Dennis M. Ritchie
 * Date     : 27-02-2015
 * ------------------------
 *  Writea an alternate version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s2.
 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "Who is this boy, that I don't know?";
    char d[] = "oih";

    squeeze(s1, d);
    printf("Remained: %s\n", s1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
            ;
        if (s2[j] == '\0')      /* end of string - no match */
            s1[k++] = s1[i];
    }
    s1[k] = '\0';

}
