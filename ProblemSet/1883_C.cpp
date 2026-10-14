#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int operations = 10, even_count = 0;
        for (const int &i : a)
        {
            if (i % 2 == 0)
                even_count++;
            if (i % k == 0)
            {
                operations = 0;
                break;
            }
            operations = min(operations, k - i % k);
        }
        if (k == 4)
        {
            if (even_count >= 2)
                operations = 0;
            else if (even_count == 1)
                operations = min(operations, 1);
            else if (even_count == 0)
                operations = min(operations, 2);
        }
        cout << operations << endl;
    }
    return 0;
}