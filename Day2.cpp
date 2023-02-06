#include<bits/stdc++.h>
/*
the framework
.1 .look for the form of the problem 
.2 look for the states and their meaning 
  Dp(level,stateOne , stateTwo)
.3 decide transitions 
.4 check time complexity 
.5 code the probelm
pruning 
base case
cache check 
transition 
save and return  
always check time complexity before writing dp solutions 
*/
/*
how to calculate time complexity ?
formula 
t.c - O((#S)(1+avg transition cost per state))
or mostly we have 
t.c - O((#S)(1+avg # of transitions per state ))
how to calculate s.c
    calculate O(#s)
*/

/*in the max Work problem as given earlier 

Dp(level,timeTaken,itemTaken)
 -->here level is in range [0,N]
 -->here timeTaken in range [0,summation T[n]] n ranges from 0 - N]
    further in this problem time was at max x so 
     so final goes from [0,x]
 -->here item taken in range [ 0, N]
    further in this problem item was at max K so 
    so final goes from [0,k]

so total state = N*x*k
t.c = O(N*x*k)(1+2)
t.c = O(N*x*k)

*/
int n;
int x , k;
int t[1001];
int s[1001];
// this dp cache carries the ans of a particular state of dp
int dp[101][101][101];
using namespace std;
 int rec (int level , int time_taken , int item_taken){

    // pruning cases 

    // base condition 
    if(level == n)return 0;
    // cache check 
    if(dp[level][time_taken][item_taken]!=-1)return dp[level][time_taken][item_taken];
    // compute / transition 
    int ans = rec(level+1,time_taken,item_taken);
    if(time_taken+t[level]<=x && item_taken+1 <= k){
    time_taken+=t[level];  item_taken++;
    ans = max(ans, s[level] + rec(level+1,time_taken,item_taken));
    time_taken-=t[level]; item_taken--;
    }
    dp[level][time_taken][item_taken]=ans;
    return ans;
    // save and return 

 }
int main(int argc, char const *argv[])
{
    /*how to write code ?*/
    memset(dp,-1,sizeof(dp));


    return 0;
}
