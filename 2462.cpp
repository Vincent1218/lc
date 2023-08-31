class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
      long long ans = 0;
        // map to store the index of the original array
        map<int, vector<ll>> indexBefore;
        for (int i = 0; i < costs.size(); i++){
            indexBefore[costs[i]].push_back(i);
        }

        int n = costs.size();
        // print map
        for (int i = 0; i < k; i++){
          for (auto it = indexBefore.begin(); it != indexBefore.end(); it++){
            cout << it->first << " " << it->second << endl;
            if (it->second < candidates && it->second >= n - candidates){
              ans += it->first;
              // remove from map
              indexBefore.erase(it->first);
              // update index
              for (auto it2 = indexBefore.begin(); it2 != indexBefore.end(); it2++){
                if (it2->second > it->second){
                  it2->second--;
                }
              }
              n--;
              break;
            }
          } 
        }
        return ans;

    }
};