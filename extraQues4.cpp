#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(){
			prev = NULL;
			next = NULL;
		}
		Node(int x){
			data = x;
			prev = NULL;
			next = NULL;	
		}
};

class DoublyLL{
	public:
		Node* head;
		void display(){
			Node* temp = head;
			while(temp != NULL){
				cout << temp->data << "->";
				temp = temp->next;
			}
			cout <<"NULL"<< endl;
        }
    void printReverse(){
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        cout << "NULL->";
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->prev;
        }
        cout<<endl;
    }
    void correctPointer(){
    	if(!head) return;
    	Node* temp = head;
    	while(temp->next != NULL){
    		if(temp->next->prev != temp){
    			temp->next->prev = temp;
			}
			temp = temp->next;
		}
	}

		
};

int main(){
	DoublyLL l1;
	l1.head = new Node(1);
	l1.head->next = new Node(2);
	l1.head->next->prev = l1.head;
	l1.head->next->next = new Node(3);
	l1.head->next->next->prev = l1.head;
	l1.head->next->next->next = new Node(4); 
    l1.head->next->next->next->prev = l1.head->next->next; 
    
    l1.display();
    l1.printReverse();
    l1.correctPointer();
    cout << "corrected Now!";
    l1.display();
    cout << "reverse is now correct: ";
    l1.printReverse();
    
	return 0;
}




