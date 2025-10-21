#include <stdio.h>
#include <string.h>
int voter()
{
    char name[32];
    int age;
    char NIC[32];
    char pass[32];
    char checkname[32], checknic[32], checkpass[32];
    char line[200];
    FILE *fp = fopen("voters_details.txt", "a+");
    if(fp == NULL){
        printf("File Missing Please Check It");
    }
    printf("Enter Your Age:\n");
    scanf("%d", &age);
    if (age >= 18 && age <= 80)
    {
        printf("Enter Your Name:\n");
        scanf("%s", name);
        do
        {
            printf("Enter Your NIC Number (12 Number):\n");
            scanf("%s", NIC);
            if (strlen(NIC) != 12)
            {
                printf("\033[1;31mWrong NIC Number please Enter Validate NIC Number\033[0m\n");
            }
            else
            {
                break;
            }

        } while (strlen(NIC) != 12);
        while (fgets(line, sizeof(line), fp))
        {
            sscanf(line, "%[^,],%[^,],%[^,\n]", checkname, checknic, checkpass);
            if (strcmp(NIC, checknic) == 0)
            {
                printf("\033[1;31mYour are already registers!\033[0m\n");
                return 1;
            }
        }
        printf("Enter Strong password:\n");
        scanf("%s", pass);
        fprintf(fp, "%s,%s,%s\n", name, NIC, pass);
        fclose(fp);
    }
    else
    {
        printf("\033[1;32mYou Are Not Eligible To Register\033[0m\n");
    }
    return 0;
}