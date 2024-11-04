#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to find the maximum value of the last element
int getMaxValue(int arr_count, int* arr) {
    // Sort the array in ascending order
    for (int i = 0; i < arr_count - 1; i++) {
        for (int j = i + 1; j < arr_count; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Ensure the first element is set to 1 as per requirement
    arr[0] = 1;

    // Adjust each subsequent element to make sure the difference
    // between adjacent elements is at most 1
    for (int i = 1; i < arr_count; i++) {
        if (arr[i] > arr[i - 1] + 1) {
            arr[i] = arr[i - 1] + 1;
        }
    }

    // Return the maximum value of the last element in the array
    return arr[arr_count - 1];
}

// Additional helper functions for reading input and parsing integers

int parse_int(char* str);
char* ltrim(char* str);
char* rtrim(char* str);
char* readline();

int main() {
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int arr_count = parse_int(ltrim(rtrim(readline())));

    int* arr = malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++) {
        int arr_item = parse_int(ltrim(rtrim(readline())));
        *(arr + i) = arr_item;
    }

    int result = getMaxValue(arr_count, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    free(arr);

    return 0;
}

// Function to read input line by line
char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (1) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
    }

    return data;
}

// Left trim function to remove leading whitespaces
char* ltrim(char* str) {
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

// Right trim function to remove trailing whitespaces
char* rtrim(char* str) {
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

// Function to parse integer from string
int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    return value;
}
