#include <iostream>
using namespace std;

int main() {
    int n, number;
    int evenSum = 0, oddSum = 0;

    // Ask for the number of integers to be input
    cout << "Enter the number of integers: ";
    cin >> n;

    cout << "Enter the integers:" << endl;

    // Loop to read integers and calculate sum of even and odd numbers
    for (int i = 0; i < n; i++) {
        cin >> number;

        if (number % 2 == 0) {
            evenSum += number;  // Add to even sum if the number is even
        } else {
            oddSum += number;   // Add to odd sum if the number is odd
        }
    }

    // Output the sums of even and odd numbers
    cout << "Sum of even integers: " << evenSum << endl;
    cout << "Sum of odd integers: " << oddSum << endl;

    return 0;
}

