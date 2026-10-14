#include <iostream>
#include <map>
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
        map<int, long long> freq;
        long long subarrays = 0;
        long long prefix = 0;
        freq[0] = 1;
        for (const char &c : s)
        {
            int x = c - '0';
            prefix += x - 1;
            subarrays += freq[prefix];
            freq[prefix]++;
        }
        cout << subarrays << endl;
    }
    return 0;
}