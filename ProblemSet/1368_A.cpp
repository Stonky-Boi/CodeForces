#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int a, b, n;
        cin >> a >> b >> n;
        int minimum = min(a, b), maximum = max(a, b);
        int operations = 0;
        while (maximum <= n)
        {
            minimum += maximum;
            minimum = minimum + maximum;
            maximum = minimum - maximum;
            minimum = minimum - maximum;
            operations++;
        }
        cout << operations << endl;
    }
    return 0;
}