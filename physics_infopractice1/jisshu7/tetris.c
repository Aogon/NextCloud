#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h> //追加のシステム系のヘッダファイル
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#define field_width 10
#define field_height 20
#define wall_width 1
#define stage_height 1
#define content_height (field_height-stage_height)
#define content_width (field_width-wall_width*2)
extern int errno;
struct termios otty,ntty;
int kbhit(void); //キー入力があったかどうか確認
// int getch(void); //キー入力 1 文字読み込み
// int tinit(void); //端末の初期化
int field[field_height][field_width];
int content[content_height][content_width];
bool focused[content_height][content_width];
bool left = false;
bool right = false;
bool flag = false;

void init();
void convert();
void show();
void fall();
void set(int x);
void generate();
void judge();
int kbhit(void);

int main() {
    
    init();
    
    convert();
    for (int i = 0; i < 30; i++)
    {
        generate();
    }
    
    
    
    
    
    return 0;
}

//初期化
void init() {
    system("clear");
    // tinit();
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content[i][j] = 0;
            focused[i][j] = false;
        }
    }
}

//現在のcontentの状態を■とスペースに変換し出力する
void convert() {
    system("clear");
    for (int i = 0; i < field_height; i++)
    {
        if (i < content_height)
        {
            for (int j = 0; j < field_width; j++)
            {
                if (j < wall_width || j >= field_width - wall_width)
                {
                    field[i][j] = 1;
                }else
                {
                    field[i][j] = content[i][j-wall_width];
                }
            }
            
        }else
        {
            for (int j = 0; j < field_width; j++)
            {
                field[i][j] = 1;
            }
        } 
        
    }
    for (int i = 0; i < field_height; i++)
    {
        for (int j = 0; j < field_width; j++)
        {
            if (field[i][j] == 0)
            {
                printf("  ");
            }else if (field [i][j] == 1)
            {
                printf("■ ");
            }
        }
        printf("\n");
    }
    
}

