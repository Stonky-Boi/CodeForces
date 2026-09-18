#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    int max_squared = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int square = dx * dx + dy * dy;
            max_squared = max(max_squared, square);
        }
    }
    cout << max_squared << endl;
    return 0;
}