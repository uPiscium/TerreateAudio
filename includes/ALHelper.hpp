#ifndef __TERREATEAUDIO_ALHELPER_HPP__
#define __TERREATEAUDIO_ALHELPER_HPP__

#include "defines.hpp"

#define alcCreateContext TerreateAudio::ALHelper::ALCCREATECONTEXT
#define alcMakeContextCurrent TerreateAudio::ALHelper::ALCMAKECONTEXTCURRENT
#define alcProcessContext TerreateAudio::ALHelper::ALCPROCESSCONTEXT
#define alcSuspendContext TerreateAudio::ALHelper::ALCSUSPENDCONTEXT
#define alcDestroyContext TerreateAudio::ALHelper::ALCDESTROYCONTEXT
#define alcGetCurrentContext TerreateAudio::ALHelper::ALCGETCURRENTCONTEXT
#define alcGetContextsDevice TerreateAudio::ALHelper::ALCGETCONTEXTSDEVICE

#define alcOpenDevice TerreateAudio::ALHelper::ALCOPENDEVICE
#define alcCloseDevice TerreateAudio::ALHelper::ALCCLOSEDEVICE

#define alcGetError TerreateAudio::ALHelper::ALCGETERROR
#define alcIsExtensionPresent TerreateAudio::ALHelper::ALCISEXTENSIONPRESENT
#define alcGetProcaddress TerreateAudio::ALHelper::ALCGETPROCADDRESS
#define alcGetEnumValue TerreateAudio::ALHelper::ALCGETENUMVALUE

#define alcGetString TerreateAudio::ALHelper::ALCGETSTRING
#define alcGetIntegerv TerreateAudio::ALHelper::ALCGETINTEGERV

#define alcCaptureOpenDevice TerreateAudio::ALHelper::ALCCAPTUREOPENDEVICE
#define alcCaptureCloseDevice TerreateAudio::ALHelper::ALCCAPTURECLOSEDEVICE
#define alcCaptureStart TerreateAudio::ALHelper::ALCCAPTURESTART
#define alcCaptureStop TerreateAudio::ALHelper::ALCCAPTURESTOP
#define alcCaptureSamples TerreateAudio::ALHelper::ALCCAPTURESAMPLES

#define alEnable TerreateAudio::ALHelper::ALENABLE
#define alDisable TerreateAudio::ALHelper::ALDISABLE
#define alIsEnabled TerreateAudio::ALHelper::ALISENABLED

#define alGetString TerreateAudio::ALHelper::ALGETSTRING
#define alGetBooleanv TerreateAudio::ALHelper::ALGETBOOLEANV
#define alGetIntegerv TerreateAudio::ALHelper::ALGETINTEGERV
#define alGetFloatv TerreateAudio::ALHelper::ALGETFLOATV
#define alGetDoublev TerreateAudio::ALHelper::ALGETDOUBLEV
#define alGetBoolean TerreateAudio::ALHelper::ALGETBOOLEAN
#define alGetInteger TerreateAudio::ALHelper::ALGETINTEGER
#define alGetFloat TerreateAudio::ALHelper::ALGETFLOAT
#define alGetDouble TerreateAudio::ALHelper::ALGETDOUBLE

#define alGetError TerreateAudio::ALHelper::ALGETERROR

#define alIsExtensionPresent TerreateAudio::ALHelper::ALISEXTENSIONPRESENT
#define alGetProcaddress TerreateAudio::ALHelper::ALGETPROCADDRESS
#define alGetEnumValue TerreateAudio::ALHelper::ALGETENUMVALUE

#define alListenerf TerreateAudio::ALHelper::ALLISTENERF
#define alListener3f TerreateAudio::ALHelper::ALLISTENER3F
#define alListenerfv TerreateAudio::ALHelper::ALLISTENERFV
#define alListeneri TerreateAudio::ALHelper::ALLISTENERI
#define alListener3i TerreateAudio::ALHelper::ALLISTENER3I
#define alListeneriv TerreateAudio::ALHelper::ALLISTENERIV

#define alGetListenerf TerreateAudio::ALHelper::ALGETLISTENERF
#define alGetListener3f TerreateAudio::ALHelper::ALGETLISTENER3F
#define alGetListenerfv TerreateAudio::ALHelper::ALGETLISTENERFV
#define alGetListeneri TerreateAudio::ALHelper::ALGETLISTENERI
#define alGetListener3i TerreateAudio::ALHelper::ALGETLISTENER3I
#define alGetListeneriv TerreateAudio::ALHelper::ALGETLISTENERIV

#define alGenSources TerreateAudio::ALHelper::ALGENSOURCES
#define alDeleteSources TerreateAudio::ALHelper::ALDELETESOURCES
#define alIsSource TerreateAudio::ALHelper::ALISSOURCE

