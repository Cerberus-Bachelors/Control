#include "cerberus_controller/BufferManager.hpp"

BufferManager::BufferManager()
{
}

BufferManager::~BufferManager()
{
}

void BufferManager::bindBuffers(nvinfer1::ICudaEngine *engine, nvinfer1::IExecutionContext *context, const char *inputName, const char *outputName)
{

    auto inputDataType = engine->getTensorDataType(inputName);
    auto inputDims = engine->getTensorShape(inputName);

    context->setInputShape(inputName, inputDims);

    inputSize_ = 1;
    for (int i = 0; i < inputDims.nbDims; ++i)
        inputSize_ *= inputDims.d[i];

    inputElementSize_ = 0;
    switch (inputDataType)
    {
    case nvinfer1::DataType::kFLOAT:
        inputElementSize_ = sizeof(float);
        break;
    case nvinfer1::DataType::kINT32:
        inputElementSize_ = sizeof(int32_t);
        break;
    default:
        throw std::runtime_error("Unsupported data type");
    }

    cudaMalloc(&inputBuffer_, inputSize_ * inputElementSize_);

    context->setTensorAddress(inputName, inputBuffer_);

    hostInput_ = new float[inputSize_];

    // ------------------------------------------------------------------------------------------------------------- //

    auto outputType = engine->getTensorDataType(outputName);
    auto outputDims = context->getTensorShape(outputName);

    outputSize_ = 1;
    for (int i = 0; i < outputDims.nbDims; ++i)
        outputSize_ *= outputDims.d[i];

    outputElementSize_ = 0;
    switch (outputType)
    {
    case nvinfer1::DataType::kFLOAT:
        outputElementSize_ = sizeof(float);
        break;
    case nvinfer1::DataType::kHALF:
        outputElementSize_ = sizeof(uint16_t);
        break;
    case nvinfer1::DataType::kINT8:
        outputElementSize_ = sizeof(int8_t);
        break;
    case nvinfer1::DataType::kINT32:
        outputElementSize_ = sizeof(int32_t);
        break;
    case nvinfer1::DataType::kBOOL:
        outputElementSize_ = sizeof(bool);
        break;
    default:
        throw std::runtime_error("Unsupported output data type");
    }

    cudaMalloc(&outputBuffer_, outputSize_ * outputElementSize_);

    context->setTensorAddress(outputName, outputBuffer_);

    hostOutput_ = new float[outputSize_];
    //std::cout << inputSize_ << std::endl;
}

void BufferManager::updateInputBuffer(std::array<float, 45> &input)
{   
    for (size_t i = 0; i < inputSize_; ++i)
    {
        hostInput_[i] = input[i];
    }
    cudaMemcpy(inputBuffer_, hostInput_, inputSize_ * sizeof(float), cudaMemcpyHostToDevice);
}

void BufferManager::updateOutputBuffer()
{

    cudaMemcpy(
        hostOutput_,                      // Destination (CPU)
        outputBuffer_,                    // Source (GPU)
        outputSize_ * sizeof(float), // Size in bytes
        cudaMemcpyDeviceToHost            // Direction
    );
}

std::vector<double> BufferManager::getOutput() const
{
    std::vector<double> actions{hostOutput_, hostOutput_+12};
    return actions;
}