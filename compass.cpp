#include "compass.h"

#include "src/blinks-support/opposite_face.h"

namespace compass {

static byte face_offset_;

// The face2 parameter is an int8_t because we need to pass a "negative face"
// when computing an absolute local face.
static byte __attribute__((noinline))
positive_face_distance(byte face1, int8_t face2) {
  return (face1 - face2 + FACE_COUNT) % FACE_COUNT;
}

void ComputeFaceOffset(byte remote_face, byte local_face) {
  // The offset is the difference beetween the opposite face to the local_face
  // and the remote_face. This formula always results in a positive offset.
  face_offset_ =
      positive_face_distance(support::OppositeFace(local_face), remote_face);
}

void ResetFaceOffset() { face_offset_ = 0; }

byte GlobalFace(byte local_face) {
  return positive_face_distance(local_face, face_offset_);
}

byte LocalFace(byte global_face) {
  // We cheat here a bit and pass a negative face offset so that we can reuse
  // the positive_face_distance() function.
  return positive_face_distance(global_face, -face_offset_);
}

}  // namespace compass
