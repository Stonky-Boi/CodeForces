#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string x;
        cin >> x;
        string s;
        cin >> s;
        int operations = 0;
        while (x.find(s) == string::npos && x.size() <= 2 * s.size())
        {
            x += x;
            operations++;
        }
        if (x.find(s) == string::npos)
        {
            x += x;
            operations++;
        }
        cout << (x.find(s) == string::npos ? -1 : operations) << endl;
    }
    return 0;
}