#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int n;
        cin >> n;
        string s;
        cin >> s;
        long long int prefix = 0, subarrays = 0;
        map<long long, long long> frequency;
        frequency[0] = 1;
        for (int i = 0; i < n; i++)
        {
            int digit = s[i] - '0';
            prefix += digit;
            long long int key = prefix - (i + 1);
            subarrays += frequency[key];
            frequency[key]++;
        }
        cout << subarrays << endl;
    }
    return 0;
}