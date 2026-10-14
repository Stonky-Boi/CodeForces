#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int min_level = 0, curr_level = 0;
        for (const char &c : s)
        {
            curr_level += (c == '(' ? 1 : -1);
            min_level = min(min_level, curr_level);
        }
        cout << 0 - min_level << endl;
    }
    return 0;
}