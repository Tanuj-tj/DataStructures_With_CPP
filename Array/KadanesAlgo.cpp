int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int maxsum = 0;
        int currsum = 0;
        
        for(int i=0;i<n;i++){
            currsum += arr[i];
            if(currsum > maxsum){
                maxsum = currsum;
            }
            if(currsum<0){
                currsum=0;
            }
        }
        
        return maxsum;
        
    }