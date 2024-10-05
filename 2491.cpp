class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        long long res = 0;
        int target = skill[0] + skill[skill.size()-1];
        for (int i = 0; i < skill.size()/2; i++) {
            if (skill[i] + skill[skill.size()-1-i] != target) {
                return -1;
            }
            else {
                res += skill[i] * skill[skill.size()-1-i];
            }
        }
        return res;
    }
};

// Another solution is calculate the target ( sum / n * 2)
// Hash Map every element
// Calculate by the sum, if corresponding element is not found, return -1
