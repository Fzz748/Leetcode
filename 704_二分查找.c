#include <stdio.h>

int binarySearch(int* nums, int numsSize, int target) 
{
    int low = 0, high = numsSize - 1;
    int mid = low + (high - low) / 2; // 防止溢出
    while (low <= high)
    {
        mid = low + (high - low) / 2; 
        if (nums[mid] < target) {
            low = mid + 1;
        }else if(nums[mid] > target) {
            high = mid - 1; 
        }else {
            return mid;
        }
    }
    return -1;
}

int main(){
    int nums[] = {-1,0,3,5,9,12};
    int target = 9;
    int index = binarySearch(nums, sizeof(nums)/sizeof(nums[0]), target);
    printf("Index: %d\n", index);
    return 0;
}