// #include <iostream>
// #include <string>

// using namespace std;

// string concat(const string &str1, const string &str2)
// {

//     return str1 + str2;
// }

// string repeat(const string &str, int n)
// {

//     string result = "";

//     for (int i = 0; i < n; i++)
//     {

//         result += str;
//     }

//     return result;
// }

// string reverse(const string &str)
// {

//     string intors = str;

//     int len = intors.length();

//     for (int i = 0; i < len / 2; i++)
//     {

//         swap(intors[i], intors[len - 1 - i]);
//     }

//     return intors;
// }

// string extract(const string &str, int i, int j)
// {
//     cout << "AICI" << str << '\n';
//     if (i > j || i < 0 || j >= str.length())
//     {

//         return "";
//     }

//     return str.substr(i, j - i + 1);
// }

// string replace(const string &str, const string &old_sub, const string &new_sub)
// {

//     size_t pos = str.find(old_sub);

//     if (pos == string::npos)
//         return str;

//     string result = str;

//     result.replace(pos, old_sub.length(), new_sub);

//     return result;
// }

// int main()
// {

//     // int a[] = {1, 2, 3};
//     const string A[] = {"a", "b", "c"};
//     const string B[] = {"x", "y", "z"};
//     const string C[] = {"1", "2", "3"};
//     const string word[] = {concat(A[0], A[1]), concat(B[0], B[1])};

//     string result1 = concat(word[0], word[1]);

//     string result2 = repeat(word[0], 2);

//     string result3 = reverse(word[0]);

//     string result4 = extract(result2, 1, 3);

//     string result5 = replace(word[0], word[0], word[1]);

//     cout << "Concat: " << result1 << endl;

//     cout << "Repeat: " << result2 << endl;

//     cout << "Reverse: " << result3 << endl;

//     cout << "Extract: " << result4 << endl;

//     cout << "Replace: " << result5 << endl;

//     return 0;
// }

// ex 3
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPalindrom(const string &s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void generatePalindroame(string current, int maxLength, const vector<char> &alphabet)
{
    if (current.size() > maxLength)
        return;

    if (!current.empty() && isPalindrom(current) && current.length() == maxLength)
    {
        cout << current << " ";
    }

    for (char c : alphabet)
    {
        generatePalindroame(current + c, maxLength, alphabet);
    }
}

int main()
{
    vector<char> alphabet = {'0', '1', '2'};

    for (int length = 1; length <= 5; length++)
    {
        cout << "Palindrom de lungime " << length << ":\n";
        generatePalindroame("", length, alphabet);
        cout << "\n\n";
    }

    return 0;
}
