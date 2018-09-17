#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
*
* Author: Mark Baker
* Date: 9/16/2018
* Class: CIS 343
* Project: C Project 1 - Reverse a File
*
* Description: The file_utils.c file contains the functions declared in the file_utils.h file.
*
*/

int read_file( char* filename, char **buffer ) {
	
	//Taken from info on Ira Woodrings BB Assignment Page
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;

	FILE *fp = fopen(filename, "r");

	//Error handling to check if the file was able to be opened
	if ( fp == NULL) {
		fprintf( stderr, "Failed to open the file." );
		exit(1);
	} else {
		//reads the contents of the file into the buffer after allocating
		//proper memory for the buffer.
		*buffer = malloc(sizeof(char) * (size));
		if (buffer == NULL) {
			fprintf( stderr, "Failed to allocate sufficient bytes into the buffer." );
			exit(1);
		}
		fread(*buffer, sizeof(char), size, fp);
		fclose(fp);
		
	}
	
	return(size);

}

int write_file( char* filename, char *buffer, int size) {
	
	FILE *fp = fopen(filename, "w");
	
	//Error handling to check if the file was able to be opened
	if ( fp == NULL ) {
		fprintf( stderr, "Failed to open the file." );
		exit(1);
	} else {
		//Writes the contents of buffer into the file
		fwrite(buffer, sizeof(char), size, fp);
		fclose(fp);

	}

	return (0);

}
