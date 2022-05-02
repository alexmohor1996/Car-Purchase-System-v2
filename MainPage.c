#include <stdio.h>
#include <stdlib.h>
#include "HelloWorld.h"
#include <stdbool.h>
#include <string.h>

char cars[8][100] = {{"1. BMW"}, {"2. Skoda"}, {"3. Volvo"}, {"4. Corvette"}, {"5. Chevy"}, {"6. Dodge"}, {"7. Audi"}, {"8. Chrysler"}};
int prices[100] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
int csize = sizeof(cars)/sizeof(cars[0]);

void FirstUser(char user[])
{
    FILE * firstUser_file = fopen("C:\\Users\\SkyLine\\Desktop\\usernames.txt", "w");
    fprintf(firstUser_file, user);
    fclose(firstUser_file);
}

void AddUsers(char m_user[])
{
    FILE * user_file = fopen("C:\\Users\\SkyLine\\Desktop\\usernames.txt", "a");
    fprintf(user_file, m_user);
    fclose(user_file);
}

void FirstPassword(char password[])
{
    FILE * firstPassword_file = fopen("C:\\Users\\SkyLine\\Desktop\\passwords.txt", "w");
    fprintf(firstPassword_file, password);
    fclose(firstPassword_file);
}

void AddPassword(char m_password[])
{
    FILE * pass_file = fopen("C:\\Users\\SkyLine\\Desktop\\passwords.txt", "a");
    fprintf(pass_file, m_password);
    fclose(pass_file);
}

bool CheckUsername(char user[])
{
    char check[255];
    FILE * user_read = fopen("C:\\Users\\SkyLine\\Desktop\\usernames.txt", "r");
    while(fscanf(user_read, "%s", check) != EOF)
    {
        if (strcmp(user, check))
        {
            return false;
        }
    }

    return true;
    fclose(user_read);
}

bool CheckPassword(char password[])
{
    char check[255];
    FILE * pass_read = fopen("C:\\Users\\SkyLine\\Desktop\\passwords.txt", "r");
    while(fscanf(pass_read, "%s", check) != EOF)
    {
        if (strcmp(password, check))
        {
            return false;
        }
    }

    return true;
    fclose(pass_read);
}

int CarList(int csize)
{
    csize = sizeof(cars)/sizeof(cars[0]);
    printf("================================\n");
    printf("\n");
    printf("Please see below a list of our cars\n");

    for (int i=0; i<csize; i++)
    {
        printf("%s - %d EUR\n", cars[i], prices[i]);
    }
}

int main()
{
    GSettings set;

    printf("==================================================\n");
    printf("======== Welcome to the Ateria Car System ========\n");
    printf("==================================================\n");
    printf("What would you like to do?\n");
    printf("1. Check the cars\n2. Purchase a car\n");

    scanf("%d", &set.choice);

    switch(set.choice)
    {
        case 1:
            CarList(csize);
            break;
        case 2:
            printf("You need an account to continue\n");
            printf("Do you have an account?\n");
            printf("Choose (1) for YES / (2) for NO\n");
            scanf("%d", &set.choice);

            switch(set.choice)
            {
                case 1:
                    printf("Write your username\n");
                    scanf("%s", set.input_user);

                    printf("Write your password\n");
                    scanf("%s", set.input_password);

                    if (CheckUsername(set.input_user) && CheckPassword(set.input_password))
                    {
                        printf("Account ok, you can login\n");
                        scanf("%s", &set.input_user);
                        scanf("%s", &set.input_password);
                        printf("Successfully logged in\n");
                        printf("Please choose your desired car\n");
                        scanf("%d", &set.choice);

                        switch(set.choice)
                        {
                            case 1:
                                printf("Ok, you have now chosen %s priced at %d", cars[0], prices[0]);
                                break;
                            case 2:
                                printf("Ok, you have now chosen %s priced at %d", cars[1], prices[1]);
                                break;
                            case 3:
                                printf("Ok, you have now chosen %s priced at %d", cars[2], prices[2]);
                                break;
                            case 4:
                                printf("Ok, you have now chosen %s priced at %d", cars[3], prices[3]);
                                break;
                            case 5:
                                printf("Ok, you have now chosen %s priced at %d", cars[4], prices[4]);
                                break;
                            case 6:
                                printf("Ok, you have now chosen %s priced at %d", cars[5], prices[5]);
                                break;
                            case 7:
                                printf("Ok, you have now chosen %s priced at %d", cars[6], prices[6]);
                                break;
                            case 8:
                                printf("Ok, you have now chosen %s priced at %d", cars[7], prices[7]);
                                break;
                        }
                    }
                    else
                    {
                        printf("Account does not exist\n");
                    }
                    break;
                case 2:
                    char username[20];
                    char password[20];
                    printf("Please enter your username\n");
                    scanf("%s", &username);
                    FirstUser(username);

                    printf("Now, please enter your password\n");
                    scanf("%s", &password);
                    FirstPassword(password);

                    printf("Account created successfully\n");
                    break;
                default:
                    printf("Invalid choice");
            }
        break;
        default:
            printf("Invalid choice");
    }

    return 0;
}
