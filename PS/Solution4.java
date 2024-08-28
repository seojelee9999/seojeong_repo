class Solution4 {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) return findMedianSortedArrays(nums2,nums1);

        int left = (nums1.length + nums2.length + 1) / 2; //left size
        int low = 0, high = nums1.length;
        int mid1,mid2;
        while (low <= high){
            mid1 = (low + high) / 2;
            mid2 = left - mid1;

            int l1 = -2147483648, l2 = -2147483648, r1 = 2147483647, r2 = 2147483647;

            if (mid1 < nums1.length) r1 = nums1[mid1];
            if (mid2 < nums2.length) r2 = nums2[mid2];
            if (mid1 >= 1) l1 = nums1[mid1-1];
            if (mid2 >= 1) l2 = nums2[mid2-1];

            if (l1 <= r2 && l2 <= r1){
                if ((nums1.length + nums2.length) % 2 == 1){
                    return Math.max(l1,l2);
                }
                return (Math.max(l1,l2) + Math.min(r1,r2)) / 2.0;
            }
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0;
    }
}