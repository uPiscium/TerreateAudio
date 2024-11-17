#include "../includes/context.hpp"
#include "../includes/exceptions.hpp"

#include <iostream>

namespace TerreateAudio::Core {
using namespace TerreateAudio::Defines;

AudioContext::AudioContext() {
  mDevice = alcOpenDevice(nullptr);
  if (!mDevice) {
    throw Exceptions::TerreateAudioException("Failed to open device");
  }

  mContext = alcCreateContext(mDevice, nullptr);
  if (!mContext) {
    alcCloseDevice(mDevice);
    throw Exceptions::TerreateAudioException("Failed to create context");
  }

  this->SetCurrent();
}

AudioContext::~AudioContext() {
  alcMakeContextCurrent(nullptr);
  if (mContext) {
    alcDestroyContext(mContext);
  }
  if (mDevice) {
    alcCloseDevice(mDevice);
  }
}
} // namespace TerreateAudio::Core
