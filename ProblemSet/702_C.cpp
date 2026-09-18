#include <iostream>
using namespace std;

int main()
{
    long int n, m;
    cin >> n >> m;
    long long int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    long long int r = 0;
    int tower_index = 0;
    for (int i = 0; i < n; i++)
    {
        while (tower_index + 1 < m && abs(b[tower_index + 1] - a[i]) <= abs(b[tower_index] - a[i]))
            tower_index++;
        r = max(r, abs(b[tower_index] - a[i]));
    }
    cout << r << endl;
    return 0;
}