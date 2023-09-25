//Traverse the boundary and find all Os and mark all connected to the boundary LC-130
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();

        //vector<vector<int>> vis (n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i== n-1 || j==0 || j==m-1){
                    if(board[i][j]=='O'){
                        dfs(i,j,board);
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='$') board[i][j]='O';
                
            }
        }



    }

    void dfs(int i,int j, vector<vector<char>>& board){
        int n= board.size();
        int m= board[0].size();
        
        board[i][j]='$';
        vector<pair<int,int>> dir ={{0,1},{1,0},{0,-1},{-1,0}};

        for(int x=0;x<4;x++){
            int ni =i+dir[x].first;
            int nj =j+dir[x].second;

            if(ni>=0 && ni<n && nj>=0 && nj<m  && board[ni][nj]=='O'){
                dfs(ni,nj,board);
            }
        }
    }
};