#define alSourcef TerreateAudio::ALHelper::ALSOURCEF
#define alSource3f TerreateAudio::ALHelper::ALSOURCE3F
#define alSourcefv TerreateAudio::ALHelper::ALSOURCEFV
#define alSourcei TerreateAudio::ALHelper::ALSOURCEI
#define alSource3i TerreateAudio::ALHelper::ALSOURCE3I
#define alSourceiv TerreateAudio::ALHelper::ALSOURCEIV

#define alGetSourcef TerreateAudio::ALHelper::ALGETSOURCEF
#define alGetSource3f TerreateAudio::ALHelper::ALGETSOURCE3F
#define alGetSourcefv TerreateAudio::ALHelper::ALGETSOURCEFV
#define alGetSourcei TerreateAudio::ALHelper::ALGETSOURCEI
#define alGetSource3i TerreateAudio::ALHelper::ALGETSOURCE3I
#define alGetSourceiv TerreateAudio::ALHelper::ALGETSOURCEIV

#define alSourcePlayv TerreateAudio::ALHelper::ALSOURCEPLAYV
#define alSourceStopv TerreateAudio::ALHelper::ALSOURCESTOPV
#define alSourcereWindv TerreateAudio::ALHelper::ALSOURCEREWINDV
#define alSourcePausev TerreateAudio::ALHelper::ALSOURCEPAUSEV

#define alSourcePlay TerreateAudio::ALHelper::ALSOURCEPLAY
#define alSourceStop TerreateAudio::ALHelper::ALSOURCESTOP
#define alSourcereWind TerreateAudio::ALHelper::ALSOURCEREWIND
#define alSourcePause TerreateAudio::ALHelper::ALSOURCEPAUSE

#define alSourceQueueBuffers TerreateAudio::ALHelper::ALSOURCEQUEUEBUFFERS
#define alSourceUnqueueBuffers TerreateAudio::ALHelper::ALSOURCEUNQUEUEBUFFERS

#define alGenBuffers TerreateAudio::ALHelper::ALGENBUFFERS
#define alDeleteBuffers TerreateAudio::ALHelper::ALDELETEBUFFERS
#define alIsBuffer TerreateAudio::ALHelper::ALISBUFFER
#define alBufferData TerreateAudio::ALHelper::ALBUFFERDATA

#define alBufferf TerreateAudio::ALHelper::ALBUFFERF
#define alBuffer3f TerreateAudio::ALHelper::ALBUFFER3F
#define alBufferfv TerreateAudio::ALHelper::ALBUFFERFV
#define alBufferi TerreateAudio::ALHelper::ALBUFFERI
#define alBuffer3i TerreateAudio::ALHelper::ALBUFFER3I
#define alBufferiv TerreateAudio::ALHelper::ALBUFFERIV

#define alGetBufferf TerreateAudio::ALHelper::ALGETBUFFERF
#define alGetBuffer3f TerreateAudio::ALHelper::ALGETBUFFER3F
#define alGetBufferfv TerreateAudio::ALHelper::ALGETBUFFERFV
#define alGetBufferi TerreateAudio::ALHelper::ALGETBUFFERI
#define alGetBuffer3i TerreateAudio::ALHelper::ALGETBUFFER3I
#define alGetBufferiv TerreateAudio::ALHelper::ALGETBUFFERIV

#define alDopplerFactor TerreateAudio::ALHelper::ALDOPPLERFACTOR
#define alSpeedofSound TerreateAudio::ALHelper::ALSPEEDOFSOUND
#define alDistanceModel TerreateAudio::ALHelper::ALDISTANCEMODEL

