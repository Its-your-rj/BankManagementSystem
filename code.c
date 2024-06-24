#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;


void createAccount(Account accounts[], int *numAccounts);
void depositMoney(Account accounts[], int numAccounts);
void withdrawMoney(Account accounts[], int numAccounts);
void checkBalance(Account accounts[], int numAccounts);
int findAccount(Account accounts[], int numAccounts, int accountNumber);

int main() {
    Account accounts[100];
    int numAccounts = 0;
    int choice;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &numAccounts);
                break;
            case 2:
                depositMoney(accounts, numAccounts);
                break;
            case 3:
                withdrawMoney(accounts, numAccounts);
                break;
            case 4:
                checkBalance(accounts, numAccounts);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void createAccount(Account accounts[], int *numAccounts) {
    printf("Enter account number: ");
    scanf("%d", &accounts[*numAccounts].accountNumber);
    printf("Enter name: ");
    scanf("%s", accounts[*numAccounts].name);
    accounts[*numAccounts].balance = 0.0;
    (*numAccounts)++;
    printf("Account created successfully!\n");
}

void depositMoney(Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int index = findAccount(accounts, numAccounts, accountNumber);
    if (index != -1) {
        printf("Enter amount to deposit: ");
        scanf("%f", &amount);
        accounts[index].balance += amount;
        printf("Amount deposited successfully!\n");
    } else {
        printf("Account not found!\n");
    }
}

void withdrawMoney(Account accounts[], int numAccounts) {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int index = findAccount(accounts, numAccounts, accountNumber);
    if (index != -1) {
        printf("Enter amount to withdraw: ");
        scanf("%f", &amount);
        if (accounts[index].balance >= amount) {
            accounts[index].balance -= amount;
            printf("Amount withdrawn successfully!\n");
        } else {
            printf("Insufficient balance!\n");
        }
    } else {
        printf("Account not found!\n");
    }
}

void checkBalance(Account accounts[], int numAccounts) {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    int index = findAccount(accounts, numAccounts, accountNumber);
    if (index != -1) {
        printf("Account balance: Rs%.2f\n", accounts[index].balance);
    } else {
        printf("Account not found!\n");
    }
}

int findAccount(Account accounts[], int numAccounts, int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}
