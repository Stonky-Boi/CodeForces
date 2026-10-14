#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string ends[] = {"00", "25", "50", "75"};
    while (t--)
    {
        string n;
        cin >> n;
        int k = 20;
        for (const string &s : ends)
        {
            int i = n.size() - 1;
            int operations = 0;
            while (i >= 0 && n[i] != s[1])
            {
                i--;
                operations++;
            }
            i--;
            while (i >= 0 && n[i] != s[0])
            {
                i--;
                operations++;
            }
            k = min(k, operations);
        }
        cout << k << endl;
    }
    return 0;
}