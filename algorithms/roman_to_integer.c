int romanToInt(char * s){
    int res = 0;
    while(*s != '\0') {
        char next = *(s + 1);
        switch(*s) {
            case 'I': {
                if((next == 'V') || (next == 'X')) {
                    res -= 1;
                }
                else {
                    res += 1;
                }
            } break;
            case 'X': {
                if((next == 'L') || (next == 'C')) {
                    res -= 10;
                }
                else {
                    res += 10;
                }
            } break;
            case 'C': {
                if((next == 'D') || (next == 'M')) {
                    res -= 100;
                }
                else {
                    res += 100;
                }
            } break;
            case 'V': {
                res += 5;
            } break;
            case 'L': {
                res += 50;
            } break;
            case 'D': {
                res += 500;
            } break;
            case 'M': {
                res += 1000;
            } break;
            default: {
                printf("something went horribly wrong...\n");
            } break;
        }
        
        ++s;
    }
    
    return res;
}
