#include <stdlib.h>
#include <stdio.h>

/*
    Memory addresses = 2^12
    Block Size = 4 
    Total Cache lines = 16 
    Sets = Lines per Se / 4 = 4
*/


const int CACHE_LINES = 16;
const int BLOCK_SIZE = 4;
const int MAX_ADDRESS = 4096; 

int main(int argc, char** argv){

    if(argc != 3){ 
        printf("Invalid number of arguments!\n");
        return EXIT_FAILURE;

    }

    FILE *fp = fopen("r", argv[1]);
    if (fp == NULL){
        printf("Error opening the file: %s", argv[1]);
        return EXIT_FAILURE;
    }






    return EXIT_SUCCESS;
}