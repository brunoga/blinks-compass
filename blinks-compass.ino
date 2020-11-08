#include <blinklib.h>

#include "compass.h"

void setup() {}

static void advertise() {
  FOREACH_FACE(face) { setValueSentOnFace(face + 1, face); }
  compass::ResetFaceOffset();
}

static void process() {
  FOREACH_FACE(local_face) {
    if (isValueReceivedOnFaceExpired(local_face)) continue;

    if (!didValueOnFaceChange(local_face)) continue;

    byte remote_face = getLastValueReceivedOnFace(local_face);

    if (remote_face == 0) continue;

    remote_face--;

    compass::ComputeFaceOffset(remote_face, local_face);

    FOREACH_FACE(face) {
      setValueSentOnFace(compass::GlobalFace(face) + 1, face);
    }

    break;
  }
}

void loop() {
  process();

  if (buttonDoubleClicked()) {
    advertise();
  }

  setColor(OFF);

  setColorOnFace(GREEN, compass::LocalFace(0));
}
