#include <iostream>
using namespace std;

void update(int marks[], int size) {
    for (int i = 0; i < size; i++) {
        marks[i] = marks[i] + 1;  // Increment each element
    }

    // Print updated array
    cout << "Updated array: ";
    for (int i = 0; i < size; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

int main() {
    int marks[] = {90, 92, 80};
    int size = sizeof(marks) / sizeof(marks[0]); // Calculate array size

    update(marks, size); 

    return 0;
}

