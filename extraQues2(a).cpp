#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class DoublyList {
public:
    Node* head;

    DoublyList() {
        head = NULL;
    }

    void insertBack(int x) {
        Node* newNode = new Node(x);
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
    int countOnes(int n) {
    int cnt = 0;
    while (n) {
        if (n & 1) cnt++;
        n = n >> 1; //shifts the bits to right by one position.
    }
    return cnt;
}

    void removeEvenParity() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            if (countOnes(temp->data) % 2 == 0) {  // even parity
                if (temp == head)
                    head = temp->next;
                if (temp->prev)
                    temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;
                delete temp;
            }
            temp = nextNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <=> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
	DoublyList dll;
	dll.insertBack(1);
	dll.insertBack(2);
	dll.insertBack(3);
	dll.insertBack(4);
	dll.insertBack(5);
	cout << "Before deletion: ";
	dll.display();
	dll.removeEvenParity();
	cout <<"After deletion: ";
	dll.display();
	return 0;
}

