class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
      /*  Solution 1 :  Moore's Voting
     
      Note => This solutuion breaks when nums = [-1,-1,-1]
      
        vector<int> ans;
        
        int count1 = 0, count2 = 0, num1=INT_MIN,num2=INT_MIN;
        
        for(int i=0;i<nums.size();i++){         // O(N)
            
            if(nums[i]==num1) count1++;
            else if(nums[i]==num2) count2++;
            
            else if(count1==0){
                num1 = nums[i];
                count1=1;
            }
            else if(count2==0){
                num2 = nums[i];
                count2=1;
            }
            else{
                count1--; count2--;
            }
        }
        
        count1=0; count2=0;
        
        for(int i=0;i<nums.size();i++){        // O(N)
            if(nums[i]==num1) count1++;
            if(nums[i]==num2) count2++;
        }
        
        if(count1 > nums.size()/3) ans.push_back(num1);
        if(count2 > nums.size()/3) ans.push_back(num2);
        
        return ans;
        
    */  
       // Solution 2 :  
        
        unordered_map<int,int> u;
        vector<int> res;
        int n = nums.size();
		
        for(int i=0 ; i<n ; i++)
            u[nums[i]]++;
        
        for(auto x: u)
           if(x.second > n/3)
               res.push_back(x.first);
        
        return res;
        
        
    }
};
