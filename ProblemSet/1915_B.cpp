#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string missing_row, letter = "ABC";
        for (int i = 0; i < 3; i++)
        {
            string str;
            getline(cin, str);
            if (str.find('?') != string::npos)
                missing_row = str;
        }
        for (int i = 0; i < letter.size(); i++)
        {
            if (missing_row.find(letter[i]) == string::npos)
                cout << letter[i] << endl;
        }
    }
    return 0;
}