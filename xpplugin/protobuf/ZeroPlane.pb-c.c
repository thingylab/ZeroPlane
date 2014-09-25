/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: protobuf/ZeroPlane.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "protobuf/ZeroPlane.pb-c.h"
void   zeroplane__zero_plane_msg__init
                     (Zeroplane__ZeroPlaneMsg         *message)
{
  static Zeroplane__ZeroPlaneMsg init_value = ZEROPLANE__ZERO_PLANE_MSG__INIT;
  *message = init_value;
}
size_t zeroplane__zero_plane_msg__get_packed_size
                     (const Zeroplane__ZeroPlaneMsg *message)
{
  assert(message->base.descriptor == &zeroplane__zero_plane_msg__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t zeroplane__zero_plane_msg__pack
                     (const Zeroplane__ZeroPlaneMsg *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &zeroplane__zero_plane_msg__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t zeroplane__zero_plane_msg__pack_to_buffer
                     (const Zeroplane__ZeroPlaneMsg *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &zeroplane__zero_plane_msg__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Zeroplane__ZeroPlaneMsg *
       zeroplane__zero_plane_msg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Zeroplane__ZeroPlaneMsg *)
     protobuf_c_message_unpack (&zeroplane__zero_plane_msg__descriptor,
                                allocator, len, data);
}
void   zeroplane__zero_plane_msg__free_unpacked
                     (Zeroplane__ZeroPlaneMsg *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &zeroplane__zero_plane_msg__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   zeroplane__attitude__init
                     (Zeroplane__Attitude         *message)
{
  static Zeroplane__Attitude init_value = ZEROPLANE__ATTITUDE__INIT;
  *message = init_value;
}
size_t zeroplane__attitude__get_packed_size
                     (const Zeroplane__Attitude *message)
{
  assert(message->base.descriptor == &zeroplane__attitude__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t zeroplane__attitude__pack
                     (const Zeroplane__Attitude *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &zeroplane__attitude__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t zeroplane__attitude__pack_to_buffer
                     (const Zeroplane__Attitude *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &zeroplane__attitude__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Zeroplane__Attitude *
       zeroplane__attitude__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Zeroplane__Attitude *)
     protobuf_c_message_unpack (&zeroplane__attitude__descriptor,
                                allocator, len, data);
}
void   zeroplane__attitude__free_unpacked
                     (Zeroplane__Attitude *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &zeroplane__attitude__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   zeroplane__airplane__init
                     (Zeroplane__Airplane         *message)
{
  static Zeroplane__Airplane init_value = ZEROPLANE__AIRPLANE__INIT;
  *message = init_value;
}
size_t zeroplane__airplane__get_packed_size
                     (const Zeroplane__Airplane *message)
{
  assert(message->base.descriptor == &zeroplane__airplane__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t zeroplane__airplane__pack
                     (const Zeroplane__Airplane *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &zeroplane__airplane__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t zeroplane__airplane__pack_to_buffer
                     (const Zeroplane__Airplane *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &zeroplane__airplane__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Zeroplane__Airplane *
       zeroplane__airplane__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Zeroplane__Airplane *)
     protobuf_c_message_unpack (&zeroplane__airplane__descriptor,
                                allocator, len, data);
}
void   zeroplane__airplane__free_unpacked
                     (Zeroplane__Airplane *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &zeroplane__airplane__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor zeroplane__zero_plane_msg__field_descriptors[2] =
{
  {
    "attitude",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__ZeroPlaneMsg, attitude),
    &zeroplane__attitude__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "airplane",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__ZeroPlaneMsg, airplane),
    &zeroplane__airplane__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned zeroplane__zero_plane_msg__field_indices_by_name[] = {
  1,   /* field[1] = airplane */
  0,   /* field[0] = attitude */
};
static const ProtobufCIntRange zeroplane__zero_plane_msg__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor zeroplane__zero_plane_msg__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "zeroplane.ZeroPlaneMsg",
  "ZeroPlaneMsg",
  "Zeroplane__ZeroPlaneMsg",
  "zeroplane",
  sizeof(Zeroplane__ZeroPlaneMsg),
  2,
  zeroplane__zero_plane_msg__field_descriptors,
  zeroplane__zero_plane_msg__field_indices_by_name,
  1,  zeroplane__zero_plane_msg__number_ranges,
  (ProtobufCMessageInit) zeroplane__zero_plane_msg__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor zeroplane__attitude__field_descriptors[6] =
{
  {
    "pitch",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Attitude, pitch),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "roll",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Attitude, roll),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "yaw",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Attitude, yaw),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "altitude",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Attitude, altitude),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vertical_speed",
    5,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Attitude, vertical_speed),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "heading",
    6,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Attitude, heading),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned zeroplane__attitude__field_indices_by_name[] = {
  3,   /* field[3] = altitude */
  5,   /* field[5] = heading */
  0,   /* field[0] = pitch */
  1,   /* field[1] = roll */
  4,   /* field[4] = vertical_speed */
  2,   /* field[2] = yaw */
};
static const ProtobufCIntRange zeroplane__attitude__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 6 }
};
const ProtobufCMessageDescriptor zeroplane__attitude__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "zeroplane.Attitude",
  "Attitude",
  "Zeroplane__Attitude",
  "zeroplane",
  sizeof(Zeroplane__Attitude),
  6,
  zeroplane__attitude__field_descriptors,
  zeroplane__attitude__field_indices_by_name,
  1,  zeroplane__attitude__number_ranges,
  (ProtobufCMessageInit) zeroplane__attitude__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor zeroplane__airplane__field_descriptors[8] =
{
  {
    "plane_num",
    1,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_INT32,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, plane_num),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tailnum",
    2,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, tailnum),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "has_stallwarn",
    3,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_BOOL,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, has_stallwarn),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vso",
    4,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, vso),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vs",
    5,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, vs),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vfe",
    6,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, vfe),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vno",
    7,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, vno),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "vne",
    8,
    PROTOBUF_C_LABEL_REQUIRED,
    PROTOBUF_C_TYPE_FLOAT,
    0,   /* quantifier_offset */
    offsetof(Zeroplane__Airplane, vne),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned zeroplane__airplane__field_indices_by_name[] = {
  2,   /* field[2] = has_stallwarn */
  0,   /* field[0] = plane_num */
  1,   /* field[1] = tailnum */
  5,   /* field[5] = vfe */
  7,   /* field[7] = vne */
  6,   /* field[6] = vno */
  4,   /* field[4] = vs */
  3,   /* field[3] = vso */
};
static const ProtobufCIntRange zeroplane__airplane__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 8 }
};
const ProtobufCMessageDescriptor zeroplane__airplane__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "zeroplane.Airplane",
  "Airplane",
  "Zeroplane__Airplane",
  "zeroplane",
  sizeof(Zeroplane__Airplane),
  8,
  zeroplane__airplane__field_descriptors,
  zeroplane__airplane__field_indices_by_name,
  1,  zeroplane__airplane__number_ranges,
  (ProtobufCMessageInit) zeroplane__airplane__init,
  NULL,NULL,NULL    /* reserved[123] */
};