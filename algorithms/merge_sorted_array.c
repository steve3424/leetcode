void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    // normal merge sort routine going in reverse
    // runs in O(m + n)
    int write = m + n - 1;
    int read_1 = m - 1;
    int read_2 = n - 1;
    while((read_1 >= 0) &&
          (read_2 >= 0))
    {
        int val_1 = nums1[read_1];
        int val_2 = nums2[read_2];
        if(val_1 > val_2) {
            nums1[write--] = val_1;
            read_1--;
        }
        else {
            nums1[write--] = val_2;
            read_2--;
        }
    }
    
    while(read_1 >= 0) {
        
        nums1[write--] = nums1[read_1--];
    }
    while(read_2 >= 0) {
        nums1[write--] = nums2[read_2--];
    }
}
