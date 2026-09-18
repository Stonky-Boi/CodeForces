#include <iostream>
#include <set>
using namespace std;

int main()
{
    int k, n;
    cin >> k >> n;
    int a[k];
    for (int i = 0; i < k; i++)
        cin >> a[i];
    long int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    long long int prefix_sum[k + 1]{0};
    for (int i = 0; i < k; i++)
        prefix_sum[i + 1] = prefix_sum[i] + a[i];
    set<long long int> valid_initial_scores;
    for (int i = 1; i <= k; i++)
    {
        long long int candidate_initial_score = b[0] - prefix_sum[i];
        set<long long int> generated_scores;
        for (int j = 1; j <= k; j++)
            generated_scores.insert(candidate_initial_score + prefix_sum[j]);
        bool is_valid = true;
        for (int j = 0; j < n; j++)
        {
            if (generated_scores.find(b[j]) == generated_scores.end())
            {
                is_valid = false;
                break;
            }
        }
        if (is_valid)
            valid_initial_scores.insert(candidate_initial_score);
    }
    cout << valid_initial_scores.size() << endl;
    return 0;
}