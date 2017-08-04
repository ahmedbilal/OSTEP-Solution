#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>

#include "abk_str_vector.h"
#include "colors.h"

/*  Warning
    I have written/compiled/test this program only on Linux (ubuntu 16.04)
    The macros for colors are only for Linux/Unix system. So, don't
    panic if it won't work or throw errors on your Windows PC
*/

int count_n_digit(char * str)
{
    int count = 0; 
    for (int i = 0; i < strlen(str); i++)
        if (isdigit(str[i]))
            count++;
    return count;
}

int strcmp_str(char * str1, char * str2)
{
    for (int i = 0; i < strlen(str1) && i < strlen(str2); i++)
    {
        if (isalpha(str1[i]))
        {
            if (tolower(str1[i]) > tolower(str2[i]))
            {
                return 1;
            }
            else if (tolower(str1[i]) < tolower(str2[i]))
            {
                return -1;
            }
        }
        
    }
    if (strlen(str1) > strlen(str2))
    {
        return 1;
    }
    else
    {
        return -1;
    }
    return 0;
}

int strcmp_n(char * str1, char * str2)
{
    int value_of_str1 = 0;
    int value_of_str2 = 0;

    int str1_digit_left = count_n_digit(str1);
    int str2_digit_left = count_n_digit(str2);

    for (int i = 0; i < strlen(str1); i++)
    {
        if (isdigit(str1[i])){
            value_of_str1 += ( (int)(str1[i]) - (int)('0') ) * pow(10, str1_digit_left - 1);
            str1_digit_left--;
        }
    }

    for (int i = 0; i < strlen(str2); i++)
    {
        if (isdigit(str2[i])){
            value_of_str2 += ( (int)(str2[i]) - (int)('0') ) * pow(10, str2_digit_left - 1);
            str2_digit_left--;
        }
    }

    if (value_of_str1 == value_of_str2)
    {
        return 0;
    }
    else if (value_of_str1 < value_of_str2)
    {
        return -1;
    }
    else if (value_of_str1 > value_of_str2)
    {
        return 1;
    }
}


int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        printf(BOLDMAGENTA "Sort utility by " BOLDRED "ABK(Ahmed Bilal Khalid)\n" RESET);
        printf("------------\n");
        printf(BOLDYELLOW "Usage Examples: " RESET "sort filename.ext [-n]\n");
        printf(BOLDYELLOW "Return Values:  " BOLDGREEN "on SUCCESS " RESET "It will produce a sorted file with name\n                           \"sorted_name_of_original_file.txt\"\n");
        printf("                " BOLDRED "on ERROR " RESET "It will display error.\n");
    }
    else if (argc >= 2 && argc <= 3)
    {
        // Open File to sort
        FILE * file_to_sort = fopen(argv[1], "r");
        if (file_to_sort == NULL){
            printf("unable to open file\n");
            exit(EXIT_FAILURE);
        }

        // Create Output (Sorted File)
        char * sorted_file_name = malloc( sizeof(char) * (strlen(argv[1]) + strlen("sorted_") + 1) );
        strcpy(sorted_file_name, "sorted_");
        strcat(sorted_file_name, argv[1]);

        FILE * sorted_file = fopen(sorted_file_name, "w");
        if (sorted_file == NULL){
            printf("unable to create sorted file\n");
            exit(EXIT_FAILURE);
        }

        // Calculate File Length
        fseek(file_to_sort, 0, SEEK_END);
        int len_of_file = ftell(file_to_sort);
        fseek(file_to_sort, 0, SEEK_SET);

        char * content = malloc(sizeof(char) * (len_of_file + 1));
        content[0]= 0;

        struct Vector array_of_lines;
        vector_init(&array_of_lines);

        // Read File line by line
        char * line = malloc(1000);
        while(fgets(line, len_of_file, file_to_sort) != NULL)
        {
            array_of_lines.insert(&array_of_lines, line);
        }

        printf("------------- Unsorted -------------------\n");
        array_of_lines.print(&array_of_lines);
        
        printf("\n");

        // I know it is bad because it is bubble sort
        // but I am too tired to code any other sorting
        for (int i = 0; i < array_of_lines.size - 1; i++)
        {
            for (int j = i + 1; j < array_of_lines.size; j++)
            {
                int check;
                if (argc == 2)
                {
                    check = strcmp_str(array_of_lines.data[i], array_of_lines.data[j]);
                }
                else if (argc == 3 && strcmp(argv[2], "-n") == 0)
                {
                    check = strcmp_n(array_of_lines.data[i], array_of_lines.data[j]);
                }
                
                // if the str[i] is greater than str[j]
                if (check > 0)
                {
                    int size_of_i = sizeof(char) * (strlen(array_of_lines.data[i]) + 1);
                    int size_of_j = sizeof(char) * (strlen(array_of_lines.data[j]) + 1);

                    char * temp = malloc(size_of_i);
                    strcpy(temp, array_of_lines.data[i]);

                    free(array_of_lines.data[i]);
                    array_of_lines.data[i] = (char * )malloc(size_of_j);
                    strcpy(array_of_lines.data[i], array_of_lines.data[j]);

                    free(array_of_lines.data[j]);
                    array_of_lines.data[j] = (char * )malloc(size_of_i);
                    strcpy(array_of_lines.data[j], temp);

                    free(temp);
                }
            }
        }
        printf("--------------- Sorted -------------------\n");
        array_of_lines.print(&array_of_lines);
        
        for (int i = 0; i < array_of_lines.size; i++)
        {
            fputs(array_of_lines.data[i], sorted_file);
        }
        fputc('\0', sorted_file);

        // exit and cleaning
        free(line);
        free(sorted_file_name);
        free(content);

        fclose(file_to_sort);
        fclose(sorted_file);

        array_of_lines.destroy(&array_of_lines);

        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("too many arguments\n");
        exit(EXIT_FAILURE);
    }
}