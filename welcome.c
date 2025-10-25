#include <stdio.h>
#include <stdlib.h>
#include "main.c"
#include "instruction.c"
int menu();
int display_instructions();
int view_result();
int main(){
        int i;
        printf("*********************************************************************\n");
        printf("*                  PARLIMENTARY VOTING SYSTEM                       *\n");
        printf("*********************************************************************\n");
        printf("**                                                                 **\n");
        printf("**             WELCOME TO THE PARLIMENTARY VOTING SYSTEM           **\n");
        printf("**                                                                 **\n");
        printf("** System Version: 1.0                                             **\n");
        printf("** Developed by:TG/2024/2124,TG/2024/2063,TG/2024/2143,TG/2024/2138**\n");
        printf("*********************************************************************\n");
        printf("* Please select an option to proceed:                               *\n");
        printf("**                                                                 **\n");
        printf("* \033[1;31m[1] - Main Menu\033[0m                                                   *\n");
        printf("* \033[1;32m[2] - View Instructions\033[0m                                           *\n");
        printf("* \033[1;33m[3] - View Results\033[0m                                                *\n");
        printf("* \033[1;35m[4] - Exit System\033[0m                                                 *\n");
        printf("**                                                                 **\n");
        printf("*********************************************************************\n");
        printf("*********************************************************************\n");
        scanf("%d", &i);
        switch(i){
            case 1:
                menu();
                break;
            case 2:
                display_instructions();
                menu();
                break;
            case 3:
                 view_result();
                menu();
                break;
            case 4:
                 printf("Successful Exit.\n");
                exit(0);             
            default:
                printf("Invalid Option Selected.\n");
                break;
}
    return 0;
}