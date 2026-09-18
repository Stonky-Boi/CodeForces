#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cout << "#";
    cout << endl;
    n--;
    bool left_hashtag = false;
    while (n)
    {
        if (left_hashtag)
        {
            cout << "#";
            for (int i = 1; i < m; i++)
                cout << ".";
        }
        else
        {
            for (int i = 0; i < m - 1; i++)
                cout << ".";
            cout << "#";
        }
        cout << endl;
        left_hashtag = !left_hashtag;
        n -= 2;
        for (int i = 0; i < m; i++)
            cout << "#";
        cout << endl;
    }
    return 0;
}