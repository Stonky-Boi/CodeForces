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
        for (int &i : a)
            cin >> i;
        int max_length = 0, curr_length = 0;
        for (const int &i : a)
        {
            if (i == 1)
            {
                max_length = max(max_length, curr_length);
                curr_length = 0;
            }
            else
                curr_length++;
        }
        cout << max(max_length, curr_length) << endl;
    }
    return 0;
}