#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
        int ch;
        FILE *fp1, *fp2, *fp3;
        char fname1[MAX], fname2[MAX], output[MAX];

        /* get the first file name from the user */
        printf("Enter your first file name:");
        fgets(fname1, MAX, stdin);
        fname1[strlen(fname1) - 1] = '\0';

        /* get the second file name from the user */
        printf("Enter your second file name:");
        fgets(fname2, MAX, stdin);
        fname2[strlen(fname2) - 1] = '\0';

        /* get the output file name from the user */
        printf("Enter your destination file name:");
        fgets(output, MAX, stdin);
        output[strlen(output) - 1] = '\0';

        /* open the first file in read mode */
        fp1 = fopen(fname1, "r");

        /* error handling */
        if (!fp1) {
                printf("Unable to open the file %s\n", fname1);
                return 0;
        }
        /* open the second file in read mode */
        fp2 = fopen(fname2, "r");

        /* error handling */
        if (!fp2) {
                printf("Unable to open the file %s!!\n", fname2);
                fclose(fp1);
                return 0;
        }

        /* open the output file in write mode */
        fp3 = fopen(output, "w");

        /* error handling */
        if (!fp3) {
                printf("Unable to open the file %s!!\n", output);
                fclose(fp1);
                fclose(fp2);
                return 0;
        }

        /* copy the contents of first file to output file */
        while (!feof(fp1)) {
                ch = fgetc(fp1);
                if (ch != EOF) {
                        fputc(ch, fp3);
                }
        }

        /* copy the contents of second file to output file */
        while (!feof(fp2)) {
                ch = fgetc(fp2);
                if (ch != EOF) {
                        fputc(ch, fp3);
                }
        }

        /* close the opened files */
        fclose(fp1);
        fclose(fp2);
        fclose(fp3);
        return 0;
  }
