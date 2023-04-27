/**
 * @file PluginLoader.h
 * @brief 插件加载类
 * @author lemon
 * @date 2023-04-20
 */

#ifndef __PLUGINLOADER_H__
#define __PLUGINLOADER_H__

#include <string>
#include <map>
#include "PluginInterface.h"

namespace Framework
{
  class PluginLoader
  {
  public:
    PluginLoader();
    ~PluginLoader();

    /**
     * @brief 加载插件
     * @param  pluginPath 插件名
     */
    void loadPlugins(const std::string &pluginName);

    /**
     * @brief 卸载插件
     */
    void unloadPlugins(const std::string &pluginName);

    /**
     * @brief 启动插件
     */
    void runPlugins();

  private:
    std::map<std::string, PluginInterface *> m_plugins;
    void *m_dlHandle; // Handle to the dynamic library (cross-platform)
  };
} // namespace CloudDisk

#endif