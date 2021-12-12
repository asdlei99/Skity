#include "src/render/hw/vk/vk_canvas.hpp"

#include <cassert>

#include "src/logging.hpp"

namespace skity {

VKCanvas::VKCanvas(Matrix mvp, uint32_t width, uint32_t height, float density)
    : HWCanvas(mvp, width, height, density) {}

void VKCanvas::OnInit(GPUContext* ctx) {
  if (ctx->type != GPUBackendType::kVulkan) {
    LOG_ERROR("GPUContext is not vulkan backend");
    assert(false);
    return;
  }

  vk_pipeline_ = std::make_unique<VKPipeline>((GPUVkContext*)ctx);
  vk_pipeline_->Init();
}

HWPipeline* VKCanvas::GetPipeline() { return vk_pipeline_.get(); }

std::unique_ptr<HWTexture> VKCanvas::GenerateTexture() {
  return std::unique_ptr<HWTexture>();
}

std::unique_ptr<HWFontTexture> VKCanvas::GenerateFontTexture(
    Typeface* typeface) {
  return std::unique_ptr<HWFontTexture>();
}

}  // namespace skity