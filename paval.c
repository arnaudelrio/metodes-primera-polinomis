#include <stdio.h>
#include <stdlib.h>
#include "pol.h"

int main (int argc, char *argv[]) {
    int n;
    double *p, x, r;

    if (plleg(stdin,&n,&p)) {
        fprintf(stderr, "pcl: error llegint el primer polinomi!\n");
        return -2;
    }

    while (fscanf(stdin, "%lf", &x) == 1) {
        r = paval(n, p, x);
        printf("%.16g %.16g\n", x, r);
    }

    free(p);
    return 0;
}
