#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int time_left = 240 - k;
    int problems = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (time_left >= 5 * i)
        {
            problems++;
            time_left -= 5 * i;
        }
    }
    cout << problems << endl;
    return 0;
}