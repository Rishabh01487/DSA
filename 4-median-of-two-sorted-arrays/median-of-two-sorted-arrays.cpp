class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int size1 = nums1.size();
        int size2 = nums2.size();
        function<int(int, int, int)> findKthElement = [&](int index1, int index2, int k) {
           
            if (index1 >= size1) {
                return nums2[index2 + k - 1];
            }
            if (index2 >= size2) {
                return nums1[index1 + k - 1];
            }
 if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }
int halfK = k / 2;
 int value1 = (index1 + halfK - 1 < size1) ? nums1[index1 + halfK - 1] : INT_MAX;
            int value2 = (index2 + halfK - 1 < size2) ? nums2[index2 + halfK - 1] : INT_MAX;
 if (value1 < value2) {
                return findKthElement(index1 + halfK, index2, k - halfK);
            } else {
                return findKthElement(index1, index2 + halfK, k - halfK);
            }
        };
        int totalLength = size1 + size2;
        int leftMedian = findKthElement(0, 0, (totalLength + 1) / 2);
        int rightMedian = findKthElement(0, 0, (totalLength + 2) / 2);
   return (leftMedian + rightMedian) / 2.0;
    }

};