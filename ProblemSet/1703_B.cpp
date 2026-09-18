#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int alphabet[26] = {0}, balloons = n;
        for (int i = 0; i < n; i++)
        {
            if (alphabet[s[i] - 'A'] == 0)
                balloons++;
            alphabet[s[i] - 'A']++;
        }
        cout << balloons << endl;
    }
    return 0;
}