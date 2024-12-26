#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void writeFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }
    fprintf(file, "%s", data);
    printf("Data written to file '%s'.\n", filename);
    fclose(file);
}

void appendFile(const char *filename, const char *data) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        exit(1);
    }
    fprintf(file, "%s", data);
    printf("Data appended to file '%s'.\n", filename);
    fclose(file);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    printf("Contents of file '%s':\n", filename);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    putchar('\n');

    fclose(file);
}

int main() {
    const char *filename = "example.txt";
    int choice;
    char data[256];

    while (1) {
        printf("\nFile Operations:\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Append to File\n");
        printf("4. Read from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                printf("Enter data to write: ");
                fgets(data, sizeof(data), stdin);
                writeFile(filename, data);
                break;
            case 3:
                printf("Enter data to append: ");
                fgets(data, sizeof(data), stdin);
                appendFile(filename, data);
                break;
            case 4:
                readFile(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
