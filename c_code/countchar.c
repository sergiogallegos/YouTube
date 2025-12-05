#include <stdio.h>

/* Count characers in input */
int main(){
    long nc = 0;
    int c;

    while ((c = getchar()) != EOF) {
        nc++;
    }

    printf("Character count: %ld\n", nc);
    return 0;
}
