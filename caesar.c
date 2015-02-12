/* Caesar.c 
 * Implements a basic caesar cipher. Provides ciphering and deciphering */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <err.h>

void cipher(char *string, int shiftkey){
    int  i;
    for (i=0; i < strlen(string); i++){
        string[i] += shiftkey;

        if (string[i] >'z')
            string[i] -=  26;

        if (string[i] <'a')
            string[i] -= 26;
    }
}

int main ( int argc, char *argv[]){
    if (argv[1] == NULL || argv[2] == NULL)
        errx(1, "This program requires two arguments.");

    int shiftkey;
    shiftkey=atoi(argv[2]);

    cipher(argv[1], shiftkey);
    printf("%s\n", argv[1]); /* Since it is printed after the function finishes,
                              * argv[1] now contains the ciphered string.     */
    return 0;
}
