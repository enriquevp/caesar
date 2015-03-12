/* Caesar.c
 * Implements a basic caesar cipher. Provides ciphering and deciphering */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <err.h>

void cipher(char *str, int offset) {
    while (*str) {
        if (*str == '?') { str++; continue; }
        *str = (*str - 'a' + (offset + 26)) % 26 + 'a' ;
        str++;
    }
}

// Handling two alphabets is out of scope, so restrict to lowercase.
// Replace uppercase letters with lowercase letters.
void sanitize(char *str) {
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') *str = *str - 'A' + 'a';
        if (*str < 'a' || *str > 'z') *str = '?';
        str++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("usage: %s <string> <key>\n", argv[0]);
        exit(1);
    }

    sanitize(argv[1]);

    int offset;
    offset = atoi(argv[2]) % 26;

    cipher(argv[1], offset);
    printf("%s\n", argv[1]); /* Since it is printed after the function finishes,
                              * argv[1] now contains the ciphered string.     */
    return 0;
}
