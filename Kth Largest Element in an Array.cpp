class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
        }
        while(k>1){
            q.pop();
            k--;
        }
        return q.top();
    }
};