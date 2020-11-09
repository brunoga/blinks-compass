#include "opposite_face.h"

namespace support {

static const byte opposite_face_[] = {3, 4, 5, 0, 1, 2};

byte OppositeFace(byte face) { return opposite_face_[face]; }

}  // namespace support
