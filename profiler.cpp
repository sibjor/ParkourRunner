#include "profiler.hpp"

    /* From head to tail, since initialization of SDL
    measuring time between parties defined below?
    - awaits verification
    - resetting the SDL timer when preferred
    */
    bool Profiler::ProfilerSDLHead()
    {
        headSDLTimer = SDL_GetTicks();
    };
    bool Profiler::ProfilerSDLTail()
    {
        tailSDLTimer = SDL_GetTicks();
        differenceBetweenSDLTimers = tailSDLTimer - headSDLTimer;
    };
    bool Profiler::ResetSDLTimer()
    {
        headSDLTimer = 0;
        tailSDLTimer = 0;
        differenceBetweenSDLTimers = 0;
    };
    /* From head to tails, recording and measuring
    - time passed between parties
    - resetting the C timer when preferred
    */
    bool Profiler::ProfilerCHead()
    {
        headCTimer = clock();
    };
    bool Profiler::ProfilerCTail()
    {
        tailCTimer = clock();
        differenceBetweenCTimers = tailCTimer - headCTimer;
    };
    bool Profiler::ResetCTimer()
    {
        headCTimer = 0;
        tailCTimer = 0;
        differenceBetweenCTimers = 0;
    };

    /* Could be necessary,
    - today I just felt
    - somewhat pedantic finishing
    - collectively between
    - both C and SDL timers
    */
    bool Profiler::ProfilerHeadBoth(std::string comment)
    {
        ProfilerSDLHead();
        ProfilerCHead();
        std::cout << comment << "Both C and SDL timers STARTED at:\n\tC TIMER:" << headCTimer << "\n\tSDL TIMER: " << headSDLTimer << std::endl;
    }

    /* If not wanting to use destructor
    - one is given the oppurtunity to
    - call both SDL & C timer endings
    - at once
    - Use destructor when resetting
    - the timers
    */
    bool Profiler::ProfilerTailBoth(std::string comment)
    {
        ProfilerSDLTail();
        ProfilerCTail();
        std::cout << comment << "Time spent since last measure:\n\tC TIMER:" << tailCTimer << "\n\tSDL TIMER: " << tailSDLTimer << std::endl;
    }

    /* Should be implemented
    - inside destructor
    - resetting the measurements
    - to zero
    - possibly continuing
    - with object destruction
    */
    bool Profiler::ProfilerResetBoth(std::string comment)
    {
        std::cout << comment << "Both C and SDL timers RESET at:\n\tC TIMER:" << differenceBetweenCTimers << "\n\tSDL TIMER: " << differenceBetweenSDLTimers << std::endl;
        ResetCTimer();
        ResetSDLTimer();
    }

    /* Universal time functions,
    - created to hold timestamps
    - from initialization
    - untill destruction
    - of the app / program
    - proposing not to use
    - "reset" untill the
    - end of application
    */
    // The solo - universal timer
    bool Profiler::ProfilerUniHead(std::string comment)
    {
        headUniTimer = clock();
        std::cout << comment << "Universal timer STARTED at:\n\t" << headUniTimer << std::endl;
    };
    bool Profiler::ProfilerUniTail(std::string comment)
    {
        tailUnitTimer = clock();
        std::cout << comment << "Time passed since first measure:\n\tUNIVERSAL " << tailUnitTimer << std::endl;
    };
    // Only call this one in desctuctor
    // of its own dedicated object
    bool Profiler::ProfilerUniReset(std::string comment)
    {
        std::cout << comment << "Universal timer RESET at:\n\t" << "CLOCK: " << differenceBetweenUniTimers << std::endl;

        headUniTimer = 0;
        tailUnitTimer = 0;
        differenceBetweenUniTimers = 0;
    }


