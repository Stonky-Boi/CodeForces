#include <iostream>
using namespace std;

string find_mex(string s)
{
    for (char a = 'a'; a <= 'z'; a++)
    {
        string curr = "";
        curr += a;
        if (s.find(curr) == string::npos)
            return curr;
    }
    for (char a = 'a'; a <= 'z'; a++)
    {
        for (char b = 'a'; b <= 'z'; b++)
        {
            string curr = "";
            curr += a;
            curr += b;
            if (s.find(curr) == string::npos)
                return curr;
        }
    }
    for (char a = 'a'; a <= 'z'; a++)
    {
        for (char b = 'a'; b <= 'z'; b++)
        {
            for (char c = 'a'; c <= 'z'; c++)
            {
                string curr = "";
                curr += a;
                curr += b;
                curr += c;
                if (s.find(curr) == string::npos)
                    return curr;
            }
        }
    }
    return "";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << find_mex(s) << endl;
    }
    return 0;
}