// 253. Meeting Rooms II

// Solution 1: min heap
class Solution {
public:
    int minMeetingRooms(vector<vector<int> >& intervals) {

      // min heap pq
      priority_queue<int, vector<int>, greater<int > > pq;
      int ans = 0;
      
      // sort intervals by start time
      sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
      });

      // print intervals
      for (vector<int> interval: intervals){
        cout << interval[0] << " " << interval[1] << endl;
      }

      for (vector<int> interval: intervals){
        if(pq.empty()) {
          pq.push(interval[1]);
        }
        else{
          if (pq.top() <= interval[0]){
            pq.pop();
          }
          pq.push(interval[1]);
        }
        ans = max(ans, (int)pq.size());
      }
        
      return ans;
    }
};

// Solution 2: map
class Solution {
public:
      int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &t : intervals)
            m[t[0]]++, m[t[1]]--;
        int cur = 0, res = 0;
        for (auto &it : m)
            res = max(res, cur += it.second);
        return res;
    }
};

