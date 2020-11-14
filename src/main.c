#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"


int main(int argc, char *argv[]){


	if(argc > 4 && argc < 3){
		puts("Wrong amount of parameters expected 3");
		exit(0);
	}

	int size = atoi(argv[4]);
	numbers all;
	all.bin = calloc(size, sizeof(char));
	all.oct = calloc(size, sizeof(char));
	all.dec = calloc(size, sizeof(char));
	all.duo = calloc(size, sizeof(char));
	all.hex = calloc(size, sizeof(char));
	all.csm = calloc(size, sizeof(char));

	int i = 1;
	short base;
	if(!strcmp(argv[i], "-bin")){
		base = 2;
		numberconv(argv[i + 1], base, all.bin, 2, size);
		numberconv(argv[i + 1], base, all.oct, 8, size);
		numberconv(argv[i + 1], base, all.dec, 10, size);
		numberconv(argv[i + 1], base, all.duo, 12, size);
		numberconv(argv[i + 1], base, all.hex, 16, size);
	}else if (!strcmp(argv[i], "-oct")){
		base = 8;
		numberconv(argv[i + 1], base, all.bin, 2, size);
		numberconv(argv[i + 1], base, all.oct, 8, size);
		numberconv(argv[i + 1], base, all.dec, 10, size);
		numberconv(argv[i + 1], base, all.duo, 12, size);
		numberconv(argv[i + 1], base, all.hex, 16, size);
	}else if (!strcmp(argv[i], "-dec")){
		base = 10;
		numberconv(argv[i + 1], base, all.bin, 2, size);
		numberconv(argv[i + 1], base, all.oct, 8, size);
		numberconv(argv[i + 1], base, all.dec, 10, size);
		numberconv(argv[i + 1], base, all.duo, 12, size);
		numberconv(argv[i + 1], base, all.hex, 16, size);
	}else if (!strcmp(argv[i], "-duo")){
		base = 12;
		numberconv(argv[i + 1], base, all.bin, 2, size);
		numberconv(argv[i + 1], base, all.oct, 8, size);
		numberconv(argv[i + 1], base, all.dec, 10, size);
		numberconv(argv[i + 1], base, all.duo, 12, size);
		numberconv(argv[i + 1], base, all.hex, 16, size);
	}else if (!strcmp(argv[i], "-hex")){
		base = 16;
		numberconv(argv[i + 1], base, all.bin, 2, size);
		numberconv(argv[i + 1], base, all.oct, 8, size);
		numberconv(argv[i + 1], base, all.dec, 10, size);
		numberconv(argv[i + 1], base, all.duo, 12, size);
		numberconv(argv[i + 1], base, all.hex, 16, size);
	}else if (!strcmp(argv[i], "-csm")){

	}

	i = 3;
		if(!strcmp(argv[i], "-bin")){
			puts(all.bin);
		}else if (!strcmp(argv[i], "-oct")){
			puts(all.oct);
		}else if (!strcmp(argv[i], "-dec")){
			puts(all.dec);
		}else if (!strcmp(argv[i], "-duo")){
			puts(all.duo);
		}else if (!strcmp(argv[i], "-hex")){
			puts(all.hex);
		}else if (!strcmp(argv[i], "-csm")){
			//puts(all.csm);
		}

	return 0;
}
