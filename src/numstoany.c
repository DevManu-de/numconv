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
    dectoduo(all);
    dectohex(all);
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
    return 0;
}

int dectoduo(numbers *all){

    short arr[10];
    int counter = 0;
    int num = all->decimal;

    while(num > 0){
        arr[counter] = num % 12;
        num /= 12;
        counter++;

    }

    char ptr[10];
    int i;
    for(i = 0; i < 10; i++){
        if(arr[i] == 10){
            ptr[i] = 'A';
        }else if (arr[i] == 11){
            ptr[i] = 'B';
        }else if (arr[i] == 12){
            ptr[i] = 'C';
        }else {
            ptr[i] = arr[i] + '0';

        }

    }

    all->duo = malloc(10);
    sprintf(all->duo, "%c", ptr[0]);

    return 0;
}

int dectohex(numbers *all){

    all->hex = malloc(strlen(all->bin));
    sprintf(all->hex, "%X", all->decimal);
    return 0;
}
