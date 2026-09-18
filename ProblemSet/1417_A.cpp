#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, x, minimum_beauty = 0, maximum_beauty = 0;
        cin >> n >> x;
        long int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] % x != 0)
                maximum_beauty += a[i] / x + 1;
            else
                maximum_beauty += a[i] / x;
            minimum_beauty += a[i];
        }
        if (minimum_beauty % x != 0)
            minimum_beauty = minimum_beauty / x + 1;
        else
            minimum_beauty = minimum_beauty / x;
        cout << minimum_beauty << " " << maximum_beauty << endl;
    }
    return 0;
}