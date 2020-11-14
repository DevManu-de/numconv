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

int bintoany(numbers *);
int octtoany(numbers *);
int dectoany(numbers *);
int duotoany(numbers *);
int hextoany(numbers *);
int csmtoany(numbers *);

int dectobin(numbers *);
int dectooct(numbers *);
int dectoduo(numbers *);
int dectohex(numbers *);
int dectocsm(numbers *);


#endif
