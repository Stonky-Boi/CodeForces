#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int groups = 1;
    string str_1, str_2;
    cin >> str_1;
    for (int i = 1; i < n; i++)
    {
        cin >> str_2;
        if (str_1 != str_2)
            groups++;
        str_1 = str_2;
    }
    cout << groups << endl;
    return 0;
}