# include <iostream>
# include <map>
# include <vector>
# include <algorithm>

using namespace std;

class Node{
	public:
		int data;
		Node* next;

		// constructor
		Node(int data){
			this -> data = data;
			this -> next = NULL;
		}
};

vector<int> fib = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181};

Node* NotFibonacci(Node* & head){  // to remove the fib form list
	Node* temp = head;
	Node* prev = head;
	while(temp != NULL){
		int x = temp -> data;
		if(find(fib.begin(), fib.end(), x) != fib.end()){
			if(x == head -> data){// if head is fib
				Node* q = head;
				head = head -> next;
				prev = head;
				temp = head;
				delete q;
				continue;
			}
			else{
				Node* curr = temp;
				prev -> next = curr -> next;
				curr -> next = NULL;
				temp = prev;
				delete curr;
			}
		}
		prev = temp;
		temp = temp -> next;
	}
	return head;
}


void insertAtHead(Node* & head, int d){
	// create Node
	Node* temp = new Node(d);
	temp -> next = head;
	head = temp;
}

void insertAtTail(Node* & tail, int d){
	// create new temp for tail
	Node* temp = new Node(d);
	tail -> next = temp;
	tail = temp;
}

int lengthlinklist(Node* head, Node* tail){
	int cnt = 1;
	Node* temp = head;
	while(temp -> next != NULL){
		cnt++;
		temp = temp -> next;
	}
	return cnt;
}

void insertAtPosition(Node* & head, Node* & tail, int position, int d){

	// if want to insert at head
	if(position == 1){
		insertAtHead(head, d);
		return;
	}

	// temp points to head at first
	Node* temp = head;
	int cnt = 1;
	while(cnt < position - 1){
		temp = temp -> next;
		cnt++;
	}// now temp points to pos - 1 

	// create a node to be inserted at pos
	Node* Nodetoinsert = new Node(d);
	// if node to be inserted at tail
	if (temp -> next == NULL){
		insertAtTail(tail, d);
		return;
	}

	// if node tobe insert betwn head and tail
	else{
		Nodetoinsert -> next = temp -> next;
		temp -> next = Nodetoinsert;
	}
}

// delete node by data
void deleteNodebyData(Node* & head, Node* & tail, int d){
	// if wanna delete head
	if (d == head -> data){
		Node* q = head;
		head = head -> next; 
		delete q;
	}
	else{
		Node* curr = head -> next;
		Node* prev = NULL;
		while(curr -> data != d && curr -> next != NULL){
			prev = curr;
			curr = curr -> next;
		}
		if (curr -> next == NULL){
			tail = prev;
		} // update tail
		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
	}
}

// delete node by position
void deletebyposition(Node* & head, Node* & tail, int position){
	 // deleting first or start Node
	if (position == 1){
		Node* temp = head;
		head = head -> next;
		temp -> next = NULL;
		// free space
		delete temp;
	}
	else{
		// deleting middle or end Node
		int cnt = 1;
		Node* prev = head;
		Node* curr = head;
		while(cnt < position - 1){
			prev = prev -> next;
			cnt++;
		}
		curr = prev -> next;
		if (curr -> next == NULL){// if last node update tail
			tail = prev;
		}
		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;
		
	}
}
	
void reverse(Node* & head, Node* & tail){

	// if only one node or zero node is present
	if (head == NULL || head -> next == NULL){
		head = head;
	}
	else{
		// more than one node present
		Node* curr = head;
		Node* prev = NULL;
		tail = curr; // update tail

		Node* forward = NULL;
		while(curr != NULL){
			forward = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = forward;
		}
		head = prev;  // update head
	}
}


Node* kReverse(Node* & head, int k){
   if (head == NULL){
        return head;
    }

    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;
    while(curr != NULL && count < k){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    
    if (forward != NULL){
        head -> next = kReverse(forward, k); 
    }
    return prev;
}
    

void traverse(Node* & head){
	// assign temp as head
	Node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
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


int main()
{

	Node* node1 = new Node(1); // create a node1 obj in heap where Node* is the pointer

	Node* head = node1;
	Node* tail = node1;
	insertAtHead(head, 14); 
	insertAtTail(tail, 2);
	insertAtTail(tail, 9);
	insertAtTail(tail, 6);

	//insertAtPosition(head, tail, 3, 40);
	//insertAtTail(tail, 8);
	
	cout << "before: " ;
	traverse(head);

	cout << head-> data<< endl;
	cout << tail -> data << endl;
	
	//deletebyposition(head, tail, 1);
	//deleteNodebyData(head, tail, 50);
	//reverse(head, tail);
	//cout << "after: " ;
	//traverse(head);

	// reverse in k group size
	//cout << "after k reverse: " ;
	//Node* prev = kReverse(head, 3);
	//traverse(prev);

	cout << "after removing fib no: " ;
	NotFibonacci(head);
	traverse(head);
	//cout << detectLoop(head) <<endl;
	return 0;
}
