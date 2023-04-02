#include "lib.h"

int maxSubArray(int arr[], int n, int *start, int *end) {
    int max_so_far = 0, max_ending_here = 0, s = 0;

    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            *start = s;
            *end = i;
        }
    }

    return max_so_far;
}