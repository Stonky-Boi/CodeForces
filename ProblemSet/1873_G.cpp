#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        bool all_A_consumed = (s[0] == 'B' || s[s.size() - 1] == 'B');
        for (int i = 0; i < (int)s.size() - 1; i++)
        {
            if (s[i] == s[i + 1] && s[i] == 'B')
                all_A_consumed = true;
        }
        vector<int> A_blocks;
        int current_block = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == 'A')
                current_block++;
            else
            {
                if (current_block != 0)
                    A_blocks.push_back(current_block);
                current_block = 0;
            }
        }
        if (current_block != 0)
            A_blocks.push_back(current_block);
        sort(A_blocks.begin(), A_blocks.end());
        if (A_blocks.empty())
        {
            cout << 0 << endl;
            continue;
        }
        int coins = 0;
        if (all_A_consumed)
            coins += A_blocks[0];
        for (int i = 1; i < (int)A_blocks.size(); i++)
            coins += A_blocks[i];
        cout << coins << endl;
    }
    return 0;
}