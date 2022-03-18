#include <iostream>
#include <map>
#include <vector>

using namespace std;

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        int i = -1;
        int j = -1;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        if (size % 2 == 0) {
            int flag = 0;
            while (i + j + 2 < size / 2) {
                if (i + 2 > size1) {
                    j++;
                    flag = 1;
                } else if (j + 2 > size2) {
                    i++;
                    flag = 0;
                } else {
                    if (nums1[i + 1] < nums2[j + 1]) {
                        i++;
                        flag = 0;
                    } else {
                        j++;
                        flag = 1;
                    }
                }
            }
            if (i + 2 > size1) {
                if (flag == 0) {
                    return (nums1[i] + nums2[j + 1]) / 2.0;
                } else {
                    return (nums2[j] + nums2[j + 1]) / 2.0;
                }
            } else if (j + 2 > size2) {
                if (flag == 0) {
                    return (nums1[i] + nums1[i + 1]) / 2.0;
                } else {
                    return (nums2[j] + nums1[i + 1]) / 2.0;
                }
            } else {
                if (nums1[i + 1] < nums2[j + 1]) {
                    if (flag == 0) {
                        return (nums1[i] + nums1[i + 1]) / 2.0;
                    } else {
                        return (nums2[j] + nums1[i + 1]) / 2.0;
                    }
                } else {
                    if (flag == 0) {
                        return (nums1[i] + nums2[j + 1]) / 2.0;
                    } else {
                        return (nums2[j] + nums2[j + 1]) / 2.0;
                    }
                }
            }
        } else {
            while (i + j + 2 < size / 2) {
                if (i + 2 > size1) {
                    j++;
                } else if (j + 2 > size2) {
                    i++;
                } else {
                    if (nums1[i + 1] < nums2[j + 1]) {
                        i++;
                    } else {
                        j++;
                    }
                }
            }
            if (i + 2 > size1) {
                return nums2[j + 1] / 1.0;
            } else if (j + 2 > size2) {
                return nums1[i + 1] / 1.0;
            } else {
                if (nums1[i + 1] < nums2[j + 1]) {
                    return nums1[i + 1] / 1.0;
                } else {
                    return nums2[j + 1] / 1.0;
                }
            }
        }
    }
};