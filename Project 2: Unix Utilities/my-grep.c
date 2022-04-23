#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *file;
    int i = 1;
    char filename;
    char *line;
    size_t linelenght = 64;


    //Check if there is no searchterm
    if (argc == 1) {
        printf("my-grep: searchterm [file...]\n");
        exit(1);
    } //Check if there is no filename given
    if (argc == 2) {
        while (getline(&line, &linelenght, stdin) != EOF) {
            if (strstr(line, argv[1]) != NULL) {
                printf("'%s' found in standard input '%s'\n", argv[1], argv[i]);
            }
        }
        return 0;
    }
    else {

        for (i = 2; i < argc; i++) {

            //Open file
            if ((file = fopen(argv[i], "r")) == NULL) {
                printf("my-cat: cannot open file\n");
                exit(1);
            }

            //Find searchterm from line one line at a time
            while (getline(&line, &linelenght, file) != EOF) {
                if (strstr(line, argv[1]) != NULL) {
                    printf("'%s' found in file '%s'\n", argv[1], argv[i]);
                }
            }
            fclose(file);
        }
    }
    return 0;
}
