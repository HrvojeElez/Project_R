// sin(2 * pi * 50 * t)
// freq = 200Hz

#include <stdio.h>
#include <io.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <cmplx.h>


#define FREQ 200
#define BROJ_PON 10

//typedef float cmplx_t[2];

int main() {
    
    int fd = open("bin_file.bin", O_CREAT|O_RDWR);
    if (fd == -1) {
        printf("Error opening file.\n");
        return 1;
    }
    double t_inc = 1.0 / FREQ;
    double t = 0;

    float vrijednost;
    void *a;
    int vrijednost_ieee;
    cmplx_t input[BROJ_PON];
    cmplx_t output[BROJ_PON];


    for(int i = 0; i < BROJ_PON; i++,t+=t_inc) {
       // printf("t %lf\n", t);

        vrijednost = sin(2 * PI * t * 50);
        //printf("vrijednost %lf\n", vrijednost);
        //a = (void *) &vrijednost;
        //vrijednost_ieee = *((int *) a);

        input[i][0] = vrijednost;
        input[i][1] = 0;
    }
    for(int i = 0; i < BROJ_PON; i++) {
       // printf("%d %.10f %.10f\n", i, input[i][0], input[i][1]);
    }
    cmplx_dft(input, output, BROJ_PON); 

    for(int i = 0; i < BROJ_PON; i++) {
       // printf("%d %.10f %.10f\n", i, output[i][0], output[i][1]);
    }

    for(int i = 0; i < BROJ_PON; i++) {
        a = (void *) &output[i][0];
        vrijednost_ieee = *((int *) a);

        write_word(fd,vrijednost_ieee);

        a = (void *) &output[i][1];
        vrijednost_ieee = *((int *) a);

        //printf("%d", vrijednost_ieee);
        write_word(fd,vrijednost_ieee);
    }

    printf("Test_dft successful.\n");

    return 0;
}