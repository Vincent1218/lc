/*

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

total = 4 + 2 + 2


Observations
1. Deleting nums[i] and delete nums[i]+1, nums[i]-1


Steps:
1. Sort the array
2. Concat the array to tuples(number, freq) 
2. DFS the array
DFS(0)
DFS(1)

Steps:

DFS(i, stored_value) -> sum: = max considering sorted_nums[i:]
  cur_sum = (number * freq)
  
  if stored, then dont to to dfs
  take_sum = DFS(i + 2) + cur_sum
  no_take_sum = DFS(i + 1)
  
  stored_value[i] = max(take_sum, no_take_sum)
  return max(take_sum, no_take_sum)

Complexity:
time: sorting:O(nlogn), dfs: 2**n
space: O(n)
  
Ex:
[1,2,3,4,5,6,7]

Take: 1, 3, 6
Cannot take: 2,4,5,7

Take: 1, 3, 5, 7
Cannot take: 2, 4, 6

Constraints:
1 <= nums.length <= 2 * 10^4
1 <= nums[i] <= 10^4


*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      // sort
      sort(nums.begin(), nums.end());

      // concat_nums
      vector<vector<int>> concat_nums;
      int cur_no = nums[0];
      int cur_sum = 1;
      for (int i = 1; i < nums.size(); i++){
        if (nums[i] == cur_no){
          cur_sum++;
        }
        else{
          concat_nums.push_back({cur_no, cur_sum});
          cur_no = nums[i];
          cur_sum = 1;
        }
      }
      concat_nums.push_back({cur_no, cur_sum});

      vector<int> stored(concat_nums.size(), -1);

      // dfs
      return dfs(0, concat_nums, stored);
    }

    int dfs(int i, vector<vector<int>>& concat_nums, vector<int>& stored){
      if (i >= concat_nums.size()){
        return 0;
      }
      int cur_sum = (concat_nums[i][0]*concat_nums[i][1]);
      int take_sum, no_take_sum;
      if (stored[i] > 0) {
        return stored[i];
      }
      else{
        if (i < concat_nums.size()-1 && concat_nums[i+1][0] -1 > concat_nums[i][0]){
          take_sum = dfs(i + 1, concat_nums, stored) + cur_sum;
          no_take_sum = 0;
        }
        else{
          take_sum = dfs(i + 2, concat_nums, stored) + cur_sum;
          no_take_sum = dfs(i + 1, concat_nums, stored);
        }
      }
      
      stored[i] = max(take_sum, no_take_sum);
      return max(take_sum, no_take_sum);
    }
};










