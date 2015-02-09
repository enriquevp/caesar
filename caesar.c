//Caesar.c
//Implements a basic caesar cipher. Provides ciphering and deciphering

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cipher(char *string, int shiftkey)
{
    int  i, output[50];
    for (i=0; i < strlen(string);i++)
    {
        output[i] = (int)string[i];
        output[i]+=shiftkey;
        if (output[i] >'z')
        {
            output[i]-=26;
        }

        if (output[i] <'a')
        {
            output[i] = ' ';
        }
        string[i] = (char) output[i];
    }

    printf("%s\n", string);
}

void decipher (char *string, int shiftkey)
{
    int i, output[50];

    for (i=0; i < strlen(string);i++)
    {
        output[i] = (int)string[i];
        output[i]-=shiftkey;
        if (output[i] <'a')
        {
            output[i]+=26;
        }
        string[i] = (char) output[i];
    }

    printf("%s\n", string);
}

int main ( int argc, char *argv[])
{
    int shiftkey;
    shiftkey=atoi(argv[2]);

    cipher(argv[1], shiftkey);
    //decipher(argv[1], shift);
    return 0;
}
