#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> target(10, vector<char>(10));
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> target[i][j];
            }
        }

        int points = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (target[i][j] == 'X')
                {
                    int ring = min(i, min(9 - i, min(j, 9 - j)));
                    points += ring + 1;
                }
            }
        }
        cout << points << endl;
    }
    return 0;
}
