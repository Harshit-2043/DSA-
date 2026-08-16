class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mx=*max_element(lights.begin(),lights.end());
        int ans=0;

        for( int t : arrivalTime){
            int r=t%period;
            int wait=(r<mx)?0: period -r;
            ans=max(ans,wait);
        }
        return ans;
    }
};