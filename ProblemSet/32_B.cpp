#include <iostream>
using namespace std;

int main()
{
    string borze_code;
    cin >> borze_code;
    for (int i = 0; i < borze_code.size(); i++)
    {
        if (borze_code[i] == '.')
            cout << "0";
        else if (borze_code[i + 1] == '.')
        {
            cout << "1";
            i++;
        }
        else
        {
            cout << "2";
            i++;
        }
    }
    cout << endl;
    return 0;
}