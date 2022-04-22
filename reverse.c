#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char *string;
    struct list *next;
}LIST;

//Reverse linked list
static void reverse(struct list **node) {
    struct list *previous = NULL;
    struct list *next = NULL;
    struct list *temp = *node;

    while (temp != NULL) {
        next = temp->next;
        temp->next = previous;

        previous = temp;
        temp = next;
    }

    *node = previous;
}

int main(int argc, char **argv ) {
    FILE *file;
    LIST *current, *head;
    char *inputFilename = argv[1];
    char *outputFilename = argv[2];
    char line[20];

    //Check that the ammount of arguments is correct (3)
    if (argc < 3) {
        fprintf(stderr, "\nToo few arguments on function call\n");
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    } if (argc > 3) {
        fprintf(stderr, "\nToo many arguments on function call\n");
        fprintf(stderr, "Usage: reverse <input> <output>\n");
        exit(1);
    }

    //Check that input and output files are not the same
    if (strcmp(inputFilename, outputFilename) == 0) {
        fprintf(stderr, "\nInput and output files must differ\n");
        exit(1);
    }

    //Open input file to read
    file = fopen(inputFilename, "r");
    if (file == NULL) {
        fprintf(stderr, "\nError: cannot open file '%s'\n", inputFilename);
        exit(1);
    }

    fprintf(stderr, "\nFile '%s' has been opened\n", inputFilename);

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

    fclose(file);

    reverse(&head);
    fprintf(stderr, "Linked list has been reversed\n");

    //Open output file
    file = fopen(outputFilename, "w+");
    if (file == NULL) {
        fprintf(stderr, "Error: cannot open file '%s'\n", outputFilename);
        exit(1);
    }

    //Write to output file
    for (current = head; current; current = current->next) {
        fprintf(file, "%s", current->string);
    }

    fprintf(stderr, "Data has been copied to file '%s'\n", outputFilename);
    fclose(file);

    return 0;
}