#include <iostream>

using namespace std;

struct node {
    node *child[2] = {nullptr};
    int id;

    node(int input): id(input) {};

    void push(node *next) {
        bool direction = next->id > this->id;

        if (child[direction]) 
            child[direction]->push(next);
        else 
            child[direction] = next;
    }

    void print() {
        for (node *n: child) if (n) n->print();
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
