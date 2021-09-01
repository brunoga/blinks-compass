#include "orientation.h"

namespace orientation {

// Per-face opposite face. This turns out to be more compact (storage-wise) than
// trying to compute the opposite face number.
static const byte opposite_face_[] = {3, 4, 5, 0, 1, 2};

static byte face_offset_;

// The face2 parameter is an int8_t because we need to pass a "negative face"
// when computing an absolute local face.
static byte __attribute__((noinline))
positive_face_distance(byte face1, int8_t face2) {
  return (face1 - face2 + FACE_COUNT) % FACE_COUNT;
}

static byte best_face_offset() {
  FOREACH_FACE(face) {
    if (isValueReceivedOnFaceExpired(face)) continue;

    if (face == 0) {
      for (byte face2 = 5; face2 > 0; face2--) {
        if (isValueReceivedOnFaceExpired(face2)) {
          return (face2 + 1) % FACE_COUNT;
        }
      }
    }

    return face;
  }

  return 0;
}

void SetFaceOffset(byte face_offset) { face_offset_ = face_offset; }

byte GetFaceOffset() { return face_offset_; }

byte ComputeFaceOffset(byte relative_remote_face, byte absolute_local_face) {
  return positive_face_distance(opposite_face_[absolute_local_face],
                                relative_remote_face);
}

byte ComputeBestFaceOffset() { return best_face_offset(); }

byte RelativeLocalFace(byte absolute_local_face) {
  return positive_face_distance(absolute_local_face, face_offset_);
}

byte AbsoluteLocalFace(byte relative_local_face) {
  return positive_face_distance(relative_local_face, -face_offset_);
}

}  // namespace orientation
