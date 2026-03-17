#include <stdio.h>
#include <stdlib.h>

/*
 * Llegir polinomi de fitxer
 */
#define ERROR(msg,ret) \
    fprintf(stderr,"plleg(): error " msg " !!\n");\
    iret=ret;\
    goto allib\

int plleg (FILE *fp, int *n, double **p) {
    int iret, i;
    iret=0;
    (*p)=NULL;
    if (fscanf(fp,"%d",n)!=1) { ERROR("llegint grau",-1); }
    (*p)=malloc(( (*n)+1 )*sizeof(double));
    if ((*p)==NULL) { ERROR("reservant memòria",-2); }
    for (i=0; i<=(*n); i++)
        if (fscanf(fp,"%lf",&(*p)[i])!=1) { ERROR("llegint coeficient",-3); }
    iret=0; goto fi;
    allib:
        if (*p!=NULL) free(*p);
    fi:
        return iret;
}

#undef ERROR

/*
 * Escriure polinomi a fitxer.
 */
void pescr (int n, double *p, FILE *fp) {
    int i;
    fprintf(fp,"%d\n",n);
    for (i=0; i<=n; i++) fprintf(fp,"%.16g\n",p[i]);
}

/*
 * Combinació lineal de polinomis.
 *
 * La funció que crida és responsable que r[] tingui lloc per
 * 1+max(m,n) coeficients.
 */
void pcl (int m, double *p, int n, double *q, double alf, double bet, double r[]) {
    int i, max = n;
    if (m > n) max = m;
    for (i=0; i<=max; i++) r[i] = 0;
    for (i=0; i<=m; i++) r[i] += alf*p[i];
    for (i=0; i<=n; i++) r[i] += bet*q[i];
}

/*
 * Producte de polinomis.
 *
 * La funció que crida és responsable que r[] tingui lloc per
 * 1+m+n coeficients.
 */
void pmul (int m, double *p, int n, double *q, double *r) {
    int i, j;
    for (i=0; i<=n+m; i++) r[i] = 0;
    for (i=0;i<=m;i++)
        for (j=0;j<=n;j++)
            r[i+j] += p[i]*q[j];
}

/*
 * Derivada d'un polinomi
 *
 * La funció que crida és responsable que dp[] tingui lloc
 * per a n coeficients.
 */
void pder (int n, double *p, double *dp) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i-1] = i*p[i];
}

/*
 * Avaluar un polinomi.
 */
double paval (int n, double *p, double x) {
    double y;
    y = 0;
    for (int i = n; 0 <= i; i--) {
        y = p[i] + y*x;
    }
    return y;
}
