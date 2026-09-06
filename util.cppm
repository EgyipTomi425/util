export module util;

#ifdef STATISTICS
export import statistics;
#ifdef ECHTERWACHTER
export import statistics_dc;
#endif
#endif

#ifdef VOICE
export import voice;
#ifdef ECHTERWACHTER
export import voice_dc;
#endif
#endif