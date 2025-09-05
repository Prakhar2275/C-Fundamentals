#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int accountNo;
    char name[100];
    float balance;
} Account;

void createAccount();
void viewAccount();
void listAccounts();
void deposit();
void withdraw();
void deleteAccount();

int main()
{
    int choice;
    while (1)
    {
        printf("\n==== Bank Management System ====\n");
        printf("1. Create New Account\n");
        printf("2. View Account\n");
        printf("3. List All Accounts\n");
        printf("4. Deposit\n");
        printf("5. Withdraw\n");
        printf("6. Delete Account\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            viewAccount();
            break;
        case 3:
            listAccounts();
            break;
        case 4:
            deposit();
            break;
        case 5:
            withdraw();
            break;
        case 6:
            deleteAccount();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void createAccount()
{
    Account acc;
    FILE *fp = fopen("accounts.dat", "ab");
    if (!fp)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc.accountNo);
    getchar(); // flush newline
    printf("Enter Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = 0; // remove newline
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(Account), 1, fp);
    fclose(fp);
    printf("Account created successfully.\n");
}

void viewAccount()
{
    int accNo, found = 0;
    Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    if (!fp)
    {
        printf("File not found.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(Account), 1, fp))
    {
        if (acc.accountNo == accNo)
        {
            printf("\nAccount Number: %d\n", acc.accountNo);
            printf("Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }

    fclose(fp);
}

void listAccounts()
{
    Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    if (!fp)
    {
        printf("No accounts found.\n");
        return;
    }

    printf("\n==== List of Accounts ====\n");
    while (fread(&acc, sizeof(Account), 1, fp))
    {
        printf("Account No: %d | Name: %s | Balance: %.2f\n", acc.accountNo, acc.name, acc.balance);
    }

    fclose(fp);
}

void deposit()
{
    int accNo;
    float amount;
    int found = 0;
    Account acc;

    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp)
    {
        printf("File error.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter Amount to Deposit: ");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(Account), 1, fp))
    {
        if (acc.accountNo == accNo)
        {
            acc.balance += amount;
            fseek(fp, -sizeof(Account), SEEK_CUR);
            fwrite(&acc, sizeof(Account), 1, fp);
            printf("Deposit successful. New balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }

    fclose(fp);
}

void withdraw()
{
    int accNo;
    float amount;
    int found = 0;
    Account acc;

    FILE *fp = fopen("accounts.dat", "rb+");
    if (!fp)
    {
        printf("File error.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &accNo);
    printf("Enter Amount to Withdraw: ");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(Account), 1, fp))
    {
        if (acc.accountNo == accNo)
        {
            if (acc.balance >= amount)
            {
                acc.balance -= amount;
                fseek(fp, -sizeof(Account), SEEK_CUR);
                fwrite(&acc, sizeof(Account), 1, fp);
                printf("Withdrawal successful. Remaining balance: %.2f\n", acc.balance);
            }
            else
            {
                printf("Insufficient balance.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Account not found.\n");
    }

    fclose(fp);
}

void deleteAccount()
{
    int accNo, found = 0;
    Account acc;

    FILE *fp = fopen("accounts.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (!fp || !temp)
    {
        printf("File error.\n");
        return;
    }

    printf("Enter Account Number to delete: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(Account), 1, fp))
    {
        if (acc.accountNo == accNo)
        {
            found = 1;
            continue;
        }
        fwrite(&acc, sizeof(Account), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("accounts.dat");
    rename("temp.dat", "accounts.dat");

    if (found)
        printf("Account deleted successfully.\n");
    else
        printf("Account not found.\n");
}
