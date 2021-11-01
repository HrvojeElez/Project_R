#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <unistd.h>

#define BROJ_PON 50

int main() {

    int fd = open("bin_file.bin", O_CREAT|O_RDWR);
    if (fd == -1) {
        printf("Error opening file.\n");
        return 1;
    }

    for (short i = 0; i < BROJ_PON; i++)
    {
        write_half(fd, i);
    }

    close(fd);

    fd = open("bin_file.bin", O_RDONLY);

    for(int i = 0; i < BROJ_PON; i++) 
    {
       short broj = read_half(fd);
       if (broj != i) 
       {
           printf("Write_half_word unsuccessful. %d %d\n", broj, i );
           return 0;
       }
    }

    printf("Write_half_word successful.\n");
    return 0;
}