#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979

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
double cmplx_phs(cmplx_t a) {
    if(a[0] == 0) {
        if(a[1] > 0) return PI / 2.0;
        else if (a[1] < 0) return -PI /2.0;
        else return 0.0;
    }
    double result = atan(a[1] / a[0]);

    if(a[0] >= 0) {

        if(a[1] >= 0) {
            return result;
        }
        else {
            return result + 2 * PI;
        }
    }
    else {
        if(a[1] >= 0) {
            return result + PI;
        }
        else {
            return result + PI;
        }
    }
}

// returns real part of mag/_phs
double cmplx_real(double mag, double phs) {
    return cos(phs) * mag ;
}

// returns imaginary part of mag/_phs
double cmplx_imag(double mag, double phs) {
    return sin(phs) * mag ;
}

// returns dft transformation of complex input signal
void cmplx_dft(cmplx_t *input, cmplx_t *output, int N) {
    cmplx_t result, temp;
    double fi;

    for(int i = 0; i < N; i++)
    {
        output[i][0] = 0;
        output[i][1] = 0;

        for(int j = 0; j < N; j++) {
            fi = -2 * PI * (1.0/N) * i * j;
            temp[0] = cmplx_real(1,fi);
            temp[1] = cmplx_imag(1,fi);
            cmplx_mul(input[j],temp,result);

            output[i][0]+=result[0];
            output[i][1]+=result[1];
        }
    }
}

// returns inverse dft transformation of complex input signal
void cmplx_idft(cmplx_t *input, cmplx_t *output, int N) {
    
    cmplx_t result, temp;
    double fi;

    for(int i = 0; i < N; i++)
    {
        output[i][0] = 0;
        output[i][1] = 0;

        for(int j = 0; j < N; j++) {
            fi = -2 * PI * (1.0/N) * i * j;
            temp[0] = cmplx_real(1,fi);
            temp[1] = cmplx_imag(1,fi);
            cmplx_mul(input[j],temp,result);

            output[i][0]+=result[0];
            output[i][1]+=result[1];
        }

        output[i][0]*=(1./N);
        output[i][1]*=(1./N);

    }
}