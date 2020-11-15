#ifndef COMPASS_H_
#define COMPASS_H_

#include <blinklib.h>

namespace orientation {

// This computes the face offset used for associating an absolute local face to
// a relative global face. The remote_face parameter is the (relative) face the
// message was sent to in the connected Blink so it needs to be sent from one
// Blink to the other in some way (either using face values or datagrams). The
// local_face parameter is the (absolute) face number of the face where we got
// the remote_face information from.
void ComputeFaceOffset(byte remote_face, byte local_face);

// Resets the face offset. Relative global face will be equal to absolute local
// face.
void ResetFaceOffset();

// Returns the relative global face associated with the given absolute local
// face.
byte GlobalFace(byte face);

// Returns the absolute local face associated with the given relative global
// face.
byte LocalFace(byte global_face);

}  // namespace orientation

#endif