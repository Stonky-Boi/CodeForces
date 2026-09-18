#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string numbers = "";
    for (int i = 0; i < s.size(); i += 2)
        numbers += s[i];
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); i++)
        s[2 * i] = numbers[i];
    cout << s << endl;
    return 0;
}