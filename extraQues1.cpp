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
		
		CircularList split(){
			CircularList secondHalf;
			if(head==NULL || head->next==head){
				return secondHalf;
			}
			Node* slow = head;
			Node* fast = head;
			
			while(fast->next != head && fast->next->next != head){
				slow = slow->next;
				fast = fast->next->next;
			}
			Node* head1 = head;
			Node* head2 = slow->next;
			
			fast = slow->next;
			while(fast->next != head){
				fast = fast->next;
			}
			fast->next = head2;
			slow->next = head1;

			secondHalf.head = head2;
			return secondHalf;
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
	CircularList cll;
	cll.insertBack(1);
	cll.insertBack(2);
	cll.insertBack(3);
	cll.insertBack(4);
	cll.insertBack(5);
	cll.insertBack(6);
	cll.insertBack(7);
	cout<<"Initial list:" << endl;
	
	cll.display();
	CircularList cll2;
	cll2 = cll.split();
	
	cout<<"The splited lists are: "<< endl;
	cll.display();
	
	cll2.display();
	
	return 0;
}
