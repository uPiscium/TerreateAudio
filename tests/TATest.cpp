#include "../includes/TerreateAudio.hpp"

#include <iostream>
using namespace TerreateAudio;
using namespace TerreateAudio::Core;

int main() {
  Initialize();
  {
    AudioContext context;
    AudioSource source;
  }
  Terminate();
  return 0;
}
