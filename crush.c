#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define mash "mash "
#define mv "mv "
#define bin_path " ./out/bin"
#define miniat "miniat_console"
#define mash_error_log " 2> mash_error.log"
/*
 *error logs redirect any errors from the commands to a respective log file 
 */

/* Miniat-Crush, Version 1.3, Last Revision 3/31/15
 * @author: Matthew Preisendorfer
 * Program description:
 * + runs the mash command on the given .asm file
 * + moves the newly created .bin file to the bin path
 * + runs miniat_console on the newly created .bin file
 * + NOTE this only works with asm code, not c/cpp files
 * + redirects error messages to log files
 * + if errors exsist in .asm files, crush will close without running miniat_console
*/

int main(int argc, char **argv){

if (argc != 2) {
		fprintf(stderr, "You must specify a asm file name to run");
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
char masher[strlen(filename_asm) + strlen(mash) + strlen(mash_error_log)];


/*** Masher Holding Array ***/
memset(masher, '\0', sizeof(masher));
strcpy(masher, mash);
strcat(masher, filename_asm);
strcat(masher, mash_error_log);	

/*** Mover Holding Array ***/
memset(mover, '\0', sizeof(mover));	
strcpy(mover, mv);
strcat(mover, filename_bin);
strcat(mover, bin_path);  

/*** Miniat_console Holding Array ***/
memset(miniat_console, '\0', sizeof(miniat_console));
strcpy(miniat_console, miniat);
strcat(miniat_console, bin_path);
strcat(miniat_console, "/");
strcat(miniat_console, filename_bin);	
	
	

/* THIS NEEDS TO BE SAFER, TODO */	

system(masher);
	
/* 
 * This portion of code tests to see if any error logs have been written to the mash_error.log file
 * If there are errors, crush will not continue running the rest of the commands
 */
	
FILE *fp;
char *path = "mash_error.log";
long size;
	
fp = fopen(path, "r");
 	if (fp)
    {
        fseek (fp, 0, SEEK_END);
        size = ftell(fp);
        fclose(fp);
    }

	if(size > 0){
		fprintf (stderr, "There are errors in the provided .asm file.\nPlease check the mash_error.log file more more information.\n");
		return -1;
	}
	else if(size == 0){
	/*
	 * If no errors are returned by mash, the error log file is deleted
	 */
	system("rm mash_error.log"); 
	}
	
	else{
	fprintf (stderr, "Impossible!!");
	return -1;	
	}	
	
system(mover);
system(miniat_console);	

return 0;
}
	
