#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<set<int>> sets(n);
        map<int, int> elementFrequency;

        for (int i = 0; i < n; ++i)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j)
            {
                int num;
                cin >> num;
                sets[i].insert(num);
                elementFrequency[num]++;
            }
        }

        int max_size = 0;
        int unionSize = 0;

        // Calculate the union size and find the maximum frequency
        for (const auto &[element, frequency] : elementFrequency)
        {
            max_size = max(max_size, frequency);
            unionSize++;
        }

        // Find the answer by taking the maximum of two cases:
        // 1. The maximum frequency that is not equal to the union size.
        // 2. The maximum size of any individual set.
        int answer = max(max_size, unionSize - 1);

        // If all sets have only one element and all elements are unique, the answer is the sum of the sizes of all sets - 1.
        if (max_size == 1 && unionSize == elementFrequency.size())
        {
            int sumOfSetSizes = 0;
            for (const set<int> &s : sets)
            {
                sumOfSetSizes += s.size();
            }
            answer = sumOfSetSizes - 1;
        }

        cout << answer << endl;
    }

    return 0;
}
