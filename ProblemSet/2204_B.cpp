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
        int operations = 0;
        int curr_max = 0;
        for (auto &i : a)
        {
            cin >> i;
            if (i >= curr_max)
            {
                operations++;
                curr_max = i;
            }
        }
        cout << operations << endl;
    }
    return 0;
}