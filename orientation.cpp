#include "orientation.h"

#include "opposite_face.h"

namespace orientation {

static byte face_offset_;

// The face2 parameter is an int8_t because we need to pass a "negative face"
// when computing an absolute local face.
static byte __attribute__((noinline))
positive_face_distance(byte face1, int8_t face2) {
  return (face1 - face2 + FACE_COUNT) % FACE_COUNT;
}

void Setup(byte relative_remote_face, byte absolute_local_face) {
  // The offset is the difference beetween the opposite face to the local_face
  // and the remote_face. This formula always results in a positive offset.
  face_offset_ = positive_face_distance(
      support::OppositeFace(absolute_local_face), relative_remote_face);
}

void Reset() { face_offset_ = 0; }

byte __attribute__((noinline)) RelativeLocalFace(byte absolute_local_face) {
  return positive_face_distance(absolute_local_face, face_offset_);
}

byte AbsoluteLocalFace(byte relative_local_face) {
  return positive_face_distance(relative_local_face, -face_offset_);
}

}  // namespace orientation
