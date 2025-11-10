#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Insert node at end
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to reverse k nodes
Node* reverseInGroups(Node* head, int k) {
    Node* current = head;
    Node* nextNode = nullptr;
    Node* newHead = nullptr;
    int count = 0;

    // Reverse first k nodes
    while (current && count < k) {
        nextNode = current->next;
        current->next = newHead;  // point to previous node in reversed group
        if (newHead)
            newHead->prev = current;
        newHead = current;
        current = nextNode;
        count++;
    }

    // Now head is the last node of reversed group
    if (nextNode) {
        head->next = reverseInGroups(nextNode, k);
        if (head->next)
            head->next->prev = head;
    } else {
        head->next = nullptr;  // last node points to NULL
    }

    newHead->prev = nullptr;  // first node of group points prev to NULL
    return newHead;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << " <-> NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int k = 2;

    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);

    cout << "Original List:\n";
    printList(head);

    head = reverseInGroups(head, k);

    cout << "\nReversed in groups of " << k << ":\n";
    printList(head);

    return 0;
}


