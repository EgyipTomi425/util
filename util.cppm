module;

#include <iostream>

export module util;

#ifdef STATISTICS
export import statistics;
#ifdef ECHTERWACHTER
export import statistics_dc;
#endif
export inline const int statistics_running = []
{
    std::cout << "[STATISTICS]: ON" << std::endl;
    return 1;
}();
#endif

#ifdef VOICE
export import voice;
#ifdef ECHTERWACHTER
export import voice_dc;
#endif
export inline const int voice_running = []
{
    std::cout << "[VOICE]: ON" << std::endl;
    return 1;
}();
#endif