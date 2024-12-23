#ifndef __TERREATECORE_OBJECT_HPP__
#define __TERREATECORE_OBJECT_HPP__

#include "defines.hpp"
#include "uuid.hpp"

namespace TerreateCore::Core {
class TerreateObjectBase {
private:
  UUID mUUID;

public:
  TerreateObjectBase() : mUUID() {}
  TerreateObjectBase(UUID const &uuid) : mUUID(uuid) {}
  TerreateObjectBase(TerreateObjectBase const &other) : mUUID(UUID()) {}
  TerreateObjectBase(TerreateObjectBase &&other) noexcept
      : mUUID(std::move(other.mUUID)) {}
  virtual ~TerreateObjectBase() {}

  UUID const &GetUUID() const noexcept { return mUUID; }

  virtual bool operator==(TerreateObjectBase const &other) const {
    return mUUID == other.mUUID;
  }
  virtual bool operator!=(TerreateObjectBase const &other) const {
    return mUUID != other.mUUID;
  }
  virtual bool operator<(TerreateObjectBase const &other) const {
    return mUUID < other.mUUID;
  }
  virtual bool operator>(TerreateObjectBase const &other) const {
    return mUUID > other.mUUID;
  }
  virtual bool operator<=(TerreateObjectBase const &other) const {
    return mUUID <= other.mUUID;
  }
  virtual bool operator>=(TerreateObjectBase const &other) const {
    return mUUID >= other.mUUID;
  }

  virtual TerreateObjectBase &operator=(TerreateObjectBase const &other);
  virtual TerreateObjectBase &operator=(TerreateObjectBase &&other) noexcept;

  virtual operator Str() const { return mUUID.ToString(); }
  virtual operator TCi8 const *() const { return mUUID.Raw(); }
  virtual operator size_t() const { return mUUID.Hash(); }
  virtual operator UUID() const { return mUUID; }
  virtual operator Bool() const { return mUUID; }
};
} // namespace TerreateCore::Core

std::ostream &operator<<(std::ostream &os,
                         TerreateCore::Core::TerreateObjectBase const &obj);

#endif // __TERREATECORE_OBJECT_HPP__
