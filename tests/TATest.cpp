#include "../includes/TerreateAudio.hpp"

#include <iostream>
using namespace TerreateAudio;
using namespace TerreateAudio::Core;

Vec<Short> GenerateSineWave(Uint const sampleRate, Uint const Hz) {
  Vec<Short> data(sampleRate);
  Float duration = 1.0f;
  for (Uint i = 0; i < sampleRate; ++i, duration *= 0.99999f) {
    data[i] = duration * (std::pow(2, 15) - 1) *
              std::sin(2.0f * 3.14159f * Hz * i / sampleRate);
  }
  return data;
}

int main() {
  Initialize();
  {
    AudioContext context;
    AudioStream stream;
    Uint idx = 0;
    Vec<AudioBuffer> buffers(4);

    Uint const sampleRate = 44100;
    Uint Hz = 440;
    Uint h = 0;
    for (Uint i = 0; i < buffers.size(); ++i, ++h) {
      Vec<Short> data =
          GenerateSineWave(sampleRate, Hz * std::pow(2, h / 12.0));
      buffers[i].SetBuffer(data, sampleRate);
      stream.QueueBuffer(buffers[i]);
    }

    stream.Play();

    while (h < 13) {
      Uint processed = stream.GetNumProcessedBuffers();
      for (Uint i = idx; i < processed; ++i, ++h) {
        stream.UnqueueBuffer(buffers[i]);
        Vec<Short> data =
            GenerateSineWave(sampleRate, Hz * std::pow(2, h / 12.0));
        buffers[i].SetBuffer(data, sampleRate);
        stream.QueueBuffer(buffers[i]);
      }
      idx += processed;
      idx %= buffers.size();
    }

    while (stream.IsPlaying()) {
    }

    for (Uint i = 0; i < buffers.size(); ++i, ++h) {
      stream.UnqueueBuffer(buffers[i]);
    }

    stream.Stop();
  }
  Terminate();
  return 0;
}
