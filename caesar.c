//Caesar.c
//Implements a basic caesar cipher. Provides ciphering and deciphering

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cipher(char *string, int shiftkey)
{
    int  i;
    for (i=0; i < strlen(string);i++)
    {
        string[i] += shiftkey;
        if (string[i] >'z')
        {
            string[i]-=26;
        }

        if (string[i] <'a')
        {
            string[i] = ' ';
        }
    }
    printf("%s\n", string);
}

void decipher (char *string, int shiftkey)
{
    int i;

    for (i=0; i < strlen(string);i++)
    {
        string[i]-=shiftkey;
        if (string[i] <'a')
        {
            string[i]+=26;
        }
    }
    printf("%s\n", string);
}

int main ( int argc, const char **argv[])
{
    int shiftkey;
    shiftkey=atoi(argv[2]);

    cipher(argv[1], shiftkey);
    return 0;
}
