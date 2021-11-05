int reverse(int x){
    ///* using string formatting */
    //// format x as string
    //char x_string[12] = {0};
    //snprintf(x_string, 12, "%d", x);
    //int len = strlen(x_string);
    //// get rid of trailing zeros
    //int i = len - 1;
    //while(x_string[i] == '0' && 0 < i) {
    //    x_string[i] = 0;
    //    --i;
    //    --len;
    //}
    //
    //// reverse string
    //int f = x < 0 ? 1 : 0; // don't want to put - at end when reversing
    //int b = len - 1;
    //while(f < b) {
    //    char temp = x_string[f];
    //    x_string[f] = x_string[b];
    //    x_string[b] = temp;
    //    ++f;
    //    --b;
    //}
    //
    //// reversed string to int
    //x = atoi(x_string);
    //
    //// reversed int back to string
    //char rev_x_string[12] = {0};
    //snprintf(rev_x_string, 12, "%d", x);
    //if(strcmp(x_string, rev_x_string) == 0) {
    //    return x;
    //}
    //return 0;
    
    // pop off digits in reverse order
    int reversed_digits[10] = {0};
    int i = 0;
    while(x != 0) {
        reversed_digits[i++] = x % 10;
        x /= 10;
    }
    
    // Create reversed X except for highest order digit
    int factor = 1;
    for(int j = i - 1; j > 0; --j) {
        x += (reversed_digits[j] * factor);
        factor *= 10;
    }
    
    // check for overflow
    int ten_digits = (i == 10);
    int digit_too_high = (reversed_digits[0] < -2) || (2 < reversed_digits[0]);
    int outside_range = ((reversed_digits[0] == 2) || (reversed_digits[0] == -2)) &&
                        ((x < -147483648) || (147483647 < x));
    // this should be 0 when true to use as flag
    int overflows = !(ten_digits && (digit_too_high || outside_range));
    
    x += (reversed_digits[0] * (factor * overflows));
    return x * overflows;
    //if(i == 10) {
    //    if((reversed_digits[0] < -2) || (2 < reversed_digits[0])) {
    //        return 0;
    //    }
    //    else if(reversed_digits[0] == 2 || reversed_digits[0] == -2) {
    //        if((x < -147483648) || (147483647 < x)) {
    //            return 0;
    //        }
    //    }
    //}
    
}
