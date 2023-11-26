#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int* My_sortedSquares(int* nums, int numsSize, int* returnSize){
    int* res = (int*)malloc(numsSize * sizeof(int));
    int left = 0, right = numsSize - 1;
    int index = numsSize - 1;
    *returnSize = numsSize;
    for (; index >= 0; index--)
    {
        if(nums[left] * nums[left] > nums[right] * nums[right]) {
            res[index] = nums[left] * nums[left];
            left++;
        } else {
            res[index] = nums[right] * nums[right];
            right--;
        }
    }
    return res;
}

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    //返回的数组大小就是原数组大小
    *returnSize = numsSize;
    //创建两个指针，right指向数组最后一位元素，left指向数组第一位元素
    int right = numsSize - 1;
    int left = 0;

    //最后要返回的结果数组
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    int index;
    for(index = numsSize - 1; index >= 0; index--) {
        //左指针指向元素的平方
        int lSquare = nums[left] * nums[left];
        //右指针指向元素的平方
        int rSquare = nums[right] * nums[right];
        //若左指针指向元素平方比右指针指向元素平方大，将左指针指向元素平方放入结果数组。左指针右移一位
        if(lSquare > rSquare) {
            ans[index] = lSquare;
            left++;
        } 
        //若右指针指向元素平方比左指针指向元素平方大，将右指针指向元素平方放入结果数组。右指针左移一位
        else {
            ans[index] = rSquare;
            right--;
        }
    }
    //返回结果数组
    return ans;
}

int main() {
    int nums1[] = {-4,-1,0,3,10};
    int returnSize1;
    int* res1 = sortedSquares(nums1, sizeof(nums1)/sizeof(nums1[0]), &returnSize1);
    printf("Test 1 result: ");
    for (int i = 0; i < returnSize1; i++) {
        printf("%d ", res1[i]);
    }
    printf("\n");

    int nums2[] = {-7,-3,2,3,11};
    int returnSize2;
    int* res2 = sortedSquares(nums2, sizeof(nums2)/sizeof(nums2[0]), &returnSize2);
    printf("Test 2 result: ");
    for (int i = 0; i < returnSize2; i++) {
        printf("%d ", res2[i]);
    }
    printf("\n");

    free(res1);
    free(res2);

    return 0;
}