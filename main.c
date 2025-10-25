#include <stdio.h>
#include "Voter_Registration.c"
#include "candidate_register.c"
#include "login.c"
#include "view_result.c"
int voter();
int cantidate();
int login();
int view_result();
int menu()
{
    while (5)
    {
        int choice;
    printf("\033[1;31m");
    printf("====================================================\n");
    printf("||                 W E L C O M E                  ||\n");
    printf("||       Sri Lanka Parliament Voting System       ||\n"); 
    printf("||               M A I N   M E N U                ||\n"); 
    printf("====================================================\n\033[0m");
    printf("||                                                ||\n");
    printf("|| \033[1;31m[1] Voter Registration\033[0m                         ||\n");
    printf("|| \033[1;32m[2] Candidate Registration\033[0m                     ||\n");
    printf("|| \033[1;33m[3] Login\033[0m                                      ||\n");
    printf("|| \033[1;34m[4] View Result\033[0m                                ||\n");
    printf("|| \033[1;35m[5] Exit\033[0m                                       ||\n");
    printf("||                                                ||\n");
    printf("====================================================\n");
    printf("");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            voter();
            printf("Type something and then press enter to return\n");

            char temp[10];
            scanf("%s", temp);
            continue;

        case 2:
            cantidate();
            printf("Type something and then press enter to return\n");
            char temp1[10];
            scanf("%s", temp1);
            continue;

        case 3:
            login();
            printf("Type something and then press enter to return\n");
            char temp2[10];
            scanf("%s", temp2);
            continue;

        case 4:
            printf("---- Voting Results ----\n");
            view_result();
            continue;
            
        case 5:
            printf("Successful Exit.\n");
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
