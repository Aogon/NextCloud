#include <stdio.h>
#include <unistd.h>
#define field_width 30
#define field_height 20
#define wall_width 3
#define stage_height 3
#define content_height (field_height-stage_height)
#define content_width (field_width-wall_width*2)
int field[field_height][field_width];
int content[content_height][content_width];

void init();;
void convert();
void show();
void fall();

int main() {
    init();
    convert();
    content[5][6]=1;
    convert();
    for (int i = 0; i < 5; i++)
    {
        sleep(1);
        fall();
        convert();
    }
    
    
    return 0;
}

//初期化
void init() {
    system("clear");
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content[i][j] = 0;
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
                printf(" ");
            }else if (field [i][j] == 1)
            {
                printf("■");
            }
        }
        printf("\n");
    }
    
}

//落下
void fall(){
    int content_new[content_height][content_width];
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            if (i == 0)
            {
                content_new[i][j] = 0;
            }else if (content[i-1][j] == 1)
            {
                content_new[i][j] = 1;
            }else
            {
                content_new[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < content_height; i++)
    {
        for (int j = 0; j < content_width; j++)
        {
            content[i][j] = content_new[i][j];
        }
        
    }
    
    
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
    
    
}