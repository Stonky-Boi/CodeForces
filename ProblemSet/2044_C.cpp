#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int m, a, b, c;
        cin >> m >> a >> b >> c;
        int monkeys = 0, empty_seats = 2 * m;
        if (m >= a)
        {
            monkeys += a;
            empty_seats -= a;
        }
        else
        {
            monkeys += m;
            empty_seats -= m;
        }
        if (m >= b)
        {
            monkeys += b;
            empty_seats -= b;
        }
        else
        {
            monkeys += m;
            empty_seats -= m;
        }
        if (empty_seats < c)
            monkeys += empty_seats;
        else
            monkeys += c;
        cout << monkeys << endl;
    }
    return 0;
}