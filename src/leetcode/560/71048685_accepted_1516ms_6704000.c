int subarraySum(int* nums, int numsSize, int k){
    int ret = numsSize && nums[0] == k;
    for(int i = 1; i < numsSize; ++i) nums[i] += nums[i - 1];
    for(int i = 1; i < numsSize; ++i) {
        ret += nums[i] == k;
        for(int j = i; j < numsSize; ++j)
            if(nums[j] - nums[i - 1] == k) ++ret;
    }
    return ret;
}