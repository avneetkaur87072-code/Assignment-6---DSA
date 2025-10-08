#include <iostream>
using namespace std;

int countOnes(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class CircularList {
public:
    Node* head;
    CircularList() {
        head = NULL;
    }

    void insertBack(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    int countOnes(int n) {
        int cnt = 0;
        while (n) {
           if (n & 1) cnt++;
           n = n >> 1; //shifts the bits to right by one position.
        }
        return cnt;
    }

    void removeEvenParity() {
        if (!head)
            return;

        // Handle case: head has even parity
        while (head && countOnes(head->data) % 2 == 0) {
            if (head->next == head) { // only one node
                delete head;
                head = NULL;
                return;
            }
            Node* last = head;
            while (last->next != head){
            	last = last->next;
			}
                
            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
        }

        // Now handle other nodes
        if (!head) return;
        Node* curr = head;
        while (curr->next != head) {
            if (countOnes(curr->next->data) % 2 == 0) {
                Node* delNode = curr->next;
                curr->next = curr->next->next;
                delete delNode;
            } else {
                curr = curr->next;
            }
        }
    }

    void display() {
        if (!head) {
            cout << "List empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " -> ";
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularList cll;
    cll.insertBack(9);
    cll.insertBack(11);
    cll.insertBack(34);
    cll.insertBack(6);
    cll.insertBack(13);
    cll.insertBack(21);

    cout << "Before removal:\n";
    cll.display();

    cll.removeEvenParity();

    cout << "After removing even-parity nodes:\n";
    cll.display();
    return 0;
}

