/*******************************************************************
 *   > File Name: helloworld.c
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年07月06日 星期五 14时27分58秒
 ******************************************************************/

#include <stdio.h>
#include "debug.h"

int main(int argc, char* argv[])
{
    printf("Date :"GREEN"%s"NONE", Time :"GREEN"%s"NONE"\n",__DATE__,__TIME__);
    printf("FILE :"GREEN"%s"NONE", FUNC :"GREEN"%s"NONE", LINE :"GREEN"%d"NONE"\n",__FILE__,__func__,__LINE__);

    printf(GREEN"Hello world! "RED"This is my first openwrt program !\n"NONE);
    printf(GREEN"你好! ^o^\n"NONE);
    printf(GREEN"--------ByFly\n"NONE);

    return 0;
}
