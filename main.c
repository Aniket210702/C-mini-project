#include<stdio.h>
#include<stdlib.h>

int Menu();
void Bus();
void Cycle();
void Riksha();
void ShowStatus();
void Delete();

int nor=0, noc=0, nob=0, amount=0, count=0;

void clrscr(){
    printf("\033[H\033[J"); // ANSI escape code to clear screen (may not work in online compilers)
}

int main(){
    while(1){
        clrscr();
        int choice = Menu(); // Store user input first

        switch(choice){
            case 1: Bus(); break;
            case 2: Cycle(); break;
            case 3: Riksha(); break;
            case 4: ShowStatus(); break;
            case 5: Delete(); break;
            case 6: exit(0);
            default: printf("Invalid Choice\n");
        }

        printf("\nPress Enter to continue...");
        while (getchar() != '\n'); // Clear input buffer
        getchar(); // Wait for Enter key
    }
}

int Menu(){
    int ch;
    printf("\n1. Enter Bus:");
    printf("\n2. Enter Cycle:");
    printf("\n3. Enter Riksha:");
    printf("\n4. Show Status");
    printf("\n5. Delete data");
    printf("\n6. Exit");
    printf("\n\nEnter your choice: ");

    if (scanf("%d", &ch) != 1) { // Check if input is valid
        while (getchar() != '\n'); // Clear invalid input
        return 0; // Return invalid choice
    }

    return ch;
}

void Delete(){
    nob = noc = nor = amount = count = 0;
    printf("\nAll data has been reset.\n");
}

void ShowStatus(){
    printf("\nNumber of buses: %d", nob);
    printf("\nNumber of cycles: %d", noc);
    printf("\nNumber of rickshaws: %d", nor);
    printf("\nTotal number of vehicles: %d", count);
    printf("\nTotal earned amount: %d", amount);
}

void Riksha(){
    nor++;
    amount += 50;
    count++;
    printf("\nRiksha parked! Fee: 50\n");
}

void Cycle(){
    noc++;
    amount += 20;
    count++;
    printf("\nCycle parked! Fee: 20\n");
}

void Bus(){
    nob++;
    amount += 100;
    count++;
    printf("\nBus parked! Fee: 100\n");
}
