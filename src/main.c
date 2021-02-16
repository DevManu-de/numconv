/* See LICENSE file for copyright and license details. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "numstoany.h"
#include <unistd.h>
#include <math.h>


int main(int argc, char *argv[]) {

    char opt;
	  //char is used to reduce memory
	  unsigned char inpbase = 0;
	  unsigned char outbase = 0;

	  char *number = NULL;
	  char *characters = NULL;
	  char *output;
	  unsigned short i;
	  unsigned short lengh;

	  while ((opt = getopt(argc, argv, ":i:o:n:s:")) != -1){
		    switch(opt){
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
				    lengh = strlen(optarg);
				    characters = strdup(optarg);
				    break;

			  case ':':
				    printf("Option -%c requires an argument\n", optopt);
				    exit(-1);
				    break;

			  case '?':
				    printf("Unknown option -%c", optopt);
				    exit(-2);
				    break;
		    }

	  }  

    /* If number is converted to number */
	  if(number && inpbase && outbase){

		    output = numberconv(number, inpbase, outbase);
		    puts(output);
		    free(output);

	  }else if(characters && outbase) {
        /* Number is the string that holds each character as an decimal number but as a string */
		    number = malloc(4);
		    for(i = 0; i < lengh; ++i){
            /* Convert to decimal */
			      sprintf(number, "%d", characters[i]);
            /* Get converted number */
			      output = numberconv(number, 10, outbase);
            /* Print converted number */
			      printf("%s ", output);

			      free(output);
		    }

		    free(characters);
		    puts("");
	  }else {

		    die("Not enough parameters or wrong values\n");
	  }

	  free(number);

	  return 0;
}
