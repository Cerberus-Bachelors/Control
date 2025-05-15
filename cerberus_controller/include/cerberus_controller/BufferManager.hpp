#ifndef BUFFERMANAGER
#define BUFFERMANAGER
#include "NvInfer.h"
#include <cuda_runtime.h>
#include <iostream>
#include <cuda_runtime.h>
#include <vector>
#include <array>

class BufferManager
{
private:
  size_t inputSize_;
  size_t inputElementSize_;

  size_t outputSize_;
  size_t outputElementSize_;

  void* inputBuffer_ = nullptr;
  void* outputBuffer_ = nullptr;

  float* hostInput_;
  float* hostOutput_;

  #if NV_TENSORRT_MAJOR < 9
  static constexpr int MAX_BINDINGS = 16;
  void* bindings_[MAX_BINDINGS]{};
  #endif


public:
  void bindBuffers(nvinfer1::ICudaEngine *engine, nvinfer1::IExecutionContext *context, const char *inputName, const char *outputName);
  void updateInputBuffer(std::array<float, 48> &input);
  void updateOutputBuffer();
  void** bindings(); //ignore if using tensorrt 10
  std::vector<double> getOutput() const;
  BufferManager();
  ~BufferManager();
};

#endif