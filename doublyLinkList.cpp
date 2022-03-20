# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;

		// constructor
		Node(int d){
			this -> data = d;
			this -> prev = NULL;
			this -> next = NULL;
		}
};


int length(Node* head){
	int cnt = 0;
	Node* temp = head;
	while(temp != NULL){
		cnt++;
		temp = temp -> next;
	}
	return cnt;
}

void insertAtHead(Node* & head, Node* & tail, int d){
	// no head is present
	if (head == NULL){
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else{
		// create node temp
		Node* temp = new Node(d);
		temp -> next = head;
		head -> prev = temp;
		head = temp;
	}
}

void insertAtTail(Node* & head, Node* & tail, int d){
	if (tail == NULL){
		Node* temp = new Node(d);
		tail = temp;// update tail
		head = temp;// update head
	}
	else{
		Node* temp = new Node(d);
		tail -> next = temp;
		temp -> prev = tail;
		tail = temp;
	}
}

void insertAtPosition(Node* & head, Node* & tail, int d, int position){
	int len = length(head);
	if (position > len + 1){
		cout << "Position not invalid" << endl;
	}
	if (position == 1){
		insertAtHead(head, tail, d);
		return;
	}
	// if position is in middle or end
	else{ 
		Node* Nodetoinsert = new Node(d);
		Node* temp = head;


		int cnt = 1;
		while(cnt < position - 1){
			temp = temp -> next;
			cnt++;
		}

		// if pos is at tail
		if (temp -> next == NULL){
			insertAtTail(head, tail, d);
			return;
		}
		// if pos is somewhere at middle
		Nodetoinsert -> next = temp -> next;
		temp -> next -> prev = Nodetoinsert;
		temp -> next = Nodetoinsert;
		Nodetoinsert -> prev = temp;
	}
}

void deleteNode(int position, Node* & head, Node* & tail){
	// deleting first or start Node
	if (position == 1){
		Node* temp = head;
		temp -> next -> prev = NULL;
		head = temp -> next;
		temp -> next = NULL;
		delete temp;
	}
	else{
		Node* curr = head;
		Node* prev = NULL;

		int cnt = 1;
		while(cnt < position){
			prev = curr;
			curr = curr -> next;
			cnt++;
		}

		// update tail if last position
		if(curr -> next == NULL){
			tail = prev;
		}

		curr -> prev = NULL;
		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
	}
}


void traverse(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main()
{

	Node* head = NULL;
	Node* tail = NULL;
	insertAtTail(head, tail, 50);
	insertAtHead(head, tail, 10);
	
	insertAtPosition(head, tail, 90, 1);
	// insertAtPosition(head, tail, 100, 5);
	deleteNode(3, head, tail);

	cout << "traverse: " ;
	traverse(head);
	cout << "Length is: " << length(head) << endl;
	cout << "head is: " << head -> data << endl;
	cout << "tail is: " << tail -> data << endl;
	return 0;
}
