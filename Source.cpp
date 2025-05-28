#include <iostream>
using namespace std;

//Ryan Hunt
//04-28-25
//COP2222

/*	This is a little mote of an advanced program meant for user use, 
	and for them to enter their own version of items. They can 
	create the linked list, and append, delete, and preview their 
	own inputed values.
*/

class Node {
public:
	int data;
	Node* next;

	//Linked list node object
	Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
	Node* head;
	int count;

	//Linked List.
	LinkedList() : head(nullptr), count(0) {}

	//Loop to continue moving the nullptr in the linked list, continuing the list.
	~LinkedList() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	//Append method
	void append(int value) {
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
		}
		else {
			Node* temp = head;
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = newNode;
		}
		count++; //Used to count incrememts of how many values and nodes are in the linked list
	}

	//Delete method
	void deleteNode(int value) {
		if (!head) {
			cout << "Warning: The Linked List is empty, cannot delete!";
			return;
		}

		if (head->data == value) {
			Node* temp = head;
			head = head->next;
			delete temp;
			cout << "Deleted the node with value " << value << "." << endl;
			count--;
			return;
		}

		//Previewing context
		Node* prev = head;
		Node* curr = head->next;

		while (curr) {
			if (curr->data == value) {
				prev->next = curr->next;
				delete curr;
				count--;
				cout << "Deleted node with value " << value << "." << endl;
				return;
			}
			prev = curr;
			curr = curr->next;
		}

		cout << "Value " << value << " was not found in the list." << endl;
	}

	//Print list method
	void printList() const {
		Node* temp = head;
		if (!temp) {
			cout << "The linked list is empty.\n" << endl;
			return;
		}

		cout << "Current Linked List: \n";
		while (temp) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}
};

int main() {
	LinkedList list;
	int choice, userValue;

	cout << "Welcome to the Linked List Manager.\n" << endl;

	//Menu for the program
	do {
		cout << "There are " << list.count << " nodes in the list";

		cout << "\nMenu:\n";
		cout << "(1) Append a value\n";
		cout << "(2) Delete a value\n";
		cout << "(3) Display the linked list\n";
		cout << "(4) Exit\n";
		cout << "What would you like to do: ";
		cin >> choice; //User choice input -
		cout << endl;

		//Switch value for the user's choice, and access the necessary methods through the choices.
		switch (choice) {
		case 1:
			cout << "Enter an integer to append: ";
			cin >> userValue;
			list.append(userValue);
			cout << "Added " << userValue << " to the linked list.\n";
			break; 

		case 2:
			cout << "Enter a value to delete: ";
			cin >> userValue;
			list.deleteNode(userValue);
			break;

		case 3:
			list.printList();
			break;

		case 4:
			cout << "Exiting, thank you and goodbye" << endl;
			break;

		//If choice is not from the list, get reinput
		default:
			cout << "Invalid choice! Please select an option from the menu." << endl;
		}
	} while (choice != 4);

	return 0;
 }