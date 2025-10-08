#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class DoublyList {
    Node* head;

public:
    DoublyList() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    // Insert at beginning
    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void insertBack(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert after a given value
    void insertAfterVal(int x, int val) {
        if (isEmpty()) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Value " << val << " not found.\n";
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    // Delete from beginning
    void deleteBegin() {
        if (isEmpty()) {
            cout << "Underflow.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    // Delete from end
    void deleteEnd() {
        if (isEmpty()) {
            cout << "Underflow.\n";
            return;
        }

        Node* temp = head;
        if (temp->next == NULL) { // Only one node
            delete head;
            head = NULL;
            return;
        }

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
    }

    // Delete by value
    void deleteByValue(int val) {
        if (isEmpty()) {
            cout << "Underflow.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Value not found.\n";
            return;
        }

        if (temp == head)
            deleteBegin();
        else if (temp->next == NULL)
            deleteEnd();
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // Search key
    bool SearchKey(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display forward
    void display() {
        if (isEmpty()) {
            cout << "List empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display backward
    void displayReverse() {
        if (isEmpty()) {
            cout << "List empty.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        cout << "Reversed List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyList l1;
    l1.insertFront(10);
    l1.insertFront(5);
    l1.insertBack(20);
    l1.insertBack(30);

    l1.display();

    l1.insertAfterVal(25, 20);
    cout << "After inserting 25 after 20:\n";
    l1.display();

    l1.deleteBegin();
    cout << "After deleting first node:\n";
    l1.display();

    l1.deleteEnd();
    cout << "After deleting last node:\n";
    l1.display();

    l1.deleteByValue(25);
    cout << "After deleting value 25:\n";
    l1.display();

    cout << (l1.SearchKey(10) ? "10 Found\n" : "10 Not Found\n");
    cout << (l1.SearchKey(100) ? "100 Found\n" : "100 Not Found\n");

    l1.displayReverse();

    return 0;
}

