#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    long int n;
    string s;
    cin >> n >> s;
    set<char> unique_types;
    for (int i = 0; i < n; i++)
        unique_types.insert(s[i]);
    long int total_types = unique_types.size();
    map<char, int> count;
    long int min_flats = n, left = 0, unique_in_window = 0;
    for (long int right = 0; right < n; right++)
    {
        if (++count[s[right]] == 1)
            unique_in_window++;
        while (unique_in_window == total_types)
        {
            min_flats = min(min_flats, right - left + 1);
            if (--count[s[left]] == 0)
                unique_in_window--;
            left++;
        }
    }
    cout << min_flats << endl;
    return 0;
}