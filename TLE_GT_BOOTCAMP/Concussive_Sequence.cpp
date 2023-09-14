#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        sort(A.begin(), A.end());

        vector<int> result(N, -1);

        int left = 0, right = N - 1;
        bool isLeft = true;

        for (int i = 0; i < N; i++)
        {
            if (isLeft)
            {
                result[i] = A[left++];
            }
            else
            {
                result[i] = A[right--];
            }
            isLeft = !isLeft;
        }

        bool isConcussive = true;
        for (int i = 1; i < N - 1; i++)
        {
            if (!((result[i - 1] < result[i] && result[i] > result[i + 1]) ||
                  (result[i - 1] > result[i] && result[i] < result[i + 1])))
            {
                isConcussive = false;
                break;
            }
        }

        if (isConcussive)
        {
            for (int i = 0; i < N; i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
