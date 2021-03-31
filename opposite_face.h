#ifndef OPPOSITE_FACE_H_
#define OPPOSITE_FACE_H_

#include <blinklib.h>

namespace support {

// Returns the opposite face in relation to the given face. Uses a very compact
// and fast method to do that.
byte OppositeFace(byte face);

}  // namespace support

#endif
