#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && s[j] == s[i])
            j++;
        char c = 'a';
        while (c == s[i] || (i > 0 && c == s[i - 1]) || (j < n && c == s[j]))
            c++;
        for (int k = i + 1; k < j; k += 2)
            s[k] = c;
        i = j;
    }
    cout << s << endl;
    return 0;
}