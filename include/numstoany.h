#ifndef _NUMSTOANY_H_
#define _NUMSTOANY_H_

typedef struct nums{

    char *bin;
    char *oct;
    long decimal;
    char *duo;
    char *hex;
    char *csm;

} numbers;

int bintoany();
int octtoany();
int dectoany();
int duotoany();
int hextoany();
int csmtoany();



#endif
