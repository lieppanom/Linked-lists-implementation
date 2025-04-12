//Implementation of Circular Doubly Linked List
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
	Node(int v) : data(v), next(nullptr), prev(nullptr) {}
};

class List {
	private:
		Node *head = nullptr;

	public:
		void addBegin(int v) {
			Node *newNode = new Node(v);
			if (!head) {
				head = newNode;
				head->next = head;
				head->prev = head;
			} else {
				newNode->next = head;
				newNode->prev = head->prev;
				head->prev->next = newNode;
				head->prev = newNode;
				head = newNode;
			}
		}

		void addEnd(int v) {
			Node *newNode = new Node(v);
			if (!head) {
				head = newNode;
				head->next = head;
				head->prev = head;
			} else {
				newNode->next = head;
				newNode->prev = head->prev;
				head->prev->next = newNode;
				head->prev = newNode;
			}
		}

		void addPos(int v, int p) {
			if (p <= 0)
				return;

			Node *newNode = new Node(v);
			if (!head) {
				if (p == 1) {
					head = newNode;
					head->next = head;
					head->prev = head;
				}
				return;
			}

			if (p == 1) {
				addBegin(v);
				return;
			}

			Node *current = head;
			for (int i = 1; i < p - 1; ++i) {
				current = current->next;
				if (current == head)
					return;
			}

			newNode->next = current->next;
			newNode->prev = current;
			current->next->prev = newNode;
			current->next = newNode;
		}


		void delBegin() {
			if (!head)
				return;

			if (head->next == head) {
				delete head;
				head = nullptr;
				return;
			}

			Node *temp = head;
			head = head->next;
			head->prev = temp->prev;
			temp->prev->next = head;

			delete temp;
		}

		void delEnd() {
			if (!head)
				return;

			if (head->next == head) {
				delete head;
				head = nullptr;
				return;
			}

			Node *temp = head->prev;
			temp->prev->next = head;
			head->prev = temp->prev;
			delete temp;
		}

		void delPos(int p) {
			if (!head || p <= 0)
				return;

			if (head->next == head) {
				if (p == 1) {
					delete head;
					head = nullptr;
				}
				return;
			}

			if (p == 1) {
				delBegin();
				return;
			}

			Node *current = head;
			for (int i = 1; i < p; ++i) {
				current = current->next;
				if (current == head)
					return;
			}

			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}

		void print() {
			if (!head) {
				cout << "List is empty." << endl;
				return;
			}

			Node *current = head;
			do {
				cout << current->data;
				if (current->next != head) {
					cout << " <-> ";
				}
				current = current->next;
			} while (current != head);
			cout << endl;
		}
};

int main() {
	List l;
	int ch, v, p;
	cout
	        << "1 AddBeg:n, 2 AddEnd:n, 3 AddPos:n, 4 DelBeg:n, 5 DelEnd:n, 6 "
	        "DelPos:n, 7 Print:n, 8 Exit:n         ";
	cin >> ch;
	while (ch != 8) {
		if (ch == 1) {
			cout << "Val:n ";
			cin >> v;
			l.addBegin(v);
		} else if (ch == 2) {
			cout << "Val:n ";
			cin >> v;
			l.addEnd(v);
		} else if (ch == 3) {
			cout << "Val:n ";
			cin >> v;
			cout << "Pos:n ";
			cin >> p;
			l.addPos(v, p);
		} else if (ch == 4)
			l.delBegin();
		else if (ch == 5)
			l.delEnd();
		else if (ch == 6) {
			cout << "Pos:n ";
			cin >> p;
			l.delPos(p);
		} else if (ch == 7)
			l.print();
		cout
		        << "1 AddBeg:n, 2 AddEnd:n, 3 AddPos:n, 4 DelBeg:n, 5 DelEnd:n, 6 "
		        "DelPos:n, 7 Print:n, 8 Exit:n ";
		cin >> ch;
	}
	return 0;
}
