#include <stdio.h>

    struct BankAccount {
    int accountNumber;
    char accountHolder[100];
    float balance;
};
void createAccount(struct BankAccount *account) {
    printf("Enter account number: ");
    scanf("%d", &(account->accountNumber));
    
    printf("Enter account holder name: ");
    scanf("%s", account->accountHolder);
    
    account->balance = 0.0;  
    printf("Account created successfully!\n");
}
void deposit(struct BankAccount *account) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);
    
    account->balance += amount;
    
    printf("Deposit successful! Current balance: %.2f\n", account->balance);
}
void withdraw(struct BankAccount *account) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount > account->balance) {
        printf("Insufficient balance.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful! Current balance: %.2f\n", account->balance);
    }
}
void checkBalance(struct BankAccount *account) {
    printf("Account holder: %s\n", account->accountHolder);
    printf("Account number: %d\n", account->accountNumber);
    printf("Balance: %.2f\n", account->balance);
}
int main() {
    struct BankAccount account;
    int choice;
    
    printf("Simple Bank Application\n");
    
    do {
        printf("\n1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                deposit(&account);
                break;
            case 3:
                withdraw(&account);
                break;
            case 4:
                checkBalance(&account);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
