#include <iostream>
using namespace std;

int main()
{
    string str_1, str_2;
    cin >> str_1 >> str_2;
    for (int i = 0; i < str_1.size(); i++)
        cout << (str_1[i] ^ str_2[i]);
    return 0;
}