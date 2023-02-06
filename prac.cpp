#include <bits/stdc++.h>

using namespace std;



int answer(int level , int weight , int vale ,int &W, int wt[] , int val[] , int n){
        
        if(level == n){
            if(weight <= W)return vale;
            else return 0;
        }
        
        
        int ans = answer(level+1 , weight , vale  , W , wt , val  , n );
        
        if(weight + wt[level] <= W){
        ans = max(ans ,answer(level+1,weight + wt[level] , vale + val[level] , W , wt,val , n));
        }
        
        
        return ans;
        
    }


int main(int argc, char const *argv[])
{
    
    return 0;
}
