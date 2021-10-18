#ifndef EXAMPLE_UTILS_VK_APP_HPP
#define EXAMPLE_UTILS_VK_APP_HPP

#include <memory>
#include <string>

namespace example {

class Platform;
class VkApp {
 public:
  VkApp(int32_t width, int32_t height, std::string name);
  virtual ~VkApp();

  void Run();

  int32_t ScreenWidth() const { return width_; }
  int32_t ScreenHeight() const { return height_; }

  Platform* GetPlatform() { return platform_.get(); }
  void* GetWindowHandle() { return window_; }

  void Update(float elapsed_time);

 protected:
  virtual void OnCreate() {}
  virtual void OnUpdate(float elapsed_time) {}
  virtual void OnDestroy() {}

 private:
  int32_t width_ = 0;
  int32_t height_ = 0;
  std::string window_name_;
  void* window_ = nullptr;
  std::unique_ptr<Platform> platform_;
};
}  // namespace example

#endif  // EXAMPLE_UTILS_VK_APP_HPP