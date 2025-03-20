#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PLACE "file.txt"

int main() {
    FILE *this_file = fopen(FILE_PLACE, "r");
    if (!this_file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    // Determine the file size
    fseek(this_file, 0, SEEK_END);
    long file_size = ftell(this_file);
    rewind(this_file);

    // Allocate memory to read the file content
    char *content = (char *)malloc(file_size + 1);
    if (!content) {
        perror("Failed to allocate memory");
        fclose(this_file);
        exit(EXIT_FAILURE);
    }

    // Read the file content into memory
    fread(content, 1, file_size, this_file);
    content[file_size] = '\0';
    fclose(this_file);

    // Perform the replacement
    char *pos;
    while ((pos = strstr(content, "of")) != NULL) {
        memmove(pos + 2, pos + 2, strlen(pos + 2) + 1); // Make space for "66"
        memcpy(pos, "66", 2);
    }

    // Write the updated content back to the file
    this_file = fopen(FILE_PLACE, "w");
    if (!this_file) {
        perror("Failed to open file for writing");
        free(content);
        exit(EXIT_FAILURE);
    }
    fwrite(content, 1, strlen(content), this_file);
    fclose(this_file);

    free(content);
    return 0;
}
