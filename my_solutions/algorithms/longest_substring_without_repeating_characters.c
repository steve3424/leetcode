#define NUM_CHARS 128

int lengthOfLongestSubstring(char * s){
    // Table to track which chars are in substring already.
    int char_table[NUM_CHARS] = {0};
    
    int front = 0;
    int back = 0;
    int max = 0;
    int len = strlen(s);
    
    while(back < len) {
        // The index into the table is equal to the
        // ASCII value of the char.
        char char_index = s[back];
        
        // If we check table and the char is clear
        // we can add it to our substring and increase
        // the back pointer. Then check if this is a new
        // max length.
        if(char_table[char_index] == 0) {
            char_table[char_index] = 1;
            ++back;
            int new_len = back - front;
            max = new_len > max ? new_len : max;
        }
        else {
            // The new char we tried to add on the back of the
            // the string is not unique. The duplicate char is
            // somewhere in the string. Find it and along the way
            // clear every char that we pass since it is no longer
            // in the substring.
            while(s[front] != s[back]) {
                char_table[s[front]] = 0;
                ++front;
            }
            
            // Our front pointer should now be at the repeated char.
            // We want to push it one forward to rid it from our
            // substring. We DON'T clear it from the table since it
            // is the same as the back char and we are keeping that one.
            // We then push the back pointer forward to check for the 
            // next char on the next iteration of the loop.
            ++front;
            ++back;
        }
    }
    
    return max;
}
