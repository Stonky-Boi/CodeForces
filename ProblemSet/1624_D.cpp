#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int frequency[26] = {0};
        for (int i = 0; i < n; i++)
            frequency[s[i] - 'a']++;
        int pairs = 0, odd = 0;
        for (int i = 0; i < 26; i++)
        {
            pairs += frequency[i] / 2;
            odd += frequency[i] % 2;
        }
        int length = 2 * (pairs / k);
        odd += 2 * (pairs % k);
        if (odd >= k)
            length++;
        cout << length << endl;
    }
    return 0;
}