class Solution {
public:
    void solve(string tiles,  vector<bool>vis, int& c){
        
        for(int i=0;i<tiles.length();i++){
            if(vis[i]==true){
                continue;
            }    
            if(i && !vis[i-1] && tiles[i]==tiles[i-1]){
                continue;
            }
            c++;
            vis[i]=true;
            solve(tiles,vis,c);
            vis[i]=false;
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        vector<bool>vis(tiles.length(),false);
        int c = 0;
        solve(tiles,vis,c);
        return c;
    }
};
