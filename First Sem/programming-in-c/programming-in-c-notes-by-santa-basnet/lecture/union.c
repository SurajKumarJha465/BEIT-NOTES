/**
 * Example to demonstrate the use of Union in C language.
 *
 * This program illustrates the three types of account in a typical
 * commercial bank which shares multiple structures in a Union type.
 * Union is all about shared memory, representation of variable sizes
 * of data.
 *
 * Everest Engineering College.
 * By: Santa Basnet.
 * Date: Nov 17, 2021.
 */

/**
 * Header files.
 */
#include <stdio.h>
#include <string.h>

/**
 * Account type literals.
 */
const int FIXED = 0;
const int SAVING = 1;
const int CURRENT = 2;

/**
 * Saving account: demo attributes.
 * Saving account provides interest but does not have mature date.
 */
struct Saving {
    float interestRate;
    double balance;
};

/**
 * Current account: demo attributes.
 * Current account does not provide interests to their clients.
 */
struct Current {
    double balance;
};

/**
 * Fixed account: demo attributes.
 * Fixed account has certain interest rate and mature date.
 */
struct Fixed {
    float interestRate;
    double balance;
    long matureDate;
};

/**
 * Account type definitions with the help of Union.
 */
struct Account {
    char name[64];
    int type;
    union {
        struct Saving saving;
        struct Current current;
        struct Fixed fixed;
    } accountDetails;
};

/**
 * Main function starts here.
 * @return
 */
int main() {
    struct Account account;
    /**
     * Initialization.
     */
    strcpy(account.name, "Everest Engineering College");
    account.type = FIXED;
    account.accountDetails.fixed.balance = 100000.9f;
    account.accountDetails.fixed.matureDate = 1637159100239l;
    account.accountDetails.fixed.interestRate = 0.12f;

    return 0;
}