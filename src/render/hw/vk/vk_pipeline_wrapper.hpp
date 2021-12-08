#ifndef SKITY_SRC_RENDER_HW_VK_VK_PIPELINE_WRAPPER_HPP
#define SKITY_SRC_RENDER_HW_VK_VK_PIPELINE_WRAPPER_HPP

#include <vulkan/vulkan.h>

#include <memory>
#include <skity/gpu/gpu_context.hpp>

namespace skity {

class VKPipelineWrapper {
 public:
  VKPipelineWrapper(size_t push_const_size)
      : push_const_size_(push_const_size) {}
  virtual ~VKPipelineWrapper() = default;

  void Init(GPUVkContext* ctx, VkShaderModule vertex, VkShaderModule fragment);

  void Destroy(GPUVkContext* ctx);

  void Bind(VkCommandBuffer cmd);

  static std::unique_ptr<VKPipelineWrapper> CreateColorPipeline();

 protected:
  virtual std::vector<VkDescriptorSetLayoutBinding> GetLayoutBindings() = 0;

 private:
  size_t push_const_size_;
  VkPipelineLayout pipeline_layout_ = {};
  VkPipeline pipeline_ = {};
};

}  // namespace skity

#endif  // SKITY_SRC_RENDER_HW_VK_VK_PIPELINE_WRAPPER_HPP