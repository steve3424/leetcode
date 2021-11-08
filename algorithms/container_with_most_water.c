int maxArea(int* height, int heightSize){
    int max_area = 0;
    for(int i = 0; i < heightSize; ++i) {
        if(height[i] > 0) {
            int x_jump = (int)((float)max_area / (float)height[i]);
            for(int j = i + x_jump; j < heightSize; ++j) {
                int x = j - i;
                int y = height[i] < height[j] ? height[i] : height[j];
                int new_area = x*y;
                max_area = new_area > max_area ? new_area : max_area;
            }
        }
    }
    
    return max_area;
}
