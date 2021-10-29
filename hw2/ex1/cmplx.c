#include <stdio.h>
#include <math.h>

typedef float cmplx_t[2];

// c = a / b;
void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = (a[0]*b[0] + a[1]*b[1] ) / (b[0]*b[0] + b[1]*b[1]);
    c[1] = (a[1]*b[0] - a[0]*b[1] ) / (b[0]*b[0] + b[1]*b[1]);

    return;
}

// c = a * b;
void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c) {
    c[0] = a[0]*b[0] - a[1]*b[1];
    c[1] = a[0]*b[1] + a[1]*b[0];

    return;
}

// returns |a|
double cmplx_mag(cmplx_t a) {
    return sqrt(a[0]*a[0] + a[1]*a[1]);
}

// returns phase in radians of a 
double cmplx_phs(cmplx_t a);

// returns real part of mag/_phs
double cmplx_real(double mag, double phs);

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs);

// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N);

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N);

int main()
{
    cmplx_t prvi = {1,1};
    cmplx_t drugi = {1,1};
    cmplx_t treci = {0,0};

    cmplx_mul(prvi,drugi,treci);

    printf("%f %f\n", treci[0], treci[1]);
    printf("%f\n", cmplx_mag(prvi));

    return 0;
}