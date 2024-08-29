// My solution

class Solution {
public:
    void helper (vector<vector<int>>& ans, vector<int>& nums, unordered_set<int> s, vector<int> temp, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if (s.find(nums[i]) == s.end()){
                temp.push_back(nums[i]);
                s.insert(nums[i]);
                helper(ans, nums, s, temp, index+1);
                temp.pop_back();
                s.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector <int>> ans;
        vector<int> temp;
        unordered_set<int> s;
        helper(ans,nums,s,temp,0);   
        return ans; 
    }
};

// swapping solution

class Solution {
public:
    vector<vector<int>> result;
    
    // Backtracking
    void permutation(vector<int> &nums,int i,int n){
        if(i==n){
            result.push_back(nums);
            return ;
        }

        for(int j=i;j<=n;j++){
            swap( nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap( nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permutation(nums,0,nums.size()-1);
        
        return result;
    }
};