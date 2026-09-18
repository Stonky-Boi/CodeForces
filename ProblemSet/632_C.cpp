#include <iostream>
#include <vector>
using namespace std;

bool lexico_compare(const string &a, const string &b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strings(n);
    for (auto &s : strings)
        cin >> s;
    sort(strings.begin(), strings.end(), lexico_compare);
    string result;
    for (auto s : strings)
        result += s;
    cout << result << endl;
    return 0;
}