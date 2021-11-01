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
            if(fabs(carg(num) - cmplx_phs(second)) >= red_greske) {
                printf("Cmplx_phs unsuccessful. \n");
                return 0;
            }
        }
        
    }

    printf("Cmplx_phs successful.\n");
    return 0;
}