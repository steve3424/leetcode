

int strStr(char * haystack, char * needle){
    if(!haystack || !needle) {
        return 0;
    }
    
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    if(needle_len == 0) {
        return 0;
    }
    
    for(int i = 0; i <= haystack_len - needle_len; ++i) {
        bool match_found = true;
        for(int j = 0; j < needle_len; ++j) {
            if(haystack[i + j] != needle[j]) {
                match_found = false;
                break;
            }
        }
        
        if(match_found) {
            return i;
        }
    }
    
    return -1;
}
