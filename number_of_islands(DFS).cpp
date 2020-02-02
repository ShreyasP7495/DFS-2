//Time Complexity-O(m*n)
//Space Complexity-O(m*n)
//Did the code run on Leetcode? Yes

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        if(grid.size()==0)
        {
            return 0;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count+=dfs(grid,i,j);
                }
            }
        }
        return count;
    }
     int dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0')
        {
            return 0;
        }
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        return 1;
    }
};