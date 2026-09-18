#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        getline(cin, s);
        int sequences = 3 * (10 - n) * (9 - n);
        cout << sequences << endl;
    }
    return 0;
}