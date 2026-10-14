#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i - cost] >= cost + 1)
                cost++;
            cout << cost << ' ';
        }
        cout << endl;
    }
    return 0;
}