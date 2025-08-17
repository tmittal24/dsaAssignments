#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int size = 0;

// Function to create the array
void create() {
    cout << "Enter number of elements: ";
    cin >> size;
    if (size > MAX) {
        cout << "Maximum size exceeded. Limit is " << MAX << ".\n";
        size = 0;
        return;
    }
    cout << "Enter elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}

// Function to display the array
void display() {
    if (size == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Current array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Function to insert an element at a given position
void insert() {
    if (size == 0) {
        cout << "Array is empty. Create the array first.\n";
        return;
    }
    if (size == MAX) {
        cout << "Array is full. Cannot insert more elements.\n";
        return;
    }

    int element, position;
    cout << "Enter the element to insert: ";
    cin >> element;
    cout << "Enter the position to insert at (0 to " << size << "): ";
    cin >> position;

    if (position < 0 || position > size) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    cout << "Element inserted successfully.\n";
}

// Function to delete an element from a given position
void deleteElement() {
    if (size == 0) {
        cout << "Array is empty. Nothing to delete.\n";
        return;
    }

    int position;
    cout << "Enter the position to delete from (0 to " << size - 1 << "): ";
    cin >> position;

    if (position < 0 || position >= size) {
        cout << "Invalid position.\n";
        return;
    }

    int deleted = arr[position];
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element " << deleted << " deleted successfully.\n";
}

// Function to perform linear search
void linearSearch() {
    if (size == 0) {
        cout << "Array is empty. Create the array first.\n";
        return;
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found in the array.\n";
    }
}

// Main function with menu
int main() {
    int choice;

    while (true) {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                linearSearch();
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    return 0;
}