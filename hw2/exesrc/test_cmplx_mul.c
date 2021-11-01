#include <stdio.h>
#include <complex.h>
#include <cmplx.h>
#include <math.h>

#define BROJ_PON 20
#define red_greske 10e-4

int main() {

    for(int i=0; i<BROJ_PON; i++) {
        for (int j = 0; j < BROJ_PON; j++)
        {
            double complex num1 = i + j * I;
            double complex num2 = 2;
            double complex result1 = cpow(num1,num2);
            cmplx_t second;
            second[0] = i * 1.0;
            second[1] = j * 1.0;

            cmplx_t result2;

            cmplx_mul(second,second,result2);

            if (   fabs(cmplx_real(cmplx_mag(result2), cmplx_phs(result2)) -  creal(result1)) >= red_greske
                || fabs(cmplx_imag(cmplx_mag(result2), cmplx_phs(result2)) -  cimag(result1)) >= red_greske) {
                printf("Cmplx_mul unsuccessful.  %f %f \n", creal(result1), cmplx_real(cmplx_mag(result2), cmplx_phs(result2)));
                return 0;
            }
        }
        
    }

    printf("Cmplx_mul successful.\n");
    return 0;
}