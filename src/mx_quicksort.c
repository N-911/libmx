#include "libmx.h"

static int median_div(char **arr, int left, int right);

int mx_quicksort(char **arr, int left, int right) {
    int count = 0;
    int low = left;
    int hi = right;
    int div = median_div(arr, left, right);

    if (left >= right)
        return 0;
    while (low <= hi) {
        while (mx_strlen(arr[hi]) > mx_strlen(arr[div]))
            hi--;
        while (mx_strlen(arr[low]) < mx_strlen(arr[div]))
            low++;
        if (low <= hi) {
            if (mx_strlen(arr[low]) > mx_strlen(arr[hi])) {
                count++;
                mx_swap((void *)&arr[low], (void *)&arr[hi]);
            }
            low++;
            hi = (hi > 0) ? hi - 1 : hi;        //checking if hi < 0!!!
        }
    }
    if (left < hi)
        count += mx_quicksort(arr, left, hi);
    if (right > low)
        count += mx_quicksort(arr, low, right);
  return count;
}

static int median_div(char **arr, int left, int right) {
    int mid_val = mx_strlen(arr[((left + right) / 2)]);
    int l_val = mx_strlen(arr[left]);
    int r_val = mx_strlen(arr[right]);

    if (l_val <= mid_val && l_val >= r_val)
        return left;
    else if (r_val <= mid_val && r_val >= l_val)
        return right;
    else
        return (left + right) / 2;
}
