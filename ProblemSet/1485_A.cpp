#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int operations = 1e9;
        for (int i = 0; i <= 30; i++)
        {
            int moves = i;
            int B = b + i;
            if (B == 1)
                continue;
            int A = a;
            while (A > 0)
            {
                A /= B;
                moves++;
            }
            operations = min(operations, moves);
        }
        cout << operations << endl;
    }
    return 0;
}