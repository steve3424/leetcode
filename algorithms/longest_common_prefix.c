char* longestCommonPrefix(char ** strs, int strsSize){
    // allocate for output string
    char* output = calloc(201, sizeof(char));
    if(!output) {
        printf("Couldn't malloc...\n");
        return NULL;
    }
    
    // put first string in output
    char* first_string = strs[0];
    int i = 0;
    while(first_string[i] != '\0') {
        output[i] = first_string[i];
        ++i;
    }
    
    // loop through all output strings
    for(int j = 0; j < strsSize; ++j) {
        char* current_string = strs[j];
        int c = 0;
        while(output[c] != '\0') {
            if(output[c] != current_string[c]) {
                output[c] = '\0';
                break;
            }
            ++c;
        }
    }
    
    //printf("%s\n", first_string);
    //printf("%s\n", output);
    
    return output;
}
