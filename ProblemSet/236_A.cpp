#include <iostream>
using namespace std;

int main()
{
    string user_name;
    int distinct_letters = 0;
    cin >> user_name;
    int a[26] = {0};
    for (int i = 0; i < user_name.size(); i++)
    {
        int id = user_name[i] - 'a';
        a[id] = 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] == 1)
            distinct_letters++;
    }
    if (distinct_letters % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;
    return 0;
}