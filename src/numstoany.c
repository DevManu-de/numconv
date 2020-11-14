#include "numstoany.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int numberconv(char *src, const int basesrc, char *dest, const int basedest){

    if(basesrc == basedest){
        strcpy(dest, src);
        return 0;
    }

    if(basedest > 36 || basesrc > 36){
        fprintf(stderr, "Wrong base");
        return -1;
    }

    long converted = strtol(src, NULL, basesrc);

    //int size = converted / basedest;

    int size = 5;

    short rests[size];
    char *conv = calloc(size, sizeof(char));

    long i;
    for(i = 0; converted > 0; i++){
        rests[i] = converted % basedest;
        converted /= basedest;
    }

    for(i = 0; i < size; i++){
        if(rests[i] > 9){
            conv[i] = rests[i] + 55;
        }else {
            conv[i] = rests[i] + '0';
        }

    }

    conv[strlen(conv) - 1] = '\0';


    char *reversed = calloc(size, sizeof(char));

    for(i = 0; i < size; i++){
       reversed[i] = conv[size - 2 - i];
    }

    reversed[size - 1] = '\0';

    strcpy(dest, reversed);

    free(conv);
    free(reversed);

    return 0;
}
