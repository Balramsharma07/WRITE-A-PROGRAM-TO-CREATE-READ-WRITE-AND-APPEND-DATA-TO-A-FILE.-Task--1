#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char content[100];

    // Creating and writing to a file
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return 1;
    }
    fprintf(file, "Hello, this is a file operations demo.\n");
    fclose(file);
    printf("File created and written successfully.\n");

    // Reading the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return 1;
    }
    printf("Reading from file:\n");
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }
    fclose(file);

    // Appending to the file
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Could not open file for appending.\n");
        return 1;
    }
    fprintf(file, "Appending a new line to the file.\n");
    fclose(file);
    printf("\nContent appended to file.\n");

    // Reading the file again
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return 1;
    }
    printf("Updated file content:\n");
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }
    fclose(file);

    return 0;
}
