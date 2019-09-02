#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int n, m, answer = 0, tmp;
  cin >> n >> m;

  if (n == 0 && m == 0) return 0;

  if (m == 1) {
    while (cin >> tmp) answer += tmp;
    std::cout << answer;
    return 0;
  }

  vector<vector<int>> orig(n, vector<int>(m, 0));
  vector<vector<int>> mr(n, vector<int>(m, 0)), ml(n, vector<int>(m, 0));
  vector<vector<int>> mrit(n, vector<int>(m, 0)), mlit(n, vector<int>(m, 0));
  vector<vector<int>> dp(n, vector<int>(m, 0));

  for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++) cin >> orig[r][c];

  for (int r = 0; r < n; r++) {
    // count max right
    for (int c = 0; c < m; c++)
      if (c == 0)
        mr[r][c] = orig[r][c];
      else
        mr[r][c] = max(mr[r][c - 1] + orig[r][c], orig[r][c]);

    // count max left
    for (int c = m - 1; c >= 0; c--)
      if (c == m - 1)
        ml[r][c] = orig[r][c];
      else
        ml[r][c] = max(ml[r][c + 1] + orig[r][c], orig[r][c]);

    // count dp
    if (r == 0) {
      for (int c = 0; c < m; c++) dp[r][c] = ml[r][c] + mr[r][c] - orig[r][c];
    } else {
      // count max right including top
      for (int c = 0; c < m; c++)
        if (c == 0)
          mrit[r][c] = orig[r][c] + dp[r - 1][c];
        else
          mrit[r][c] =
              max(mrit[r][c - 1] + orig[r][c], mr[r][c] + dp[r - 1][c]);

      // count max left including top
      for (int c = m - 1; c >= 0; c--)
        if (c == m - 1)
          mlit[r][c] = orig[r][c] + dp[r - 1][c];
        else
          mlit[r][c] =
              max(mlit[r][c + 1] + orig[r][c], ml[r][c] + dp[r - 1][c]);

      // count dp itself, using all the data we've got
      for (int c = 0; c < m; c++)
        if (c == 0)
          dp[r][c] =
              max(max(mrit[r][c] + ml[r][c + 1], mrit[r][c]), mlit[r][c]);
        else if (c == m - 1)
          dp[r][c] =
              max(mrit[r][c], max(mlit[r][c] + mr[r][c - 1], mlit[r][c]));
        else
          dp[r][c] =
              max(max(mrit[r][c], mlit[r][c]),
                  max(mrit[r][c] + ml[r][c + 1], mlit[r][c] + mr[r][c - 1]));
    }
  }

  answer = dp[n - 1][0];
  for (int i = 1; i < m; i++) answer = max(dp[n - 1][i], answer);
  std::cout << answer << endl;
  return 0;
}