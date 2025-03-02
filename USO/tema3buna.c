#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PROGRAM "char *s=\"#include <stdio.h>\\n#include <stdlib.h>\\n#include <string.h>\\n#include <time.h>\\n\\n#define PROGRAM \\\"%s\\\"\\n\\nvoid generateAnagram(char *input) {\\n    srand(time(NULL));\\n    int len = strlen(input);\\n    char *anagram = malloc(len + 1);\\n    strcpy(anagram, input);\\n\\n    // Algoritmul Fisher-Yates pentru amestecarea caracterelor\\n    for (int i = len - 1; i > 0; i--) {\\n        int j = rand() % (i + 1);\\n        char temp = anagram[i];\\n        anagram[i] = anagram[j];\\n        anagram[j] = temp;\\n    }\\n\\n    printf(\\\"Anagrama: %s\\\", anagram);\\n    free(anagram);\\n}\\n\\nint main() {\\n    generateAnagram(PROGRAM);\\n    return 0;\\n}\\n\\n\\n\";void generateAnagram(char *input) {    srand(time(NULL));    int len = strlen(input);    char *anagram = malloc(len + 1);    strcpy(anagram, input);    for (int i = len - 1; i > 0; i--) {        int j = rand() % (i + 1);        char temp = anagram[i];        anagram[i] = anagram[j];        anagram[j] = temp;    }    printf(\"Anagrama: %s\", anagram);    free(anagram);}int main() {    generateAnagram(PROGRAM);    return 0;}"
void festeleste(char *input) {
    srand(time(NULL));
    int len = strlen(input);
    char *anagrama = malloc(len + 1);
    strcpy(anagrama, input);

    // Fisher-Yates
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = anagrama[i];
        anagrama[i] = anagrama[j];
        anagrama[j] = temp;
    }

    printf("Anagrama: %s", anagrama);
    free(anagrama);
}

int main() {
    festeleste(PROGRAM);
    return 0;
}
