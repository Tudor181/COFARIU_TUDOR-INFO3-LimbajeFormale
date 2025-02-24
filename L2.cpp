#include <iostream>
#include <string>
#include <vector>

using namespace std;

void transit(const int value, const vector<pair<int, vector<int>>> transitions, int &startQ)
{
    // startQ = transitions.
    for (auto transition : transitions)
    {
        if (transition.first == startQ)
        {
            startQ = transition.second[value];
            return;
        }
    }
    // return true;
}

int main()
{
    const int input[] = {0, 1};   // sigma
    const int output = 3;         // F
    const int q[] = {0, 1, 2, 3}; // starile
    int startQ = q[0];            // q0 start value

    vector<pair<int, vector<int>>> transitions = {{q[0], {1, 2}}, {q[1], {0, 3}}, {q[2], {1, 3}}, {q[3], {3, 3}}};

    const int test[] = {1, 0, 0};
    for (int v : test)
    {
        cout << 'v' << v << ' ';
        cout << 'q' << startQ << ' ';
        transit(v, transitions, startQ);
    }
    cout << 'q' << startQ;

    // cout << transitions[2];
}