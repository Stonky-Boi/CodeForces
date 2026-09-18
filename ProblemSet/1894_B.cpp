#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> array(n);
        vector<int> frequency(101, 0);
        vector<int> first_occurence(101, -1);
        vector<int> b(n, 1);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
            frequency[array[i]]++;
            if (first_occurence[array[i]] == -1)
                first_occurence[array[i]] = i;
        }
        int occurs_more_than_once = 0;
        int first_number_appearing_more_than_once = -1;
        for (int i = 1; i <= 100; i++)
        {
            if (frequency[i] > 1)
            {
                occurs_more_than_once++;
                first_number_appearing_more_than_once = i;
            }
        }
        if (occurs_more_than_once < 2)
        {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 1; i <= 100; i++)
        {
            if (frequency[i] > 1)
                b[first_occurence[i]] = 2;
        }
        b[first_occurence[first_number_appearing_more_than_once]] = 3;
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}