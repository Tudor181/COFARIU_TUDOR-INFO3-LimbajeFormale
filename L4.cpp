
// ex1
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int encodeChar(int c)
// {
//     if (c == 'A')
//         return 0;
//     if (c == 'B')
//         return 1;
// }

// void transit(const char value, const vector<pair<int, vector<int>>> transitions, int &startQ, const vector<string> outputs, string &exit)
// {

//     const int translatedValue = encodeChar(value);

//     for (auto transition : transitions)
//     {
//         if (transition.first == startQ)
//         {
//             startQ = transition.second[translatedValue];
//             exit.append(outputs[startQ]);
//             return;
//         }
//     }
//     // return true;
// }

// int main()
// {
//     // const int input[] = {0, 1};   // sigma
//     const int output = {};  // F
//     const int q[] = {0, 1}; // starile
//     int startQ = q[0];      // q0 start value

//     vector<pair<int, vector<int>>> transitions = {{q[0], {0, 1}}, {q[1], {0, 1}}};
//     vector<string> outputs = {"o1", "o2"};
//     string exit = outputs[startQ];
//     const char test[] = {'A', 'B', 'A'};

//     for (char v : test)
//     {
//         cout << 'v' << v << ' ';
//         cout << 'q' << startQ << ' ';
//         transit(v, transitions, startQ, outputs, exit);
//     }
//     cout << 'q' << startQ << "\nexit value:";
//     cout << exit << endl;
// }

// ex2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int encodeChar(int c)
{
    if (c == 'X')
        return 0;
    if (c == 'Y')
        return 1;
}

void transit(const char value, const vector<pair<int, vector<int>>> transitions, int &startQ, const vector<string> outputs, string &exit)
{

    const int translatedValue = encodeChar(value);

    for (auto transition : transitions)
    {
        if (transition.first == startQ)
        {
            exit.append(outputs[startQ]);
            startQ = transition.second[translatedValue];
            return;
        }
    }
    // return true;
}

int main()
{
    // const int input[] = {0, 1};   // sigma
    const int output = {};  // F
    const int q[] = {0, 1}; // starile
    int startQ = q[0];      // q0 start value

    vector<pair<int, vector<int>>> transitions = {{q[0], {0, 1}}, {q[1], {0, 1}}};
    vector<string> outputs = {"o1", "o2"};
    string exit;
    const char test[] = {'X', 'Y', 'X'};

    for (char v : test)
    {
        cout << 'v' << v << ' ';
        cout << 'q' << startQ << ' ';
        transit(v, transitions, startQ, outputs, exit);
    }
    cout << 'q' << startQ << "\nexit value:";
    cout << exit << endl;
}
