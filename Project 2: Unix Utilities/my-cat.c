#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE* file;
    int i = 1;
    char line[1024];

    //Goes trough all arguments after 'my-cat'
    for (i = 1; i < argc; i++) {

        //Open file and check that the file has opened
        if ((file = fopen(argv[i], "r")) == NULL) {
            printf("my-cat: cannot open file\n");
            exit(1);
        }

        //Print all lines in file
        while (fgets(line, 1024, file)) {
            printf("%s", line);
        }

        fclose(file);
        printf("\n");
    }
    return 0;
}
