#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int N = 3;
const int MOD = 1e9 + 7;

int grid[N][N];
double dp[3][3][3][3][3][3][3][3][3];

bool isValid(int a, int b, int c)
{
    return (a != b && b != c && a != c);
}

double solve(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    if (dp[a][b][c][d][e][f][g][h][i] >= 0.0)
    {
        return dp[a][b][c][d][e][f][g][h][i];
    }

    int filled = a + b + c + d + e + f + g + h + i;
    if (filled == 9)
    {
        return dp[a][b][c][d][e][f][g][h][i] = 1.0;
    }

    double prob = 0.0;

    // Place the next number in an empty cell.
    for (int x = 1; x <= 9; x++)
    {
        if (x != a && x != b && x != c && x != d && x != e && x != f && x != g && x != h && x != i)
        {
            int next_a = b;
            int next_b = c;
            int next_c = d;
            int next_d = e;
            int next_e = f;
            int next_f = g;
            int next_g = h;
            int next_h = i;
            int next_i = x;

            if (filled >= 2)
            {
                // Check for disappointments
                if ((next_a == next_b && next_b != next_c) ||
                    (next_b == next_c && next_c != next_d) ||
                    (next_d == next_e && next_e != next_f) ||
                    (next_e == next_f && next_f != next_g) ||
                    (next_g == next_h && next_h != next_i))
                {
                    continue;
                }
            }

            prob += solve(next_a, next_b, next_c, next_d, next_e, next_f, next_g, next_h, next_i);
        }
    }

    return dp[a][b][c][d][e][f][g][h][i] = prob;
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Initialize the DP table with -1.0 to indicate uncalculated values.
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            for (int c = 0; c < 3; c++)
            {
                for (int d = 0; d < 3; d++)
                {
                    for (int e = 0; e < 3; e++)
                    {
                        for (int f = 0; f < 3; f++)
                        {
                            for (int g = 0; g < 3; g++)
                            {
                                for (int h = 0; h < 3; h++)
                                {
                                    for (int i = 0; i < 3; i++)
                                    {
                                        dp[a][b][c][d][e][f][g][h][i] = -1.0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    double answer = solve(0, 0, 0, 0, 0, 0, 0, 0, 0);
    cout << fixed << setprecision(12) << answer << endl;

    return 0;
}
