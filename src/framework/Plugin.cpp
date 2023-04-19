// Plugin.cpp
#include "PluginInterface.h"

class MyPlugin : public PluginInterface {
public:
  void init() override {
    // Initialization code
  }
  void run() override {
    // Run code
  }
  void stop() override {
    // Cleanup code
  }
};

extern "C" {
  PluginInterface* createPlugin() {
    return new MyPlugin();
  }
}
