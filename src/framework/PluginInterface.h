/**
 * @file PluginLoader.cpp
 * @brief 插件接口基类
 * @author lemon
 * @date 2023-04-20
 */

#ifndef __PLUGININTERFACE_H__
#define __PLUGININTERFACE_H__

namespace Framework
{
  class PluginInterface
  {
  public:
    virtual void init() = 0;
    virtual void run() = 0;
    virtual void stop() = 0;
  };
}

#endif