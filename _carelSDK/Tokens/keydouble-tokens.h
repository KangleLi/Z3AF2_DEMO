
#include <stdint.h>

#define CREATOR_KEYDOUBLE_SET   ((uint16_t)0xA001)
#define CREATOR_MFG_INFO      	((uint16_t)0xA002)


// Types for the tokens
#ifdef DEFINETYPES
typedef struct {
  char mfgName[32];
} mfgInfo_t;

typedef struct {
  uint8_t keyDouble_Set[32];
} keyDouble_Set_t;


#endif // DEFINETYPES

// Actual token definitions
#ifdef DEFINETOKENS
DEFINE_BASIC_TOKEN(KEYDOUBLE_SET, keyDouble_Set_t, {0})
DEFINE_BASIC_TOKEN(MFG_INFO, mfgInfo_t, {0})
#endif // DEFINETOKENS
