
#include "PluginLoader.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

namespace Framework
{

  PluginLoader::PluginLoader() : m_dlHandle(nullptr) {}

  PluginLoader::~PluginLoader()
  {
    for (auto plugin : m_plugins)
    {
      unloadPlugins(plugin.first);
    }
  }

  void PluginLoader::loadPlugins(const std::string &pluginPath)
  {
// Load the dynamic library
#ifdef _WIN32
    m_dlHandle = LoadLibraryA(pluginPath.c_str());
#else
    m_dlHandle = dlopen(pluginPath.c_str(), RTLD_LAZY);
#endif

    if (!m_dlHandle)
    {
      // Handle error
    }

    // Get the plugin object
    PluginInterface *plugin = nullptr;
#ifdef _WIN32
    //typedef PluginInterface *(__cdecl * createPlugin_t)();
    // createPlugin_t createPlugin = (createPlugin_t)GetProcAddress(m_dlHandle, "createPlugin");
    //if (createPlugin)
    //{
    //  plugin = createPlugin();
    //}
#else
    typedef PluginInterface *(*createPlugin_t)();
    createPlugin_t createPlugin = (createPlugin_t)dlsym(m_dlHandle, "createPlugin");
    if (createPlugin)
    {
      plugin = createPlugin();
    }
#endif

    if (!plugin)
    {
      // Handle error
    }

    // m_plugins.push_back(plugin);
  }

  void PluginLoader::unloadPlugins(const std::string &pluginName)
  {
    for (auto plugin : m_plugins)
    {
      // delete plugin;
    }
    m_plugins.clear();

    if (m_dlHandle)
    {
#ifdef _WIN32
      FreeLibrary((HMODULE)m_dlHandle);
#else
      dlclose(m_dlHandle);
#endif
      m_dlHandle = nullptr;
    }
  }

  void PluginLoader::runPlugins()
  {
    for (auto plugin : m_plugins)
    {
      // plugin->init();
      // plugin->run();
      // plugin->stop();
    }
  }

} // namespace Framework