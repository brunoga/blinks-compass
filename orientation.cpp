#include "orientation.h"

namespace orientation {

static const byte opposite_face_[] = {3, 4, 5, 0, 1, 2};

// The face2 parameter is an int8_t because we need to pass a "negative face"
// when computing an absolute local face.
static byte __attribute__((noinline))
positive_face_distance(byte face1, int8_t face2) {
  return (byte)(((int8_t)face1 - face2 + FACE_COUNT) % FACE_COUNT);
}

byte OppositeFace(byte face) { return opposite_face_[face]; }

byte FaceOffset(byte absolute_local_face, byte relative_remote_face) {
  // The offset is the difference beetween the face opposite to the
  // absolute_local_face and the relative_remote_face. This formula always
  // results in a positive offset.
  return positive_face_distance(OppositeFace(absolute_local_face),
                                relative_remote_face);
}

byte RelativeLocalFace(byte absolute_local_face, byte face_offset) {
  return positive_face_distance(absolute_local_face, face_offset);
}

byte AbsoluteLocalFace(byte relative_local_face, byte face_offset) {
  return positive_face_distance(relative_local_face, -face_offset);
}

}  // namespace orientation
