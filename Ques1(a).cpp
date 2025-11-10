#include<iostream>
using namespace std;

class Node{
	public:	
	int data;
	Node* next;
	
	Node(int x){
		data = x;
		next = NULL;
	}
};

class CircularList{
	Node* head;
	public:
		CircularList(){
			head=NULL;
		}
		bool isEmpty(){
			if(head==NULL) return true;
			else return false;
		}
		void insertFront(int x){
			Node* newNode = new Node(x);
			if(isEmpty()){
				head = newNode;
				newNode->next = head;
			}
			else{
				Node* temp=head;
				while(temp->next != head){
					temp = temp->next;
				}
				newNode->next = head;
				temp->next = newNode;
				head = newNode;
			}
		}
		void insertBack(int x){
			Node* newNode = new Node(x);
			if(isEmpty()){
				head = newNode;
				newNode->next = head;
			}
			else{
				Node* temp=head;
				while(temp->next != head){
					temp = temp->next;
				}
				newNode->next = head;
				temp->next = newNode;
			}
		}
		void insertAtPosition(int x,int pos){
			if(pos < 0){
				cout << "Invalid position." << endl;
				return;
			}
			Node* newNode = new Node(x);
			if(isEmpty()){
				head = newNode;
			}
			else{
				int count = 0;
				Node* temp = head;
				while(temp->next != head && count < pos-1){
					temp = temp->next;
					count++;
				}
				if(temp->next == head){
					cout<<"position out of range."<< endl;
					return;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		
		void insertAfterVal(int x,int val){
			Node* newNode = new Node(x);
			
			if(isEmpty()){
				head = newNode;
			}
			else{
				Node* temp = head;
//				while(temp != head && temp->data != val){
//					temp = temp->next;
//				}
//				newNode->next = temp->next;
//				temp->next = newNode;
   do {                                     //here we use do while loop, otherwise the loop will never start because in starting only temp = head
            if (temp->data == val) {
                Node* newNode = new Node(x);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

			}
		}
		
		void deleteBegin(){
			if(head == NULL){
				cout <<"underflow."<< endl;
				return;
			} 
			else if(head->next == head){
				delete head;
				head = NULL;
				return;
			}
			else{
				Node* temp = head;
		    	Node* curr=head;
			    while(curr->next != head){
				    curr = curr->next;
			    }
			    head = head->next;
			    curr->next = head;
			    delete temp;
			}
		}
		
		void deleteEnd(){
			if(head == NULL){
				cout <<"underflow."<< endl;
				return;
			} 
			else if(head->next == head){
				delete head;
				head = NULL;
				return;
			}
			else{
				Node* temp=head;
				Node* prev = NULL;
				while(temp->next!= head){
					prev = temp;
					temp= temp->next;
				}
				prev->next = head;
				delete temp;
			}
		}
		bool SearchKey(int key){
			if(isEmpty()){
				return false;
			}
			else{
				Node* temp = head;
				while(temp->data != key && temp->next != head){
					temp = temp->next;
				}
				if(temp->next == head){
					return false;
				}
				else{
					return true;
				}
			}	
		}
		void display(){
			if(isEmpty()){
				cout << "List empty." << endl;
				return;
			}
			Node* temp = head;
			while(temp->next != head){
				cout << temp->data<<" ";
				temp = temp->next;
			}
			cout << temp->data<< endl;
		}
};

int main(){
	CircularList l1;
	l1.insertFront(1);
	l1.insertFront(2);
	l1.insertBack(3);
	l1.insertBack(4);
	l1.display();
	cout << endl;
	l1.insertAfterVal(5,3);
	l1.display();
	cout << endl;
	l1.insertAtPosition(6,3);
	l1.display();
	cout<< endl;
    if(	l1.SearchKey(7)){
    	cout <<"found!!"<< endl;
	}
	else{
		cout <<"Not found!!"<<endl;
	}
	
	return 0;
}



