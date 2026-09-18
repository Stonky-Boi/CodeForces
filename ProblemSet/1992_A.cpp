#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int maximum_bananas = 0;
        for (int i = 0; i <= 5; i++)
        {
            for (int j = 0; j <= 5 - i; j++)
            {
                int bananas = (a + i) * (b + j) * (c + 5 - i - j);
                maximum_bananas = max(maximum_bananas, bananas);
            }
        }
        cout << maximum_bananas << endl;
    }
    return 0;
}