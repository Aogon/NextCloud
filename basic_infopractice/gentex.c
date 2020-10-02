#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

// このコメントのすぐ下の文字列 みょうじなまえ を編集して自分の名前に変更せよ。
// ただし、かな・漢字を使って入力すること。漢字入力の方法については課題の指示を参照せよ。
// このプログラムを改変するのは指定の部分だけとし他の部分は変更しないこと。
// 文字列を囲っているふたつの二重引用符 " も削除・変更しないこと。
char *nameJP = "酒井 葵生";

char date[256];
char name[1024];
char cwd[1024];
char *fname = "./EA1.tex";

#define TODAY 3
#define NAME 4
#define CWD 7
#define EXP  9
#define LNS 12

char *script[] = {
"\\documentclass{jsarticle}[12pt]",
"%%%%",
"\\title{E-A-1課題(提出用)}",
"",   // \date...
"",  //  \author...
"\\begin{document}",
"\\maketitle",
"",  // CWD
"\\[ \\sum_{n=0}^{\\infty}\\frac{1}{n!} \\approx",
"",   // "2.7..",
"\\]",
"\\end{document}",
NULL
};

char* get_date() {
    // char *now, *p;
    time_t timer;
    timer = time(NULL);
    strftime(date, 256, "%Y-%m-%d %H:%M", localtime(&timer));
    return (date);
}

#define bar(x,y) ((x)+179*(y)%65536)
int foo(char*name, char* date) {
    int d1,d2,d3,d4,d5;
    int i,c; 

    sscanf(date,"%d-%d-%d %d:%d",&d1,&d2,&d3,&d4,&d5); 

    c= bar(d1,bar(d2,bar(d3,bar(d4,d5)))); 
    for(i=0; name[i]!='\0'; i++) 
        c=bar((int)name[i],c);

    return(c);
}

void texout(char *today, char *name, char *nameJP, double e, FILE *fp) {
    int i; 
    // double f; f=pow(2.0,3.2);
    for (i=0; i<LNS; i++) {
        switch (i) {
            case TODAY: 
              fprintf(fp, "\\date{%s}\n",today); break;
            case NAME:
              fprintf(fp, "\\author{{\\small\\textsc{%s}}\\\\%s\\thanks{%04X}}\n",name,nameJP,foo(name,date)); break;
            case CWD:
              fprintf(fp, "Current Working Directory = \\verb|%s|\n", cwd); break;
            case EXP:
              fprintf(fp, "%1.11lf\n",e); break;
            default:
              fprintf(fp, "%s\n", script[i]); break;
        }
    }
}

int getname(char *name) {
    int i, jj, k, sp;
    char c, buff[256];


    fgets(buff, 256, stdin);    
    jj=0;
    for (i=0, k=0, sp=0; buff[i]!='\0'; i++) {
        c = buff[i]; 
        switch (c) {
            // case ' ': case '\t':
            //   if (!(sp!=0 || i==0)) { name[k]=c; k++; };
            //   sp=1;              break;
            case '\n': 
              buff[i]='\0'; 
              name[(sp!=0)?(k-1):k]='\0'; sp=0; 
              break;
            default:
              if (c>='0' && c<='9')
                { jj++; sp=0; name[k]=c; k++; break; }
              else  return -1;
        }
    };
    return ((jj>1)?1:-1);
}

int main(void) {
    char *today; int ok, i; FILE *fp; 
    
    getcwd(cwd,512);
    for(ok=-1; ok<0; ) {
        fprintf(stderr, "Input your student ID(学生番号) in digits (0-9): ");
        ok = getname(name);
    }; 

	  if ((fp = fopen(fname, "w")) == NULL) {
		  fprintf(stderr, "Can't open file %s. CWD = %s\n",fname,cwd);
		  exit(-1);
  	};

    putenv("LANG=C");
    today = get_date();
    putenv("LANG=en_US.UTF-8");
    texout(today, name, nameJP, exp(1.0), fp);

    fclose(fp);
    
    exit(0);
}