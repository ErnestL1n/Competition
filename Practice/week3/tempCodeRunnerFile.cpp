  while (i > 0 and j > 0) {
    if (s[i - 1] == revs[j - 1]) {
      res += s[i - 1];
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      --i;
    } else {
      --j;
    }
  }