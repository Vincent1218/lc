class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r){
            if (numbers[l] + numbers[r] == target){
                // return an array
                vector<int> v = {l+1, r+1};
                return v;
            }
            else if (numbers[l] + numbers[r] < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {};
    }
};


