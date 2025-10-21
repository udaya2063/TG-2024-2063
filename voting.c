#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tre();
void displayCandidates(const char* filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening %s\n", filename);
        return;
    }

    char line[256];
    char name[50], party[50], number[50], extra[50];
    
    printf("\nCandidates from %s:\n", filename);
    printf("-----------------------------------\n");
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", name, party, number, extra) == 4)
            printf("Name: %-15s | Number: %s\n", name, number);
    }
    fclose(fp);
}

void voteForCandidate(const char* partyFile, const char* voteFile) {
    char line[256];
    char name[50], party[50], number[50], extra[50];
    char input_number[50];
    int found = 0;

    displayCandidates(partyFile);

    printf("\nEnter candidate number to vote: ");
    scanf("%s", input_number);

    FILE *votes = fopen(voteFile, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!temp) {
        printf("Error opening temp file.\n");
        if (votes) fclose(votes);
        return;
    }

    char v_name[50], v_number[50];
    int v_count;

    if (votes) {
        while (fgets(line, sizeof(line), votes)) {
            if (sscanf(line, "%[^,],%[^,],%d", v_name, v_number, &v_count) == 3) {
                if (strcmp(v_number, input_number) == 0) {
                    v_count++;
                    printf("\nYou voted for %s (Number: %s). New total votes: %d\n", v_name, v_number, v_count);
                    fprintf(temp, "%s,%s,%d\n", v_name, v_number, v_count);
                    found = 1;
                } else {
                    fprintf(temp, "%s,%s,%d\n", v_name, v_number, v_count);
                }
            }
        }
        fclose(votes);
    }

    if (!found) {
        FILE *fp = fopen(partyFile, "r");
        while (fgets(line, sizeof(line), fp)) {
            if (sscanf(line, "%[^,],%[^,],%[^,],%[^\n]", name, party, number, extra) == 4) {
                if (strcmp(number, input_number) == 0) {
                    v_count = 1;
                    printf("\nYou voted for %s (Number: %s). New total votes: %d\n", name, number, v_count);
                    fprintf(temp, "%s,%s,%d\n", name, number, v_count);
                    found = 1;
                    break;
                }
            }
        }
        fclose(fp);
    }

    fclose(temp);

    if (found) {
        remove(voteFile);
        rename("temp.txt", voteFile);
        printf("Vote saved successfully!\n");
    } else {
        remove("temp.txt");
        printf("Candidate number not found.\n");
    }
}

void displayVotes(const char* voteFile) {
    FILE *show = fopen(voteFile, "r");
    if (!show) {
        printf("No votes recorded yet for this party.\n");
        return;
    }

    char line[256];
    char v_name[50], v_number[50];
    int v_count;

    printf("\nCurrent Vote Counts:\n");
    printf("-----------------------------------\n");
    while (fgets(line, sizeof(line), show)) {
        if (sscanf(line, "%[^,],%[^,],%d", v_name, v_number, &v_count) == 3)
            printf("Name: %-15s | Number: %s | Votes: %d\n", v_name, v_number, v_count);
    }
    fclose(show);
}

void displayAllVotes() {
    printf("\n=== ALL VOTE COUNTS ===\n");
    printf("\nNPP Votes:\n");
    displayVotes("NPP_votes.txt");
    
    printf("\nUDP Votes:\n");
    displayVotes("UDP_votes.txt");
    
    printf("\nUNP Votes:\n");
    displayVotes("UNP_votes.txt");
}

void voteMenu() {
    int partyChoice;
    char cont;
    
    do {
        printf("\n=== SELECT PARTY ===\n");
        printf("1. NPP\n");
        printf("2. UDP\n");
        printf("3. UNP\n");
        printf("4. View All Vote Counts\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &partyChoice);

        switch(partyChoice) {
            case 1:
                voteForCandidate("NPP.txt", "NPP_votes.txt");
                break;
            case 2:
                voteForCandidate("UDP.txt", "UDP_votes.txt");
                break;
            case 3:
                voteForCandidate("UNP.txt", "UNP_votes.txt");
                break;
            case 4:
                displayAllVotes();
                break;
            case 5:
                printf("Returning to main menu...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }

        if (partyChoice >= 1 && partyChoice <= 3) {
            printf("\nDo you want to vote again? (y/n): ");
            scanf(" %c", &cont);
            if (cont == 'n' || cont == 'N') {
                return;
            }
        } else if (partyChoice == 4) {
            printf("\nPress any key to continue...");
            getchar();
            getchar();
        }

    } while (1);
}

int tre() {
    int choice;

    do {
        printf("\n=== VOTING SYSTEM ===\n");
        printf("[1] Vote\n");
        printf("[2] Exit\n");
        printf("Enter your choice (1-2): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                voteMenu();
                break;
            case 2:
                printf("Thank you for using the voting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1 or 2.\n");
        }

    } while (1);

    return 0;
}