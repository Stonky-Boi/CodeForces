#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<long int> factors[100001];
    for (int i = 1; i <= 100000; i++)
        for (int j = i; j <= 100000; j += i)
            factors[j].push_back(i);
    while (t--)
    {
        long int n, m;
        cin >> n >> m;
        pair<long int, int> a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        int frequency[m + 1] = {0};
        int unique_topics = 0, left = 0, minimum_difference = 1000000;
        for (int right = 0; right < n; right++)
        {
            long int value = a[right].first;
            for (int k = 0; k < (int)factors[value].size(); k++)
            {
                int topic = factors[value][k];
                if (topic > m)
                    break;
                if (frequency[topic] == 0)
                    unique_topics++;
                frequency[topic]++;
            }
            while (unique_topics == m)
            {
                long int current_diff = a[right].first - a[left].first;
                if (current_diff < minimum_difference)
                    minimum_difference = current_diff;
                long int remove_value = a[left].first;
                for (int k = 0; k < (int)factors[remove_value].size(); k++)
                {
                    int topic = factors[remove_value][k];
                    if (topic > m)
                        break;
                    frequency[topic]--;
                    if (frequency[topic] == 0)
                        unique_topics--;
                }
                left++;
            }
        }
        if (minimum_difference == 1000000)
            cout << "-1" << endl;
        else
            cout << minimum_difference << endl;
    }
    return 0;
}