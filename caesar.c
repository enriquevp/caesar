/* Caesar.c
 * Implements a basic caesar cipher. Provides ciphering and deciphering */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <err.h>

void cipher(char *string, int offset) {
    int i;
    for (i = 0; i < strlen(string); i++){
        string[i] += offset;

        if (string[i] > 'z')
            string[i] -=  26;

        if (string[i] < 'a')
            string[i] -= 26;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3){
        printf("usage: %s <string> <key>\n", argv[0]);
        exit(1);
    }

    int offset;
    offset = atoi(argv[2]) % 26;

    cipher(argv[1], offset);
    printf("%s\n", argv[1]); /* Since it is printed after the function finishes,
                              * argv[1] now contains the ciphered string.     */
    return 0;
}
