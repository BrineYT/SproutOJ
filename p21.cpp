#include <iostream>
#include <vector>

using namespace std;

struct node {
  node *last = nullptr;
  node *next = nullptr;
  int id;

  void removeSelf() {
    last->next = this->next;
    next->last = this->last;
  }

  void swap() {
    if (this->last) {
      node *a = last->last;
      node *d = next;
      last->last->next = this;
      next->last = last;
      last->last = this;
    }
  }

  void print() {
    cout << this->id << ' ';
    if (this->next) {
      next->print();
    } else {
      cout << '\n';
    }
  }
};

void evaluate(const int, const int);

int main() {
  int racer, action;
  cin >> racer >> action;

  evaluate(racer, action);
}

void evaluate(const int racer, const int action) {
  vector<node> player;
  player.push_back({nullptr, nullptr, 0});
  player.push_back({nullptr, nullptr, 1});

  int start = 1;

  for (int i = 1; i < racer; ++i) {
    player.push_back({nullptr, nullptr, i + 1});
  }
  for (int i = racer - 1; i > 0; --i) {
    player[i].next = &player[i + 1];
  }
  for (int i = 2; i <= racer; ++i) {
    player[i].last = &player[i - 1];
  }

  for (auto &n: player) {
    cout << n.last << ' ' << &n << ' ' << n.next << ' ' << n.id << '\n';
  }

  int command, target;
  for (int i = 0; i < action; ++i) {
    cin >> command >> target;

    if (command) {
      if (player[target].last && player[target].last->last == nullptr) {
        start = target;
      }
      player[target].swap();
    } else {
      if (target == start) {
        start = player[start].next->id;
      }
      player[target].removeSelf();
    }
  }

  player[start].print();
}