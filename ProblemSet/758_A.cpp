#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = 0, max_wealth = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max_wealth)
            max_wealth = a[i];
    }
    for (int i = 0; i < n; i++)
        s += (max_wealth - a[i]);
    cout << s << endl;
    return 0;
}