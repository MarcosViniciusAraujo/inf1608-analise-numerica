#define K 0.5
#define R 200.0
#define MASSA 2.0
#define DELTA 0.002
#define GRAVIDADE 9.8
#define VENTO 20.0

void forca(double t, double x, double y, double *fx, double *fy);

double evolui(double t, double h, double x, double y, double xp, double yp, double *xn, double *yn);

void simula(double x0, double y0, double t_final, int n, double *x, double *y);
