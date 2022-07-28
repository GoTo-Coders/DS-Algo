def countSubsets(nums: list, target: int) -> int:
  dp = [[0 for j in range(target+1)] for i in range(len(nums)+1)]
  dp[0][0] = 1

  for i in range(1, len(nums)+1):
    for j in range(target+1):
      if j == 0:
        dp[i][j] = 1
      else:
        if j >= nums[i-1]:
          dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]]
        else:
          dp[i][j] = dp[i-1][j]
  
  return dp[-1][-1]

nums = [2, 3, 5, 6, 7, 8, 9, 10, 10, 15]
target = 15
print(countSubsets(nums, target))