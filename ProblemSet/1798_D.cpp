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
        int minimum = 1e9, maximum = -1e9;
        for (int &i : a)
        {
            cin >> i;
            minimum = min(minimum, i);
            maximum = max(maximum, i);
        }
        if (minimum == maximum)
        {
            cout << "No" << endl;
            continue;
        }
        vector<int> positive, negative;
        vector<int> A;
        for (int i : a)
        {
            if (i > 0)
                positive.push_back(i);
            else if (i < 0)
                negative.push_back(i);
            else
                A.push_back(i);
        }
        long long sum = 0;
        int p = 0, q = 0;
        while (p < positive.size() || q < negative.size())
        {
            if (sum <= 0)
            {
                A.push_back(positive[p]);
                sum += positive[p];
                p++;
            }
            else
            {
                A.push_back(negative[q]);
                sum += negative[q];
                q++;
            }
        }
        cout << "Yes" << endl;
        for (const int &i : A)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}