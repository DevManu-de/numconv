#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "numstoany.h"
#include "xmemtools.h"

int main(int argc, char *argv[], __attribute__((unused)) char *envp[]) {
    
    unsigned short inpbase = 0;
    unsigned short outbase = 0;
    
    char *number = NULL;
    char *characters = NULL;
    char *output;
    unsigned long length;

    int opt;
    while((opt = getopt(argc, argv, ":i:o:n:s:")) != -1) {
        switch(opt) {
            case 'i':
                inpbase = atoi(optarg);
                break;
    
            case 'o':
                outbase = atoi(optarg);
                break;
    
            case 'n':
                number = strdup(optarg);
                break;
    
            case 's':
                length = strlen(optarg);
                characters = strdup(optarg);
                break;
    
            case ':':
                die("Option -%c requires an argument\n", optopt);
                break;
    
            case '?':
                die("Unknown option -%c\n", optopt);
                break;

        }
    }

    if (inpbase && number && outbase) {
        output = numberconv(number, inpbase, outbase);
        puts(output);
        xfree(output);
    } else if (characters && outbase) {
        number = xmalloc(4);
        for (unsigned long i = 0; i < length; ++i) {
            snprintf(number, 4, "%d", characters[i]);
            output = numberconv(number, 10, outbase);
            printf("%s ", output);
            xfree(output);
        }
        xfree(characters);
        putc('\n', stdout);
    } else {
        die("Not enough parameters or wrong values\n");
    }

    xfree(number);

	return 0;
}

