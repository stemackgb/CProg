#include <stdio.h>
#include <stdlib.h>
#define FILENAME "Test.txt"

int main()
{
    int linesCount = 0;
    int textlineCount = 0;
    char ch[200];
    FILE *fp;

    //Open file in Read-Only mode
    fp = fopen(FILENAME, "r");

    //End if file does not exist
    if(fp == NULL)
    {
        printf("File doesn't exist\n");
        return -1;
    }
    while(fgets(ch, 200, fp) != NULL)
    {
        if(strlen(ch) <= 1)
        {
            linesCount++;
        }
        else
        {
            textlineCount++;
        }
    }

    printf("Number of lines with text are: %d\n", ++textlineCount);
    printf("Total number of lines are: %d\n", linesCount+textlineCount);
    fclose(fp);
    return 0;
}
