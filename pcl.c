#include <stdio.h>
#include <stdlib.h>
#include "pol.h"

int main (int argc, char *argv[]) {
    int n1, n2, n3;
    double alf, bet, *p1, *p2, *p3;

    if (argc!=3
         || sscanf(argv[1],"%lf",&alf)!=1
         || sscanf(argv[2],"%lf",&bet)!=1) {
        fprintf(stderr, "./pcl alf bet\n");
        return -1;
    }

    if (plleg(stdin,&n1,&p1)) {
        fprintf(stderr, "pcl: error llegint el primer polinomi!\n");
        return -2;
    }
    if (plleg(stdin,&n2,&p2)) {
        fprintf(stderr, "pcl: error llegint el segon polinomi!\n");
        free(p1);
        return -2;
    }

    n3=n1; if (n2>=n3) n3=n2;
    p3=malloc((1+n3)*sizeof(double));
    if (p3==NULL) {
        fprintf(stderr, "Error reservant memòria!\n");
        free(p1); free(p2);
        return -4;
    }
    pcl(n1,p1,n2,p2,alf,bet,p3);
    pescr(n3,p3,stdout);

    free(p1);
    free(p2);
    free(p3);
    return 0;
}
