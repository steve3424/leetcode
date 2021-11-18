typedef struct {
    int x;
    int y;
    int word_i;
} Node;

int BOARD_HEIGHT = 0;
int BOARD_WIDTH  = 0;

inline bool Explored(Node n, Node* explored, int num_explored) {
    for(int i = 0; i < num_explored; ++i) {
        if(explored[i].x == n.x &&
           explored[i].y == n.y)
        {
            return true;
        }
    }
    
    return false;
}

inline Node GetTopNode(Node node) {
    Node res = node;
    res.y--;
    return res;
}
inline Node GetBotNode(Node node) {
    Node res = node;
    res.y++;
    return res;
}
inline Node GetLefNode(Node node) {
    Node res = node;
    res.x--;
    return res;
}
inline Node GetRigNode(Node node) {
    Node res = node;
    res.x++;
    return res;
}
inline char GetBoardChar(Node node, char** board) {
    if(0 <= node.x && node.x < BOARD_WIDTH &&
       0 <= node.y && node.y < BOARD_HEIGHT)
    {
        return board[node.y][node.x];
    }
    
    return 0;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    BOARD_HEIGHT = boardSize;
    BOARD_WIDTH  = *boardColSize;
    int word_len = strlen(word);
    
    for(int start_y = 0; start_y < boardSize; ++start_y) {
        for(int start_x = 0; start_x < *boardColSize; ++start_x) {
            
            // Only start DFS if we find the first letter
            if(board[start_y][start_x] == word[0]) {
                Node explored[36];
                
                Node stack[36];
                stack[0].x = start_x;
                stack[0].y = start_y;
                stack[0].word_i = 1;
                int stack_size = 1;
                while(stack_size > 0) {
                    Node current = stack[--stack_size];
                    explored[current.word_i - 1] = current;

                    if(current.word_i == word_len) {
                        return true;
                    }
                    
                    Node top = GetTopNode(current);
                    if(GetBoardChar(top, board) == word[current.word_i] &&
                       !Explored(top, explored, current.word_i)) 
                    {
                        top.word_i++;
                        stack[stack_size++] = top;
                    }
                    
                    Node bottom = GetBotNode(current);
                    if(GetBoardChar(bottom, board) == word[current.word_i] && 
                       !Explored(bottom, explored, current.word_i)) 
                    {
                        bottom.word_i++;
                        stack[stack_size++] = bottom;
                    }
                    
                    Node left = GetLefNode(current);
                    if(GetBoardChar(left, board) == word[current.word_i] &&
                       !Explored(left, explored, current.word_i)) 
                    {
                        left.word_i++;
                        stack[stack_size++] = left;
                    }
                    
                    Node right = GetRigNode(current);
                    if(GetBoardChar(right, board) == word[current.word_i] &&
                       !Explored(right, explored, current.word_i)) 
                    {
                        right.word_i++;
                        stack[stack_size++] = right;
                    }
                } 
            }
        }
    }
    
    return false;
}
