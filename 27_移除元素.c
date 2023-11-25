#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != val) {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}

int main(){
    int nums[] = {0,1,2,2,3,0,4,2};
    int val = 2;
    int newLength = removeElement(nums, sizeof(nums)/sizeof(nums[0]), val);
    printf("New Length: %d\n", newLength);
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}