#include <stdlib.h>
#include <stdio.h>
#include <string.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";

    int CMD_SIZE = 8;
    int FILENAME_SIZE = strlen(argv[1]);
    
    if (CMD_SIZE + FILENAME_SIZE < BUFSIZE) {
        strncat(cmd, argv[1], FILENAME_SIZE);
        system(cmd);
    }
}