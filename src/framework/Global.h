/**
 * @file Global.h
 * @brief 导入导出
 * @author lemon 
 * @date 2023-04-20
 */

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

// 实现Windows与Linux的导入导出宏
#ifdef _WIN32
    #ifdef FRAMEWORK_EXPORTS
        #define FRAMEWORKAPI __declspec(dllexport)
    #else
        #define EXPFRAMEWORKAPIORT __declspec(dllimport)
    #endif
#else
    #ifdef FRAMEWORK_EXPORTS
        #define FRAMEWORKAPI __attribute__((visibility("default")))
    #else
        #define FRAMEWORKAPI
    #endif
#endif

#endif