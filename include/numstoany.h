#ifndef _NUMSTOANY_H_
#define _NUMSTOANY_H_

#define maxsize(__num) log2(__num)+2

char *numberconv(char *__src, int __srcbse, int __destbse);
void die(char *__messge);

#endif
