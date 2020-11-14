#include "numstoany.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int bintoany(numbers *all){

    int i, pos = 1, number = 0;
    for(i = strlen(all->bin) - 1; i >= 0; i--){
        int bit = all->bin[i] - '0';
        number += bit * pos;
        pos *= 2;
    }

    all->decimal = number;
    dectooct(all);
    //dectoduo(all);
    //dectohex(all);
    //dectocsm(all);

    return 0;
}


//int octtoany(char *, numbers);
//int dectoany(char *, numbers);
//int duotoany(char *, numbers);
//int hextoany(char *, numbers);
//int csmtoany(char *, numbers);

int dectooct(numbers *all){

    all->oct = malloc(strlen(all->bin));
    sprintf(all->oct, "%o", all->decimal);
}
