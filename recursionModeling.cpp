#include<bits/stdc++.h>
// model -->
// level - ways to iterate over all solution space efficiently 
// choice - for each level what moves we can do to go to next level 
// check - for each choice check weahter the current partial solution is correct or not 
// move - if check is true then move to next level 

int n;
int queen[20];
int t[1001];
int s[1001];
int maxTime,maxItem;
int currTime = 0  , itemTaken = 0;
using namespace std;
// solving - ways to reach stair n
int stair(int level){
        // pruning condition 

        // base condition 
        if(level==n)return 1;
    int ans=0;
        // choices 
    for(int i = 1 ; i <=3 ; i++){
            // check 
        if(level+i<=n){
            // moves
            int partialAns = stair(level+i);
            ans+=partialAns;
        }
    }

    return ans;
}

// n - queen problem 
bool check(int row , int i){
    for(int k = 0 ; k < row ; k++){
        if(i==queen[k] || abs(row-k)==abs(i-queen[k]))return false;
    }
    return true;
}
int queenPlaced(int row, int column){

    // base conditon 
    if(row == n)return 1 ;
    // choices 
    int ans = 0;
    for(int i = 0 ; i < column ; i++){
        if(check(row,i)){
            queen[row]=i;
            int partialAns = queenPlaced(row+1,column);
            queen[row]=-1;
            ans+=partialAns;
        }
    }
        return ans;
}

int maxWork(int i ){
    // base condition 
    if(i==n)return 0;

    // choices 
    // dont include 
    int skill = maxWork(i+1);

    // include 
    currTime+=t[i];
    itemTaken++;
    if(currTime<=maxTime && itemTaken<=maxItem)
    skill = max(maxWork(i+1)+s[i],skill); 
    currTime-=t[i];
    itemTaken--;

    return skill;
}
int main(){


    // int n ;
    // n=4;
    // cout<<stair(1);

    // n queen 
    // n no. of rows 
    cin>>n;
    // memset(queen,-1,sizeof(queen));
    //  cout<<queenPlaced(0,8);
    for(int i = 0 ; i < n ; i++){
        cin>>t[i]>>s[i];
    }
    
    cin>>maxTime>>itemTaken;
    
cout<<maxWork(0);
    return 0;
}