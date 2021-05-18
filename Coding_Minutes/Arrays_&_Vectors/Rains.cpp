// O(N+N) = Time
// O(N+N) => Space 

#include<bits/stdc++.h>
using namespace std;

int Rains(vector<int> &heights){
    
    // Size of arr
    int n = heights.size();

    // If the size is >= 2 no water can be trapped
    if(n<=2) return 0;

    // Create 2 heightsays to keep track of max from left and max from right
    vector<int> left(n,0);
    vector<int> right(n,0);
    
    left[0] = heights[0];
    right[n-1] = heights[n-1];

    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],heights[i]);    // {0,1,1,2,2,2,2,3,3,3,3,3}
        right[n-i-1] = max(right[n-i],heights[n-i-1]);   // {3,3,3,3,3,3,3,3,2,2,2,1}
    }
    
    // Maintain the count of Rain water
    int water = 0;
    for(int i=0;i<n;i++){
        water += min(left[i],right[i]) - heights[i];
    }

    return water;
}

int main(){
   vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<Rains(heights);
    return 0;
}