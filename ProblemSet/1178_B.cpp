#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long long w_count = 0, wo_count = 0, wow_count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'o')
            wo_count += w_count;
        else if (i > 0 && s[i - 1] == 'v')
        {
            w_count++;
            wow_count += wo_count;
        }
    }
    cout << wow_count << endl;
    return 0;
}