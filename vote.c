#include <stdio.h>
int votering(char *voter_nic)
{
    int choice, party, votecount;
    printf("\t[1] vote\n \t[2] exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("---You Can Vote Now---\n");
        printf("Selecet Party\n");
        printf("\033[1;31m[1] NPP\033[0m\n\033[1;32m[2] UNP\033[0m\n\033[1;33m[3] UDP\033[0m\n");
        scanf("%d", &party);
        switch (party)
        {
        case 1:     
        int i=0;
        while(i<3){
            FILE *fp = fopen("NPP.txt", "r");
            FILE *votersfp = fopen("voters_details.txt", "r");
            FILE *votedfp = fopen("voted_voters.txt", "a+"); 
            if (votedfp == NULL)
            {
                printf("Error\n");
                return 1;
            }
            if (fp == NULL)
            {
                printf("Error\n");
                return 1;
            }
            char line[256], name[32], nic[32], num[32], pass[32], votes[9];
            while (fgets(line, sizeof(line), fp))
            {
                sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", name, nic, num, pass);
                printf( "Name:%s Number:%s\n", name, num);                
            }          
        char candidate_num[32];
        printf("Enter Your Candidate Number: ");
        scanf("%s", candidate_num);
            FILE *vfp = fopen("NPP_votes.txt", "r");
            if(vfp==NULL){
                fprintf(stderr, "Could not open the file!\n");
                exit(2);
            }
            (void) remove(".\\tmp.txt");
            FILE *tmpfp = fopen(".\\tmp.txt", "a");
            if(tmpfp==NULL){
                fprintf(stderr, "Could not open the file!\n");
                exit(2);
            }
            int found = 0;
            while (fgets(line, sizeof(line), vfp))
            {
                sscanf(line, "%[^,],%[^,],%[^\n]", name, num, votes);
                if(strcmp(num, candidate_num)==0){
                   found = 1;
                }
            }
            if(!found){
                printf("Candidate number not found!\n");
                fclose(votersfp);
                fclose(tmpfp);
                fclose(vfp);
                fclose(fp);
                break;
            }
            found = 0;
            fseek(vfp, 0, SEEK_SET);
            while (fgets(line, sizeof(line), vfp))
            {
                sscanf(line, "%[^,],%[^,],%[^\n]", name, num, votes);
                if(strcmp(num, candidate_num)==0){
                   fprintf(tmpfp, "%s,%s,%d\n", name, num, atoi(votes)+1);
                    fprintf(votedfp, "%s\n", voter_nic);
                    printf( "Match found => Name:%s Number:%s \n", name, num);
                }else{
                    fprintf(tmpfp, "%s,%s,%s\n", name, num, votes);
                }
            }
            i++;
            fclose(votedfp);
            fclose(tmpfp);
            fclose(vfp);
            fclose(fp);
            remove(".\\NPP_votes.txt");
            rename(".\\tmp.txt", ".\\NPP_votes.txt");       
        }
break;
 //..........................................................................................          
            case 2:
             int k=0;
            while(k<3){           
            FILE *fp1 = fopen("UNP.txt", "r");
            FILE *votersfp1 = fopen("voters_details.txt", "r");
            FILE *votedfp1 = fopen("voted_voters.txt", "a+");
            if (votedfp1 == NULL)
            {
                printf("Error\n");
                return 1;
            }
            if (fp1 == NULL)
            {
                printf("Error\n");
                return 1;
            }
            char line1[256], name2[32], nic2[32], num2[32], pass2[32], votes2[9];
            while (fgets(line1, sizeof(line1), fp1))
            {
                sscanf(line1, "%[^,],%[^,],%[^,],%[^\n]", name2, nic2, num2, pass2);
                printf( "Name:%s Number:%s\n", name2, num2);

            }
            char candidate_num2[32];
            printf("Enter Your Candidate Number: ");
            scanf("%s", candidate_num2);
            FILE *vfp1 = fopen("UNP_votes.txt", "r");
            if(vfp1==NULL){
                fprintf(stderr, "Could not open the file!\n");
                exit(2);
            }
            (void) remove(".\\tmp.txt");
            FILE *tmpfp1 = fopen(".\\tmp.txt", "a");
            if(tmpfp1==NULL){
                fprintf(stderr, "Could not open the file!\n");
                exit(2);
            }
            int found1 = 0;
            while (fgets(line1, sizeof(line1), vfp1))
            {
                sscanf(line1, "%[^,],%[^,],%[^\n]", name2, num2, votes2);
                if(strcmp(num2, candidate_num2)==0){
                    found1 = 1;
                }
            }
            if(!found1){
                printf("Candidate number not found!\n");
                fclose(tmpfp1);
                fclose(vfp1);
                fclose(fp1);
                break;
            }
            found1 = 0;
            fseek(vfp1, 0, SEEK_SET);
            while (fgets(line1, sizeof(line1), vfp1))
            {
                sscanf(line1, "%[^,],%[^,],%[^\n]", name2, num2, votes2);
                if(strcmp(num2, candidate_num2)==0){
                    fprintf(tmpfp1, "%s,%s,%d\n", name2, num2, atoi(votes2)+1);
                    fprintf(votedfp1, "%s\n", voter_nic);
                    printf( "Match found => Name:%s Number:%s\n", name2, num2);
                }else{
                    fprintf(tmpfp1, "%s,%s,%s\n", name2, num2, votes2);
                }
            }
            k++;
            fclose(votedfp1);
            fclose(tmpfp1);
            fclose(vfp1);
            fclose(fp1);
            remove(".\\UNP_votes.txt");
            rename(".\\tmp.txt", ".\\UNP_votes.txt");
        }
break;
//.................................................................................................
        case 3:
        int m=0;
        while(m<3){
              FILE *fp2 = fopen("UDP.txt", "r");
              FILE *votersfp2 = fopen("voters_details.txt", "r");
              FILE *votedfp2 = fopen("voted_voters.txt", "a+");
            if (votedfp2 == NULL)
            {
                printf("Error\n");
                return 1;
            }
            if (fp2 == NULL)
            {
                printf("Error\n");
                return 1;
            }
            char line3[256], name3[32], nic3[32], num3[32], pass3[32], votes3[9];
            while (fgets(line3, sizeof(line3), fp2))
            {
                sscanf(line3, "%[^,],%[^,],%[^,],%[^\n]", name3, nic3, num3, pass3);
                printf( "Name:%s Number:%s\n", name3, num3);

            }
            char candidate_num3[32];
            printf("Enter Your Candidate Number: ");
            scanf("%s", candidate_num3);
            FILE *vfp2 = fopen("UDP_votes.txt", "r");
            if(vfp2==NULL){
                fprintf(stderr, "Could not open the file!\n");
                exit(2);
            }
            (void) remove(".\\tmp.txt");
            FILE *tmpfp2 = fopen(".\\tmp.txt", "a");
            if(tmpfp2==NULL){
                fprintf(stderr, "Could not open the file!\n");
                exit(2);
            }
            int found2 = 0;
            while (fgets(line3, sizeof(line3), vfp2))
            {
                sscanf(line3, "%[^,],%[^,],%[^\n]", name3, num3, votes3);
                if(strcmp(num3, candidate_num3)==0){
                    found2 = 1;
                }
            }
            if(!found2){
                printf("Candidate number not found!\n");
                fclose(tmpfp2);
                fclose(vfp2);
                fclose(fp2);
                break;
            }
            found2 = 0;
            fseek(vfp2, 0, SEEK_SET);
            while (fgets(line3, sizeof(line3), vfp2))
            {
                sscanf(line3, "%[^,],%[^,],%[^\n]", name3, num3, votes3);
                if(strcmp(num3, candidate_num3)==0){
                    fprintf(tmpfp2, "%s,%s,%d\n", name3, num3, atoi(votes3)+1);
                    fprintf(votedfp2, "%s\n", voter_nic);
                    printf( "Match found => Name:%s Number:%s \n", name3, num3);
                }else{
                    fprintf(tmpfp2, "%s,%s,%s\n", name3, num3, votes3);
                }
            }
            m++;
            fclose(votedfp2);
            fclose(tmpfp2);
            fclose(vfp2);
            fclose(fp2);
            remove(".\\UDP_votes.txt");
            rename(".\\tmp.txt", ".\\UDP_votes.txt");
        }
        break;  
    }     
    case 2:
        printf("successfully Exit\n");
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    return 0;
}