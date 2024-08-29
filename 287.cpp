class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> record(n,0);
        for (int num : nums){
            if (record[num] != 0){
                return num;
            }
            record[num] = 1;
        }
        return 0;
    }
};