#include <stdio.h>
int voter()
{
    char name[32];
    int age;
    char NIC[20];
    char pass[8];
    
    printf("Enter Your Age:\n");
    scanf("%d", &age);

    if (age >= 18 && age <= 80)
    {
        printf("Enter Your Name:\n");
        scanf("%s", name);

        printf("Enter Your NIC Number:\n");
        scanf("%s",NIC); 

        printf("Enter Strong password:\n");
        scanf("%s", pass);

        FILE *fp = fopen("voters_details.txt", "a");
        fprintf(fp, "%s,%s,%s\n", name,NIC,pass);
        fclose(fp);
    }
    else
    {
        printf("You Are Not Eligible To Register\n");
    }
    return 0;
}