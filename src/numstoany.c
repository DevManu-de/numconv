#include "numstoany.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *numberconv(char *src, const int basesrc, const int basedest){

    if(basedest > 36 || basesrc > 36 || basedest < 2 || basesrc < 2){
        fprintf(stderr, "Wrong base");
        return NULL;
    }

    //Converts the input number to decimal
    unsigned int converted = strtol(src, NULL, basesrc);

    unsigned int size = maxsize(converted);

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
    char *end = conv;

    //Removes leading 0's
    for(i = 0; i < size - 1; i++){
        if(conv[i] == '0'){
            end = &conv[i + 1];
        }else {
            break;
        }
    }

    char *endptr = malloc(strlen(end));
    strcpy(endptr, end);

    free(conv);

    return endptr;
}
