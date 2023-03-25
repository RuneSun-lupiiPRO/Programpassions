#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHOICES 3
#define MAX_NAME_LENGTH 20

int main() {
    char name[MAX_NAME_LENGTH];
    int age, year_born;
    char country[MAX_NAME_LENGTH];
    char app_name[MAX_NAME_LENGTH];
    int app_version_major, app_version_minor;
    int choice, rand_num;

    // Get player name
    printf("What is your name?\n");
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Get player age
    printf("How old are you?\n");
    scanf("%d", &age);

    // Calculate year born
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    year_born = tm->tm_year + 1900 - age;

    // Get country
    printf("Which country are you from?\n");
    fgets(country, MAX_NAME_LENGTH, stdin);

    // Get app name
    printf("What is the name of your app?\n");
    fgets(app_name, MAX_NAME_LENGTH, stdin);

    // Get app version
    printf("What is the version number of your app?\n");
    scanf("%d.%d", &app_version_major, &app_version_minor);

    // Start game
    printf("\nWelcome to the game, %s", name);
    printf("You were born in %d and come from %s", year_born, country);
    printf("Your app, %s, is currently at version %d.%d\n\n", app_name, app_version_major, app_version_minor);

    while (1) {
        printf("Choose an action:\n");
        printf("1. Generate a random number\n");
        printf("2. Quit game\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                srand(time(NULL));
                rand_num = rand() % 100 + 1;
                printf("Your random number is: %d\n\n", rand_num);
                break;
            case 2:
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n\n");
                break;
        }
    }
}
