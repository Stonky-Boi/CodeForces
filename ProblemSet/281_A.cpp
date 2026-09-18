#include <iostream>
using namespace std;

int main()
{
    string word;
    cin >> word;
    int ascii = (int)word[0];
    if (ascii > 96 && ascii < 123)
        ascii -= 32;
    word[0] = (char)ascii;
    cout << word << endl;
    return 0;
}