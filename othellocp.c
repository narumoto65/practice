#include <stdio.h>

#define WIDTH 8
#define HEIGHT 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define TRUE 1
#define FALSE 0
int field[HEIGHT][WIDTH];
int TURN_CT;
/*
void something(){
    printf("helloooo");
}
*/
void reversi_print();
void reversi_initiate();
int reversi_play();
int reversi_check1();
int reversi_check2();
int main(){
    int *px, *py, bw;
    int x, y;
    /*int TURN_CT;*/
    /*
    int WIDTH = 8;
    int HEIGHT = 8;

    int EMPTY = 0;
    int BLACK = 1;
    int WHITE = 2;

    int field[HEIGHT][WIDTH];
    */
    /*
    int height  = 8;
    int width  = 8;
    int i,j;
    int field[i][j];
    for(i = 0;i<height;i++){
        for(j=0; j < width; j++){
            printf("%s","hi");
        }
        printf("\n");
    }
    */
    reversi_initiate();
    reversi_print();
    /*something();*/
    /*return 1;*/
    /*while(1){
        scanf("%d %d", px,py);
        if(reversi_play(1,px,py)){
            printf("success");
        }
        */
        while(1){
            printf("TURN:%d\n", TURN_CT);
            printf("choose where you want to put it\n");
            scanf("%d %d", &x, &y);
            
            if (TURN_CT %2 != 0 && reversi_play(x,y)==FALSE){
                reversi_print();
                continue;
            }
            if(TURN_CT %2 != 0 && reversi_play(x,y) == TRUE){
                if(reversi_check1(x,y)==TRUE){
                    field[x][y] = WHITE;
                    reversi_print();
                }
                else if(reversi_check1(x,y)==FALSE){
                    reversi_print();
                    printf("Cannot be placed. Try again.\n"); 
                }
                TURN_CT += 1;
                continue;
            }
            if(TURN_CT %2 == 0 && reversi_play(x,y)==FALSE){
                reversi_print();
                continue;
            }
            if(TURN_CT %2 == 0 && reversi_play(x,y) == TRUE){

                if(reversi_check2(x,y)==TRUE){
                    field[x][y] = BLACK;
                    reversi_print();
                }
                else if(reversi_check2(x,y)==FALSE){
                    printf("cannot be placed. Try again.\n");
                    reversi_print();
                }
                TURN_CT += 1;
                continue;
            }
        }
    }

    
void reversi_print(){
    int i,j;
    int k;
    printf("%s %d %d %d %d %d %d %d %d %s"," ", 0,1,2,3,4,5,6,7,"\n");
    for(i = 0; i < HEIGHT; i++){
        printf("%d|",i);
        for ( j = 0; j<WIDTH; j++){
            /*printf("%s"," ");*/
            
            if(field[j][i] == EMPTY){
                printf("\x1b[40m");
                printf(" |");
            }
            else if(field[j][i]==WHITE){
                printf("\x1b[41m");
                printf(" ");
                printf("\x1b[40m");
                printf("|");
            }
            else if(field[j][i] == BLACK){
                printf("\x1b[44m");
                printf(" ");
                printf("\x1b[40m");
                printf("|");
            }
            else{
                printf(" A");
            }
            
            /*printf("why");*/

        }
        printf("%s","\n");
    }
        /*printf("hi");*/
}
void reversi_initiate(){
    int i,j;
    for(i = 0; i< HEIGHT; i++){
        for(j = 0; j<WIDTH;j++){
            field[WIDTH][HEIGHT] = EMPTY;
        }
    }
    field[HEIGHT/2 -1][WIDTH/2 -1] = WHITE; /*field[3][3]*/
    field[HEIGHT/2][WIDTH/2-1] = BLACK; /*field[4][3]*/
    field[HEIGHT/2-1][WIDTH/2] = BLACK; /*field[3][4]*/
    field[HEIGHT/2][WIDTH/2]=WHITE; /*field[4][4]*/
}

