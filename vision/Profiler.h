
#ifndef _Profiler_h_DEFINED
#define _Profiler_h_DEFINED

#include "profileconfig.h"


#ifdef USE_TIME_PROFILING
#  define PROF_NFRAME(p)  ((p)->nextFrame())
#  define PROF_ENTER(p,c) ((p)->profiling && (p)->enterComponent(c))
#  define PROF_EXIT(p,c)  ((p)->profiling && (p)->exitComponent(c))
#else
#  define PROF_NFRAME(p)
#  define PROF_ENTER(p,c)
#  define PROF_EXIT(p,c)
#endif

enum ProfiledComponent {
  
  P_GETIMAGE = 0,
  P_TRANSFORM,
  P_THRESHOLD,
  P_FGHORIZON,
  P_RUNS,
  P_THRESHRUNS,
  P_OBJECT,
  P_LINES,
  P_VISION,
  P_LOGGING,
  P_AIBOCONNECT,
  P_TOOLCONNECT,
  P_PYUPDATE,
  P_PYRUN,
  P_PYTHON,
  P_FINAL,
};
static const int NUM_PCOMPONENTS = P_FINAL + 1;

static const char *PCOMPONENT_NAMES[] = {
  "GetImage",
  "Transform",
  "Threshold",
  "FGHorizon",
  "Runs",
  "ThreshRuns",
  "Object",
  "Lines",
  "Vision",
  "Logging",
  "AiboConnect",
  "TOOLConnect",
  "PyUpdate",
  "PyRun",
  "Python",
  "Final"
};



class Profiler {
  public:

    Profiler(long long (*f)());
    ~Profiler();

    void profileFrames(int num_frames);
    void reset();

    void printCurrent();
    void printSummary();

    bool nextFrame();

    inline bool enterComponent(ProfiledComponent c) {
      enterTime[c] = timeFunction();
      return profiling;
    }
    inline bool exitComponent(ProfiledComponent c) {
      lastTime[c] = timeFunction() - enterTime[c];
      return profiling;
    }

  public:
    bool profiling;

  private:
    long long (*timeFunction) ();

    bool start_next_frame;
    int num_profile_frames;
    int current_frame;
    long long enterTime[NUM_PCOMPONENTS];
    long long lastTime[NUM_PCOMPONENTS];
    long long sumTime[NUM_PCOMPONENTS];
};

#endif

