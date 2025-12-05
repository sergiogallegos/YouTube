#include <stdio.h>

/* Copy input to output; 2nd version (book K&R)*/
int main(){
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
}
