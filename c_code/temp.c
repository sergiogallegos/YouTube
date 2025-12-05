#include <stdio.h>


#define LOWER 0.0 // lower limit of table
#define UPPER 300.0 // upper limit
#define STEP 20.0 // step size

/*
 * print Farenheit-Celcius table
 */
int main() {
    float fahr, celsius;

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + STEP;
    }


    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
