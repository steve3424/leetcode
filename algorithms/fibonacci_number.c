int fib(int n){
    int nums[2];
    nums[0] = 0;
    nums[1] = (n != 0);

    for(int i = 2; i <= n; ++i) {
        int new_num = nums[0] + nums[1];
        nums[0] = nums[1];
        nums[1] = new_num;
    }
    
    return nums[1];
}
