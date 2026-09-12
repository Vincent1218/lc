class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m_map;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (m_map.find(comp) != m_map.end()) {
                return {m_map[comp], i};
            }
            m_map[nums[i]] = i;
        }
        return {};
    }
};
