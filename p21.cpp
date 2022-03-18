#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    node *last = nullptr, *next = nullptr;
    int id;

    node(int id): id(id) {}

    void removeSelf() {
        if (last) last->next = this->next;
        if (next) next->last = this->last;
    }

    void customSwap() {
        swap(this->id, last->id);
    }

    void print() {
        if (this->next) {
            cout << this->id << ' ';
            next->print();
        } else {
            cout << this->id << '\n';
        }
    }
};

void evaluate(const int, const int);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int racer, action;
    cin >> racer >> action;

    evaluate(racer, action);
}


void evaluate(const int racer, const int action) {
    vector<node*> player;

    for (int i = 0; i <= racer; ++i) {
        node* temp = new node(i);
        player.push_back(temp);
    }
    for (int i = 2; i < racer; ++i) {
        player[i]->last = player[i - 1];
        player[i]->next = player[i + 1];
    }
    player[1]->next = player[2];
    player[racer]->last = player[racer - 1];

    int start = 1, command, target;
    for (int i = 0; i < action; ++i) {
        cin >> command >> target;

        if (command) {
            if (target == start) continue;
            if (!player[target]->last->last) start = target;
            player[target]->customSwap();

            int &next = player[target]->id;
            swap(player[target], player[next]);
        } else {
            if (target == start) {
                start = player[start]->next->id;
            }
            player[target]->removeSelf();
        }
    }

    player[start]->print();
}
