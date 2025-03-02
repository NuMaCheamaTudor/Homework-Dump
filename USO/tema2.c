#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern char **environ;  

void concatenare() {
    int i, count;
    
    // Calculam numarul total de variabile de mediu
    for (count = 0; environ[count] != NULL; count++);

    // Iteram doar peste pozitiile impare 
    for (i = 1; i < count; i += 2) {
        if (environ[i] != NULL && environ[i + 1] != NULL) {
            // Alocam suficient spatiu pentru concatenare
            size_t len = strlen(environ[i]) + strlen(environ[i + 1]) + 1;
            char *concat = (char *)malloc(len);

            if (concat == NULL) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            strcpy(concat, environ[i]);
            strcat(concat, environ[i + 1]);
            free(environ[i]);
            environ[i] = concat;
        }
    }
}

int main() {

    printf("Inainte de nebunie:\n");
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
    concatenare();
    if (errno != 0) {
        perror("concatenare");
        exit(EXIT_FAILURE);
    }
    printf("\nDupa nebunie:\n");
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}
