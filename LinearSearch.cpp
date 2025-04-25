#include <iostream>
using namespace std;

int main() {
    // Linear search
    int n, i, num;
    
    cout << "Enter the size of an array: ";
    cin >> n;

    int arr[n]; // Array declaration

    cout << "Enter array elements:" << endl;
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element you want to search: ";
    cin >> num;

    // Searching logic
    bool found = false;
    for (i = 0; i < n; i++) {
        if (arr[i] == num) {
            found = true;
            cout << "Search successful! Element found at index " << i << endl;
            break;
        }
    }

    if (!found) {
        cout << "Search unsuccessful! Element not found." << endl;
    }

    return 0;
}

