class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charMap;

        for (char &c: s){
            charMap[c]++;
        }

        // iterate map
        int count = -1;
        for (int i = 0; i < s.size(); i++){
            if (charMap[s[i]] == 1){
                return count;
            }
        }
        return -1;
    }
};
