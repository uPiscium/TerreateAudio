#ifndef __TERREATEAUDIO_HPP__
#define __TERREATEAUDIO_HPP__

#include "ALHelper.hpp"
#include "buffer.hpp"
#include "context.hpp"
#include "defines.hpp"
#include "source.hpp"

namespace TerreateAudio {
using namespace TerreateAudio::Defines;

inline Bool Initialize() noexcept { return ALHelper::Initialize(); }
inline void Terminate() noexcept { ALHelper::Terminate(); }
} // namespace TerreateAudio

#endif // __TERREATEAUDIO_HPP__