//落下
void fall(){
    int content_new[content_height][content_width];
    int content_new2[content_height][content_width];
    bool focused_new[content_height][content_width];
    bool focused_new2[content_height][content_width];
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content_new[i][j] = content[i][j];
            focused_new[i][j] = focused[i][j];
        }
    }

    
    
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            if (focused[i][j] == true || (i != 0 && focused[i-1][j] == true))
            {
                if (i == 0)
                {
                    content_new[i][j] = 0;
                    focused_new[i][j] = false;
                }else if (content[i-1][j] == 1)
                {
                    content_new[i][j] = 1;
                    focused_new[i][j] = true;
                    
                }else if (content[i-1][j] == 0){
                    content_new[i][j] = 0;
                    focused_new[i][j] = false;
                }
            }
            
            
            
        }
    }
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            focused_new2[i][j] = focused_new[i][j];
            content_new2[i][j] = content_new[i][j];
        }
    }
    if (left)
    {
        for (int i = 0; i < content_height; i++)
        {
            for (int j = 0; j < content_width; j++)
            {
                if ((focused_new2[i][j] == true || (j+1 < content_width && focused[i][j+1] == true)))
                {
                    if (content_new2[i][j+1] == 1)
                    {
                        content_new[i][j] = 1;
                        focused_new[i][j] = true;
                        
                    }else if (content_new2[i][j+1] == 0){
                        content_new[i][j] = 0;
                        focused_new[i][j] = false;
                    }
                }
            }
        }
    }else if(right){
        for (int i = 0; i < content_height; i++)
        {
            for (int j = 0; j < content_width; j++)
            {
                if ((focused_new2[i][j] == true || (j-1 >= 0 && focused[i][j-1] == true)))
                {
                    if (content_new2[i][j-1] == 1)
                    {
                        content_new[i][j] = 1;
                        focused_new[i][j] = true;
                        
                    }else if (content_new2[i][j-1] == 0){
                        content_new[i][j] = 0;
                        focused_new[i][j] = false;
                    }
                }
            }
        }

    }
    
    
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            if (left &&( (j+1 < content_width) &&(focused_new2[i][j+1])))
            {
                content_new[i][j] = content_new2[i][j+1];
                focused_new[i][j] = focused_new2[i][j+1];
                flag = true;
                // printf("leftpart\n");
                // printf("content_new%d %d = %d, content_new2 %d %d = %d\n", i, j, content_new[i][j], i, j+1, content_new2[i][j+1]);
                
            }else if (right &&( (j-1 >= 0) &&(focused_new2[i][j-1])))
            {
                content_new[i][j] = content_new2[i][j-1];
                focused_new[i][j] = focused_new2[i][j-1];
            }
            
        }
    }
    left = false;
    right = false;
            
            
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content[i][j] = content_new[i][j];
            focused[i][j] = focused_new[i][j];
        }
        
    }
    
    
    
    
}
void generate(){
    content[0][content_width/2-1] = 1;
    content[0][content_width/2] = 1;
    focused[0][content_width/2-1] = true;
    focused[0][content_width/2] = true;
    convert();
    printf("generate1\n");
    // show();
    sleep(1);
    fall();
    convert();
    // show();
    content[0][content_width/2-1] = 1;
    content[0][content_width/2] = 1;
    focused[0][content_width/2-1] = true;
    focused[0][content_width/2] = true;
    convert();
    printf("generate2\n");
    // show();
    sleep(1);
    fall();
    convert();
    // show();
    int i = 1;
    int j = content_width/2-1;
    while (1)
    {
        i++;
        printf("%d\n", i);
        if(kbhit()!=0)
        {
            int c = getchar();
            if(c=='f')
            {
                
                if ((focused[i][j-1]!=true&&content[i][j-1] == 1)||(focused[i-1][j-1]!=true&&content[i-1][j-1] == 1)||(j-1 < 0))
                {
                    left = false;
                }else
                {
                    j--;
                    left = true;
                }
                
                
                
                // printf("left\n");
            }else if(c=='j')
            {
                if ((focused[i][j+2]!=true&&content[i][j+2] == 1)||(focused[i-1][j+2]!=true&&content[i-1][j+2] == 1)||(j+2 >= content_width))
                {
                    right = false;
                }else
                {
                    j++;
                    right = true;
                }
                
                // printf("right\n");
            }
            
            
        }
        if (content[i+2][j]==1||content[i+2][j+1]==1||i == content_height-2)
        {
            sleep(1);
            fall();
            // show();
            for (int i = 0; i < content_height; i++)
            {
                for (int j = 0; j < content_width; j++)
                {
                    focused[i][j] = false;
                }
            }
            printf("%d\n", i);
            show();
            convert();
            judge();
            break;
        }
        sleep(1);
        fall();
        convert();
        // show();
        
    }
    
}

//１列揃ったか判定
void judge()
{
    for (int i = 0; i < content_height; i++)
    {
        bool result = true;
        for (int j = 0; j < content_width; j++)
        {
            if (content[i][j] == 0)
            {
                result = false;
                continue;
            }
            
        }
        if (result)
        {
            for (int j = 0; j < content_width; j++)
            {
                content[i][j] = 0;
            }
            convert();
            sleep(1);
            set(i);
        }
    }  
}

void set(int x){
    int content_new[content_height][content_width];
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content_new[i][j] = content[i][j];
        }
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content_new[i][j] = content[i-1][j];
        }
    }
    for (int i = 0; i < content_width; i++)
    {
        content_new[0][i] = 0;
    }
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content[i][j] = content_new[i][j];
        }
    }
}
int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}






//デバッグ用にfieldとcontentの中身を表示
void show(){
    printf("field\n");
    for (int i = 0; i < field_height; i++)
    {
        for (int j = 0; j < field_width; j++)
        {
            printf("%d", field[i][j]);
        }
        printf("\n");
    }
    printf("content\n");
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            printf("%d", content[i][j]);
        }
        printf("\n");
    }
    printf("focused\n");
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            if (focused[i][j])
            {
                printf("1");
            }else
            {
                printf("0");
            }
        }
        printf("\n");
    }
    
    
}