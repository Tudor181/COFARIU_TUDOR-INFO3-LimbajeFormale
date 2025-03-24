// ex1 - Mealy

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int encodePair(const vector<int> &v)
// {
//     switch (v[0])
//     {
//     case 0:
//         switch (v[1])
//         {
//         case 0:
//             return 0;
//         case 1:
//             return 1;
//         }
//         break;
//     case 1:
//         switch (v[1])
//         {
//         case 0:
//             return 2;
//         case 1:
//             return 3;
//         }
//         break;
//     }
//     return -1; // În caz de eroare
// }

// void transit(const vector<int> &v, const vector<pair<int, vector<pair<int, int>>>> &transitions, int &startQ, const vector<string> outputs, string &exit)
// {

//     const int translatedValue = encodePair(v); // primim o pereche pe care o vom encoda intr un int care ne furnizeaza index ul cazului pt respectiva pereche din
//     // tabelul de tranzitii
//     if (translatedValue == -1)
//     {
//         cout << "eroare intrare" << '\n';
//         return;
//     }

//     for (auto transition : transitions) // iteram prin tranzitii pana gasim tranzitia pt starea curenta
//     {
//         if (transition.first == startQ)
//         {
//             exit.append(outputs[transition.second[translatedValue].second]); // adaugam iesirea conform valorii (0/1) dar cu un string custom
//             exit.append(",");                                                // adaugam o virgula dupa fiecare iesire
//             startQ = transition.second[translatedValue].first;               // ne mutam in urmatoarea stare conform tabelului de tranzitie
//             return;
//         }
//     }
//     // return true;
// }

// int main()
// {

//     const int output = {};  // F
//     const int q[] = {0, 1}; // starile
//     int startQ = q[0];      // q0 start value

//     // vector -> pair (stare, intrare, starea urmatoare, iesire)
//     vector<pair<int, vector<pair<int, int>>>> transitions = {{q[0], {{0, 0}, {1, 1}, {0, 0}, {1, 1}}}, {q[1], {{1, 1}, {1, 1}, {0, 0}, {0, 0}}}};
//     vector<string> outputs = {"verdeA", "verdeB"};
//     string exit;
//     const vector<vector<int>> testVector = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 0}};

//     for (vector<int> v : testVector)
//     {
//         cout << "intrare:" << v[0] << ' ' << v[1] << " stare curenta:";
//         cout << 'q' << startQ << " stare iesire:";
//         transit(v, transitions, startQ, outputs, exit);
//         cout << 'q' << startQ << '\n';
//     }
//     exit.pop_back(); // stergem ultima virgula
//     cout << 'q' << startQ << "\nexit value: ";
//     cout << exit << endl;
// }

// ex1 - transformare in Moore

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int encodePair(const vector<int> &v)
// {
//     switch (v[0])
//     {
//     case 0:
//         switch (v[1])
//         {
//         case 0:
//             return 0;
//         case 1:
//             return 1;
//         }
//         break;
//     case 1:
//         switch (v[1])
//         {
//         case 0:
//             return 2;
//         case 1:
//             return 3;
//         }
//         break;
//     }
//     return -1; // În caz de eroare
// }

// void transit(const vector<int> &v, const vector<pair<int, vector<int>>> &transitions, int &startQ, const vector<string> &outputs, string &exit)
// {

//     const int translatedValue = encodePair(v); // primim o pereche pe care o vom encoda intr un int care ne furnizeaza index ul cazului pt respectiva pereche din
//     // tabelul de tranzitii
//     if (translatedValue == -1)
//     {
//         cout << "eroare intrare" << '\n';
//         return;
//     }

//     for (auto transition : transitions) // iteram prin tranzitii pana gasim tranzitia pt starea curenta
//     {
//         if (transition.first == startQ)
//         {
//             startQ = transition.second[translatedValue]; // ne mutam in urmatoarea stare conform tabelului de tranzitie

//             exit.append(outputs[startQ]); // adaugam iesirea conform valorii (0/1) dar cu un string custom
//             exit.append(",");             // adaugam o virgula dupa fiecare iesire
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
//     vector<string> outputs = {"verdeA", "verdeB"};

//     // vector -> pair (stare, intrare, starea urmatoare)
//     vector<pair<int, vector<int>>> transitions = {{q[0], {0, 1, 0, 1}},
//                                                   {q[1], {1, 1, 0, 0}}};

//     string exit = outputs[startQ] + ",";
//     const vector<vector<int>> testVector = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {0, 0}};

//     for (vector<int> v : testVector)
//     {
//         cout << "intrare:" << v[0] << ' ' << v[1] << " stare curenta:";
//         cout << 'q' << startQ << " stare iesire:";
//         transit(v, transitions, startQ, outputs, exit);
//         cout << 'q' << startQ << '\n';
//     }
//     exit.pop_back(); // stergem ultima virgula
//     cout << 'q' << startQ << "\nexit value: ";
//     cout << exit << endl;
// }

// ex 2 regex to nfa-epsilon
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Tranzitie
{
    int stareDest;
    char simbol; // 'a', 'b', '#' pentru ε
};

const int START_STATE = 0;
const set<int> STARI_FINALE = {4, 6};
const char EPSILON = '#';

map<int, vector<Tranzitie>> tranzitii;

bool verifica(int stareCurenta, const string &input, int pozitie)
{
    // cout << "\nverifica: " << stareCurenta << " " << " pozitie" << pozitie << "\n";
    for (const auto &tranz : tranzitii[stareCurenta])
    {
        // daca tranzitia e de tip epsilon atunci ne mutam pe urmatoarea stare astfel putand "naviga" pe mai multe ramuri simultan folosind backtracking
        if (tranz.simbol == EPSILON)
        {
            if (verifica(tranz.stareDest, input, pozitie)) // respectiv daca starea 3 trece in 4 cu epsilon doar asa va trece, si daca trece in q4 dar mai este sir va returna fals
                return true;
        }
    }

    if (pozitie == input.size())
    {
        return STARI_FINALE.count(stareCurenta); // daca starea curenta se afla in setul de stari finale
    }

    char simbolCurent = input[pozitie];
    // de ex la 'ab' - a trece in q6 si tranzitii[q6] nu exista deci va return fals ca nu e corect.
    // daca e in q1 - q1 nu are tranzitie cu a deci va da fals
    for (const auto &tranz : tranzitii[stareCurenta])
    {
        if (tranz.simbol == simbolCurent)
        {
            if (verifica(tranz.stareDest, input, pozitie + 1))
                return true;
        }
    }

    return false;
}

int main()
{
    tranzitii[0] = {{1, EPSILON}, {5, EPSILON}};
    tranzitii[1] = {{2, 'b'}};
    tranzitii[2] = {{3, 'a'}, {3, 'b'}};
    tranzitii[3] = {{3, 'a'}, {3, 'b'}, {4, EPSILON}};
    tranzitii[5] = {{6, 'a'}};

    vector<string> testCases = {"ba", "bab", "baaa", "a", "bb", "b", "ab", "baa", ""};
    // vector<string> testCases = {"baaa"};

    for (const string &input : testCases)
    {
        cout << "Test: '" << input << "' → ";
        bool acceptat = verifica(START_STATE, input, 0);
        cout << (acceptat ? "ACCEPTAT" : "REJECT") << endl;
    }

    return 0;
}
