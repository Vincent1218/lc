/*
Thoughts:
Array can split if:
1. Can split if length of array is one
Means if array length == 2, then for sure we can split
We can also split an array with length n in to n-1, 1 array, as long as the n-1 array satisfies second condition

2. The sum of elements of the subarray is greater than or equal to m;

Both condition concludes that
If we can split array into a state that, it is either len 1 or len 2 with sum more than m, then true

So if n + n+1 element < m, we must split them:
While splitting: check prefix sum and length = 1 : if not satisfied, return false
if the rest of length = 2, skip

Constraints:
1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= m <= 200





*/


class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
      int n = nums.size();
      if (n < 3){
        return true;
      }

      bool ans = true;

      // suffix sum
      vector<int> suffixSum(n,0);
      suffixSum[n-1] = nums[n-1];
      for (int i = n-2; i >= 0; i--){
        suffixSum[i] = suffixSum[i+1] + nums[i];
      }

      for (int i = 0; i < n-2; i++){
        if (nums[i] + nums[i+1] < m){
          if ((suffixSum[i+1] < m)){
            ans = false;
          }
        }
        else{
          i += 1;
        }
      }

      if(ans){
        return true;
      }
    
      // prefix sum
      vector<int> prefixSum(n,0);
      prefixSum[0] = nums[0];
      for (int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i-1] + nums[i];
      }

      for (int i = n-1; i > 1; i--){
        if (nums[i] + nums[i-1] < m){
          if ((prefixSum[i-1] < m)){
            return false;
          }
        }
        else{
          i -= 2;
        }
      }

      return true;

        
    }
};
