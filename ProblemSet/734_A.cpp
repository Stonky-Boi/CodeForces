#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int anton_wins = 0, danik_wins = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
            anton_wins++;
        if (s[i] == 'D')
            danik_wins++;
    }
    if (anton_wins > danik_wins)
        cout << "Anton" << endl;
    else if (anton_wins < danik_wins)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
    return 0;
}