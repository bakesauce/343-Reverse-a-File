#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

/*
*
* Author: Mark Baker
* Date: 9/16/2018
* Class: CIS 343
* Project: C Project 1 - Reverse a File
*
* Description: This program will take in two command line arguments
* file1, and file2. It will take the contents of file1 and reverse them
* before writing them into file2.
*
*/
int main (int argc, char* argv[]) {
	
	char* buffer;
	char* tempbuffer;
	int filesize;

	//Reads the contents of the first command line argument (filename) into buffer, sets filesize
	//to the size of the file read
	filesize = read_file(argv[1], &buffer);
	
	//x will start at the end of buffer and decrement
	int x;
	//placeinbuff will start at 0 and incremen
	int placeinbuff = 0;
	
	//Allocates memory for tempbuffer
	tempbuffer = malloc(sizeof(char) * (filesize));
	
	//Loop to reverse the buffer. x starts at the end of the filesize, placeinbuff starts at 0
	for (x = filesize - 1; x >= 0; --x) {
		tempbuffer[placeinbuff] = buffer[x];
		placeinbuff++;
	}

	//Frees memory previously allocated to buffer
	free(buffer);

	//Writes the contents of tempbuffer into the second command line argument
	write_file(argv[2], tempbuffer, filesize);

	//Frees memory previously allocated to tempbuffer
	free(tempbuffer);
	
	return(0);

}
