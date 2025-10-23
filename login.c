#include <stdio.h>
#include <string.h>
#include "voting.c"
int login()
{

    char login_NIC[20];
    char login_pass[20];


    printf("Enter Your NIC Number:\n");
    scanf("%s", login_NIC);
    printf("Enter Your Password:\n");
    scanf("%s", login_pass);

    
    FILE *fp = fopen("voters_details.txt", "r");
    if (fp == NULL)
    {
        printf("Error\n");
        return 1;
    }
    char line[256], db_name[20], db_nic[20], db_pass[20];
    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%[^,],%[^,],%[^\n]", db_name, db_nic, db_pass);
        if (strcmp(db_nic, login_NIC) == 0 && strcmp(db_pass, login_pass) == 0)
        {
            printf("Hi...%s\n--You Are Loging Successfully--\nNOW YOU CAN VOTE !\n\n\n", db_name);
            printf("Hi..%s Select Your Choice\n", db_name);
            fclose(fp);
            tre();
        }
        
        
    }

    

    
    return 0;
}