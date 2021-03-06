/* 

Vision Constants that span multiple classes and systems.
-NOTE: please only put constants here that cannot be put in one class header.

*/

#ifndef VisionDef_h_DEFINED
#define VisionDef_h_DEFINED


#include "Common.h"

#define QQVGA 0  // equivalent to kQQVGA
#define QVGA  1  // equivalent to kQVGA
#define VGA   2  // equivalent to kVGA
#ifndef NAO_IMAGE_SIZE
#  define NAO_IMAGE_SIZE VGA
#endif

#define YUV422INTER_CS  9 // equivalent to kYUV422InterlaceColorSpace
#define YUV_CS         10 // equivalent to kYUVColorSpace
#define RGB_CS         11 // equivalent to kYUVColorSpace
#ifndef NAO_COLOR_SPACE
#  define NAO_COLOR_SPACE YUV422INTER_CS
#endif

#define AIBO_IMAGE_WIDTH       208
#define AIBO_IMAGE_HEIGHT      160
#define AIBO_IMAGE_BYTE_SIZE   (AIBO_IMAGE_WIDTH * AIBO_IMAGE_HEIGHT * 3)
#define AIBO_FOV_X_DEG         56.9
#define AIBO_FOV_Y_DEG         45.2
#define NAO_FOV_X_DEG          46.4
#define NAO_FOV_Y_DEG          34.8
#define NAO_SIM_IMAGE_WIDTH    160
#define NAO_SIM_IMAGE_HEIGHT   120
#define NAO_SIM_IMAGE_BYTE_SIZE (NAO_SIM_IMAGE_WIDTH * NAO_SIM_IMAGE_HEIGHT * 3)
#define NAO_SIM_FOV_X_DEG      36
#define NAO_SIM_FOV_Y_DEG      27

#if NAO_IMAGE_SIZE == VGA
#  define NAO_IMAGE_WIDTH      640
#  define NAO_IMAGE_HEIGHT     480
#elif NAO_IMAGE_SIZE == QVGA
#  define NAO_IMAGE_WIDTH      320
#  define NAO_IMAGE_HEIGHT     240
#elif NAO_IMAGE_SIZE == QQVGA
#  define NAO_IMAGE_WIDTH      160
#  define NAO_IMAGE_HEIGHT     120
#else
#  error Undefined Nao image type
#endif

#define NAO_IMAGE_BYTE_SIZE    (NAO_IMAGE_WIDTH * NAO_IMAGE_HEIGHT * 2)


#define AIBO_ONLINE_IMAGE_ROW_OFFSET  (AIBO_IMAGE_WIDTH * 6)
#define AIBO_OFFLINE_IMAGE_ROW_OFFSET (AIBO_IMAGE_WIDTH * 3)
#define NAO_IMAGE_ROW_OFFSET          (NAO_IMAGE_WIDTH * 2)
#define NAO_SIM_IMAGE_ROW_OFFSET      (NAO_SIM_IMAGE_WIDTH * 3)


#if ROBOT(AIBO_ERS7) || ROBOT(AIBO_220) 
#  define IMAGE_WIDTH AIBO_IMAGE_WIDTH
#  define IMAGE_HEIGHT AIBO_IMAGE_HEIGHT
#  define FOV_X_DEG AIBO_FOV_X_DEG
#  define FOV_Y_DEG AIBO_FOV_Y_DEG
#  define IMAGE_BYTE_SIZE AIBO_IMAGE_BYTE_SIZE
#  define JPEG_ROW_SKIP (AIBO_IMAGE_WIDTH * 3)

#  ifndef OFFLINE
#    define IMAGE_ROW_OFFSET AIBO_ONLINE_IMAGE_ROW_OFFSET
#  else
#    define IMAGE_ROW_OFFSET AIBO_OFFLINE_IMAGE_ROW_OFFSET
#  endif

#elif ROBOT(NAO_SIM)

#  define IMAGE_WIDTH NAO_SIM_IMAGE_WIDTH
#  define IMAGE_HEIGHT NAO_SIM_IMAGE_HEIGHT
#  define FOV_X_DEG NAO_SIM_FOV_X_DEG
#  define FOV_Y_DEG NAO_SIM_FOV_Y_DEG
#  define IMAGE_BYTE_SIZE NAO_SIM_IMAGE_BYTE_SIZE

#  define IMAGE_ROW_OFFSET NAO_SIM_IMAGE_ROW_OFFSET
#  define JPEG_ROW_SKIP IMAGE_ROW_OFFSET

#elif ROBOT(NAO_RL)

