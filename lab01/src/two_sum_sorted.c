#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.
    int* start = nums;
    int* end = nums + n;

    while (start < end) {
        int a = *start;
        int b = *end;
        int t = a + b;
        if (t == target) {
            *out_i = start - nums;
            *out_j = end - nums;
            return 1;
        } else if (t < target) {
            start++;
        } else {
            end--;
        }
    }

    return 0;
}
// think about the time complexity and space complexity of your solution

