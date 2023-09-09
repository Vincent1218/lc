// 2789. Largest Element in an Array after Merge Operations


class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
      int n = nums.size();
      long long ans = nums[n-1], curMax = nums[n-1];
      for (int i = n-2; i >= 0; i--){
        if (nums[i] <= curMax){
          curMax += nums[i];
          ans = curMax;
        }
        else{
          curMax = nums[i];
          ans = max(ans, curMax);
        }
      }
      return ans;

    }
};