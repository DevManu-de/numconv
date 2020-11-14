#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"


int main(int argc, char *argv[]){


	if(argc > 4 && argc < 3){
		puts("Wrong amount of parameters expected 2 or 3");
		exit(0);
	}

	//int size = strlen(argv[2]) * 2;
	int size = 5;
	numbers all;
	all.bin = calloc(size, sizeof(char));
	all.oct = calloc(size, sizeof(char));
	all.dec = calloc(size, sizeof(char));
	all.duo = calloc(size, sizeof(char));
	all.hex = calloc(size, sizeof(char));
	all.csm = calloc(size, sizeof(char));

	int i;
	for(i = 1; i < argc; i++){

		if(!strcmp(argv[i], "-bin")){
			numberconv(argv[i + 1], 2, all.bin, 2, size);
			numberconv(argv[i + 1], 2, all.oct, 8, size);
			numberconv(argv[i + 1], 2, all.dec, 10, size);
			numberconv(argv[i + 1], 2, all.duo, 12, size);
			numberconv(argv[i + 1], 2, all.hex, 16, size);
		}else if (!strcmp(argv[i], "-oct")){

		}else if (!strcmp(argv[i], "-dec")){

		}else if (!strcmp(argv[i], "-duo")){
		
		}else if (!strcmp(argv[i], "-hex")){

		}else if (!strcmp(argv[i], "-csm")){

		}
	}

	printf("%s %s %s %s %s\n", all.bin, all.oct, all.dec, all.duo, all.hex);

}
