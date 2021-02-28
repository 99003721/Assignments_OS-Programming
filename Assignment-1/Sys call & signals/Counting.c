#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    char path[100];

    char ch;
    int characters, words, lines;

char s_file[]="Document1.txt";
    file = fopen(s_file, "r");
    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");

        exit(EXIT_FAILURE);
    }
    characters = words = lines = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        characters++;
        if (ch == '\n' || ch == '\0')
            lines++;
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
            words++;
    }
    if (characters > 0)
    {
        words++;
        lines++;
    }
    printf("\n");
    printf("Total characters in files = %d\n", characters);
    printf("Total words in files = %d\n", words);
    printf("Total lines in file = %d\n", lines);
    fclose(file);

    return 0;
}