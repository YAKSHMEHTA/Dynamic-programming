# Dynamic Programming 🚀

A comprehensive collection of Dynamic Programming problems and solutions, organized by patterns and difficulty levels.

## 📚 About

This repository contains my journey through mastering Dynamic Programming - one of the most powerful algorithmic techniques for solving optimization problems. Each solution includes detailed explanations, time/space complexity analysis, and multiple approaches where applicable.

## 🎯 Topics Covered

### Core DP Patterns
- **0/1 Knapsack** - Classic optimization problems
- **Unbounded Knapsack** - Unlimited item selection variants
- **Longest Common Subsequence (LCS)** - String matching patterns
- **Longest Increasing Subsequence (LIS)** - Sequence optimization
- **Matrix Chain Multiplication** - Optimal parenthesization
- **DP on Trees** - Tree-based dynamic programming
- **DP on Grids** - Path and grid problems
- **Palindromic Subsequences** - String palindrome patterns
- **Partition Problems** - Subset division challenges

## 📂 Repository Structure

```
Dynamic-Programming/
├── 0-1-Knapsack/
├── Unbounded-Knapsack/
├── LCS/
├── LIS/
├── Matrix-Chain-Multiplication/
├── Strings/
├── Grids/
└── Advanced/
```

Each folder contains:
- Problem statement
- Solution code (with comments)
- Approach explanation
- Time & Space complexity analysis
- Related problems

## 🛠️ Languages Used

- **Primary**: C++
- All solutions include detailed comments and explanations
- Three approaches provided: Recursion → Memoization → Tabulation → Space-Optimized

## 📈 Progress Tracker

- [ ] 0/1 Knapsack Pattern (0/15)
- [ ] Unbounded Knapsack (0/10)
- [ ] LCS Problems (0/12)
- [ ] LIS Problems (0/8)
- [ ] Matrix Chain Multiplication (0/7)
- [ ] Palindromic Subsequences (0/10)
- [ ] DP on Grids (0/15)
- [ ] Advanced Topics (0/20)

**Total Problems Solved**: 0 / 97

## 🚀 How to Use This Repository

1. **Clone the repository**
   ```bash
   git clone https://github.com/YAKSHMEHTA/Dynamic-programming.git
   cd Dynamic-programming
   ```

2. **Navigate to specific pattern**
   ```bash
   cd 0-1-Knapsack
   ```

3. **Study the problems progressively** - Start with basic problems before moving to advanced ones

## 💡 Learning Resources

### Recommended Playlists
- [Aditya Verma's DP Playlist](https://www.youtube.com/playlist?list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go) - Excellent pattern-based approach
- [Striver's DP Series](https://takeuforward.org/dynamic-programming/striver-dp-series-dynamic-programming-problems/)

### Practice Platforms
- [LeetCode DP Problems](https://leetcode.com/tag/dynamic-programming/)
- [Codeforces DP Tags](https://codeforces.com/problemset?tags=dp)
- [GeeksforGeeks DP](https://www.geeksforgeeks.org/dynamic-programming/)

## 🎓 Key Concepts

### What is Dynamic Programming?

Dynamic Programming is an algorithmic technique for solving optimization problems by breaking them down into simpler subproblems and storing their solutions to avoid redundant computations.

### Two Main Approaches

1. **Memoization (Top-Down)**
   - Recursive approach
   - Store results in a cache
   - Start from the main problem and break down

2. **Tabulation (Bottom-Up)**
   - Iterative approach
   - Fill up a DP table
   - Start from base cases and build up

### DP Problem Identification Checklist
- ✅ Problem asks for optimization (min/max/count)
- ✅ Has overlapping subproblems
- ✅ Current decision affects future choices
- ✅ Can be broken into similar smaller subproblems

## 🔥 Problem-Solving Template

```cpp
// Memoization Template (Top-Down)
class Solution {
public:
    int solve(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case
        if (n == 0 || target == 0) {
            return base_value;
        }
        
        // Check memo
        if (dp[n][target] != -1) {
            return dp[n][target];
        }
        
        // Recursive relation (choice diagram)
        if (arr[n-1] <= target) {
            // Two choices: include or exclude
            dp[n][target] = max(
                value + solve(n-1, target - arr[n-1], arr, dp),  // include
                solve(n-1, target, arr, dp)                       // exclude
            );
        } else {
            // Only one choice: exclude
            dp[n][target] = solve(n-1, target, arr, dp);
        }
        
        return dp[n][target];
    }
    
    int main_function(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(n, target, arr, dp);
    }
};

// Tabulation Template (Bottom-Up)
class Solution {
public:
    int solve(vector<int>& arr, int target) {
        int n = arr.size();
        
        // Initialize DP table
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        // Fill base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = base_value;  // e.g., 1 for count problems, 0 for sum
        }
        
        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i-1] <= j) {
                    // Choice: include or exclude
                    dp[i][j] = max(
                        value + dp[i-1][j - arr[i-1]],  // include
                        dp[i-1][j]                       // exclude
                    );
                } else {
                    // Can't include
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
    }
};

// Space-Optimized (1D array)
class Solution {
public:
    int solve(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(target+1, 0);
        
        // Base case
        dp[0] = base_value;
        
        // Fill DP array
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= arr[i]; j--) {  // reverse for 0/1
                dp[j] = max(dp[j], value + dp[j - arr[i]]);
            }
        }
        
        return dp[target];
    }
};
```

## 📊 Complexity Analysis Guide

Each solution includes:
- **Time Complexity**: How runtime scales with input size
- **Space Complexity**: Memory usage (including recursion stack)
- **Optimization notes**: How to reduce space (e.g., space-optimized tabulation)

## 🤝 Contributing

Feel free to:
- Suggest better solutions
- Add alternative approaches
- Fix bugs or improve explanations
- Add more problems

## 📝 License

This repository is open source and available for educational purposes.

## 🎯 My Goals

- Master all major DP patterns
- Solve 100+ DP problems
- Achieve 1800+ rating on LeetCode
- Help others learn DP through clear explanations

## 📬 Connect

- **GitHub**: [@YAKSHMEHTA](https://github.com/YAKSHMEHTA)
- **LeetCode**: [Your LeetCode Profile]
- **LinkedIn**: [Your LinkedIn]

---

⭐ **Star this repo** if you find it helpful!

💬 **Questions?** Open an issue or reach out!

🔄 **Last Updated**: March 2026