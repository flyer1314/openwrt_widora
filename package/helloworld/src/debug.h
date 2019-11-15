/*******************************************************************
 *   > File Name: debug.h
 *   > Author: fly
 *   > Mail: XXXXXXXX@icode.com
 *   > Create Time: 2018年07月06日 星期五 14时31分35秒
 ******************************************************************/
#ifndef __DEBUG_H__
#define __DEBUG_H__


#include <stdio.h>


#define DISABLE         0
#define ENABLE          1
#define DEBUG_TEST      ENABLE

#define NONE    "\e[m"
#define RED     "\e[0;31m"
#define GREEN   "\e[0;32m"
#define YELLOW  "\e[0;33m"
#define BLUE    "\e[0;34m"

#define DEBUG_MSG(string...)    \
        if(DEBUG_TEST)\
{\
        printf("FILE :"BLUE"%s"NONE", FUNC :"GREEN"%s"NONE", LINE :"RED"%d"NONE" -->",\
                            __FILE__,__func__,__LINE__);\
        printf(string);\
}

#define DEBUG_WRNMSG(string...)    \
        if(DEBUG_TEST)\
{\
        printf("FILE :"BLUE"%s"NONE", FUNC :"GREEN"%s"NONE", LINE :"RED"%d"NONE" -->",\
                            __FILE__,__func__,__LINE__);\
        printf(YELLOW""string""NONE);\
}

#define DEBUG_ERRMSG(string...)    \
        if(DEBUG_TEST)\
{\
        printf("FILE :"BLUE"%s"NONE", FUNC :"GREEN"%s"NONE", LINE :"RED"%d"NONE" -->",\
                            __FILE__,__func__,__LINE__);\
        printf(RED""string""NONE);\
}


#endif
