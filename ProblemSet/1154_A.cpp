#include <iostream>
using namespace std;

int main()
{
    int x[4];
    cin >> x[0] >> x[1] >> x[2] >> x[3];
    int sum_of_abc = max(x[0], max(x[1], max(x[2], x[3])));
    for (int i = 0; i < 4; i++)
    {
        if (sum_of_abc == x[i])
            x[i] = 0;
    }
    for (int i = 0; i < 4; i++)
    {
        if (x[i] != 0)
            cout << sum_of_abc - x[i] << " ";
    }
    return 0;
}