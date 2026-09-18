#include <iostream>
#include <vector>
using namespace std;

bool can_fit(const vector<int> &tokens, int k, int width)
{
    int lines = 1, curr = 0;
    for (int len : tokens)
    {
        if (len > width)
            return false;
        if (curr + len <= width)
            curr += len;
        else
        {
            lines++;
            curr = len;
        }
    }
    return lines <= k;
}

int main()
{
    int k;
    cin >> k;
    cin.ignore();
    string s;
    getline(cin, s);
    vector<int> tokens;
    int curr_length = 0;
    for (char c : s)
    {
        curr_length++;
        if (c == ' ' || c == '-')
        {
            tokens.push_back(curr_length);
            curr_length = 0;
        }
    }
    if (curr_length > 0)
        tokens.push_back(curr_length);
    int l = 1, r = s.size();
    int min_width = r;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (can_fit(tokens, k, m))
        {
            min_width = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    cout << min_width << endl;
    return 0;
}