#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "test.h"

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int getHash(void * element){
    return (*(int *)element);
}

int copyValue(void * element){
    return (*(int *)element);
}

struct elements
{
    int value;
    //set based on radix
    struct elements ** children;
};



int main(void) {

    int test[] = {3,236,33,12312351,22,1};

    clock_t begin = clock();

    int size = sizeof(test) / sizeof(test[0]);

    qsort(test, size, sizeof(int), cmpfunc);
    clock_t fin = clock();
    double time_spent = (double)(fin - begin) / CLOCKS_PER_SEC;
    printf("\nRun time is: %lfms\n", time_spent);
    return(0);
}
