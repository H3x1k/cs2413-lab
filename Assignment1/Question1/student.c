#include "Student.h"

//You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n:
//nums1 has length m + n
//The first m values in nums1 are real elements
//The last n values in nums1 are placeholders (0)
//nums2 has length n
//Goal: Merge nums2 into nums1 so that nums1 becomes one sorted array.
//Return: Nothing (modify nums1 in-place).

//Example:
//Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//Output: nums1 = [1,2,2,3,5,6]
//Explanation: The arrays we are merging are [1,2,3] and [2,5,6].

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    (void)nums2Size;
    if (n == 0) return;
    if (m == 0) {
        for (int i = 0; i < n; i++) nums1[i] = nums2[i];
        return;
    }
    int* current = nums1 + nums1Size - 1;
    int* n1 = nums1 + m - 1;
    int* n2 = nums2 + n - 1;
    while (n2 >= nums2) {
        if (n1 < nums1) *current-- = *n2--;
        else if (*n1 > *n2) *current-- = *n1--;
        else *current-- = *n2--;
    }
}
