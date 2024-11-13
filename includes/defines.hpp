#ifndef __TERREATEAUDIO_DEFINES_HPP__
#define __TERREATEAUDIO_DEFINES_HPP__

#include <TerreateCore/TerreateCore.hpp>

#ifdef _WIN32
#include <Windows.h>
namespace TerreateAudio::Dynamic {
using namespace TerreateCore::Defines;

typedef HMODULE Module;
inline Module LoadDynamic(Str const &filename) {
  return LoadLibrary(filename.c_str());
}
inline void FreeDynamic(Module module) { FreeLibrary(module); }
template <typename T>
inline T ExtractFunction(Module module, Str const &function) {
  return reinterpret_cast<T>(GetProcAddress(module, function.c_str()));
}

static Str const DYNAMIC_LIBRARY_EXTENSION = "openal32.dll";
} // namespace TerreateAudio::Dynamic
#else
#include <dlfcn.h>
namespace TerreateAudio::Dynamic {
using namespace TerreateCore::Defines;

typedef void *Module;
inline Module LoadDynamic(Str const &filename) {
  return dlopen(filename.c_str(), RTLD_LAZY);
}
inline void FreeDynamic(Module module) { dlclose(module); }
template <typename T>
inline T ExtractFunction(Module module, Str const &function) {
  return reinterpret_cast<T>(dlsym(module, function.c_str()));
}

static Str const OPENAL_LIB_PATH = "libopenal.so";
} // namespace TerreateAudio::Dynamic
#endif

#define AL_NO_PROTOTYPES
#include <openal/al.h>
#include <openal/alc.h>

