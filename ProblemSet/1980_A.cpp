#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string a;
        cin >> n >> m;
        cin >> a;
        int difficulty[7] = {0}, problems = 0;
        for (int i = 0; i < n; i++)
            difficulty[a[i] - 'A']++;
        for (int i = 0; i < 7; i++)
        {
            if (difficulty[i] < m)
                problems += m - difficulty[i];
        }
        cout << problems << endl;
    }
    return 0;
}