#  define IMAGE_WIDTH NAO_IMAGE_WIDTH
#  define IMAGE_HEIGHT NAO_IMAGE_HEIGHT
#  define FOV_X_DEG NAO_FOV_X_DEG
#  define FOV_Y_DEG NAO_FOV_Y_DEG
#  define IMAGE_BYTE_SIZE NAO_IMAGE_BYTE_SIZE

#  define IMAGE_ROW_OFFSET NAO_IMAGE_ROW_OFFSET
#  define JPEG_ROW_SKIP IMAGE_ROW_OFFSET

#else

#  error "Undefined robot type"

#endif


#define AIBO_STYLE_IMAGE_BYTE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT * 3)

#define FOV_X RAD_OVER_DEG*FOV_X_DEG
#define FOV_Y RAD_OVER_DEG*FOV_Y_DEG

#define HALF_IMAGE_WIDTH  (IMAGE_WIDTH / 2)
#define HALF_IMAGE_HEIGHT (IMAGE_HEIGHT / 2)

// Core Image Constants
static const double MAX_BEARING = IMAGE_WIDTH / FOV_X_DEG; // relative to cam
static const double MAX_ELEVATION = IMAGE_HEIGHT / FOV_Y_DEG; // ''

// THRESHOLD COLORS
#define GREY 0
#define WHITE 1
#define GREEN 2
#define BLUE 3
#define YELLOW 4
#define ORANGE 5
#define YELLOWWHITE 6
#define BLUEGREEN 7
#define ORANGERED 8
#define ORANGEYELLOW 9
#define RED 10
#define NAVY 11
#define BLACK 12
#define PINK 13
#define SHADOW 14
#define CYAN 15
#define DARK_TURQUOISE 16
#define LAWN_GREEN 17
#define PALE_GREEN 18
#define BROWN 19
#define SEA_GREEN 20
#define ROYAL_BLUE 21
#define POWDER_BLUE 22
#define MEDIUM_PURPLE 23
#define MAROON 24
#define LIGHT_SKY_BLUE 25
#define MAGENTA 26
#define PURPLE 27


// CAMERA SETTINGS (open-r has its own constants for implementation)
// WHITE BALANCES
#define INDOOR_MODE 1
#define OUTDOOR_MODE 2
#define FL_MODE 3
// GAINS
#define LOW_GAIN 4
#define MID_GAIN 5
#define HIGH_GAIN 6
// SHUTTER SPEEDS
#define SLOW_SHUTTER 7
#define MID_SHUTTER 8
#define FAST_SHUTTER 9

// might be used for landmark recognition certainty - now used for ball certainty
#define SURE       2
#define MILDLYSURE 1
#define NOTSURE    0

// Are the heights and widths from Vision to be trusted? Used in localization
#define BOTH_SURE  3
#define HEIGHT_UNSURE  2
#define WIDTH_UNSURE  1
#define BOTH_UNSURE  0 

// Image Types for Saving Frames 
#define UNCORRECTED_IMAGE 0
#define CORRECTED_IMAGE 1

// Absolute min distance to the ball the vision system will return
#define MINVISIONDIST      3

// describe how the ball is occluded - note these all MUST be prime numbers
#define NOOCCLUSION        1   // nothing apparent occluding the ball
#define LEFTOCCLUSION      2   // something occluding the left side
#define RIGHTOCCLUSION     3   // something occluding the right side
#define TOPOCCLUSION       5   // something occluding the top
#define BOTTOMOCCLUSION    7   // bottom

// green near ball - note these all MUST be prime numbers
#define NOGREEN            1   // the ball isn't near any green
#define GREENBELOW         2   // green under the ball
#define GREENABOVE         3   // green above the ball
#define GREENLEFT          5   // green left of the ball
#define GREENRIGHT         7   // green right of the ball

// values for backstop - where to move to get best shot
#define MOVELEFT           1
#define MOVERIGHT          2
#define DONTMOVE           3
#define ALLBLOCKED         4
#define EITHERWAY          5
#define MINSHOTWIDTH       10


// Math helper functions
//
inline static double RAD2DEG(const double x) {
  return ((x) * DEG_OVER_RAD);
}
inline static double DEG2RAD(const double x) {
  return ((x) * RAD_OVER_DEG);
}
inline static double DEG2RADSQ(const double x) {
  return (x * RAD_OVER_DEG * RAD_OVER_DEG);
}
inline static long RAD2MICRO(const double x) {
  return (long) ((x) * 1000000);
}
inline static long DEG2MICRO(const double x) {
  return RAD2MICRO(DEG2RAD(x));
}
inline static double MICRO2RAD(const long x) {
  return ((x) / 1000000.0);
}
inline static double MICRO2DEG(const long x) {
  return RAD2DEG(MICRO2RAD(x));
}


#endif // VisionDef_h_DEFINED

