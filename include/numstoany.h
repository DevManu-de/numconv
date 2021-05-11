/* See LICENSE file for copyright and license details. */

#ifndef _NUMSTOANY_H_
#define _NUMSTOANY_H_

#define maxsize(__num) log2(__num) + 2 > 0 ? log2(__num) + 2 : 2

char *numberconv(const char *__src, const unsigned short __srcbse, const unsigned short __destbse);

void die(char *format, ...);
#endif
