#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"


int main(int argc, char *argv[]){

	char *a = "1011";
	char *b = malloc(5);
	numberconv(a, 2, b, 8);
	printf("%s\n", b);
	free(b);
	exit(0);

/*
	if(argc > 4 && argc < 3){
		puts("Wrong amount of parameters expected 2 or 3");
		exit(0);
	}

	numbers all;

	int i;
	for(i = 1; i < argc; i++){

		if(!strcmp(argv[i], "-bin")){
			all.bin = malloc(strlen(argv[i + 1]) * sizeof(char));
			strcpy(all.bin, argv[i + 1]);
			bintoany(&all);
		}else if (!strcmp(argv[i], "-oct")){

		}else if (!strcmp(argv[i], "-dec")){

		}else if (!strcmp(argv[i], "-duo")){
		
		}else if (!strcmp(argv[i], "-hex")){

		}else if (!strcmp(argv[i], "-csm")){

		}
	}

	printf("%s %d %s %s %s\n", all.bin, all.decimal, all.oct, all.hex, all.duo);

*/
}
