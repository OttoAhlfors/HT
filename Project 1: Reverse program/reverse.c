#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char *string;
    struct list *next, *previous;
}LIST;

int main(int argc, char **argv ) {
    FILE *file;
    LIST *current, *head;
    char *inputFilename = argv[1];
    char *outputFilename = argv[2];
    char line[500];

    //Check that the ammount of arguments is correct (3)
    if (argc > 3) {
        fprintf(stderr, "Too few arguments on function call\n");
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    } if (argc < 3) {
        fprintf(stderr, "Too many arguments on function call\n");
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    }

    //Check that input and output files are not the same
    if (strcmp(inputFilename, outputFilename) == 0) {
        fprintf(stderr, "Input and output files must differ\n");
        exit(1);
    }

    //Open input file to read
    file = fopen(inputFilename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", inputFilename);
        exit(1);

    }
    //Create linked list and allocate memory
    head = current = NULL;
    while (fgets(line, sizeof(line), file)) {
        LIST *node = malloc(sizeof(LIST));
        node->string = strdup(line);
        node->next = NULL;
        if (head == NULL) {
            current = head = node;
        } else {
            current = current->next = node;
        }
    }

    //Reverse linked list
    struct list *previous = NULL;
    struct list *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }

    fclose(file);

    //Open file to write in
    file = fopen(outputFilename, "w+");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", outputFilename);
    }
        exit(1);

    //Write to file
    struct list *temp = head;
    while (temp != NULL) {
        fprintf(file, "%s", temp->string);
        temp = temp->next;
    }

    fprintf(stderr, "Data has been copied to file '%s'\n", outputFilename);
    fclose(file);
    return 0;
}
