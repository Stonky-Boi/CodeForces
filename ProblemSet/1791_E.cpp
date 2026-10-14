#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int negatives = 0;
        long long sum = 0;
        int minimum = 1e9;
        for (int &i : a)
        {
            cin >> i;
            sum += abs(i);
            minimum = min(minimum, abs(i));
            if (i < 0)
                negatives++;
        }
        cout << (negatives % 2 == 0 ? sum : sum - 2 * minimum) << endl;
    }
    return 0;
}