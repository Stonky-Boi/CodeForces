#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int denomination[] = {1, 5, 10, 20, 100};
    int bills = 0;
    for (int i = 0; i < 5; i++)
    {
        bills += n / denomination[5 - i - 1];
        n = n % denomination[5 - i - 1];
    }
    cout << bills << endl;
    return 0;
}