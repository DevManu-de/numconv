#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"
#include <unistd.h>
#include <math.h>


int main(int argc, char *argv[]){

	char opt;
	unsigned int inpbase = 0;
	unsigned int outbase = 0;
	char *number = NULL;
	char **characters;
	char *output;
	int i;
	int lengh;
	char *arg;

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

				if(strlen(optarg) == 1 && optarg[0] == '0'){

					die("Number connot be 0");
				}
			
				strcpy(number, optarg);
				break;

			case 's' :
				lengh = strlen(optarg);
				characters = calloc(lengh, sizeof(char*));
				arg = malloc(lengh);
				strcpy(arg, optarg);
				for(i = 0; i < lengh; i++){
					characters[i] = calloc(1, sizeof(char));
					memcpy(characters[i], &arg[i], sizeof(char));
				}

				break;

		}

	}

	if(number && inpbase && outbase){

		output = numberconv(number, inpbase, outbase);
		puts(output);

	}else if(outbase) {
		number = calloc(1, sizeof(int));
		for(i = 0; i < lengh; i++){
			sprintf(number, "%d", characters[i][0]);
			output = numberconv(number, 10, outbase);
			printf("%s ", output);

		}
		printf("\n");
		free(characters);
		free(arg);
	}else {

		die("Not enough parameters or wrong values");
	}

	free(number);
	free(output);

	return 0;
}
