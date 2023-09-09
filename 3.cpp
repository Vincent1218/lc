class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> record;
        int start = -1;
        int ans = 0;
        for (int i = 0; i < s.size(); i++){
            if (record.find(s[i]) != record.end() && record[s[i]] > start){
                start = record[s[i]];
            }
            record[s[i]] = i;
            ans = max(ans, i-start);
        }
        return ans;
    }
};