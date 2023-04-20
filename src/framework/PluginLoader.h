#ifndef __PLUGINLOADER_H__
#define __PLUGINLOADER_H__

#include <string>
#include <vector>
#include "PluginInterface.h"

class PluginLoader {
public:
  PluginLoader();
  ~PluginLoader();
  void loadPlugins(const std::string& pluginPath);
  void unloadPlugins();
  void runPlugins();
private:
  std::vector<PluginInterface*> m_plugins;
  void* m_dlHandle; // Handle to the dynamic library (cross-platform)
};

#endif