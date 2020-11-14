#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"
#include <unistd.h>
#include <math.h>


int main(int argc, char *argv[]){

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
				size = (int) log2(strtol(optarg, NULL, inpbase));
				number = calloc(size, 1);
				output = calloc(size, 1);
				strcpy(number, optarg);
				break;

		}

	}

	numberconv(number, inpbase, output, outbase);
	printf("%s\n", output);

	return 0;
}
