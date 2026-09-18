#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string p, s;
        cin >> p >> s;
        int i = 0, j = 0;
        int p_len = p.length(), s_len = s.length();
        bool valid = true;
        while (i < p_len && j < s_len)
        {
            char current = p[i];
            int consec_p = 0, consec_s = 0;
            while (i < p_len && p[i] == current)
            {
                consec_p++;
                i++;
            }
            while (j < s_len && s[j] == current)
            {
                consec_s++;
                j++;
            }
            if (consec_s < consec_p || consec_s > 2 * consec_p)
            {
                valid = false;
                break;
            }
        }
        if (i == p_len && j == s_len && valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}