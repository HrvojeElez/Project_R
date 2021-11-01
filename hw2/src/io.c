#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define SIZE_OF_WORD 4
#define SIZE_OF_HALF_WORD 2

// read 32 bit (4 bytes) word

/**
 * @brief Read 4 byte word from input file.
 * 
 * @param fd file descriptor 
 * @return -1 if something went wrong
 *          0 if everything OK
 */
int read_word(int fd) {

    int result = 0;

    if (read(fd,  &result, SIZE_OF_WORD) == SIZE_OF_WORD) {
       // printf("SUCCESS\n");
        return result;
    }
    else return -1;
}

// read 16 bit (2 bytes) word
short read_half(int fd) {
    short result = 0;

    if (read(fd,  &result, SIZE_OF_HALF_WORD) == SIZE_OF_HALF_WORD) {
        //printf("SUCCESS\n");
        return result;
    }
    else return -1;
}

// write 32 bit (4 bytes) word
void write_word(int fd, int word) {

    if (write(fd, &word, SIZE_OF_WORD) == SIZE_OF_WORD) ;//printf("SUCCESS WRITE\n");
    else printf("WRITE UNSUCCESSFULL\n");
}

// write 16 bit (2 bytes) word
void write_half(int fd, short word) {

    if (write(fd, &word, SIZE_OF_HALF_WORD) == SIZE_OF_HALF_WORD) {
       // printf("SUCCESS WRITE\n");
    }
    else printf("WRITE UNSUCCESSFULL\n");
}

