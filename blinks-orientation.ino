#include <blinklib.h>

#include "orientation.h"

void setup() {}

static void advertise() {
  FOREACH_FACE(absolute_local_face) {
    setValueSentOnFace(orientation::RelativeLocalFace(absolute_local_face) + 1,
                       absolute_local_face);
  }
}

static void process() {
  FOREACH_FACE(absolute_local_face) {
    if (isValueReceivedOnFaceExpired(absolute_local_face)) continue;

    if (!didValueOnFaceChange(absolute_local_face)) continue;

    byte relative_remote_face = getLastValueReceivedOnFace(absolute_local_face);

    if (relative_remote_face == 0) continue;

    relative_remote_face--;

    orientation::Setup(relative_remote_face, absolute_local_face);

    break;
  }
}

void loop() {
  process();

  if (buttonDoubleClicked()) {
    orientation::Reset();
  }

  setColor(OFF);

  setColorOnFace(GREEN, orientation::AbsoluteLocalFace(0));

  advertise();
}
