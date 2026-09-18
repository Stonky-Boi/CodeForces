#include <iostream>
#include <vector>
using namespace std;

int digit_sum(int value)
{
    int sum = 0;
    while (value > 0)
    {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int main()
{
    const int MAX_K = 9 * 100000;
    vector<string> suffix(MAX_K + 1);
    vector<vector<int>> suffix_freq(MAX_K + 1, vector<int>(10, 0));
    vector<int> suffix_sum(MAX_K + 1, 0);
    for (int i = 1; i <= MAX_K; i++)
    {
        int curr = i;
        string suffix_x = to_string(curr);
        while (curr > 9)
        {
            curr = digit_sum(curr);
            suffix_x += to_string(curr);
        }
        suffix[i] = suffix_x;
        for (char c : suffix_x)
        {
            int d = c - '0';
            suffix_freq[i][d]++;
            suffix_sum[i] += d;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        if (n == 1)
        {
            cout << s << endl;
            continue;
        }
        vector<int> freq(10, 0);
        int total_sum = 0;
        for (char c : s)
        {
            int d = c - '0';
            freq[d]++;
            total_sum += d;
        }
        for (int i = 1; i <= 9 * n; i++)
        {
            bool possible = true;
            for (int j = 0; j < 10; j++)
                if (suffix_freq[i][j] > freq[j])
                {
                    possible = false;
                    break;
                }
            if (!possible)
                continue;
            if (total_sum - suffix_sum[i] != i)
                continue;
            vector<int> remaining_freq = freq;
            for (int j = 0; j < 10; j++)
                remaining_freq[j] -= suffix_freq[i][j];
            string prefix = "";
            for (int j = 9; j >= 0; j--)
                while (remaining_freq[j] > 0)
                {
                    prefix.push_back('0' + j);
                    remaining_freq[j]--;
                }
            cout << prefix + suffix[i] << endl;
            break;
        }
    }
    return 0;
}