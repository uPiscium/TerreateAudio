#include "../includes/alobj.hpp"
#include "../includes/exceptions.hpp"

namespace TerreateAudio::AL {
TCu32 *ALObject::Ptr() {
  if (mObject == nullptr) {
    throw Exceptions::NullObjectException();
  }
  return mObject.get();
}

TCu32 const *ALObject::Ptr() const {
  if (mObject == nullptr) {
    throw Exceptions::NullObjectException();
  }
  return mObject.get();
}

TCu32 &ALObject::Ref() {
  if (mObject == nullptr) {
    throw Exceptions::NullObjectException();
  }
  return *mObject;
}

TCu32 const &ALObject::Ref() const {
  if (mObject == nullptr) {
    throw Exceptions::NullObjectException();
  }
  return *mObject;
}

void ALObject::Delete() {
  if (mObject != nullptr) {
    mObject = nullptr;
  }
}

ALObject &ALObject::operator=(ALObject const &other) {
  mObject = other.mObject;
  return *this;
}

ALObject &ALObject::operator=(ALObject &&other) {
  mObject = std::move(other.mObject);
  other.mObject = nullptr;
  return *this;
}

ALObject &ALObject::operator=(TCu32 const &other) {
  mObject = std::make_shared<TCu32>(other);
  return *this;
}
} // namespace TerreateAudio::AL
