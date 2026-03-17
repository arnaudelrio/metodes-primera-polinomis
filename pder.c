#include <stdio.h>
#include <stdlib.h>
#include "pol.h"

int main (int argc, char *argv[]) {
    int n, m;
    double *p, *r;

    if (plleg(stdin,&n,&p)) {
        fprintf(stderr, "pder: error llegint el polinomi!\n");
        return -2;
    }

    m = n == 0 ? 0 : n-1;
    r=malloc((m+1)*sizeof(double));
    if (r==NULL) {
        fprintf(stderr, "Error reservant memòria!\n");
        free(p);
        return -4;
    }
    pder(n,p,r);
    pescr(m,r,stdout);

    free(p);
    free(r);
    return 0;
}
