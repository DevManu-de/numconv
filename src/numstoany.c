#include "numstoany.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int numberconv(char *src, const int basesrc, char *dest, const int basedest, const unsigned int size){

    if(basesrc == basedest){
        strcpy(dest, src);
        return 0;
    }

    if(basedest > 36 || basesrc > 36 || basedest < 2 || basesrc < 2){
        fprintf(stderr, "Wrong base");
        return -1;
    }

    //Converts the input number to decimal
    unsigned int converted = strtol(src, NULL, basesrc);

    short rests[size];
    char *conv = calloc(size, sizeof(char));

    //Devides the number and writes it reversed in the array
    unsigned int i;
    for(i = 0; converted > 0; i++){
        rests[i] = converted % basedest;
        converted /= basedest;
    }

    //Convert numbers to characters if needed and reverses the array
    for(i = 0; i < size - 1; i++){
        if(rests[i] > 9){
            conv[size - 2 - i] = rests[i] + 55;
        }else {
            conv[size - 2 - i] = rests[i] + '0';
        }

    }

    conv[size - 1] = '\0';

    //copys the string to the destination
    strcpy(dest, conv);

    free(conv);

    return 0;
}
