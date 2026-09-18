#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, start;
        int count = 0;
        cin >> n;
        for (int i = 1; i <= 9; i++)
        {
            start = i;
            while (start <= n)
            {
                count++;
                start = start * 10 + i;
            }
        }
        cout << count << endl;
    }
    return 0;
}