/*
 * Author   : Ciprian Manea
 * Date     : 08-03-2015
 * ----------------------------
 *  Write the function strrindex(s, t), which returns the position of the
 * rightmost occurrence of t in s, or -1 if there is none.
 */

#include <stdio.h>

#define MAXLINE 1000        /* maximum input line length */

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int pos;

    while (getLine(line, MAXLINE) > 0)
        if ((pos = strindex(line, pattern)) >= 0) {
            printf("pos: %d ; %s", pos, line);
            found++;
        }
    return found;
}

/* getline: get line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    int r_pos;

    r_pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            r_pos = i;
    }
    if (r_pos >= 0)
        return r_pos;
    
    return -1;
}