namespace TerreateAudio::ALHelper {
using namespace TerreateCore::Defines;
using namespace TerreateAudio::Defines;

Bool Initialize();
void Terminate();

extern Dynamic::Module ALModule;

extern FPALCCREATECONTEXT ALCCREATECONTEXT;
extern FPALCMAKECONTEXTCURRENT ALCMAKECONTEXTCURRENT;
extern FPALCPROCESSCONTEXT ALCPROCESSCONTEXT;
extern FPALCSUSPENDCONTEXT ALCSUSPENDCONTEXT;
extern FPALCDESTROYCONTEXT ALCDESTROYCONTEXT;
extern FPALCGETCURRENTCONTEXT ALCGETCURRENTCONTEXT;
extern FPALCGETCONTEXTSDEVICE ALCGETCONTEXTSDEVICE;

extern FPALCOPENDEVICE ALCOPENDEVICE;
extern FPALCCLOSEDEVICE ALCCLOSEDEVICE;

extern FPALCGETERROR ALCGETERROR;

extern FPALCISEXTENSIONPRESENT ALCISEXTENSIONPRESENT;
extern FPALCGETPROCADDRESS ALCGETPROCADDRESS;
extern FPALCGETENUMVALUE ALCGETENUMVALUE;

extern FPALCGETSTRING ALCGETSTRING;
extern FPALCGETINTEGERV ALCGETINTEGERV;

extern FPALCCAPTUREOPENDEVICE ALCCAPTUREOPENDEVICE;
extern FPALCCAPTURECLOSEDEVICE ALCCAPTURECLOSEDEVICE;
extern FPALCCAPTURESTART ALCCAPTURESTART;
extern FPALCCAPTURESTOP ALCCAPTURESTOP;
extern FPALCCAPTURESAMPLES ALCCAPTURESAMPLES;

extern FPALENABLE ALENABLE;
extern FPALDISABLE ALDISABLE;
extern FPALISENABLED ALISENABLED;

extern FPALGETSTRING ALGETSTRING;
extern FPALGETBOOLEANV ALGETBOOLEANV;
extern FPALGETINTEGERV ALGETINTEGERV;
extern FPALGETFLOATV ALGETFLOATV;
extern FPALGETDOUBLEV ALGETDOUBLEV;
extern FPALGETBOOLEAN ALGETBOOLEAN;
extern FPALGETINTEGER ALGETINTEGER;
extern FPALGETFLOAT ALGETFLOAT;
extern FPALGETDOUBLE ALGETDOUBLE;

extern FPALGETERROR ALGETERROR;

extern FPALISEXTENSIONPRESENT ALISEXTENSIONPRESENT;
extern FPALGETPROCADDRESS ALGETPROCADDRESS;
extern FPALGETENUMVALUE ALGETENUMVALUE;

extern FPALLISTENERF ALLISTENERF;
extern FPALLISTENER3F ALLISTENER3F;
extern FPALLISTENERFV ALLISTENERFV;
extern FPALLISTENERI ALLISTENERI;
extern FPALLISTENER3I ALLISTENER3I;
extern FPALLISTENERIV ALLISTENERIV;

extern FPALGETLISTENERF ALGETLISTENERF;
extern FPALGETLISTENER3F ALGETLISTENER3F;
extern FPALGETLISTENERFV ALGETLISTENERFV;
extern FPALGETLISTENERI ALGETLISTENERI;
extern FPALGETLISTENER3I ALGETLISTENER3I;
extern FPALGETLISTENERIV ALGETLISTENERIV;

extern FPALGENSOURCES ALGENSOURCES;
extern FPALDELETESOURCES ALDELETESOURCES;
extern FPALISSOURCE ALISSOURCE;

extern FPALSOURCEF ALSOURCEF;
extern FPALSOURCE3F ALSOURCE3F;
extern FPALSOURCEFV ALSOURCEFV;
extern FPALSOURCEI ALSOURCEI;
extern FPALSOURCE3I ALSOURCE3I;
extern FPALSOURCEIV ALSOURCEIV;

extern FPALGETSOURCEF ALGETSOURCEF;
extern FPALGETSOURCE3F ALGETSOURCE3F;
extern FPALGETSOURCEFV ALGETSOURCEFV;
extern FPALGETSOURCEI ALGETSOURCEI;
extern FPALGETSOURCE3I ALGETSOURCE3I;
extern FPALGETSOURCEIV ALGETSOURCEIV;

extern FPALSOURCEPLAYV ALSOURCEPLAYV;
extern FPALSOURCESTOPV ALSOURCESTOPV;
extern FPALSOURCEREWINDV ALSOURCEREWINDV;
extern FPALSOURCEPAUSEV ALSOURCEPAUSEV;

extern FPALSOURCEPLAY ALSOURCEPLAY;
extern FPALSOURCESTOP ALSOURCESTOP;
extern FPALSOURCEREWIND ALSOURCEREWIND;
extern FPALSOURCEPAUSE ALSOURCEPAUSE;

extern FPALSOURCEQUEUEBUFFERS ALSOURCEQUEUEBUFFERS;
extern FPALSOURCEUNQUEUEBUFFERS ALSOURCEUNQUEUEBUFFERS;

extern FPALGENBUFFERS ALGENBUFFERS;
extern FPALDELETEBUFFERS ALDELETEBUFFERS;
extern FPALISBUFFER ALISBUFFER;
extern FPALBUFFERDATA ALBUFFERDATA;

extern FPALBUFFERF ALBUFFERF;
extern FPALBUFFER3F ALBUFFER3F;
extern FPALBUFFERFV ALBUFFERFV;
extern FPALBUFFERI ALBUFFERI;
extern FPALBUFFER3I ALBUFFER3I;
extern FPALBUFFERIV ALBUFFERIV;

extern FPALGETBUFFERF ALGETBUFFERF;
extern FPALGETBUFFER3F ALGETBUFFER3F;
extern FPALGETBUFFERFV ALGETBUFFERFV;
extern FPALGETBUFFERI ALGETBUFFERI;
extern FPALGETBUFFER3I ALGETBUFFER3I;
extern FPALGETBUFFERIV ALGETBUFFERIV;

extern FPALDOPPLERFACTOR ALDOPPLERFACTOR;
extern FPALSPEEDOFSOUND ALSPEEDOFSOUND;
extern FPALDISTANCEMODEL ALDISTANCEMODEL;
} // namespace TerreateAudio::ALHelper
#endif // __TERREATEAUDIO_ALHELPER_HPP__
