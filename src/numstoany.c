/* See LICENSE file for copyright and license details. */

#include "numstoany.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *numberconv(const char *src, const unsigned short basesrc, const unsigned short basedest){

    if(basedest > 36 || basesrc > 36 || basedest < 2 || basesrc < 2){

        die("Wrong base\n");
    }

    if (*src == '0')
        puts(src);

    //Converts the input number to decimal
    int converted = strtol(src, NULL, basesrc);

    converted = (converted < 0 ? abs(converted) : converted);

    unsigned int maxsize = maxsize(converted);

    short *rests = calloc(maxsize, sizeof(*rests));
    char *conv = calloc(maxsize, sizeof(*conv));

    //Devides the number and writes it reversed in the array
    unsigned int i;
    for (i = 0; converted > 0; ++i){
        rests[i] = converted % basedest;
        converted /= basedest;
    }

    //Convert numbers to characters if needed and reverses the array
    for (i = 0; i < maxsize - 1; ++i){
        if (rests[i] > 9){
            conv[maxsize - 2 - i] = rests[i] + 55;
        }else {
            conv[maxsize - 2 - i] = rests[i] + '0';
        }

    }

    free(rests);
   
    conv[maxsize - 1] = '\0';
    char *end = conv;

    //Removes leading 0's
    while (*end == '0')
        ++end;

    //copys the string to new memory location and returns it
    char *endptr = strdup(end);

    free(conv);

    return endptr;
}

void die(char *message){

    fputs(message, stderr);
    exit(-1);

}
