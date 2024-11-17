#ifndef __TERREATEAUDIO_BUFFER_HPP__
#define __TERREATEAUDIO_BUFFER_HPP__

#include "ALHelper.hpp"
#include "alobj.hpp"
#include "defines.hpp"

namespace TerreateAudio::Core {
using namespace TerreateAudio::Defines;
using namespace TerreateAudio::AL;

class AudioBuffer : public TerreateObjectBase {
private:
  ALObject mBuffer = ALObject();
  BufferFormat mFormat = BufferFormat::MONO16;
  Vec<Short> mBufferData = Vec<Short>();

  friend class AudioStream;

  ALObject &GetBuffer() { return mBuffer; }
  ALObject const &GetBuffer() const { return mBuffer; }

public:
  AudioBuffer(BufferFormat const &format = BufferFormat::MONO16)
      : mFormat(format) {
    alGenBuffers(1, mBuffer);
  }
  ~AudioBuffer();

  Vec<Short> const &GetBufferData() const { return mBufferData; }
  void GetProperty(BufferProperty const &property, Int &value) const {
    alGetBufferi(mBuffer, static_cast<ALenum>(property), &value);
  }
  Uint GetFrequency() const;
  Uint GetBits() const;
  Uint GetChannels() const;
  Uint GetSize() const;

  void SetBuffer(Vec<Short> const &data, Size const &frequency);
  void SetBuffer(Short const *data, Ulong const &size, Ulong const &frequency);
};
} // namespace TerreateAudio::Core

#endif // __TERREATEAUDIO_BUFFER_HPP__
