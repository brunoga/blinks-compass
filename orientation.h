#ifndef ORIENTATION_H_
#define ORIENTATION_H_

// Global orientation support for Blinks. This enables to concept of relative
// face numbers that would "point" in the same direction on all Blinks in a
// cluster no matter what is the Blink orientation in relation to its absolute
// face numbers.

#include <blinklib.h>

namespace orientation {

// Sets up the local Blink orientation based on the given face offset.
void Setup(byte face_offset);

// Returns the current face offset.
byte FaceOffset();

// Returns what would be the face offset associated with the given parameters.
// The relative_remote_face parameter is the face the message was sent to in a
// connected Blink so it needs to be sent from one Blink to the other in some
// way (either using face values or datagrams). The absolute_local_face
// parameter is the absolute face number of the face where we got the
// relative_remote_face information from. This does not change the current
// orientation.
byte ComputeFaceOffset(byte relative_remote_face, byte absolute_local_face);

// Same as above but tries to determine what is the best orientation
// independently of any information from remote faces being available. It
// determines that based on the currently connected faces. This does not change
// the current orientation.
byte ComputeBestFaceOffset();

// Returns the relative local face associated with the given absolute local
// face.
byte RelativeLocalFace(byte absolute_local_face);

// Returns the absolute local face associated with the given relative local
// face.
byte AbsoluteLocalFace(byte relative_local_face);

}  // namespace orientation

#endif