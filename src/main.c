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

	while ((opt = getopt(argc, argv, ":i:o:n:s:")) != -1){
		switch(opt){
			case 'i':
				inpbase = atoi(optarg);
				break;

			case 'o' :
				outbase = atoi(optarg);
				break;

			case 'n' :
				number = calloc(strlen(optarg) + 1, sizeof(char));
				strcpy(number, optarg);
				break;

			case 's' :
				break;

		}

	}

	output = numberconv(number, inpbase, outbase);
	printf("%s\n", output);

	return 0;
}
