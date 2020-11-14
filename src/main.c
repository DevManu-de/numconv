#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"


int main(int argc, char *argv[]){

	if(argc > 4 && argc < 3){
		puts("Wrong amount of parameters expected 2 or 3");
		exit(0);
	}

	numbers all;

	int i;
	for(i = 1; i < argc; i++){

		if(!strcmp(argv[i], "-bin")){

		}else if (!strcmp(argv[i], "-oct")){

		}else if (!strcmp(argv[i], "-dec")){

		}else if (!strcmp(argv[i], "-duo")){
		
		}else if (!strcmp(argv[i], "-hex")){

		}else if (!strcmp(argv[i], "-csm")){

		}
	}

}
