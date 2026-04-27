#include <stdio.h>
#include <stdlib.h>
#include "pol.h"

void pescr_m (int n, double *p, FILE *fp) {
    int i;
    fprintf(fp,"%d\n",n);
    for (i=n; i>=0; i--) fprintf(fp,"%.16g\n",p[i]);
}

int main (int argc, char *argv[]) {
    int n1, n2, nr;
    double *p1, *p2, *r;

    if (plleg(stdin,&n1,&p1)) {
        fprintf(stderr, "pmul: error llegint el primer polinomi!\n");
        return -2;
    }
    if (plleg(stdin,&n2,&p2)) {
        fprintf(stderr, "pmul: error llegint el segon polinomi!\n");
        free(p1);
        return -2;
    }

    nr=n1+n2;
    r=malloc((1+nr)*sizeof(double));
    if (r==NULL) {
        fprintf(stderr, "Error reservant memòria!\n");
        free(p1); free(p2);
        return -4;
    }
    pmul(n1,p1,n2,p2,r);
    pescr_m(nr,r,stdout);

    free(p1);
    free(p2);
    free(r);
    return 0;
}
