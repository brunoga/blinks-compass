#ifndef ORIENTATION_H_
#define ORIENTATION_H_

#include <blinklib.h>

namespace orientation {

// Sets up the local Blink orientation based on the given parameters. The
// relative_remote_face parameter is the face the message was sent to in a
// connected Blink so it needs to be sent from one Blink to the other in some
// way (either using face values or datagrams). The absolute_local_face
// parameter is the absolute face number of the face where we got the
// relative_remote_face information from.
void Setup(byte relative_remote_face, byte absolute_local_face);

// Resets the local Blink orientation. The relative local face will be equal to
// the absolute local face.
void Reset();

// Returns the relative local face associated with the given absolute local
// face.
byte RelativeLocalFace(byte absolute_local_face);

// Returns the absolute local face associated with the given relative local
// face.
byte AbsoluteLocalFace(byte relative_local_face);

}  // namespace orientation

#endif