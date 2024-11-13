#include "game.h"
void Initboard(char as[ROWS][COLS] ,int row ,int col, char ad){
    for(int i =1;i<=row;i++){
        for(int j = 1;j<=col;j++){
                as[i][j] = ad;
        }
    }

}
void Displayboard(char af[ROWS][COLS],int h ,int l){
 
     for(int w = 0; w<=l;w++)
    {
       
        printf("%d",w);
    }
    printf("\n");
     for(int i =1;i<=h;i++){
        printf("%d",i);
        for(int j = 1;j<=l;j++){
                printf("%c",af[i][j]);
        }
        printf("\n");
    }
   printf("\n");

}
void setlei(char ae[ROWS][COLS],int a,int c){
    int i = 10;
    int x =0;
    int y =0;
    while(i){
        x = rand()%a + 1;
        y = rand()%c + 1;
        if(ae[x][y] == '0'){
            ae[x][y] = '1';
            i--;
        }
    }
}
int getlei(char ng[ROWS][COLS], int x,int y,int q){
    for(int i = -1;i<=1;i++){
        for(int j = -1;j<=1;j++){
            q+=ng[x+i][y+j]-'0';
        }
    }
    return q;
   // mg[x][y] = q +'0';//计算周围类的个数



}
int iswin(char cg[ROWS][COLS],int row,int col){
    int num =0;
    for(int i = 1;i<=row;i++){
        for(int j = 1;j<=col;j++){
            if(cg[i][j] == '*'|| cg[i][j] == '#' ){
                num++;
            }
        }
    }
    if(num == 10){
        return 0;
    }else{
        return 1;
    }
}
void baozha(char nc[ROWS][COLS],char mc[ROWS][COLS], int x,int y){
    int num = getlei(nc,x,y,0);
    if(num){
        mc[x][y] = num +'0';
    }else if(mc[x][y] == '*'){
        mc[x][y] = ' ';
        int i = 0;
        int j = 0;
        for(i = x-1;i<= x+1;i++){
            for(j = y-1;j<= y+1;j++){
                baozha(nc,mc,i,j);
            }
        }
    }



}
void findlei(char nb[ROWS][COLS] ,char mb[ROWS][COLS]){
    int x = 0;
    int y = 0;
    int z = 0;
    int a = 11;
    int b = 11;
    int w =71;
    while(iswin(mb,ROW,COL)){
        //char sum = '*';
        printf("选择是否标记：");
        scanf("%d",&z);
        if(z == 1){
            printf("请输入要标记的坐标");
            scanf("%d%d",&a,&b);
            if(a>=1 && a<=9 && b>=1 && b<=9){
                mb[a][b] = '#';
                Displayboard(mb,ROW,COL);
            }
        }
        printf("请输入你要排查类的坐标：");
        scanf("%d%d",&x,&y);
        if(x == a && y == b){
            printf("已经标记过了，请重新输入");
        }else{
            if(x>=1 && x<=9 && y>=1 && y<=9){
                if(nb[x][y] == '1'){
                    printf("你被炸死了\n");
                    Displayboard(nb,ROW,COL);
                    break;
                }else{
                    if (mb[x][y] != '*'){
                        printf("该坐标已经输入过了，请重新输入");
                    }else{
                        /*sum = '0';
                        sum = sum - '0';
                        for(int i = -1;i<=1;i++){
                            for(int j = -1;j<=1;j++){
                                sum +=nb[x+i][y+j]-'0';
                            }
                        }
                        mb[x][y] = sum +'0';//计算周围类的个数
                        baozha(nb,mb,sum);*/
                        baozha(nb,mb,x,y);
                        Displayboard(mb,ROW,COL);
                        
                    }
                }
            }else{
                printf("坐标输入错误请重新输入");
                }
            }
    }
    if(iswin(mb,ROW,COL) == 0){
        Displayboard(nb,ROW,COL);
        printf("恭喜你获胜\n");
    }
    
}
