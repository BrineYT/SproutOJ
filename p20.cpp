#include <iostream>
#include <vector>

#define debug(x) cerr << #x << " " << x << '\n'

using namespace std;

void evaluate();

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int testData;
    cin >> testData;

    for (int i = 1; i <= testData; ++i) {
        cout << "Line #" << i << '\n';

        evaluate();
    }
}


void evaluate() {
    int groupCount, member, id;
    cin >> groupCount;
    
    short group[1000000] = {0};

    for (int i = 1; i <= groupCount; ++i) {
        cin >> member;
        for (int j = 0; j < member; ++j) {
            cin >> id;
            group[id] = i;
        }
    } 

    int statement, nextPerson, index = 0;
    vector< vector<int> > queue;
    cin >> statement;

    string command;
    while (statement--) {
        cin >> command;
        if (command[0] == 'E') {
            cin >> nextPerson;

            
            bool flag = true;
            int currentId = group[nextPerson];
            if (currentId) {
                for (int i = index; i < queue.size(); ++i) {
                    if (queue[i][0] == currentId && queue[i][1] != queue[i].size()) {
                        queue[i].emplace_back(nextPerson);
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {     
                if (!queue.empty() && currentId == 0 && queue[queue.size() - 1][0] == 0) {
                    queue[queue.size() - 1].emplace_back(nextPerson);
                } else {
                    queue.emplace_back(vector<int>{currentId, 2, nextPerson});
                }
            }

            // for (auto n: queue) {
            //     for (auto x: n) {
            //         cout << x << ' ';
            //     }
            //     cout << '\n';
            // }
        } else {
            // queue[index] = {groupId, nextPerson, p1, p2...}
            if (queue[index][1] == queue[index].size()) index++;
            cout << queue[index][queue[index][1]++] << '\n';
        }
    }
}