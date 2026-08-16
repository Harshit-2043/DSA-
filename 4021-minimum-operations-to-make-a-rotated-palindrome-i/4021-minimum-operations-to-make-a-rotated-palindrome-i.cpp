class Solution {
public:
    int minOperations(string s) {
        int n =s.size();
        int ans= INT_MAX;

        for(int k=0; k<n;k++){
            int cost=k;
            for( int i=0;i<n/2;i++){
                char a=s[(i+k)%n];
                char b=s[(n-1-i+k)%n];
                int best =INT_MAX;
                for (char c='a';c<='z';c++){
                    int x = (c - a + 26) % 26;
                    int y = (c - b + 26) % 26;

                    best = min(best, x + y);
                }
                cost+=best;
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};