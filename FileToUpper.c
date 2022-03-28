#include <stdio.h>
#include <stdlib.h>
#define FILENAME "Test.txt"

int main()
{
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    char ch = ' ';

    //Open and check file exists
    fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("File does not exist!");
        return -1;
    }
    fp1 = fopen("temp2.txt", "w");
    if(fp1 == NULL);
    {
        printf("File does not exist!");
        return -1;
    }

    //If Lower convert to Upper and copy
    while ((ch =fgetc(fp)) != EOF)
        if(islower(ch))
        {
            ch = ch-32;
            putc(ch, "temp.txt");
        }

    fclose(FILENAME);
    fclose("temp.txt");

    remove(FILENAME);
    rename("temp.txt", FILENAME);
    remove("temp.txt");

    fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("File does not exist!");
        return -1;
    }

    while ((ch =fgetc(fp)) != EOF)
        printf("%c", ch);

    fclose(FILENAME);

    return 0;
}
