#include <stdio.h>
#include <limits.h>
#include <math.h>
//滑动窗口
int minSubArrayLen(int target, int *nums, int numsSize)
{
  int start = 0, end = 0, sum = 0, minLen = INT_MAX;
  while (end < numsSize) // 循环遍历数组
  {
    sum += nums[end]; // 将当前元素加到sum中
    while (sum >= target) // 当sum大于等于目标值时
    {
      minLen = fmin(minLen, end - start + 1); // 更新最小长度
      sum -= nums[start]; // 从sum中减去起始元素
      start++; // 更新起始位置
    }
    end++; // 更新结束位置
  }
  return minLen == INT_MAX ? 0 : minLen; // 返回最小长度，如果没有符合条件的子数组则返回0
}

int main() {
    int nums1[] = {2,3,1,2,4,3};
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test 1: %d\n", minSubArrayLen(7, nums1, len1));  // 应该输出2

    int nums2[] = {1,4,4};
    int len2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test 2: %d\n", minSubArrayLen(4, nums2, len2));  // 应该输出1

    int nums3[] = {1,1,1,1,1,1,1,1};
    int len3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test 3: %d\n", minSubArrayLen(11, nums3, len3));  // 应该输出0

    return 0;
}