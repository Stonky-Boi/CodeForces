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
        cin >> n;
        cin >> s;
        int start = int('a') - 1, end = int('a');
        for (int i = 0; i < n; i++)
        {
            if (int(s[i]) > end)
                end = int(s[i]);
        }
        cout << end - start << endl;
    }
    return 0;
}