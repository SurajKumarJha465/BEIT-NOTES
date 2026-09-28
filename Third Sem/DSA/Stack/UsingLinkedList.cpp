#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Top of the stack
Node* top = nullptr;

// Function to create a new node
Node* creatnode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == nullptr;
}

// Push operation
void push() {
    int value;
    cout << "Enter the data you want to insert: ";
    cin >> value;

    // Create a new node and update top
    Node* newnode = creatnode(value);
    newnode->next = top; // Link the new node to the current top
    top = newnode;

    cout << "Inserted " << value << " into the stack." << endl;
}

// Pop operation
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }

    // Remove the top node
    Node* temp = top;
    cout << "Popped element: " << top->data << endl;
    top = top->next;

    // Free the memory of the removed node
    delete temp;
}

// Traverse operation
void traverse() {
    if (isEmpty()) {
        cout << "Stack is empty. Nothing to display." << endl;
        return;
    }

    cout << "Stack elements are: ";
    Node* current = top;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Main function
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
