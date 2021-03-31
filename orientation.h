#ifndef ORIENTATION_H_
#define ORIENTATION_H_

#include <blinklib.h>

namespace orientation {

// Computes the local Blink face offset based on the given parameters. The
// absolute_local_face parameter is the absolute face number of the face where
// we got the relative_remote_face information from. The relative_remote_face
// parameter is the face the message was sent to in a connected Blink so it
// needs to be sent from one Blink to the other in some way (either using face
// values or datagrams). A 0 face offset indicates that the absolute and
// relative faces match.
byte FaceOffset(byte absolute_local_face, byte relative_remote_face);

// Returns the relative local face associated with the given absolute local
// face based on the given face_offset.
byte RelativeLocalFace(byte absolute_local_face, byte face_offset);

// Returns the absolute local face associated with the given relative local
// face based on the given face_offset.
byte AbsoluteLocalFace(byte relative_local_face, byte face_offset);

}  // namespace orientation

#endif