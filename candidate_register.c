#include <stdio.h>
#include <string.h>
int cantidate()
{
    char name[38];
    int party;
    char num[32];
    char nic[38];
    char pass[38];
    char choice;
    int age;
    char cnic[38], cpass[38], cname[38], cnum[32];
    char line[200];
    FILE *fp = fopen("NPP.txt", "a+");
    FILE *fp1 = fopen("UNP.txt", "a+");
    FILE *fp2 = fopen("UDP.txt", "a+");

    printf("Enter You Age:\n");
    scanf("%d", &age);
    if (age >= 25)
    {
        printf("Are You Sri Lnaken ? (\033[1;33m y \033[0m/\033[1;34m n \033[0m):");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'Y':
        case 'y':

            printf("Select Your Party\n\t\033[31m 1.NPP\033[0m \n\t\033[32m 2.UNP\033[0m \n\t\033[33m 3.UDP\033[0m \n");

            scanf("%d", &party);

            switch (party)
            {

            case 1:
                printf("Enter Your Name:\n");
                scanf("%s", name);

                do
                {
                    printf("Enter Your NIC Number:\n");
                    scanf("%s", nic);
                    if (strlen(nic) != 12)
                    {
                        printf("\033[1;31m You Enter Wrong Type NIC Number\033[0m\n");
                    }

                    else
                    {
                        break;
                    }
                } while (strlen(nic) != 12);

                while (fgets(line, sizeof(line), fp))
                {
                    sscanf(line, "%[^,],%[^,],%[^,%[^\n]", cname, cnic, cnum, cpass);
                    if (strcmp(nic, cnic) == 0)
                    {
                        printf("\033[1;31mYour are already registers!\033[0m\n");
                        return 1;
                    }
                }
             
                    do
                    {
                        int taken = 0;
                        printf("Enter Your Own Vote Number:\n");
                        scanf("%s", num);

                        rewind(fp);
                        while (fgets(line, sizeof(line), fp))
                        {
                            sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", cname, cnic, cnum, cpass);
                            if (strcmp(cnum, num) == 0)
                            {
                                printf("\033[1;31m This Number Already Taken! Try another.\033[0m\n");
                                taken = 1;
                                break;
                            }
                        }
                        if (!taken)
                            break;

                    }
                     while (1);

                    printf("Enter Strong password:\n");
                    scanf("%s", pass);

                    fprintf(fp, "%s,%s,%s,%s\n", name, nic, num, pass);
                    fclose(fp);

                    break;

                case 2:
                    printf("Enter Your Name:\n");
                    scanf("%s", name);

                    printf("Enter Your NIC Number:\n");
                    scanf("%s", nic);
                    do
                    {
                        if (strlen(nic) != 12)
                        {
                            printf("\033[1;31m You Enter Wrong Type NIC Number\033[0m\n");
                        }

                        else
                        {
                            break;
                        }
                    } while (strlen(nic) != 12);

                    while (fgets(line, sizeof(line), fp1))
                    {
                        sscanf(line, "%[^,],%[^,],%[^,%[^\n]", cname, cnic, cnum, cpass);
                        if (strcmp(nic, cnic) == 0)
                        {
                            printf("\033[1;31mYour are already registers!\033[0m\n");
                            return 1;
                        }
                    }

                    printf("Enter Your Own Vote Number:\n");
                    scanf("%d", &num);

                    do
                    {
                        int taken = 0;
                        printf("Enter Your Own Vote Number:\n");
                        scanf("%s", num);

                        rewind(fp);
                        while (fgets(line, sizeof(line), fp1))
                        {
                            sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", cname, cnic, cnum, cpass);
                            if (strcmp(cnum, num) == 0)
                            {
                                printf("\033[1;31m This Number Already Taken! Try another.\033[0m\n");
                                taken = 1;
                                break;
                            }
                        }
                        if (!taken)
                            break;

                    }
                     while (1);

                    printf("Enter Strong password:\n");
                    scanf("%s", pass);

                    fprintf(fp1, "%s,%s,%s,%s\n", name, nic, num, pass);
                    fclose(fp1);

                    break;

                case 3:
                    printf("Enter Your Name:\n");
                    scanf("%s", name);
                    do
                    {
                        printf("Enter Your NIC Number:\n");
                        scanf("%s", nic);

                        if (strlen(nic) != 12)
                        {
                            printf("\033[1;31m You Enter Wrong Type NIC Number\033[0m\n");
                        }

                        else
                        {
                            break;
                        }

                    } while (strlen(nic) != 12);

                    while (fgets(line, sizeof(line), fp2))
                    {
                        sscanf(line, "%[^,],%[^,],%[^,%[^\n]", cname, cnic, cnum, cpass);
                        if (strcmp(nic, cnic) == 0)
                        {
                            printf("\033[1;31mYour are already registers!\033[0m\n");
                            return 1;
                        }
                    }

                    printf("Enter Your Own Vote Number:\n");
                    scanf("%d", &num);

                    do
                    {
                        int taken = 0;
                        printf("Enter Your Own Vote Number:\n");
                        scanf("%s", num);

                        rewind(fp);
                        while (fgets(line, sizeof(line), fp2))
                        {
                            sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", cname, cnic, cnum, cpass);
                            if (strcmp(cnum, num) == 0)
                            {
                                printf("\033[1;31m This Number Already Taken! Try another.\033[0m\n");
                                taken = 1;
                                break;
                            }
                        }
                        if (!taken)
                            break;

                    }
                     while (1);

                    printf("Enter Strong password:\n");
                    scanf("%s", pass);

                    fprintf(fp2, "%s,%s,%s,%s\n", name, nic, num, pass);
                    fclose(fp2);

                    break;

                default:
                    printf("Enter correct number of your party \n");
                    break;
                }

                break;

            case 'N':
            case 'n':
                printf("Sorry! You can not apply for candidate list.\n");
            }
        }
        else
        {
            printf("\033[1;31m You Are Not Eligible For Election!\033[0m\n");
        }
        return 0;
    }