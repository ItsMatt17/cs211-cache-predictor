#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ADDRS_SIZE 1024
#define PREDICTIONS 800


int main(int argc, char** argv){
    if(argc != 3){ 
        printf("Invalid number of arguments!\n");
        return EXIT_FAILURE;
    }
    
    FILE *in = fopen(argv[1], "r");
    if (in == NULL){
        printf("Error opening the file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }   

    int arr[ADDRS_SIZE];
    int idx = 0;
    int curr;
    while (fscanf(in, "%x", &curr) != EOF){ 
        arr[idx] = curr;
    }   

    fclose(in);
    in = NULL;

    FILE *out = fopen(argv[2], "w");
    if (out == NULL){
        printf("Error opening the file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int stride = arr[idx - 1] - arr[idx - 2];
    int last = arr[idx - 1];

    for(int i = 1; i < PREDICTIONS; i++){ 
        fprintf(out, "0x%x\n", last + (i * stride));
    }

    fclose(out);
    return EXIT_SUCCESS;
}

