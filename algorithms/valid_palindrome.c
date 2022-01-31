bool isPalindrome(char * s){
    int front = 0;
    int back = strlen(s) - 1;
    while(front < back) {
        char front_char = s[front];
        char back_char = s[back];
        
        bool front_is_num = (front_char >= 48) &&
                            (front_char <= 57);
        if(!front_is_num && front_char < 97) {
            front_char += 32;
        }
        bool front_is_lower_case = (front_char >= 97) &&
                                   (front_char <= 122);
        bool back_is_num = (back_char >= 48) &&
                           (back_char <= 57);
        if(!back_is_num && back_char < 97) {
            back_char += 32;
        }
        bool back_is_lower_case = (back_char >= 97) &&
                                  (back_char <= 122);
        
        
        if(!front_is_num &&
           !front_is_lower_case)
        {
            front++;
            continue;
        }
        if(!back_is_num &&
           !back_is_lower_case)
        {
            back--;
            continue;
        }
        
        if(front_char != back_char) {
            return false;
        }
        else {
            front++;
            back--;
        }
    }
    
    return true;
}
