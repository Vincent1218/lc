class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for (int const& num : nums) {
            sum = (sum % p + num % p) % p;
        }
        int target = sum % p;

        if (target == 0) {
            return 0;
        }

        int n = nums.size();
        int res = n;
        int cur = 0;
        std::unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            cur = (cur % p + nums[i] % p) % p;
            int need = (cur - target + p) % p;
            if (mp.count(need)) {
                res = std::min(res, i - mp[need]);
            }
            mp[cur] = i;
        }
        return res == n ? -1 : res;
    
        
    }
};
