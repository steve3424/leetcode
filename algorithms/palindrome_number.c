bool isPalindrome(int x){
    if(x < 0) {
        return false;
    }
    
    int digits[10];
    int i = 0;
    while(x != 0) {
        digits[i++] = x % 10;
        x /= 10;
    }
    
    int f = 0;
    --i;
    while(f < i) {
        if(digits[f] != digits[i]) {
            return false;
        }
        ++f;
        --i;
    }
    
    return true;
}
