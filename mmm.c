#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define mash "mash "
#define mv "mv "
#define bin_path " ./out/bin"
#define miniat "miniat_console"

/* Matt Makes Miniat, Version 1.0, 2/16/15 
 * Program description:
 * + runs the mash command on the given .asm file
 * + moves the newly created .bin file to the bin path
 * + runs miniat_console on the newly created .bin file
 * + NOTE this only works with asm code, not c/cpp files
*/

int main(int argc, char **argv){

if (argc != 2) {
		fprintf(stderr, "You must specify a bin file name to run");
	}	
	
/* creating arrays for filenames */
char filename_asm[strlen(argv[1])];
char filename_bin[strlen(argv[1])];

/* copping cmd line arg to filename_asm and filename_bin */
strcpy(filename_asm, argv[1]);
strcpy(filename_bin, argv[1]);

/* filename_bin replaces file ext "asm" with "bin" */

filename_bin[strlen(argv[1])-3] = 'b';
filename_bin[strlen(argv[1])-2] = 'i';
filename_bin[strlen(argv[1])-1] = 'n';

/* declaring full command holding arrays */
char miniat_console[strlen(miniat) + strlen(bin_path) + strlen("/") + strlen(filename_bin)]; // miniat_console + bin_path + /filename_bin
char mover[strlen(mv) + strlen(filename_bin) + strlen(bin_path)]; 
char masher[strlen(filename_asm) + strlen(mash)];

printf( "filename_bin is : %s\n", filename_bin);

/* putting the full mash command in the mash holding array */
memset(masher, '\0', sizeof(masher));
strcpy(masher, mash);
strcat(masher, filename_asm);

//printf( "Mash Command is: %s\n", masher);

strcpy(mover, mv);
strcat(mover, filename_bin);

/*replaces the asm file extention with bin */


 
strcat(mover, bin_path);  

//printf("Move Command is: %s\n", mover);

strcpy(miniat_console, miniat);
strcat(miniat_console, bin_path);
strcat(miniat_console, "/");
strcat(miniat_console, filename_bin);
	
//printf("Miniat Command is: %s\n", miniat_console);	

/* THIS NEEDS TO BE SAFER, TODO */	
system(masher);
system(mover);
system(miniat_console);	

return 0;
}
	
