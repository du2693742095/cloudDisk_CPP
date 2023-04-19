#ifndef __PLUGININTERFACE_H__
#define __PLUGININTERFACE_H__


class PluginInterface {
public:
  virtual void init() = 0;
  virtual void run() = 0;
  virtual void stop() = 0;
};

#endif