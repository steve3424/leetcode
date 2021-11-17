

char * addBinary(char * a, char * b){
    int a_index = strlen(a) - 1;
    int b_index = strlen(b) - 1;
    
    int write_index = 0;
    char* result_string = calloc((a_index + b_index + 3), sizeof(char));
    
    int carry_digit = 0;
    while(a_index >= 0 &&
          b_index >= 0) 
    {
        int a_digit = a[a_index] == '1';
        int b_digit = b[b_index] == '1';
        int result = a_digit + b_digit + carry_digit;
        carry_digit = result > 1;
        result = result % 2;
       
        result_string[write_index++] = (result == 0) ? '0' : '1';
        
        a_index--;
        b_index--;
    }
    
    while(a_index >= 0) {
        int a_digit = a[a_index] == '1';
        int result = a_digit + carry_digit;
        carry_digit = result > 1;
        result = result % 2;
       
        result_string[write_index++] = (result == 0) ? '0' : '1';
        
        a_index--;
    }
    
    while(b_index >= 0) {
        int b_digit = b[b_index] == '1';
        int result = b_digit + carry_digit;
        carry_digit = result > 1;
        result = result % 2;
       
        result_string[write_index++] = (result == 0) ? '0' : '1';
        
        b_index--;
    }
   
    if(carry_digit) {
        result_string[write_index++] = '1';
    }
    
    int front = 0; 
    int back = write_index - 1;
    while(front < back) {
        char temp = result_string[front];
        result_string[front++] = result_string[back];
        result_string[back--] = temp;
    }
    
    return result_string;
}
