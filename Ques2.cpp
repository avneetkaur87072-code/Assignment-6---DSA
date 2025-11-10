#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;  
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
       while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        } 
        cout << temp->data <<" ";
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertEnd(20);
    cll.insertEnd(100);
    cll.insertEnd(40);
    cll.insertEnd(80);
    cll.insertEnd(60);

    cout << "Circular Linked List: ";
    cll.display();

    return 0;
}


