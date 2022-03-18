#include <iostream>
#include <vector>

using namespace std;

struct node {
    node* next = nullptr;
    int id;

    node(int name): id(name) {}

    void merge(node* nextNode) {
        this->next = nextNode;
    }

    void print() {
        cout << this->id;
        if (next) {
            cout << ' ';
            next->print();
        } else {
            cout << '\n';
        }
    }
};

void evaluate(int, int);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("out.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    int shopCount, commandCount;
    cin >> shopCount >> commandCount;

    evaluate(shopCount, commandCount);
}


void evaluate(int shopCount, int commandCount) {
    vector<node*> firstCustomer(shopCount + 1, nullptr);
    vector<node*> lastCustomer(shopCount + 1, nullptr);

    string command;
    int shopId, personId, toShop;
    for (int i = 0; i < commandCount; ++i) {
        cin >> command >> shopId;

        if (command[0] == 'A') {
            cin >> personId;
            node* next = new node(personId);
            if (lastCustomer[shopId]) {
                // cerr << "merging " << next->id << " to " << lastCustomer[shopId]->id << '\n';
                lastCustomer[shopId]->merge(next);
                lastCustomer[shopId] = next;
            } else {
                // cerr << "merging " << next->id << " to shop " << shopId << '\n';
                firstCustomer[shopId] = lastCustomer[shopId] = next;
            }
        } else if (command[0] == 'L') {
            if (firstCustomer[shopId]) {
                // cerr << firstCustomer[shopId]->id << " leaves\n";
                node* nextCustomer = firstCustomer[shopId]->next;
                if (!nextCustomer) lastCustomer[shopId] = nullptr;
                firstCustomer[shopId] = nextCustomer;
            } else {
                cout << "queue " << shopId << " is empty!\n";
            }
        } else {
            cin >> toShop;
            if (lastCustomer[toShop]) {
                lastCustomer[toShop]->merge(firstCustomer[shopId]);
                if (lastCustomer[shopId]) lastCustomer[toShop] = lastCustomer[shopId];
            } else {
                firstCustomer[toShop] = firstCustomer[shopId];
                lastCustomer[toShop] = lastCustomer[shopId];
            }
            firstCustomer[shopId] = lastCustomer[shopId] = nullptr;
            
        }
    }
    for (int i = 1; i <= shopCount; ++i) {
        cout << "queue " << i << ": ";
        if (firstCustomer[i]) {
            firstCustomer[i]->print();
        } else {
            cout << "empty\n";
        }
    }
}