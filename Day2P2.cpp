#include<bits/stdc++.h>

using namespace std;
int n = 5;
int q;
int x[101] = {1,3,4,5,6};
int t = 10;
int dp[101][10001];
int s ;

/*
there r n items 
 x1 x2 x3 x4 .... xN 
 that sum up to target T 

find if there exist a subset that sum up to target T

N<=100
xi<=10^4
t<=10^4
*/
/*
follow framework 
    1. identify form (here it is a subsequence probelm belonging to form we read earlier )
    2. states are (level , sum)
    3. transition include level and not include 
    4. t.c check (below)
    5. code problem 

t.c 
     no. of states :
     level has - 0-N states 
     sum has - 0-T states
     we can calculate all no. of states - sum*level = O(N*T)(1+ 2(possible transition))
     we get O(N*T)
*/
bool rec(int level , int sum){

    // pruning conditions 
    // we can include check here to for sum not greater than t 
    // base case
    if(level == n){
        if(sum == t)return 1;
        else return 0;
    }   
    //  cache check 
    // if(dp[level][sum]!=-1)return dp[level][sum];

    // transitions 
    bool ans = rec(level+1,sum);

    if(!(sum+x[level]>t))
    ans = ans || rec(level+1, sum+x[level]);

    // save 
    // dp[level][sum]=ans;
    // return 
    return ans;

}
bool rec2(int level , int left){
// cout<<"h"<<endl;
    // pruning conditions 
    // we can include check here to for sum not greater than t 
    // base case
    if(level == n){
        // cout<<"hello"<<endl;
        if(left == 0)return 1;
        else return 0;
    }   
    //  cache check 
    if(dp[level][left]!=-1)return dp[level][left];

    // transitions 
    bool ans = rec2(level+1,left);

    if(left-x[level]>=0)
    ans = ans || rec2(level+1, left-x[level]);

    // save 
    dp[level][left]=ans;
    // return 
    return ans;

}
int main(int argc, char const *argv[])
{
    //  cin>>n;
    //  cin>>q;

    //  for(int i = 0 ; i < n ; i++){
    //     cin>>x[i];
    //  }

    //  memset(dp,-1,sizeof(dp));
    //  cout<<rec(0,0);
/*
     what if we have q queries?
     q = targetSum
     in that case we have to clear dp array again and again 
     so t.c of code will be O(q*((#s)+O(N*T)))  
     #s is number of possible states 
     so ans = O(N*T*Q)

     the key point there is if we want to reduce complexity in
     then we have to do something so that dp array is not cleared after every query 
     sol- when we encounter such situation where the query that changes is used in the recursion function then we have to make recursion query independent 
     for this problem we can replace sum with left and this work !
*/
/*
    when we do this with queries then simple rule -->
    O(#s)+O(DP) and then think of q queires as O(1)
    so final complexity is - O(Dp + q) - O(N*T + Q);
*/
        memset(dp,-1,sizeof(dp));
        cout<<rec2(0,t);
    // while(q--){
    //     cin>>s;
    //    cout<<rec(0,s);
    // }
    // cout<<x[5]<<endl;
    // cout<<x[6];
    return 0;
}
