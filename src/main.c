#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"
#include <unistd.h>
#include <math.h>


int main(int argc, char *argv[]){

	//char *a = "f16";
	//char *b = malloc((int) (log10(strtol(a, NULL, 16)) / log10(2)) + 1);
	//numberconv(a, 16, b, 2, 1);
	//printf("%d\n", (int) log2(5) + 1);
	//exit(0);

	char opt;
	unsigned int inpbase;
	unsigned int outbase;
	char *number;
	char *output;
	int size;

	while ((opt = getopt(argc, argv, ":i:o:n:")) != -1){
		switch(opt){
			case 'i':
				inpbase = atoi(optarg);
				break;

			case 'o' :
				outbase = atoi(optarg);
				break;

			case 'n' :
				size = (int) log2(atoi(optarg));
				number = malloc(size);
				output = malloc(size);
				strcpy(number, optarg);
				break;

		}

	}

	numberconv(number, inpbase, output, outbase);
	printf("%s\n", output);

	return 0;
}
