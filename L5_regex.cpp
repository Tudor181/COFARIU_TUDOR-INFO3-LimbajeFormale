#include <iostream>
#include <regex>
#include <vector>
#include <string>

using namespace std;

int main()
{

    regex E1("(1|00*1)|(1|00*1)(0|10*1)*(0|10*1)");
    regex E2("0*1(0|10*1)*");

    vector<string> testValues = {
        "0001", "00001", "1", "0000001", "00010", "10101", "10", "1001", "00010101", "100",
        "0001001", "001", "100101", "0101", "00101", "110", "0011001", "0010001", "01", "0000"};

    for (const string &test : testValues)
    {
        bool match1 = regex_match(test, E1);
        bool match2 = regex_match(test, E2);

        cout << "Input: '" << test << "' testat: ";
        if (match1 == match2)
            cout << "OK";
        else
        {

            cout << "DIFFERENT" << "NOT EQUAL";
            break;
        }
        cout << "  (E1: " << (match1 ? "Y" : "N") << ", E2: " << (match2 ? "Y" : "N") << ")\n";
    }

    return 0;
}