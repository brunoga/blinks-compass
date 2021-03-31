#include <blinklib.h>

#include "orientation.h"

void setup() {}

static byte previous_face_value_[FACE_COUNT];

static byte face_offset_;

void loop() {
  FOREACH_FACE(face) {
    if (isValueReceivedOnFaceExpired(face)) continue;

    byte face_value = getLastValueReceivedOnFace(face);

    if (face_value != previous_face_value_[face]) {
      face_offset_ = orientation::FaceOffset(face, face_value);

      previous_face_value_[face] = face_value;
    }
  }

  if (buttonDoubleClicked()) {
    face_offset_ = 0;
  }

  setColor(OFF);
  setColorOnFace(GREEN, orientation::AbsoluteLocalFace(0, face_offset_));

  FOREACH_FACE(face) {
    setValueSentOnFace(orientation::RelativeLocalFace(face, face_offset_),
                       face);
  }
}
