#include <stdio.h>
int cantidate()
{
    char name[32];
    int party,num ;
    char nic[20];
    char pass[8];
    char choice;
    

    printf("Are You Sri Lnaken ? (y/n)");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'Y':
    case 'y':

        printf("Select Your Party\n\t1.NPP \n\t2.UNP \n\t3.UDP \n");
      
        scanf("%d", &party);

        switch (party)
        {
        case 1:
            printf("Enter Your Name:\n");
            scanf("%s", name);

            printf("Enter Your NIC Number:\n");
            scanf("%s", nic);

            printf("Enter Your Own Vote Number:\n");
            scanf("%d", &num);

            printf("Enter Strong password:\n");
            scanf("%s", pass);
            

            FILE *fp= fopen("NPP.txt", "a");
            fprintf(fp, "%s,%s,%d,%s\n",  name, nic, num,  pass);
            fclose(fp);

            break;

        case 2:
            printf("Enter Your Name:\n");
            scanf("%s", name);

            printf("Enter Your NIC Number:\n");
            scanf("%s", nic);

             printf("Enter Your Own Vote Number:\n");
            scanf("%d", &num);

            printf("Enter Strong password:\n");
            scanf("%s",pass);

            FILE *fp1= fopen("UNP.txt", "a");
            fprintf(fp1, "%s,%s,%d,%s\n",  name, nic, num, pass);
            fclose(fp1);

            break;

        case 3:
            printf("Enter Your Name:\n");
            scanf("%s", name);

            printf("Enter Your NIC Number:\n");
            scanf("%s", nic);

             printf("Enter Your Own Vote Number:\n");
            scanf("%d", &num);

            printf("Enter Strong password:\n");
            scanf("%s", pass);

            FILE *fp2 = fopen("UDP.txt", "a");
            fprintf(fp2, "%s,%s,%d,%s\n", name, nic, num, pass);
            fclose(fp2);

            break;

        default:
            printf("\"Enter correct number of your party\"\n");
            break;
        }

        break;
        
    case 'N':
    case 'n':
        printf("Sorry! You can not apply for candidate list.\n");
    }

    return 0;
}