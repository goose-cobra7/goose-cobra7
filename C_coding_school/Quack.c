#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_help_text() {
    printf("Available commands:\n");
    printf("  help - Display this help message\n");
    printf("  quit/Q/out/end/END - End the session\n");
    printf("  alse: talk to the duck\n");
}

int count_words(const char *input) {
    int count = 0;
    const char *ptr = input;
    while (*ptr) {
        while (*ptr && (*ptr == ' ' || *ptr == '\n' || *ptr == '\t')) {
            ptr++;
        }
        if (*ptr) {
            count++;
            while (*ptr && (*ptr != ' ' && *ptr != '\n' && *ptr != '\t')) {
                ptr++;
            }
        }
    }
    return count;
}

int main() {
    print_help_text();
    char input[256];
    while (1) {
        printf("Enter text: ");
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "help") == 0) {
            print_help_text();
        } else if (strcmp(input, "quit") == 0 || strcmp(input, "Q") == 0 ||
                   strcmp(input, "out") == 0 || strcmp(input, "end") == 0 ||
                   strcmp(input, "END") == 0) {
            break;//quit command
        } else {
            int word_count = count_words(input);
            for ( int i = 0; i < word_count; i++)
            {
                printf("quack ");//print quack word for each word in the input
            }
            printf("\n");
        }
    }
    return 0;
}
