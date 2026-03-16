/* Entrada i sortida */
int plleg (FILE *fp, int *n, double **p);
void pescr (int n, double *p, FILE *fp);
/* Operacions */
void pcl (int m, double *p, int n, double *q, double alf, double bet, double r[]);
void pmul (int m, double *p, int n, double *q, double *r);
void pder (int n, double *p, double *dp);
double paval (int n, double *p, double x);
