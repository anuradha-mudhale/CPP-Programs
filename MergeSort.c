#include <stdio.h>

void merge(int arr[], int si, int mid, int ei) {
    int temp[100]; // Temporary array
    int i = si, j = mid + 1, k = 0;

    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= ei) {
        temp[k++] = arr[j++];
    }

    // Copy sorted values back to original array
    for (i = si, k = 0; i <= ei; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

int main() {
    int n,i;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n]; // Correct declaration after getting `n`
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

