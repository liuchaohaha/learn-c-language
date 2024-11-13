#include "game.h"
void game(){
    char lei[ROWS][COLS] = {};
    char show[ROWS][COLS] = {};
    Initboard(lei,ROWS,COLS,'0');
    Initboard(show,ROWS,COLS,'*');
    Displayboard(show,ROW,COL);
    setlei(lei,ROW,COL);
    //Displayboard(lei,ROW,COL);
    findlei(lei,show);



}
void menu(){
    printf("******************\n");
    printf("******1.play******\n");
    printf("******0..exit*****\n");
    printf("******************\n");
}

int main(){
    int input = 0;
    srand((unsigned int)time(NULL));//生成一个随机数，time函数无参返回，返回类型强制转换为unsigned
    do{
        menu();
        printf("请输入：\n");
        scanf("%d",&input);
        switch(input){
            case 1:
                printf ("游戏开始\n");
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                break;
    }
    }while(input);
    return 0;


}