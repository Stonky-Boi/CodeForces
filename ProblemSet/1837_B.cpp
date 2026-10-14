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
        string s;
        cin >> n >> s;
        int curr_block = 1, max_block = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                curr_block++;
            else
            {
                max_block = max(max_block, curr_block);
                curr_block = 1;
            }
        }
        cout << max(max_block, curr_block) + 1 << endl;
    }
    return 0;
}