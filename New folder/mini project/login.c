#include <stdio.h>
#include<string.h>
int login(){

    char login_NIC[20];
    char login_pass[20];

        char NIC[12];
        char pass[8];

    // FILE *fp;

printf("Enter Your NIC Number:\n");
scanf("%s",login_NIC);
printf("Enter Your Password:\n");
scanf("%s",login_pass);

// fp=fopen("voters details.txt","r");
FILE *fp = fopen("voters.txt" , "r");
    if(fp==NULL){
        printf("Error\n");
        return 1;
    }
    char line[256] , db_name[20] , db_nic[20] , db_pass[20];
    while(fgets(line ,sizeof(line),fp)){
        sscanf(line,"%[^,],%[^,],%[^\n]",db_name ,db_nic,db_pass);
         if(strcmp(db_nic,login_NIC)==0 && strcmp(db_pass,login_pass)==0){
            printf("yes hutto\n");
            fclose(fp);
         }
         //printf("compare %s with %s & %s with %s\n" , db_nic , login_NIC , db_pass , login_pass);
        //printf("%s\t%s\n",db_nic , db_pass);
    }
    

    // while(fscanf(fp,"%s %s",login_NIC,login_pass)==2){
       

    // }
    return 0;
}