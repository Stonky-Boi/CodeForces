#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "I hate";
    bool love = true;
    while (--n)
    {
        if (love == true)
            cout << " that I love";
        else
            cout << " that I hate";
        love = !love;
    }
    cout << " it" << endl;
    return 0;
}