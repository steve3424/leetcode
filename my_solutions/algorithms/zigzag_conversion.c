char * convert(char * s, int numRows){
    unsigned int len = strlen(s);
    char* result = calloc(len + 1, sizeof(char));
    
    int write_i = 0;
    int row_to_write = 0;
    while(write_i < len) {
        
        // Each loop the read index progresses through the loop from 0.
        // A row index zigzags back an forth between 0 and numRows - 1
        // while the read index moves forward, mapping each index in the
        // original string to a row in a zigzag pattern.
        int read_i = 0;
        int row = 0;
        int row_vel = -1;
        while(read_i < len) {
            if(row == row_to_write) {
                result[write_i++] = s[read_i];
            }
            
            if(row == 0) {
                row_vel = 1;
            }
            else if(row == (numRows - 1)) {
                row_vel = -1;
            }
            
            row += row_vel;
            read_i++;
        }
        
        ++row_to_write;
    }
    
    return result;
}
