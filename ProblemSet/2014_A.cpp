#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, people = 0, gold = 0;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= k)
                gold += a[i];
            if ((a[i] == 0) && (gold > 0))
            {
                people++;
                gold--;
            }
        }
        cout << people << endl;
    }
    return 0;
}