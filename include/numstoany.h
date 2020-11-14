#ifndef _NUMSTOANY_H_
#define _NUMSTOANY_H_

typedef struct nums{

    char *bin;
    char *oct;
    unsigned int decimal;
    char *duo;
    char *hex;
    char *csm;

} numbers;

int numberconv(char *__src, int __srcbse, char *__dest , int __destbse, const unsigned int __size);

#endif
