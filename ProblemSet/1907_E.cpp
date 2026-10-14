#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ways(10, 0);
    for (int a = 0; a <= 9; a++)
    {
        for (int b = 0; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (a + b + c <= 9)
                    ways[a + b + c]++;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long triples = 1;
        while (n > 0)
        {
            int digit = n % 10;
            triples *= ways[digit];
            n /= 10;
        }
        cout << triples << endl;
    }
    return 0;
}