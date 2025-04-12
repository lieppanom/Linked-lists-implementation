//Implementation of Circular Singly Linked List
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class List {
	private:
		Node *h = nullptr;

	public:
		void addBegin(int v) {
			Node *n = new Node{v, h};
			if (!h) {
				h = n;
				h->next = h;
				return;
			}
			Node *tail = h;
			while (tail->next != h) {
				tail = tail->next;
			}
			n->next = h;
			tail->next = n;
			h = n;
		}

		void addEnd(int v) {
			Node *n = new Node{v, h};
			if (!h) {
				h = n;
				h->next = h;
				return;
			}
			Node *c = h;
			while (c->next != h) { //Keep circularity by checking c->next != h
				c = c->next;
			}
			c->next = n;
			n->next = h;
		}

		void addPos(int v, int p) {
			Node *n = new Node{v, nullptr};

			if (!h) {
				if (p == 1) {
					h = n;
					h->next = h;
					return;
				} else {
					cout << "List is empty" << endl;
					return;
				}
			}

			if (p == 1) {
				addBegin(v);
				return;
			}

			Node *c = h;
			for (int i = 1; i < p - 1 && c->next != h; ++i) {
				c = c->next;
				if (c->next == h)
					break;
			}

			if (c->next != h) {
				n->next = c->next;
				c->next = n;
			} else {

				n->next = h;
				c->next = n;
			}

		}

		void delBegin() {
			if (!h)
				return;

			if (h->next == h) {
				delete h;
				h = nullptr;
				return;
			}

			Node *tail = h;
			while (tail->next != h) {
				tail = tail->next;
			}

			Node *t = h;
			h = h->next;
			tail->next = h;
			delete t;
		}

		void delEnd() {
			if (!h)
				return;

			if (h->next == h) {
				delete h;
				h = nullptr;
				return;
			}
			Node *c = h, *prev = nullptr;
			while (c->next != h) {
				prev = c;
				c = c->next;
			}
			prev->next = h;
			delete c;
		}

		void delPos(int p) {
			if (!h)
				return;

			if (h->next == h) {
				if (p == 1) {
					delete h;
					h = nullptr;
					return;
				} else {
					cout << "Invalid" << endl;
					return;
				}
			}
			if (p == 1) {
				delBegin();
				return;
			}

			Node *c = h, *prev = nullptr;
			for (int i = 1; i < p && c->next != h; ++i) {
				prev = c;
				c = c->next;
			}
			if (c->next == h) {
				return;
			}


			prev->next = c->next;
			delete c;

		}

		void print() {
			if (!h)
				return;

			Node *c = h;
			Node *start = h;

			do {
				cout << c->data;
				if (c->next != start) {
					cout << " -> ";
				}
				c = c->next;
			} while (c != start);

			cout << " (circ)" << endl;
		}
};

int main() {
	List l;
	int ch, v, p;
	cout << "1 AddBeg:n, 2 AddEnd:n, 3 AddPos:n, 4 DelBeg:n, 5 DelEnd:n, 6 DelPos:n, 7 Print:n, 8 Exit:n";
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
		cout << "1 AddBeg:n, 2 AddEnd:n, 3 AddPos:n, 4 DelBeg:n, 5 DelEnd:n, 6 DelPos:n, 7 Print:n, 8 Exit:n";
		cin >> ch;
	}
	return 0;
}
