// Code for question 1 of File IO assignment
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 80

int write(FILE *file, char *line);
int read(FILE *file, char *linebuf);

int main(int argc, char *argv[]) {
     if (argc != 3) {
          printf("Invalid usage\n");
          printf("Usage: ./twolines <text line1> <text line2>\n");
          return EXIT_FAILURE;
     }
     char line1[LINESIZE+1], line2[LINESIZE+1];
     FILE *outfile = fopen("fout.txt","w");
     if (outfile == NULL) {
          printf("Unable to open file fout.txt for writting\n");
          return EXIT_FAILURE;
     }
     write(outfile, argv[1]); 
     write(outfile, "\n"); 
     write(outfile, argv[2]); 
     write(outfile, "\n"); 
     
     if (outfile) fclose(outfile);
     
     FILE *infile = fopen("fout.txt","r");
     if (infile == NULL) {
          printf("Unable to open file fout.txt for reading\n");
          return EXIT_FAILURE;
     }
     read(infile, line1);
     read(infile, line2); 

     printf("Line1 = %s", line1);
     printf("Line2 = %s", line2);

     if (infile) fclose(infile);
     return EXIT_SUCCESS;
}

int write(FILE *file, char *line) {
    fputs(line, file);
    return EXIT_SUCCESS;
}

int read(FILE *file, char *linebuf) {
    fgets(linebuf, LINESIZE, file);
    return EXIT_SUCCESS;
}
