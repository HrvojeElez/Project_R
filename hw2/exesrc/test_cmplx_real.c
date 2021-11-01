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
            double complex num = i + j * I;
            cmplx_t second;
            second[0] = i * 1.0;
            second[1] = j * 1.0;
            if(fabs(creal(num) - cmplx_real(cmplx_mag(second), cmplx_phs(second))) >= red_greske) {
                printf("Cmplx_real unsuccessful. %d %d %f %f \n", i, j, creal(num), cmplx_real(cmplx_mag(second), cmplx_phs(second)) );
                return 0;
            }
        }
        
    }

    printf("Cmplx_real successful.\n");
    return 0;
}