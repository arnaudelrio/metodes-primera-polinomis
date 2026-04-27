#include <stdio.h>
#include <stdlib.h>
#include "pol.h"

double paval_s (double a, int n, double *p, double x) {
    double y;
    double xa = x - a;
    y = 0;
    for (int i = n; 0 <= i; i--) {
	y = p[i] + y*xa;
    }
    return y;
}

int main (int argc, char *argv[]) {
    int n;
    double *p, x, r, a;

    if (argc != 2 || sscanf(argv[1],"%lf",&a)!=1) {
        fprintf(stderr, "paval_s a\n"); return -1;
    }

    if (plleg(stdin,&n,&p)) {
        fprintf(stderr, "pcl: error llegint el primer polinomi!\n");
        return -2;
    }

    while (fscanf(stdin, "%lf", &x) == 1) {
        r = paval_s(a, n, p, x);
        printf("%.16g %.16g\n", x, r);
    }

    free(p);
    return 0;
}
