#include <stdio.h>
#include "Voter_Registration.c"
#include "candidate_register.c"
#include "login.c"
int voter();
int cantidate();
int login();
int main()
{
    while (1)
    {
        int choice;
        printf("\033[2J\033[H");
        printf("---------------------------------------------\n ");
        printf("\tWELCOME\n Sri Lanka Parliment Voting System\n ");
        printf("---------------------------------------------\n ");

        printf("[1] Voter Registration\n [2] Candidate Registration\n [3] Login\n [4] View Result\n [5] Exit\n");
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
             View Result();
            break;

                    
        default:
            break;
        }
    }
    return 0;
}
