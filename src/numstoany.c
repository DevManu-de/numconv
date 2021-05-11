#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "numstoany.h"
#include "xmemtools.h"

char *numberconv(const char *src, const unsigned short basesrc, const unsigned short basedest){

    if (basedest > 36 || basesrc > 36 || basedest < 2 || basesrc < 2)
        die("Wrong base(input %d, output %d)\n", basesrc, basedest);

    //Converts the input number to decimal
    long long converted = strtoll(src, NULL, basesrc);
    if (converted == 0)
        return strdup("0");

    converted = (converted < 0 ? -converted : converted);

    unsigned int maxsize = maxsize(converted);

    char *rests = xcalloc(maxsize, sizeof(*rests));
    char *conv = xcalloc(maxsize, sizeof(*conv));

    //Devides the number and writes it reversed in the array
    unsigned int i;
    for (i = 0; converted > 0; ++i) {
        rests[i] = converted % basedest;
        converted /= basedest;
    }

    //Convert numbers to characters if needed and reverses the array
    for (i = 0; i < maxsize - 1; ++i) {
        if (rests[i] > 9){
            conv[maxsize - 2 - i] = rests[i] + 55;
        }else {
            conv[maxsize - 2 - i] = rests[i] + '0';
        }

    }

    xfree(rests);
   
    conv[maxsize - 1] = '\0';
    char *end = conv;

    //Removes leading 0's
    while (*end == '0')
        ++end;

    //copys the string to new memory location and returns it
    char *endptr = strdup(end);

    xfree(conv);

    return endptr;
}

void die(char *format, ...){
    va_list ap;
    va_start(ap, format);
    vfprintf(stderr, format, ap);
    va_end(ap);
    exit(-1);
}
