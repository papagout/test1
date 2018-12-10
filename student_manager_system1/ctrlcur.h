#ifndef CTRLCUR_H
#define CTRLCUR_H

//上移光标
#define MOVEUP(x) printf("\033[%dA",(x))

//下移光标
#define MOVEDOWN(x) printf("\033[%dB",(x))

//左移光标
#define MOVELEFT(x) printf("\033[%dD",(x))

//右移光标
#define MOVERIGHT(x) printf("\033[%dC",(x))

//定位光标
#define MOVETO(x,y) printf("\033[%d;%dH",(x),(y))

//清屏
#define CLEAR() printf("\033[2J")

//清除从光标到行尾的内容
#define CLEAR_LINE() printf("\033[K")

//清除向上第x行
#define CLEAR_UP_LINE(x) MOVEUP(x);CLEAR_LINE()

//设置颜色
#define SET_FRONT_COLOR(color) printf("\033[%dm",(color))
#define SET_BACKGROUND_COLOR(color) printf("\033[%dm",(color))

//前景色
#define FRONT_BLACK 30
#define FRONT_RED 31
#define FRONT_GREEN 32
#define FRONT_YELLOW 33
#define FRONT_BLUE 34
#define FRONT_PURPLE 35
#define FRONT_DEEP_GREEN 36
#define FRONT_WHITE 37
 
//背景色
#define BACKGROUND_BLACK 40
#define BACKGROUND_RED 41
#define BACKGROUND_GREEN 42
#define BACKGROUND_YELLOW 43
#define BACKGROUND_BLUE 44
#define BACKGROUND_PURPLE 45
#define BACKGROUND_DEEP_GREEN 46
#define BACKGROUND_WHITE 47

#endif //CTRLCUR_H
