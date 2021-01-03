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
#define field_width 20
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
void generate();
int kbhit(void);

int main() {
    
    init();
    
    convert();
    generate();
    generate();
    generate();
    
    
    
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
                
            }
        }
    }
    left = false;
            
            
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content[i][j] = content_new[i][j];
            focused[i][j] = focused_new[i][j];
        }
        
    }
    if (flag)
    {
        // show();
        flag = false;

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
                right = true;
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
            break;
        }
        sleep(1);
        fall();
        convert();
        // show();
        
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

//キーイベントの取得
// int kbhit(void)
// {
//  int ret;
//  fd_set rfd;
//  struct timeval timeout = {0,0};
//  FD_ZERO(&rfd);
//  FD_SET(0, &rfd); //0:stdin
//  ret = select(1, &rfd, NULL, NULL, &timeout);
//  if (ret == 1)
//  return 1;
//  else
//  return 0;
// }

// int getch(void)
// {
//  unsigned char c;
//  int n;
//  while ((n = read(0, &c, 1)) < 0 && errno == EINTR) ;
//  if (n == 0)
//  return -1;
//  else
//  return (int)c;
// }

// static void onsignal(int sig) //内部利用のシグナルハンドラ
// {
//  signal(sig, SIG_IGN);
//  switch(sig){
//  case SIGINT:
//  case SIGQUIT:
//  case SIGTERM:
//  case SIGHUP:
//  exit(1);
//  break;
//  }
// }
// int tinit(void)
// {
//     if (tcgetattr(1, &otty) < 0)
//     return -1;
//     ntty = otty;
//     ntty.c_iflag &= ~(INLCR|ICRNL|IXON|IXOFF|ISTRIP);
//     ntty.c_oflag &= ~OPOST;
//     ntty.c_lflag &= ~(ICANON|ECHO);
//     ntty.c_cc[VMIN] = 1;
//     ntty.c_cc[VTIME] = 0;
//     tcsetattr(1, TCSADRAIN, &ntty);
//     signal(SIGINT, onsignal);
//     signal(SIGQUIT, onsignal);
//     signal(SIGTERM, onsignal);
//     signal(SIGHUP, onsignal);
// }

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