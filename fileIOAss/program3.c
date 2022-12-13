#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100
#define FAILURE 0

int getFileString (char ***text, char *input)
{
  FILE *fp;

  int textCount = 0, len = 0;

  char buff[MAX_SIZE];

  fp = fopen ("input.txt", "r");

  if (fp != NULL)
    {
      *text = (char **) malloc (sizeof (char) * (MAX_SIZE + 1));

      if (text != NULL)
	{
	  while (fgets (buff, MAX_SIZE, fp) != NULL)
	    {
	      len = strlen (buff) + 1;
	      (*text)[textCount] = (char *) malloc (sizeof (char *) * len);

	      if ((*text)[textCount] != NULL)
		{
		  strcpy ((*text)[textCount], buff);

		  len -= 2;

		  if (((*text)[textCount])[len] == '\n')
		    {
		      ((*text)[textCount])[len] = '\0';
		    }

		  textCount += 1;
		}
	    }
	}
      else
	{
	  printf ("\nNot able to allocate memory");
	  return FAILURE;
	}
      fclose (fp);
      return textCount;

    }
  else
    {
      printf ("\nFile cannot be opened");
    }
}
void display(char **arr, int num)
{
        
        for(int i=0;i<num;i++)
        {
                printf("%s\n",arr[i]);
                printf("\n");
        }

        //TBD Traverse the arr input and display all strings
}
int main(int argc, char *argv[])
{
        char **text = NULL;

        int textCount = 0;

        if(argc !=  3)
        {
                textCount = getFileString(&text, argv[1]); //function calling getfilestring to take an input from a file input.txt
                display(text,textCount);
        }
        else
        {
                printf("\nEntered else\n");
        }
        return FAILURE;
}
