/*
1905. Count Sub Islands

You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Constraints:

m == grid1.length == grid2.length
n == grid1[i].length == grid2[i].length
1 <= m, n <= 500
grid1[i][j] and grid2[i][j] are either 0 or 1.

Observations:
We stack two grids on top of each other to get red colored islands
It might be an island in grid 1, but there might be separated in grid 2

Steps:
1. Using grid 2, do a dfs to neighbours cells, keep track of visited cells, count the number of separated island, do an additional checks to see if the cells is overlapping with grid 1

grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], 
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]],
O(n*m)
grid3 = [[1,1,1,0,0],[0,0,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[0,1,0,1,0]]


*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& visited, int i, int j, bool& isSub){
      int n = grid1.size();
      int m = grid1[0].size();
      if (grid2[i][j] && visited[i][j] == 0){
        if(!grid1[i][j]){
          isSub = false;
        }
        visited[i][j] = 1;
        if (i-1 >= 0){
          // Up 
          dfs(grid1, grid2, visited, i-1, j, isSub);
        }
        if (j+1 < m){
          // Right
          dfs(grid1, grid2, visited, i, j+1, isSub);
        }
        if (i+1 < n){
          // Down
          dfs(grid1, grid2, visited, i+1, j, isSub);
        }
        if (j-1 >= 0){
          // Left  
          dfs(grid1, grid2, visited, i, j-1, isSub);
        } 
      }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        // Variables
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        bool isSub; 
        vector<vector<int>> visited(n, vector<int>(m,0));

        for (int i = 0; i < n; i++){
          for (int j = 0; j < m; j++){
            isSub = false;
            if (grid2[i][j] && visited[i][j] == 0){
              isSub = true;
              dfs(grid1, grid2, visited, i, j, isSub);
            }
            if (isSub) ans ++;
          }
        }
        return ans;
    }
};