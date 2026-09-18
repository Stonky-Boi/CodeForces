#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int cost;
        if (a * 2 <= b)
            cost = n * a;
        else
            cost = (n / 2) * b + (n % 2) * a;
        cout << cost << endl;
    }
    return 0;
}