namespace TerreateAudio::Defines {
using namespace TerreateCore::Defines;
using namespace TerreateCore::Math;

// OpenAL structs
typedef ALCdevice Device;
typedef ALCcontext Context;

enum class ALError {
  NO_ERROR = AL_NO_ERROR,
  INVALID_NAME = AL_INVALID_NAME,
  INVALID_ENUM = AL_INVALID_ENUM,
  INVALID_VALUE = AL_INVALID_VALUE,
  INVALID_OPERATION = AL_INVALID_OPERATION,
  OUT_OF_MEMORY = AL_OUT_OF_MEMORY
};

enum class BufferFormat {
  MONO8 = AL_FORMAT_MONO8,
  MONO16 = AL_FORMAT_MONO16,
  STEREO8 = AL_FORMAT_STEREO8,
  STEREO16 = AL_FORMAT_STEREO16
};

enum class BufferProperty {
  FREQUENCY = AL_FREQUENCY,
  BITS = AL_BITS,
  CHANNELS = AL_CHANNELS,
  SIZE = AL_SIZE
};

enum class DistanceModel {
  NONE = AL_NONE,
  INVERSE = AL_INVERSE_DISTANCE,
  INVERSE_CLAMPED = AL_INVERSE_DISTANCE_CLAMPED,
  LINEAR = AL_LINEAR_DISTANCE,
  LINEAR_CLAMPED = AL_LINEAR_DISTANCE_CLAMPED,
  EXPONENTIAL = AL_EXPONENT_DISTANCE,
  EXPONENTIAL_CLAMPED = AL_EXPONENT_DISTANCE_CLAMPED
};

enum class SourceProperty {
  PITCH = AL_PITCH,
  GAIN = AL_GAIN,
  MIN_GAIN = AL_MIN_GAIN,
  MAX_GAIN = AL_MAX_GAIN,
  MAX_DISTANCE = AL_MAX_DISTANCE,
  ROLLOFF_FACTOR = AL_ROLLOFF_FACTOR,
  REFERENCE_DISTANCE = AL_REFERENCE_DISTANCE,
  CONE_INNER_ANGLE = AL_CONE_INNER_ANGLE,
  CONE_OUTER_ANGLE = AL_CONE_OUTER_ANGLE,
  CONE_OUTER_GAIN = AL_CONE_OUTER_GAIN,
  POSITION = AL_POSITION,
  VELOCITY = AL_VELOCITY,
  DIRECTION = AL_DIRECTION,
  SOURCE_RELATIVE = AL_SOURCE_RELATIVE,
  LOOPING = AL_LOOPING,
  BUFFER = AL_BUFFER,
  SOURCE_STATE = AL_SOURCE_STATE,
  BYTE_OFFSET = AL_BYTE_OFFSET,
  SAMPLE_OFFSET = AL_SAMPLE_OFFSET,
  SEC_OFFSET = AL_SEC_OFFSET
};

enum class SourceState {
  INITIAL = AL_INITIAL,
  PLAYING = AL_PLAYING,
  PAUSED = AL_PAUSED,
  STOPPED = AL_STOPPED
};

enum class SourceType {
  STATIC = AL_STATIC,
  STREAMING = AL_STREAMING,
  UNDETERMINED = AL_UNDETERMINED
};

// Function entry points
typedef Device *(*FPALCCREATECONTEXT)(Device *device, ALCint const *attribs);
typedef Bool (*FPALCMAKECONTEXTCURRENT)(Device *device, Context *context);
typedef void (*FPALCPROCESSCONTEXT)(Context *context);
typedef void (*FPALCSUSPENDCONTEXT)(Context *context);
typedef void (*FPALCDESTROYCONTEXT)(Context *context);
typedef Context *(*FPALCGETCURRENTCONTEXT)(void);
typedef Device *(*FPALCGETCONTEXTSDEVICE)(Context *context);

typedef Device *(*FPALCOPENDEVICE)(ALCchar const *devicename);
typedef Bool (*FPALCCLOSEDEVICE)(Device *device);

typedef void (*FPALCGETERROR)(Device *device);

typedef ALCboolean (*FPALCISEXTENSIONPRESENT)(Device *device,
                                              ALCchar const *extname);
typedef void *(*FPALCGETPROCADDRESS)(Device *device, ALCchar const *fname);
typedef ALCenum (*FPALCGETENUMVALUE)(Device *device, ALCchar const *ename);

typedef ALCchar const *(*FPALCGETSTRING)(Device *device, ALCenum param);
typedef void (*FPALCGETINTEGERV)(Device *device, ALCenum param, ALCsizei size,
                                 ALCint *data);

typedef Device *(*FPALCCAPTUREOPENDEVICE)(ALCchar const *devicename,
                                          ALCuint freq, ALCenum format,
                                          ALCsizei buffersize);
typedef Bool (*FPALCCAPTURECLOSEDEVICE)(Device *device);
typedef void (*FPALCCAPTURESTART)(Device *device);
typedef void (*FPALCCAPTURESTOP)(Device *device);
typedef void (*FPALCCAPTURESAMPLES)(Device *device, void *buffer,
                                    ALCsizei samples);

typedef void (*FPALENABLE)(ALenum capability);
typedef void (*FPALDISABLE)(ALenum capability);
typedef ALboolean (*FPALISENABLED)(ALenum capability);

typedef ALchar const *(*FPALGETSTRING)(ALenum param);
typedef void (*FPALGETBOOLEANV)(ALenum param, ALchar *data);
typedef void (*FPALGETINTEGERV)(ALenum param, ALint *data);
typedef void (*FPALGETFLOATV)(ALenum param, ALfloat *data);
typedef void (*FPALGETDOUBLEV)(ALenum param, ALdouble *data);
typedef ALboolean (*FPALGETBOOLEAN)(ALenum param);
typedef ALint (*FPALGETINTEGER)(ALenum param);
typedef ALfloat (*FPALGETFLOAT)(ALenum param);
typedef ALdouble (*FPALGETDOUBLE)(ALenum param);

typedef ALenum (*FPALGETERROR)(void);

typedef ALboolean (*FPALISEXTENSIONPRESENT)(ALchar const *extname);
typedef void *(*FPALGETPROCADDRESS)(ALchar const *fname);
typedef ALenum (*FPALGETENUMVALUE)(ALchar const *ename);

typedef void (*FPALLISTENERF)(ALenum param, ALfloat value);
typedef void (*FPALLISTENER3F)(ALenum param, ALfloat value1, ALfloat value2,
                               ALfloat value3);
typedef void (*FPALLISTENERFV)(ALenum param, ALfloat const *values);
typedef void (*FPALLISTENERI)(ALenum param, ALint value);
typedef void (*FPALLISTENER3I)(ALenum param, ALint value1, ALint value2,
                               ALint value3);
typedef void (*FPALLISTENERIV)(ALenum param, ALint const *values);

typedef void (*FPALGETLISTENERF)(ALenum param, ALfloat *value);
typedef void (*FPALGETLISTENER3F)(ALenum param, ALfloat *value1,
                                  ALfloat *value2, ALfloat *value3);
typedef void (*FPALGETLISTENERFV)(ALenum param, ALfloat *values);
typedef void (*FPALGETLISTENERI)(ALenum param, ALint *value);
typedef void (*FPALGETLISTENER3I)(ALenum param, ALint *value1, ALint *value2,
                                  ALint *value3);
typedef void (*FPALGETLISTENERIV)(ALenum param, ALint *values);

typedef void (*FPALGENSOURCES)(Int n, Uint *sources);
typedef void (*FPALDELETESOURCES)(Int n, const Uint *sources);
typedef Bool (*FPALISSOURCE)(Uint source);

typedef void (*FPALSOURCEF)(Uint source, ALenum param, ALfloat value);
typedef void (*FPALSOURCE3F)(Uint source, ALenum param, ALfloat value1,
                             ALfloat value2, ALfloat value3);
typedef void (*FPALSOURCEFV)(Uint source, ALenum param, ALfloat const *values);
typedef void (*FPALSOURCEI)(Uint source, ALenum param, ALint value);
typedef void (*FPALSOURCE3I)(Uint source, ALenum param, ALint value1,
                             ALint value2, ALint value3);
typedef void (*FPALSOURCEIV)(Uint source, ALenum param, ALint const *values);

typedef void (*FPALGETSOURCEF)(Uint source, ALenum param, ALfloat *value);
typedef void (*FPALGETSOURCE3F)(Uint source, ALenum param, ALfloat *value1,
                                ALfloat *value2, ALfloat *value3);
typedef void (*FPALGETSOURCEFV)(Uint source, ALenum param, ALfloat *values);
typedef void (*FPALGETSOURCEI)(Uint source, ALenum param, ALint *value);
typedef void (*FPALGETSOURCE3I)(Uint source, ALenum param, ALint *value1,
                                ALint *value2, ALint *value3);
typedef void (*FPALGETSOURCEIV)(Uint source, ALenum param, ALint *values);

typedef void (*FPALSOURCEPLAYV)(ALsizei ns, ALuint const *ALsids);
typedef void (*FPALSOURCESTOPV)(ALsizei ns, ALuint const *ALsids);
typedef void (*FPALSOURCEREWINDV)(ALsizei ns, ALuint const *ALsids);
typedef void (*FPALSOURCEPAUSEV)(ALsizei ns, ALuint const *ALsids);

typedef void (*FPALSOURCEPLAY)(ALuint source);
typedef void (*FPALSOURCESTOP)(ALuint source);
typedef void (*FPALSOURCEREWIND)(ALuint source);
typedef void (*FPALSOURCEPAUSE)(ALuint source);

typedef void (*FPALSOURCEQUEUEBUFFERS)(ALuint source, ALint nb,
                                       ALuint const *buffers);
typedef void (*FPALSOURCEUNQUEUEBUFFERS)(ALuint source, ALint nb,
                                         ALuint *buffers);

typedef void (*FPALGENBUFFERS)(ALsizei n, ALuint *buffers);
typedef void (*FPALDELETEBUFFERS)(ALsizei n, ALuint const *buffers);
typedef Bool (*FPALISBUFFER)(ALuint bid);
typedef void (*FPALBUFFERDATA)(ALuint buffer, ALenum format, const void *data,
                               ALsizei size, ALsizei freq);

typedef void (*FPALBUFFERF)(ALuint buffer, ALenum param, ALfloat value);
typedef void (*FPALBUFFER3F)(ALuint buffer, ALenum param, ALfloat value1,
                             ALfloat value2, ALfloat value3);
typedef void (*FPALBUFFERFV)(ALuint buffer, ALenum param,
                             ALfloat const *values);
typedef void (*FPALBUFFERI)(ALuint buffer, ALenum param, ALint value);
typedef void (*FPALBUFFER3I)(ALuint buffer, ALenum param, ALint value1,
                             ALint value2, ALint value3);
typedef void (*FPALBUFFERIV)(ALuint buffer, ALenum param, ALint const *values);

typedef void (*FPALGETBUFFERF)(ALuint buffer, ALenum param, ALfloat *value);
typedef void (*FPALGETBUFFER3F)(ALuint buffer, ALenum param, ALfloat *value1,
                                ALfloat *value2, ALfloat *value3);
typedef void (*FPALGETBUFFERFV)(ALuint buffer, ALenum param, ALfloat *values);
typedef void (*FPALGETBUFFERI)(ALuint buffer, ALenum param, ALint *value);
typedef void (*FPALGETBUFFER3I)(ALuint buffer, ALenum param, ALint *value1,
                                ALint *value2, ALint *value3);
typedef void (*FPALGETBUFFERIV)(ALuint buffer, ALenum param, ALint *values);

typedef void (*FPALDOPPLERFACTOR)(ALfloat value);
typedef void (*FPALSPEEDOFSOUND)(ALfloat value);
typedef void (*FPALDISTANCEMODEL)(ALenum value);
} // namespace TerreateAudio::Defines
#endif // __TERREATEAUDIO_DEFINES_HPP__
