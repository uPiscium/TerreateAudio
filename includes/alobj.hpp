#ifndef __TERREATEAUDIO_ALOBJ_HPP__
#define __TERREATEAUDIO_ALOBJ_HPP__

#include "defines.hpp"

namespace TerreateAudio::AL {
using namespace TerreateCore::Defines;
using namespace TerreateAudio::Defines;

class ALObject {
private:
  Shared<TCu32> mObject;

public:
  ALObject() { mObject = std::make_shared<TCu32>(0); };
  explicit ALObject(TCu32 const &object) {
    mObject = std::make_shared<TCu32>(object);
  }
  ALObject(ALObject const &other) : mObject(other.mObject) {}
  ALObject(ALObject &&other) : mObject(std::move(other.mObject)) {
    other.mObject = nullptr;
  }
  ~ALObject() {}

  TCu32 *Ptr();
  TCu32 const *Ptr() const;
  TCu32 &Ref();
  TCu32 const &Ref() const;

  Uint Count() const { return mObject.use_count(); }
  void Delete();

  TCu32 operator*() const;
  ALObject &operator=(ALObject const &other);
  ALObject &operator=(ALObject &&other);
  ALObject &operator=(TCu32 const &object);

  Bool operator==(TCu32 const &object) const { return this->Ref() == object; }
  Bool operator!=(TCu32 const &object) const { return this->Ref() != object; }

  operator TCu32 *() { return this->Ptr(); }
  operator TCu32 const *() const { return this->Ptr(); }
  operator TCu32 &() { return this->Ref(); }
  operator TCu32 const &() const { return this->Ref(); }
  operator Bool() const { return mObject != nullptr; }
};
} // namespace TerreateAudio::AL

#endif // __TERREATEAUDIO_ALOBJ_HPP__
