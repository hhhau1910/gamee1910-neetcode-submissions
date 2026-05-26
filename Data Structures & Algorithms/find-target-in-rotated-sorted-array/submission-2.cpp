class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size(), left = 0, right = size - 1;

        while(left < right){
            int mid = (left + right) / 2;

            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }


        int minIndex = left;

        if(minIndex == 0){
            left = 0, right = size - 1;
        } else if(target >= nums[0]){
            left = 0, right = minIndex - 1;
        } else {
            left = minIndex, right = size - 1;
        }


        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                return mid;
            } else if(nums[mid] < target){
                left =  mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
