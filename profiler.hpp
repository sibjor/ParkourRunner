#pragma once

#include "central.hpp"

/* class Profiler:
- Measuring time between timestamps
- from head to tail
- implementing both contructor of both timers
- and the respective destructor, as well for both timers
*/
class Profiler
{

public:
   Profiler();

   /* Destructor of profiler
   - commencing reset of
   - both C and SDL timers
   - following the universal timer
   - and finally frees memory
   */
   ~Profiler();

    /* From head to tail, measuring time between parties defined below*/
    bool ProfilerSDLHead();
    bool ProfilerSDLTail();
    bool ResetSDLTimer();

    bool ProfilerCHead();
    bool ProfilerCTail();
    bool ResetCTimer();

    bool ProfilerHeadBoth(std::string comment);
    bool ProfilerTailBoth(std::string comment);
    // Reset C and SDL timers
    bool ProfilerResetBoth(std::string comment);

    // The solo - universal timer
    bool ProfilerUniHead(std::string comment);
    bool ProfilerUniTail(std::string comment);
    // Only call this one in desctuctor
    // of its own dedicated object
    bool ProfilerUniReset(std::string comment);

private:
    /* The C time measuring parties */
    clock_t timer_start_C;
    clock_t timer_stop_C;
    unsigned int differenceBetweenCTimers = timer_stop_C - timer_start_C;

    /* The SDL time measuring parties */
    unsigned int headSDLTimer = SDL_GetTicks();
    unsigned int tailSDLTimer = SDL_GetTicks();
    unsigned int differenceBetweenSDLTimers = tailSDLTimer - headSDLTimer;

};