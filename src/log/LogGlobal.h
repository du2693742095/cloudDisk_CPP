/**
 * @file Global.h
 * @brief 导入导出
 * @author lemon 
 * @date 2023-04-20
 */

#ifndef __LOGGLOBAL_H__
#define __LOGGLOBAL_H__

// 实现Windows与Linux的导入导出宏
#ifdef _WIN32
    #ifdef LOG_EXPORT
        #define LOGAPI __declspec(dllexport)
    #else
        #define LOGAPI __declspec(dllimport)
    #endif
#else
    #ifdef LOG_EXPORT
        #define LOGAPI __attribute__((visibility("default")))
    #else
        #define LOGAPI
    #endif
#endif

#endif