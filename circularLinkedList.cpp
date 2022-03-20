# include <iostream>
# include <map>
# include <vector>
# include <algorithm>
using namespace std;

class Node{
	public:
		int data;
		Node* next;

		Node(int data){
			this -> data = data;
			this -> next = NULL;
		}

};


void insertNode(Node* & tail, int element, int d){

	// empty list
	if (tail == NULL){
		Node* newNode = new Node(d);
		tail = newNode;
		newNode -> next = newNode;
	}
	else{
		// non empty
		Node* curr = tail;
		while(curr -> data != element){
			curr = curr -> next;
		}
		Node* temp = new Node(d);
		temp -> next = curr -> next;
		curr -> next = temp;
		//tail = temp;
	}
}

void DeletebyData(Node* & tail, int element){
	// if empty
	if (tail == NULL){
		cout << "No Node Present for deletion" << endl;
	}
	else if(tail -> next == tail){
		// only one Node
		Node* temp = tail;
		temp -> next = NULL;
		tail = NULL;
		delete temp;
		cout << "Node Deleted" << endl;
	}

	else{
		// more than one node
		Node* prev = tail;
		Node* curr = prev -> next;

		while(curr -> data != element){
			prev = curr;
			curr = curr -> next;
		}
		prev -> next = curr -> next;
		if (curr == tail){
			tail = prev;
		}
		curr -> next = NULL;
		delete curr;
	}
}


bool detectLoop(Node* head){
	map<Node*, bool> visited;
	Node* temp = head;

	while(temp != NULL){
		//if loop found
		if (visited[temp] == true){
			return true;
		}
		visited[temp]= true;
		temp = temp -> next;
	}
	return false;
}

void traverse(Node* tail){

	if (tail == NULL){
		cout << "Empty" << endl;
	}
	else{
		Node* temp = tail;
		do{
			cout << temp -> data << " " ;
			temp = temp -> next;
		}while(temp != tail);
	}

}

int main()
{

	Node* tail = NULL;
	insertNode(tail, 10, 20);
	insertNode(tail, 20, 30);
	insertNode(tail, 20, 15);

	DeletebyData(tail, 30);
	traverse(tail);
	cout <<"\n" << "tail is: " << tail -> data << endl;
	cout << detectLoop(tail) << endl;
	return 0;
}

