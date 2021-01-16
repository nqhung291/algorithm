# Dynamic Programming

# 1. Dynamic Programming Pattern

- **Minimum (Maximum) Path to Reach a Target**

    > **Statement:** Given a target, find minimum (maximum) cost / path / sum to reach the target

    > **Approach:** Choose minimum (maximum) path among all possible paths before the current state, then add value for the current state

    Generate optimal solutions for all values in the target and return the value for the target.

    ```python
    for (int i = 1; i <= target; ++i) {
    	for (int j = 0; j < ways.size(); ++j) {
    		if (ways[j] <= i) {
    			dp[i] = (min/max)(dp[i], dp[i - ways[j]] + cost / path / sum)
    		}
    	}
    }
    return dp[target]
    ```

- **Distinct Ways**

    > **Statement:** Given a target, find a number of distinct ways to reach the target

    > **Approach:** Sum all possible ways to reach the current state

    Generate sum for all values in the target and return the value for the target

    ```cpp
    for (int i = 1; i <= target; i++) {
    	for (int j = 0; j < ways.size(); j++) {
    		if (ways[j] < i) 
    			dp[i] += dp[i-ways[j]];
    	}
    }
    ```

- **Merging Intervals**

    > **Statement:** Given a set of numbers find an optimal solution for a problem considering the current number and the best you can get from the left and right sides

    > **Approach:** Find all optimal solutions for every interval and return the best possible answer

    ```cpp
    // from i to j
    dp[i][j] = dp[i][k] + result[k] + dp[k+1][j]
    ```

    Get the best from the left and right sides and add a solution for the current position

    ```cpp
    for(int l = 1; l<n; l++) {
       for(int i = 0; i<n-l; i++) {
           int j = i+l;
           for(int k = i; k<j; k++) {
               dp[i][j] = max(dp[i][j], dp[i][k] + result[k] + dp[k+1][j]);
           }
       }
    }
     
    return dp[0][n-1]
    ```

- **Decision Making**

    The general problem statement for this pattern is forgiven situation decide whether to use or not to use the current state. So, the problem requires you to make a decision at a current state.

    > **Statement:** Given a set of values, find an answer with an option to choose or ignore the current value

    > **Approach:** If you decide to choose the current value, use the previous result where the value was ignored; vice-versa, if you decide to ignore the current value use the previous result where value was used

    ```cpp
    // i - indexing a set of values
    // j - options to ignore j values
    for (int i = 1; i < n; ++i) {
       for (int j = 1; j <= k; ++j) {
           dp[i][j] = max({dp[i][j], dp[i-1][j] + arr[i], dp[i-1][j-1]});
           dp[i][j-1] = max({dp[i][j-1], dp[i-1][j-1] + arr[i], arr[i]});
       }
    }
    ```

- **DP on Strings**

    > **Statement:** Given two string s1, s2, return *some result*

    > **Approach:** Most of the problems of this pattern requires a solution that can be accepted in O(n^2) complexity

    ```cpp
    // i: indexing string s1
    // j: indexing string s2
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		if (s1[i-1] == s2[j-1]) {
    			dp[i][j] = /*code*/			
    		} else {
    			dp[i][j] = /*code*/		
    		}
    	}
    }
    ```

    If you are given only one string s, the approach may little vary

    ```cpp
    for (int l = 1; l < n; ++l) {
       for (int i = 0; i < n-l; ++i) {
           int j = i + l;
           if (s[i] == s[j]) {
               dp[i][j] = /*code*/;
           } else {
               dp[i][j] = /*code*/;
           }
       }
    }
    ```