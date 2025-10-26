#include <stdio.h>
int view_result()
{
    printf("Select a party to view results:\n");
    printf("[1] NPP\n[2] UNP\n[3] UDP\n");
    int choice;
    char line[256];
    scanf("%d", &choice);

    FILE *fp;

    switch (choice)
    {
    case 1:
        fp = fopen("NPP_votes.txt", "r");
        if (fp == NULL) { 
            printf("Error opening NPP_votes.txt\n");
            return 1;
        }
        printf("--- NPP Votes ---\n");
        while (fgets(line, sizeof(line), fp))
        {
            printf("%s", line);
        }
        fclose(fp);
        break;
    
    case 2:
        fp = fopen("UNP_votes.txt", "r");
        if (fp == NULL) {
            printf("Error opening UNP_votes.txt\n");
            return 1;
        }
        printf("--- UNP Votes ---\n");
        while (fgets(line, sizeof(line), fp))
        {
            printf("%s", line);
        }
        fclose(fp);
        break;

    case 3:
        fp = fopen("UDP_votes.txt", "r");
        if (fp == NULL) {
            printf("Error opening UDP_votes.txt\n");
            return 1;
        }
        printf("--- UDP Votes ---\n");
        while (fgets(line, sizeof(line), fp))
        {
            printf("%s", line);
        }
        fclose(fp);
        break;

    default:
        printf("Invalid choice.\n");
        return 1;
    }    
    printf("\nPress Enter to return to main menu...");
    while (getchar() != '\n');
    getchar();

    return 0;
}