#include <stdio.h>
#include <unistd.h>
#define field_width 30
#define field_height 20
#define wall_width 3
#define stage_height 3
int field[field_height][field_width];
int content[field_height-stage_height][field_width-wall_width*2];

void init();;
void convert();
void show();

int main() {
    init();
    
    convert();
    for (int i = 0; i < 5; i++)
    {
        
        content[5+i][6]=1;
        sleep(1);
        convert();
        content[5+i][6]=0;
    }
    
    
    return 0;
}

void init() {
    system("clear");
    for (int i = 0; i < field_height-stage_height; i++)
    {
        for (int j = 0; j < field_width-wall_width*2; j++)
        {
            content[i][j] = 0;
        }
        
    }
    
    
    
}
void convert() {
    system("clear");
    for (int i = 0; i < field_height; i++)
    {
        if (i < field_height - stage_height)
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
    for (int i = 0; i < field_height-stage_height; i++)
    {
        for (int j = 0; j < field_width-wall_width*2; j++)
        {
            printf("%d", content[i][j]);
        }
        printf("\n");
    }
    
    
}