int reversi_play(int x, int y){
    if(x < 0 || x >= HEIGHT){
        return FALSE;
    }
    if(y < 0 || y >= WIDTH){
        return FALSE;
    }
    if(field[x][y] != EMPTY){
        return FALSE;
    } 
    else{
        return TRUE;
    }
}
int reversi_check1(int x, int y){
    for(int i = x; i < HEIGHT; i++){
        /*
        if(field[i][y] == EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[i][y] == WHITE){
            for(int k = x; k <i; k++){
                field[k][y] = WHITE;
            }
            return TRUE;
        }
    }
    
    for(int i = x; i >=0; i--){
        /*
        if(field[i][y] == EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[i][y] == WHITE){
            for(int k = x; k > i; k--){
                field[k][y] = WHITE;
            }
            return TRUE;
        }
    }
    
    for(int i = y; i< WIDTH; i++){
        /*
        if(field[x][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x][i]==WHITE){
            for(int k=y;k<i;k++){
                field[x][k]=WHITE;
            }
            return TRUE;
        }
    }
    for(int i =y; i>=0; i--){
        /*
        if(field[x][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x][i]==WHITE){
            for(int k=y;k>i;k--){
                field[x][k]=WHITE;
            }
            return TRUE; 
        }
    }
    
    for(int i = y; i<WIDTH;i++){
        /*
        if(field[x+i-y][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x+i-y][i]==WHITE){
            for(int k=y;k<i;k++){
                field[x+k-y][k]=WHITE;
            }
            return TRUE;
        }
    }
    for(int i = y; i>= 0; i--){
        /*
        if(field[x+i-y][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x+i-y][i]==WHITE){
            for(int k=y;k>i;k--){
                field[x+k-y][k]=WHITE;
            }
            return TRUE;
        }
    }
    for(int i = x; i<WIDTH; i++){
        /*
        if(field[i][y-i+x]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[i][y-i+x]==WHITE){
            for(int k=x;k<i;k++){
                field[k][y-k+x]=WHITE;
            }
            return TRUE;
        }
    }
    for(int i =x; i>=0;i--){
        /*
        if(field[i][y-i+x]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[i][y-i+x]==WHITE){
            for(int k=x;k>i;k--){
                field[k][y-k+x]=WHITE;
            }
            return TRUE;
        }
    }
    
}
int reversi_check2(int x, int y){
    /*
    for(int i = x; i < HEIGHT; i++){
        if(field[i][y] == BLACK){
            for(int k = x; k <i; k++){
                field[k][y] = BLACK;
            }
        }
    }
    for(int i = x; i >=0; i--){
        if(field[i][y] == BLACK){
            for(int k = x; k > i; k--){
                field[k][y] = BLACK;
            }
        }
    }
    for(int i = y; i< WIDTH; i++){
        if(field[x][i]==BLACK){
            for(int k=y;k<i;k++){
                field[x][k]=BLACK;
            }
        }
    }
    for(int i =y; i>=0; i--){
        if(field[x][i]==BLACK){
            for(int k=y;k>i;k--){
                field[x][k]=BLACK;
            } 
        }
    }
    */
    for(int i = x; i < HEIGHT; i++){
        /*
        if(field[i][y] == EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[i][y] == BLACK){
            for(int k = x; k <i; k++){
                field[k][y] = BLACK;
            }
            return TRUE;
        }
    }
    for(int i = x; i >=0; i--){
        /*
        if(field[i][y] == EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[i][y] == BLACK){
            for(int k = x; k > i; k--){
                field[k][y] = BLACK;
            }
            return TRUE;
        }
    }
    for(int i = y; i< WIDTH; i++){
        /*
        if(field[x][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x][i]==BLACK){
            for(int k=y;k<i;k++){
                field[x][k]=BLACK;
            }
            return TRUE;
        }
    }
    for(int i =y; i>=0; i--){
        /*
        if(field[x][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x][i]==BLACK){
            for(int k=y;k>i;k--){
                field[x][k]=BLACK;
            } 
            return TRUE;
        }
    }
    
    for(int i = y; i<WIDTH;i++){
        /*
        if(field[x+i-y][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x+i-y][i]==BLACK){
            for(int k=y;k<i;k++){
                field[x+k-y][k]=BLACK;
            }
            return TRUE;
        }
    }
    for(int i = y; i>= 0; i--){
        /*
        if(field[x+i-y][i]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[x+i-y][i]==BLACK){
            for(int k=y;k>i;k--){
                field[x+k-y][k]=BLACK;
            }
            return TRUE;
        }
    }
    for(int i = x; i<WIDTH; i++){
        /*
        if(field[i][y-i+x]==EMPTY){
            return FALSE;
          
            break;
        }
        */
        if(field[i][y-i+x]==BLACK){
            for(int k=x;k<i;k++){
                field[k][y-k+x]=BLACK;
            }
            return TRUE;
        }
    }
    for(int i =x; i>=0;i--){
        /*
        if(field[i][y-i+x]==EMPTY){
            return FALSE;
            break;
        }
        */
        if(field[i][y-i+x]==BLACK){
            for(int k=x;k>i;k--){
                field[k][y-k+x]=BLACK;
            }
            return TRUE;
        }
    }
}    
