#include <iostream>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    string min_string(k, 'z');
    for (int length = 1; length <= n; length++)
    {
        string curr_string;
        for (int i = 0; i < k; i++)
            curr_string += s[i % length];
        min_string = min(min_string, curr_string);
    }
    cout << min_string << endl;
    return 0;
}