#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> solutions;
        long long power = 10;
        for (int k = 1; k <= 18; k++)
        {
            long long divisor = 1 + power;
            if (n % divisor == 0)
                solutions.push_back(n / divisor);
            if (power > (long long)1e18 / 10)
                break;
            power *= 10;
        }
        if (solutions.empty())
            cout << 0 << endl;
        else
        {
            sort(solutions.begin(), solutions.end());
            cout << solutions.size() << endl;
            for (int i = 0; i < (int)solutions.size(); i++)
                cout << solutions[i] << (i + 1 == (int)solutions.size() ? '\n' : ' ');
        }
    }
    return 0;
}