#ifndef __TERREATEAUDIO_EXCEPTIONS_HPP__
#define __TERREATEAUDIO_EXCEPTIONS_HPP__

#include <exception>

#include "defines.hpp"

namespace TerreateAudio::Exceptions {
using namespace TerreateAudio::Defines;

class TerreateAudioException : public std::exception {
private:
  Str mMessage;

public:
  TerreateAudioException(Str message) : mMessage(message) {}

  const char *what() const noexcept override { return mMessage.c_str(); }
};

class NullObjectException : public TerreateAudioException {
public:
  NullObjectException() : TerreateAudioException("Null object") {}
};

class SourceError : public TerreateAudioException {
public:
  SourceError(Str const &msg) : TerreateAudioException(msg) {}
};
} // namespace TerreateAudio::Exceptions

#endif // __TERREATEAUDIO_EXCEPTIONS_HPP__
