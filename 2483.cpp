/** 
Thoughts
1. How is penalty calculated in each index

_YYNY
index 0 -> Count the Y at right = 3

Y_YNY
index 1 -> Count the Y at right = 2

YY_NY
index 2 -> Count the Y at right = 1

YYN_Y
index 3 -> Count the Y at right + Count the N at left = 2

YYNY_
index 4 -> Count the N at left = 1

Calculation: Count the Y at right + Count the N at left

rightY[i] = number of Y to the right of index i
leftN[i] = number of X to the left of index i

Pseudocode
n = customers.size()
1. Construct rightY, leftN -> O(2n) ->  O(n)
2. Loop n times, update ans if penalty < current ans O(n)
3. return ans

Time complexity = O(n)
Space complexity = O(n)

**/


class Solution {
public:
    int bestClosingTime(string customers) {
      // Variables declaration
      int minPenalty = 10000000;
      int ans = 0;
      int n = customers.size();
      vector<int> rightY(n+1,0);
      vector<int> leftN(n+1,0);

      // 1. Construct rightY, leftN -> O(2n) ->  O(n)
      // leftN
      int charCount = 0;
      for (int i = 1; i < n+1; i++){
        if(customers[i-1]=='N'){
          charCount++;
        }
        leftN[i] = charCount;
      }
      // rightY
      charCount = 0;
      for (int i = n-1; i >= 0; i--){
        if(customers[i]=='Y'){
          charCount++;
        }
        rightY[i] = charCount;
      }

      // 2. Loop n times, update ans if penalty < current ans
      for (int i = 0; i < n+1; i++){
        int temp = leftN[i]+rightY[i];
        if (temp < minPenalty){
          minPenalty = temp;
          ans = i;
        }
      }

      // 3. return ans
      cout << ans << endl;

      return ans;

    }
};