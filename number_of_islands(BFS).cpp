//Time Complexity-O(m*n)
//Space Complexity- O(n) or (m) depending upon the direction of traversal
//I think in case of BFS solution for Number of islands space complexity totally depends on the direction array that we declare.
//I tried it for 3 instances:
//m-no of rows
//n-no of columns
// 1.m==n
// 2.m>n
// 3.m<n
// if m=n, then the space complexity will be O(n) or O(m) [Max Queue Size]
// if m<n or n>m:
//       i. if the direction array is {{0,1},{0,-1},{1,0},{-1,0}} then it will be O(n)[Max Queue Size]
//     ii. if the direction array is {{1,0},{-1,0},{0,1},{0,-1}} then it will   be  O(m)[Max Queue Size]


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        queue<vector<int>>m;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    grid[i][j]='0';
                    m.push({i,j});
                    while(!m.empty())
                    {
                        vector<int>k=m.front();
                        m.pop();
                        for(int a=0;a<dir.size();a++)
                        {
                            vector<int>b=dir[a];
                            int row=b[0]+k[0];
                            int col=b[1]+k[1];
                            if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size())
                            {
                                if(grid[row][col]=='1')
                                {
                                    grid[row][col]='0';
                                    m.push({row,col});
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};