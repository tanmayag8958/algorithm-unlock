#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int MaxCut(int n, int a, int b, int c){
    long int dp[n+1];
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        dp[i] = INT_MIN;
        if(a <= i && dp[i-a] != -1)
            dp[i] = max(dp[i], 1 + dp[i-a]);

        if(b <= i && dp[i-b] != -1)
            dp[i] = max(dp[i], 1 + dp[i-b]);

        if(c <= i && dp[i-c] != -1)
            dp[i] = max(dp[i], 1 + dp[i-c]);
    }
    return dp[n];
}

int MinCut(int n, int a, int b, int c){
    long int dp[n+1];
    dp[0] = 0;

    for(int i=1;i<=n;i++){
        dp[i] = INT_MAX;
        if(a <= i && dp[i-a] != -1)
            dp[i] = min(dp[i], 1 + dp[i-a]);

        if(b <= i && dp[i-b] != -1)
            dp[i] = min(dp[i], 1 + dp[i-b]);

        if(c <= i && dp[i-c] != -1)
            dp[i] = min(dp[i], 1 + dp[i-c]);
    }
    return dp[n];
}
                                                                
int main()
{
    int ans;

    ans = MaxCut(25,11,12,13);
    cout<<ans<<endl;

    ans = MaxCut(25,2,5,7);
    cout<<ans<<endl;

    ans = MaxCut(50,3,10,12);
    cout<<ans<<endl;

    ans = MaxCut(100,7,10,15);
    cout<<ans<<endl;

    cout<<endl;

    ans = MinCut(25,11,12,13);
    cout<<ans<<endl;

    ans = MinCut(25,2,5,7);
    cout<<ans<<endl;

    ans = MinCut(50,3,10,12);
    cout<<ans<<endl;

    ans = MinCut(100,7,10,15);
    cout<<ans<<endl;
}