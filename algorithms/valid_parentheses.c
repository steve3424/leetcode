// Strategy is to use a stack where we always push an open bracket when found.
// If we find a close bracket, we need to make sure it was the most recent one
// that was opened. This means it should be at the top of the stack. 
// If it is NOT, we can return false. 
// If it IS, we can delete the open/close pair from the stack.
// This means all valid pairs should be deleted from the stack at the end.
// If there is anything left on the stack, something was wrong and we can return false.

typedef struct {
    char open;
    char close;
} BracketPair;

bool isValid(char* s) {
    BracketPair pairs[] = {
        {.open='(', .close=')'},
        {.open='[', .close=']'},
        {.open='{', .close='}'}
    };
    
    char stack[512*7] = {0};
    // push variable doubles as stack_size.
    int push = 0;
    
    char* current_char = s;
    while(*current_char) {
        for(int i = 0; i < 3; ++i) {
            if(*current_char == pairs[i].open) {
                stack[push++] = *current_char;
                break;
            }
            else if(*current_char == pairs[i].close) {
                if(push) {
                    if(stack[push - 1] == pairs[i].open) {
                        push--;
                    }
                    else {
                        // Found a close bracket, but most recently opened bracket
                        // is not a match.
                        return false;
                    }
                }
                else {
                    // Found a close bracket, but there
                    // is no recently opened bracket.
                    return false;
                }
            }
        }
        
        ++current_char;
    }
    
    // Push variable is also the stack size so if there is
    // something left on the stack, that means there are opened
    // brackets that weren't closed.
    return push == 0;
}
