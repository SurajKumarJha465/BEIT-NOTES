#include <iostream>
using namespace std;

#define size 5
int array[size];
int top = -1;

bool isFull() {
    return top == size - 1;
}

bool isEmpty() {
    return top == -1;
}

void push() {
    if (isFull()) {
        cout << "Stack Overflow! Cannot insert more elements." << endl;
        return;
    }
    int x;
    cout << "Enter the data you want to insert: ";
    cin >> x;
    top++;
    array[top] = x;
    cout << "Inserted " << x << " into the stack." << endl;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }
    cout << "Popped element: " << array[top] << endl;
    top--;
}

void traverse() {
    if (isEmpty()) {
        cout << "Stack is empty. Nothing to display." << endl;
        return;
    }
    cout << "Stack elements are: ";
    for (int i = top; i >= 0; i--) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    while (true) {
        int choice;
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                traverse();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
