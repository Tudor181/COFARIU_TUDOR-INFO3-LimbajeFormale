
// ex1
//  #include <iostream>
//  #include <string>
//  #include <vector>

// using namespace std;

// void transit(const int value, const vector<pair<int, vector<int>>> transitions, int &startQ)
// {
//     // startQ = transitions.
//     for (auto transition : transitions)
//     {
//         if (transition.first == startQ)
//         {
//             startQ = transition.second[value];
//             return;
//         }
//     }
//     // return true;
// }

// int main()
// {
//     const int input[] = {0, 1};   // sigma
//     const int output = 3;         // F
//     const int q[] = {0, 1, 2, 3}; // starile
//     int startQ = q[0];            // q0 start value

//     //cat

//     vector<pair<int, vector<int>>> transitions = {{q[0], {1, 2}}, {q[1], {0, 3}}, {q[2], {1, 3}}, {q[3], {3, 3}}};

//     const int test[] = {1, 0, 0};
//     for (int v : test)
//     {
//         cout << 'v' << v << ' ';
//         cout << 'q' << startQ << ' ';
//         transit(v, transitions, startQ);
//     }
//     cout << 'q' << startQ;

//     // cout << transitions[2];
// }

// ex2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int encodeChar(char c)
{
    if (c == 'c')
        return 0;
    if (c == 'a')
        return 1;
    if (c == 't')
        return 2;
    return 3; // Any other character
}

void transit(const char value, const vector<pair<int, vector<int>>> &transitions, int &startQ)
{
    const char translatedValue = encodeChar(value);
    // startQ = transitions.
    for (auto transition : transitions)
    {
        if (transition.first == startQ)
        {
            startQ = transition.second[translatedValue];
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

    vector<pair<int, vector<int>>> transitions = {{q[0], {1, 0, 0, 0}}, {q[1], {1, 2, 0, 0}}, {q[2], {1, 0, 3, 0}}, {q[3], {3, 3, 3, 3}}};

    const string test = "xcat";

    vector<string> testCases = {

        "cat",
        "xcat",
        "catx",
        "xxcatxx",
        "cata",
        "dogcat",
        "catch",
        "xcxaxct",

        "c a t",
        "ca",
        "cta",
        "tac",
        "atc",
        "xcty",
        "",
        "randomtext",

        "caaaaaaaaaaaaaaaaaat",
        "cccccaaaaattttt",
        "CCCCat",
        "cAt",
        "C A T"};

    for (string Case : testCases)
    {

        for (char c : Case)
        {
            cout << "v:" << c << ' ';
            cout << "q:" << startQ << '\n';
            transit(c, transitions, startQ);
        }
        cout << 'q' << startQ << '\n';

        if (startQ == output)
        {
            cout << "TEST VALUE: '" << Case << "' -> contains 'cat'" << startQ << "\n\n";
        }
        else
        {
            cout << "TEST VALUE: '" << Case << "' not contained" << "\n\n";
        }
        startQ = 0;
    }
}