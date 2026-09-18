#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string name;
        getline(cin, name);
        cout << name[0];
        for (int i = 0; i < name.length() - 1; i++)
            if (name[i] == ' ')
                cout << name[i + 1];
        cout << endl;
    }
    return 0;
}