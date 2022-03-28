#include <stdio.h>
#include <stdlib.h>
#define FILENAME "Test.txt"

int main()
{
    FILE *fp;
    char ch;
    int linesCount = 0;

    //Open file in Read-Only mode
    fp = fopen(FILENAME, "r");

    //End if file does not exist
    if(fp == NULL)
    {
        printf("File doesn't exist\n");
        return -1;
    }

    //Count total number of lines
    while((ch=fgetc(fp)) != EOF)
    {
        if(ch == '\n')
            linesCount++;
    }

    printf("Total number of lines are: %d\n", ++linesCount);
    fclose(fp);
    return 0;
}
