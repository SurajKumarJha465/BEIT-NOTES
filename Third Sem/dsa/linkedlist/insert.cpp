#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;            // Data part
    Node* next;          // Pointer to the next node
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();  // Allocate memory for the new node
    newNode->data = value;       // Assign value to the node
    newNode->next = nullptr;     // Initialize next pointer to nullptr
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {  // If the list is empty
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;  // Link the last node to the new node
}

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int position, int value) {
    Node* newNode = createNode(value);

    if (position == 1) {  // Insert at the beginning if position is 1
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;  // Traverse to the node before the desired position
    }

    if (temp == nullptr) {  // If position is out of range
        cout << "Position out of range." << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;  // Link the new node
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    Node* head = nullptr;  // Initialize the list as empty

    // Insert nodes
    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtPosition(head, 2, 15);  // Insert 15 at position 2
    insertAtPosition(head, 1, 5);  // Insert 5 at position 1

    // Display the list
    cout << "Linked list after insertions:" << endl;
    displayList(head);

    return 0;
}
