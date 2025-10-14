#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];
    int lineCount = 0;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    printf("Writing lines to %s...\n", filename);
    fprintf(fp, "Hello, file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fprintf(fp, "And one more for good measure.\n");
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("Reading contents:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        lineCount++;
    }

    fclose(fp);
    printf("Total lines read: %d\n", lineCount);

    return 0;
}
