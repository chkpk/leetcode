class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestBetween(nums, 0, nums.size() - 1, k);
    }

    int findKthLargestBetween(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        int mid = left + (right - left) * (rand() * 1.0 / RAND_MAX);
        swap(nums[mid], nums[right]);
        int x = nums[right];
        int l = left;
        int r = right;
        while (l < r){
            while (l < r && nums[l] <= x) ++l;
            if (l == r) break;
            nums[r--] = nums[l];
            while (l < r && nums[r] >= x) --r;
            if (l == r) break;
            nums[l++] = nums[r];
        }
        nums[r] = x;
        int n = right - r + 1;
        if (n == k) return x;
        if (n > k) return findKthLargestBetween(nums, r + 1, right, k);
        if (n < k) return findKthLargestBetween(nums, left, r - 1, k - n);
    }
};
