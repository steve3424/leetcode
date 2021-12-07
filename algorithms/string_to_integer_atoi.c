inline int GetDigitFromChar(char c) {
    return (c - 48);
}

int myAtoi(char * s){
    int front = 0;
    
    // ignore leading whitespace
    while((s[front] != '\0') && s[front] == ' ') {
        ++front;
    }
    
    // check for plus_minus
    int plus_minus = 1;
    if(s[front] == '-') {
        plus_minus = -1;
        ++front;
    }
    else if(s[front] == '+') {
        ++front;
    }
    
	// Process rest of string    
    int result = 0;
    int clamp = INT_MAX / 10;
    while(s[front] != '\0') {
        // Convert char to digit using ascii value
        int digit = GetDigitFromChar(s[front]);
        
        // Catch leading 0's
        if(digit == 0 && result == 0) {
            ++front;
            continue;
        }
        // Process 0-9 digits
        else if(0 <= digit && digit <= 9) {
            // Check for overflow
            if(result > clamp) {
                return (plus_minus == 1) ? INT_MAX : INT_MIN;
            }
            else if(result == clamp) {
                if(plus_minus == 1 && digit >= 7) {
                    return INT_MAX;
                }
                else if(plus_minus == -1 && digit >= 8) {
                    return INT_MIN;
                }
            }
            
            // Process if no overflow detected
            result *= 10;
            result += digit;
            ++front;
        }
        // Break on first non-digit char
        else {
            break;
        }
    }
    
    return result * plus_minus;
}
