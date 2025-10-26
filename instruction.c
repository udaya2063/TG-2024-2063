#include <stdio.h>
int display_instructions() {
    printf("\n");
    printf("==========================================================\n");
    printf("||                 SYSTEM INSTRUCTIONS                   ||\n");
    printf("==========================================================\n");
    printf("||                                                       ||\n");
    printf("|| 1. SYSTEM NAVIGATION:                                 ||\n");
    printf("||    - To select an option, type the corresponding      ||\n");
    printf("||      number ([1], [2], [3], [4], or [5]) and Type     ||\n");
    printf("||      any thing and press the [ENTER] key.             ||\n");
    printf("||                                                       ||\n");
    printf("|| 2. REGISTRATION (Options [1] & [2]):                  ||\n");
    printf("||    - Use [1] to register as a new voter (if allowed). ||\n");
    printf("||    - Use [2] to register new candidates               ||\n");
    printf("||                                                       ||\n");
    printf("|| 3. VOTING PROCESS (Option [3] - Login):               ||\n");
    printf("||    - You must successfully Login to access the        ||\n");
    printf("||      'Voting Interface' and cast your vote.           ||\n");
    printf("||    - Once a vote is cast, it cannot be changed.       ||\n");
    printf("||                                                       ||\n");
    printf("|| 4. VIEW RESULTS (Option [4]):                         ||\n");
    printf("||    - Select [4] to view the live tally of party       ||\n");
    printf("||      and candidate votes.                             ||\n");
    printf("||                                                       ||\n");    
    printf("|| 5. EXITING THE SYSTEM:                                ||\n");
    printf("||    - Select [5] to close the application immediately. ||\n");
    printf("||                                                       ||\n");    
    printf("==========================================================\n");
    printf("\n");
    printf("Press ENTER to continue to the Main Menu...");
    while (getchar() != '\n'); 
    getchar();
    return 0;
}