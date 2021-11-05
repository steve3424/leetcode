/*
    N^2 solution:
    Checks all possible substrings to see if it is a palindrome.
    If yes it will check if it is longer than the last one found.
    If longer it will save the end points and size to copy into the result later.
*/

char * longestPalindrome(char * s){
    int len = strlen(s);
   
    int max_front = 0;
    int max_back = 0;
    int max_len = 1;
    
    // Check every possible sub string
    for(int front = 0; front < len; ++front) {
        for(int back = len - 1; front < back; --back) {
            // Check if current substring is palindrome
            int temp_front = front;
            int temp_back = back;
            bool is_palindrome = true;
            while(temp_front < temp_back) {
                if(s[temp_front] != s[temp_back]) {
                    is_palindrome = false;
                    break;
                }
                
                ++temp_front;
                --temp_back;
            }
            
            int sub_len = back - front + 1;
            if(is_palindrome &&
               sub_len > max_len) 
            {
                max_front = front;
                max_back = back;
                max_len = sub_len;
            }
        }
    }
    
    char* result = calloc(max_len + 1, sizeof(char));
    memcpy(result, s + max_front, max_len);
    
    return result;
}
