#include <iostream>
using namespace std;

int main()
{
    string letter_set;
    getline(cin, letter_set);
    int distinct_letters = 0, alphabet[26] = {0};
    if (letter_set == "{}")
    {
        distinct_letters = 0;
        cout << distinct_letters << endl;
        return 0;
    }
    for (int i = 1; i < letter_set.size(); i += 3)
        alphabet[(int)letter_set[i] - 97] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == 1)
            distinct_letters++;
    }
    cout << distinct_letters << endl;
    return 0;
}