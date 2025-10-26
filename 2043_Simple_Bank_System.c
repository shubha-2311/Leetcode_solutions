#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int balanceSize;
    long long *balance;
} Bank;

Bank* bankCreate(long long* balance, int balanceSize) {
    Bank *bank = (Bank*)malloc(sizeof(Bank));
    bank->balanceSize = balanceSize;
    bank->balance = (long long*)malloc(balanceSize * sizeof(long long));
    for (int i = 0; i < balanceSize; i++) {
        bank->balance[i] = balance[i];
    }
    return bank;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    if ((account1 <= obj->balanceSize && account1 > 0) &&
        (account2 <= obj->balanceSize && account2 > 0)) {
        if (money <= obj->balance[account1 - 1]) {
            obj->balance[account1 - 1] -= money;
            obj->balance[account2 - 1] += money;
            return true;
        }
    }
    return false;
}

bool bankDeposit(Bank* obj, int account, long long money) {
    if (account <= obj->balanceSize && account > 0) {
        obj->balance[account - 1] += money;
        return true;
    }
    return false;
}

bool bankWithdraw(Bank* obj, int account, long long money) {
    if (account <= obj->balanceSize && account > 0) {
        if (money <= obj->balance[account - 1]) {
            obj->balance[account - 1] -= money;
            return true;
        }
    }
    return false;
}

void bankFree(Bank* obj) {
    free(obj->balance);
    free(obj);
}

/* Example Simulation */
int main() {
    long long balance[] = {10, 100, 20, 50, 30};
    int size = sizeof(balance) / sizeof(balance[0]);

    Bank* bank = bankCreate(balance, size);

    printf("%s\n", bankWithdraw(bank, 3, 10) ? "true" : "false");   // true
    printf("%s\n", bankTransfer(bank, 5, 1, 20) ? "true" : "false"); // true
    printf("%s\n", bankDeposit(bank, 5, 20) ? "true" : "false");     // true
    printf("%s\n", bankTransfer(bank, 3, 4, 15) ? "true" : "false"); // false
    printf("%s\n", bankWithdraw(bank, 10, 50) ? "true" : "false");   // false

    bankFree(bank);
    return 0;
}
