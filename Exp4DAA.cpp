#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int profit;
    float ratio; 
} Item;

int compare(const void *a, const void *b) {
    float r1 = ((Item *)a)->ratio;
    float r2 = ((Item *)b)->ratio;
    return (r2 > r1) - (r2 < r1); 
}


void fractionalKnapsack(Item items[], int n, int capacity) {

    qsort(items, n, sizeof(Item), compare);

    float totalProfit = 0.0;
    int currentWeight = 0;

    printf("Selected items:\n");
    

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
          
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("Item with weight %d and profit %d completely taken.\n", items[i].weight, items[i].profit);
        } else {
            
            int remainingWeight = capacity - currentWeight;
            float fraction = (float)remainingWeight / items[i].weight;
            totalProfit += items[i].profit * fraction;
            printf("Item with weight %d and profit %d taken %.2f%%.\n", items[i].weight, items[i].profit, fraction * 100);
            break;
        }
    }

    printf("Total profit: %.2f\n", totalProfit);
}


int main() {
    
    Item items[] = {{4, 12}, {2, 1}, {2, 2}, {1, 1}, {10, 4}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 15; 

    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

 
    fractionalKnapsack(items, n, capacity);

    return 0;
}

