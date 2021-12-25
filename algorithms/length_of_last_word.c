

int lengthOfLastWord(char * s){
    printf("%s", s);
    char* c = s;
    while(*c) {
        ++c;
    }
    
    while(*c == '\0' || *c == ' ') {
        --c;
    }
    
    int count = 0;
    while(c >= s && *c != ' ') {
        ++count;
        --c;
    }
    
    return count;
}
