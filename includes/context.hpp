#ifndef __TERREATEAUDIO_CONTEXT_HPP__
#define __TERREATEAUDIO_CONTEXT_HPP__

#include "ALHelper.hpp"
#include "defines.hpp"

namespace TerreateAudio::Core {
using namespace TerreateAudio::Defines;

class AudioContext : public TerreateObjectBase {
private:
  Context *mContext = nullptr;
  Device *mDevice = nullptr;

public:
  AudioContext();
  ~AudioContext();

  void SetCurrent() const { alcMakeContextCurrent(mContext); }
};
} // namespace TerreateAudio::Core

#endif // __TERREATEAUDIO_CONTEXT_HPP__
