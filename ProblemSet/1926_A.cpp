#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int count_A = 0, count_B = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'A')
                count_A++;
            else
                count_B++;
        }
        if (count_A > count_B)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }
    return 0;
}