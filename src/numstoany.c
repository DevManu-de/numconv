/* See LICENSE file for copyright and license details. */

#include "numstoany.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *numberconv(const char *src, const unsigned short basesrc, const unsigned short basedest){

    if(basedest > 36 || basesrc > 36 || basedest < 2 || basesrc < 2){

        die("Wrong base");
    }

    //Converts the input number to decimal
    int converted = strtol(src, NULL, basesrc);

    converted = (converted < 0 ? abs(converted) : converted);

    unsigned int size = maxsize(converted);

    short *rests = calloc(size, sizeof(short));
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

    free(rests);
   
    conv[size - 1] = '\0';
    char *end = conv;

    //Removes leading 0's
    for(i = 0; i < size - 1; i++){
        if(conv[i] == '0' && strlen(conv) > 1){
            end = &conv[i + 1];
        }else {
            break;
        }
    }

    //copys the string to new memory location and return it
    char *endptr = malloc(strlen(end));
    strcpy(endptr, end);

    free(conv);

    return endptr;
}


void die(char *message){

    fprintf(stderr, "%s\n", message);
    exit(-1);

}
