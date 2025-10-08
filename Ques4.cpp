#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char ch) {
        data = ch;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = NULL;
    }


    void insertEnd(char ch) {
        Node* newNode = new Node(ch);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    
    bool isPalindrome() {
        if (head == NULL)
            return true;

        Node* left = head;
        Node* right = head;

        // right pointer to the last node
        while (right->next != NULL) {
            right = right->next;
        }

        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }

        return true;
    }


    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertEnd('r');
    dll.insertEnd('a');
    dll.insertEnd('d');
    dll.insertEnd('a');
    dll.insertEnd('r');

    dll.display();

    if (dll.isPalindrome())
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}

