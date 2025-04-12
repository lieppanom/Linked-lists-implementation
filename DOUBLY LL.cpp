//Implementation of Doubly Linked List
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

class List {
	private:
		Node *h = nullptr;

	public:
		void addBegin(int v) {
			Node *n = new Node{v, h, nullptr};
			if (h) {
				h->prev = n;
			}
			h = n;
		}

		void addEnd(int v) {
			Node *n = new Node{v, nullptr, nullptr};
			if (!h) {
				h = n;
				return;
			}
			Node *c = h;
			while (c->next) {
				c = c->next;
			}
			c->next = n;
			n->prev = c;
		}

		void addPos(int v, int p) {
			Node *n = new Node{v, nullptr, nullptr};
			if (p == 1) {
				n->next = h;
				if (h) {
					h->prev = n;
				}
				h = n;
				return;
			}
			Node *c = h;
			for (int i = 1; i < p - 1 && c; ++i) {
				c = c->next;
			}
			if (c) {
				n->next = c->next;
				n->prev = c;
				if (c->next) {
					c->next->prev = n;
				}
				c->next = n;
			}
		}

		void delBegin() {
			if (h) {
				Node *t = h;
				h = h->next;
				if (h) {
					h->prev = nullptr;
				}
				delete t;
			}
		}

		void delEnd() {
			if (!h)
				return;
			if (!h->next) {
				delete h;
				h = nullptr;
				return;
			}
			Node *c = h;
			while (c->next->next) {
				c = c->next;
			}
			delete c->next;
			c->next = nullptr;
		}

		void delPos(int p) {
			if (!h || p < 1)
				return;
			if (p == 1) {
				Node *t = h;
				h = h->next;
				if (h) {
					h->prev = nullptr;
				}
				delete t;
				return;
			}
			Node *c = h;
			for (int i = 1; i < p - 1 && c; ++i) {
				c = c->next;
			}
			if (c && c->next) {
				Node *t = c->next;
				c->next = t->next;
				if (t->next) {
					t->next->prev = c;
				}
				delete t;
			}
		}

		void print() {
			Node *c = h;
			while (c) {
				cout << c->data;
				if (c->next) {
					cout << " <-> ";
				} else {
					cout << " (null)";
				}
				c = c->next;
			}
			cout << endl;
		}
};

int main() {
	List l;
	int ch, v, p;
	cout << "1 AddBeg:\n, 2 AddEnd:\n, 3 AddPos:\n, 4 DelBeg:\n, 5 DelEnd:\n, 6 DelPos:\n, 7 Print:\n, 8 Exit:\n         ";
	cin >> ch;
	while (ch != 8) {
		if (ch == 1) {
			cout << "Val:\n ";
			cin >> v;
			l.addBegin(v);
		} else if (ch == 2) {
			cout << "Val:\n ";
			cin >> v;
			l.addEnd(v);
		} else if (ch == 3) {
			cout << "Val:\n ";
			cin >> v;
			cout << "Pos:\n ";
			cin >> p;
			l.addPos(v, p);
		} else if (ch == 4)
			l.delBegin();
		else if (ch == 5)
			l.delEnd();
		else if (ch == 6) {
			cout << "Pos:\n ";
			cin >> p;
			l.delPos(p);
		} else if (ch == 7)
			l.print();
		cout << "1 AddBeg:\n, 2 AddEnd:\n, 3 AddPos:\n, 4 DelBeg:\n, 5 DelEnd:\n, 6 DelPos:\n, 7 Print:\n, 8 Exit:\n ";
		cin >> ch;
	}
	return 0;
}
