#include <stdio.h>
#include <string.h>

typedef struct {
    int row; 
    int col; 
} BoardNode;

#define SIZE 64
#define MAX_DIST 99 

BoardNode queue[SIZE];
int front = 0;
int rear = 0;

int dist[8][8];

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void enqueue(BoardNode node) {
    if (rear < SIZE) {
        queue[rear++] = node;
    }
}

BoardNode dequeue() {
    return queue[front++];
}

int is_empty() {
    return front == rear;
}

BoardNode convert_coords(char *s) {
    BoardNode node;
    node.col = s[0] - 'a';
    node.row = 8 - (s[1] - '0');
    return node;
}

int bfs(BoardNode start, BoardNode end) {
    if (start.row == end.row && start.col == end.col) {
        return 0;
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dist[i][j] = MAX_DIST;
        }
    }
    front = 0; rear = 0; 

    dist[start.row][start.col] = 0;
    enqueue(start);
    
    while (!is_empty()) {
        BoardNode current = dequeue();
        int r = current.row;
        int c = current.col;
        
        for (int i = 0; i < 8; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            
            if (new_r >= 0 && new_r < 8 && new_c >= 0 && new_c < 8 && dist[new_r][new_c] == MAX_DIST) {
                
                dist[new_r][new_c] = dist[r][c] + 1;
                
                if (new_r == end.row && new_c == end.col) {
                    return dist[new_r][new_c];
                }
                
                BoardNode next_node = {new_r, new_c};
                enqueue(next_node);
            }
        }
    }
    
    return -1;
}

int main() {
    char start_s[3], end_s[3];
    
    while (scanf("%s %s", start_s, end_s) != EOF) {
        
        BoardNode start = convert_coords(start_s);
        BoardNode end = convert_coords(end_s);
        
        int min_moves = bfs(start, end);
        
        printf("To get from %s to %s takes %d knight moves.\n", start_s, end_s, min_moves);
    }
    
    return 0;
}
