#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#define field_width 4
#define field_height 10
#define wall_width 1
#define stage_height 1
#define content_height (field_height-stage_height)
#define content_width (field_width-wall_width*2)
int field[field_height][field_width];
int content[content_height][content_width];
bool focused[content_height][content_width];

void init();;
void convert();
void show();
void fall();
void generate();

int main() {
    init();
    convert();
    generate();
    generate();
    
    
    return 0;
}

//初期化
void init() {
    // system("clear");
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
    // system("clear");
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
    bool focused_new[content_height][content_width];
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
                    // focused_new[i-1][j] = false;
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
    printf("generate1");
    show();
    sleep(1);
    convert();
    fall();
    show();
    content[0][content_width/2-1] = 1;
    content[0][content_width/2] = 1;
    focused[0][content_width/2-1] = true;
    focused[0][content_width/2] = true;
    printf("generate2");
    show();
    sleep(1);
    convert();
    fall();
    show();
    int i = 1;
    while (1)
    {
        i++;
        printf("%d\n", i);
        if (content[i+1][content_width/2-1]==1||content[i+1][content_width/2]==1||i == content_height-2)
        {
            sleep(1);
            convert();
            fall();
            show();
            for (int i = 0; i < content_height; i++)
            {
                for (int j = 0; j < content_width; j++)
                {
                    focused[i][j] = false;
                }
            }
            show();
            break;
        }
        sleep(1);
        convert();
        fall();
        show();
        
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