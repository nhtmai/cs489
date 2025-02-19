#include <stdlib.h>
#include <stdio.h>
    
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    FILE* fp = fopen(argv[1], "r"); 
  
    // checking if the file exists and can be read
    if (fp == NULL) { 
        fprintf(stderr, "File Not Found!\n"); 
        return -1; 
    } 
    
    int seek_status = fseek(fp, 0, SEEK_END);
    
    if (seek_status != 0) { // moving to end of file failed
        fclose(fp);
        fprintf(stderr, "Cannot determine file size!\n");
        return -1;
    }

    // getting size of file 
    long int file_size = ftell(fp);
    fclose(fp);
    if (file_size == -1L) { // if failed
        fprintf(stderr, "Cannot determine file size!\n");
        return -1;
    } else {
        printf("%ld\n", file_size);
    }
}