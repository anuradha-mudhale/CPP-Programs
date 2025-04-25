#include <stdio.h>

// Function to sort the coin array in descending order (Simple Bubble Sort)
void sortDescending(int coins[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (coins[j] < coins[j+1]) {
                temp = coins[j];
                coins[j] = coins[j+1];
                coins[j+1] = temp;
            }
        }
    }
}

int main() {
    int coins[] = {1, 5, 10, 25};  // Available denominations
    int n = sizeof(coins) / sizeof(coins[0]);  // Number of denominations
    int amount = 63;  // Amount for which we want change

    sortDescending(coins, n);  // Step 1: Sort denominations in descending order

    int coinCount = 0;
    int usedCoins[100];  // To store the coins used
    int k = 0;  // index for usedCoins[]

    // Step 2: Greedy selection
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];  // Subtract coin value
            usedCoins[k++] = coins[i];  // Store the coin used
            coinCount++;  // Increase the count
        }
    }

    // Output result
    printf("Minimum coins required: %d\n", coinCount);
    printf("Coins used: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", usedCoins[i]);
    }
    printf("\n");

    return 0;
}

