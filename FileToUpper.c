#include <stdio.h>
#include <stdlib.h>
#define FILENAME "Test.txt"

int main()
{
    FILE *fp = NULL;
    FILE *fp1 = NULL;
    char ch = ' ';
    //Check and open file(s)
    fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("File does not exist!");
        return -1;
    }
    fp1 = fopen("Temp.txt", "w");
    if(fp1 == NULL)
    {
        printf("File does not exist!");
        return -1;
    }
    //Loop change all lower-case to upper-case
    while((ch=fgetc(fp)) != EOF)
    {
        ch = toupper(ch);
        fputc(ch,fp1);
    }
    //Administrative tasks
    fclose(fp);
    fclose(fp1);
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    remove("temp.txt");
    //Check and open file
    fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("File does not exist!");
        return -1;
    }
    //Print output to screen
    while((ch=fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    //Administrative tasks
    fclose(fp);
    fp = NULL;
    fp1 = NULL;
}
