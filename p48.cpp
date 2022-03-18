#include <iostream>

using namespace std;

struct node {
    node *lChild = nullptr, *rChild = nullptr;
    int id;

    node(int input): id(input) {};

    void push(node *next) {
        if (next->id < this->id) {
            if (this->lChild) {
                lChild->push(next);
            } else {
                lChild = next;
            }
        } else {
            if (this->rChild) {
                rChild->push(next);
            } else {
                rChild = next;
            }
        }
    }

    void print() {
        if (lChild) lChild->print();
        if (rChild) rChild->print();
        cout << id << '\n';
    }
};

int main() {
    int size, id;
    cin >> size;

    cin >> id;
    node *tree = new node(id);

    for (int i = 1; i < size; i++) {
        cin >> id;
        node *next = new node(id);
        tree->push(next);
    }

    tree->print();
}