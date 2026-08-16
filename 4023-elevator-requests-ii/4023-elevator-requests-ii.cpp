class Solution{
public:
long long elevatorRequests(int n,int start,vector<int>&requests){
int m=requests.size();
vector<int>a=requests;
a.push_back(start);
sort(a.begin(),a.end());
a.erase(unique(a.begin(),a.end()),a.end());
int k=a.size();
int s=lower_bound(a.begin(),a.end(),start)-a.begin();
bool x=find(requests.begin(),requests.end(),start)!=requests.end();
const long long INF=1e18;
vector<vector<long long>>L(k,vector<long long>(k,INF)),R(k,vector<long long>(k,INF));
L[s][s]=R[s][s]=0;
for(int len=1;len<=k;len++){
for(int l=0;l+len-1<k;l++){
int r=l+len-1;
int served=len;
if(!x)served--;
int rem=m-served;
if(l>0){
L[l-1][r]=min(L[l-1][r],L[l][r]+1LL*(a[l]-a[l-1])*rem);
L[l-1][r]=min(L[l-1][r],R[l][r]+1LL*(a[r]-a[l-1])*rem);
}
if(r+1<k){
R[l][r+1]=min(R[l][r+1],L[l][r]+1LL*(a[r+1]-a[l])*rem);
R[l][r+1]=min(R[l][r+1],R[l][r]+1LL*(a[r+1]-a[r])*rem);
}
}
}
return min(L[0][k-1],R[0][k-1]);
}
};