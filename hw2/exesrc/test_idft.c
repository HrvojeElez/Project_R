// sin(2 * pi * 50 * t)
// freq = 200Hz

#define FREQ 200
#define PI 3.14159265358979
#define BROJ_PON 10

#include <stdio.h>
#include <io.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <cmplx.h>

int main() {
    
    int fd = open("bin_file.bin", O_RDONLY);

    cmplx_t input[BROJ_PON];
    cmplx_t output[BROJ_PON];
    int vrijednost;
    void *a;
    float vrijednost_ieee;
    float t_inc = 1.0 / FREQ;
    float t = 0;

    for(int i = 0; i < BROJ_PON ; i++) {
        for(int j = 0; j < 2; j++) {
            vrijednost = read_word(fd);
            a = (void *) &vrijednost;
            vrijednost_ieee = *((float *) a);

            //printf("%.10f\n", vrijednost_ieee);

            input[i][j] = vrijednost_ieee;
        }  
    }

    cmplx_idft(input,output, BROJ_PON);

    /*for (int i = 0; i < BROJ_PON; i++)
    {
        printf("%d %f %f\n", i, output[i][0], output[i][1]);
    }*/
    
    double rezultat;
    
    for(int i = 0; i < BROJ_PON; i++) {
      // printf("t %lf\n", t);


        rezultat = sin(2 * PI * t * 50);
        //printf("sinus %lf\n", sin(2 * PI * t * 50));
        //printf("Razlika_%d = %8f i, %8f j\n", i, fabs(output[i][0] - rezultat), fabs(output[i][1] - 0));

        t+=t_inc;
    }

    printf("test_idft successful.\n");
    
    return 0;
}