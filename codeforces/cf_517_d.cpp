#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct coordCompare {
    bool operator()(const vector<int> &lhs, const vector<int> &rhs) { return lhs[1] + lhs[2] > rhs[1] + rhs[2]; }
};

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    vector<vector<char>> m(n, vector<char>(n, 'a'));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<bool>> taken(n, vector<bool>(n, false));
    vector<vector<int>> first, second;

    int max_sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];

            if (m[i][j] != 'a')
                dp[i][j] = 1;

            if (i == 0) {
                if (j != 0)
                    dp[i][j] += dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] += dp[i - 1][j];
            } else {
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            }

            if (((dp[i][j] <= k) || (i == 0 && j == 0)) && (i + j) >= max_sum) {
                first.emplace_back(initializer_list<int>{ m[i][j], i, j });
                if (i + j > max_sum)
                    max_sum = i + j;
            }
        }
    }

    sort(first.begin(), first.end(), coordCompare());

    int first_size = 1, second_size = 0;

    int sum = first[0][1] + first[0][2];

    for (int i = 1; i < first.size(); i++) {
        if (first[i][1] + first[i][2] != sum) {
            first_size = i;
            break;
        }
    }

    string ANSWER = "";

    if (k > 0 || (k == 0 && sum > 0))
        for (int i = 0; i <= sum; i++)
            ANSWER += "a";
    else
        ANSWER += m[0][0];

    int min_char;
    int need_to_add = (2 * n - 1 - ANSWER.length());

    for (int i = 0; i < need_to_add; i++) {
        min_char = 'z';

        for (int j = 0; j < first_size; j++) {
            if (first[j][1] + 1 < n && !taken[first[j][1] + 1][first[j][2]]) {
                int n_row = first[j][1] + 1;
                int n_col = first[j][2];
                int n_char = m[n_row][n_col];

                taken[n_row][n_col] = true;

                if (second_size < second.size()) {
                    second[second_size][0] = n_char;
                    second[second_size][1] = n_row;
                    second[second_size][2] = n_col;
                    second_size++;
                } else {
                    second.emplace_back(initializer_list<int>{ n_char, n_row, n_col });
                    second_size++;
                }

                min_char = min(n_char, min_char);
            }

            // take right
            if (first[j][2] + 1 < n && !taken[first[j][1]][first[j][2] + 1]) {
                int n_row = first[j][1];
                int n_col = first[j][2] + 1;
                int n_char = m[n_row][n_col];

                taken[n_row][n_col] = true;

                if (second_size < second.size()) {
                    second[second_size][0] = n_char;
                    second[second_size][1] = n_row;
                    second[second_size][2] = n_col;
                    second_size++;
                } else {
                    second.emplace_back(initializer_list<int>{ n_char, n_row, n_col });
                    second_size++;
                }

                min_char = min(n_char, min_char);
            }
        }

        ANSWER += min_char;

        first_size = 0;
        for (int j = 0; j < second_size; j++)
            if (second[j][0] == min_char) {

                if (first_size < first.size()) {
                    first[first_size][0] = second[j][0];
                    first[first_size][1] = second[j][1];
                    first[first_size][2] = second[j][2];
                    first_size++;
                } else {
                    first.push_back(second[j]);
                    first_size++;
                }
            }
        second_size = 0;
    }

    if (ANSWER.length() != 2 * n - 1)
        ANSWER += m[n - 1][n - 1];
    cout << ANSWER << endl;
    return 0;
}