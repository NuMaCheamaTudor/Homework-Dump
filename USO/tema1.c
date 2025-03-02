#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <errno.h>

struct passwd *getpwnam_custom(const char *username) {
    struct passwd *pwd;
    
    // Deschide fisierul
    setpwent();

    // Cauta informatii despre user
    while ((pwd = getpwent()) != NULL) {
        if (strcmp(pwd->pw_name, username) == 0) {
           
            // Daca gaseste ceva afiseaza informatiile
            printf("Username: %s\n", pwd->pw_name);
            printf("Gecos: %s\n", pwd->pw_gecos);

            // Inchide fisierul 
            endpwent();

            // Returneaza structura passwd cu informatiile despre utilizator
            return pwd;
        }
    }

    // Inchide fisierul 
    endpwent();

    // Afiseaza eroarea daca utilizatorul nu a fost gasit
    perror("getpwnam_custom");

    // Returneaza NULL dacaa utilizatorul nu a fost gasit
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <username>\n", argv[0]);
        return 1;
    }

    const char *username = argv[1];

    // Apelul functiei pentru a obtine informatiile despre utilizator
    struct passwd *user_info = getpwnam_custom(username);

    if (user_info == NULL) {
        fprintf(stderr, "Utilizatorul %s nu a fost gasit.\n", username);
        return 1;
    }

    return 0;
}
