#include <zmq.h>
#include <stdlib.h>
#include <string.h>
#include "XPLMDataAccess.h"
#include "datarefs.h"
#include "init.h"
#include "utils/hashmap.h"
#include "protobuf/ZeroPlane.pb-c.h"

#include "airplane.h"

int plane_num = 0;

zmq_msg_t *airplane_message()
{
    void *buf;
    size_t len;
    int copied;
    float vso, vs, vfe, vno, vne;
    
    Zeroplane__Message *msg = (Zeroplane__Message *)malloc(sizeof(Zeroplane__Message));
    zeroplane__message__init(msg);
    
    Zeroplane__Airplane *airplane = (Zeroplane__Airplane *)malloc(sizeof(Zeroplane__Airplane));;
    zeroplane__airplane__init(airplane);
    
    char *callsign = (char *)malloc(40 * sizeof(char));
    copied = XPLMGetDatab(((dataref_rep_t *)hashmap_get(datarefs_map, TAILNUM))->dataref, callsign, 0, 39);
    
    vso = XPLMGetDataf(((dataref_rep_t *)hashmap_get(datarefs_map, SPEED_VSO))->dataref);
    vs = XPLMGetDataf(((dataref_rep_t *)hashmap_get(datarefs_map, SPEED_VS))->dataref);
    vfe = XPLMGetDataf(((dataref_rep_t *)hashmap_get(datarefs_map, SPEED_VFE))->dataref);
    vno = XPLMGetDataf(((dataref_rep_t *)hashmap_get(datarefs_map, SPEED_VNO))->dataref);
    vne = XPLMGetDataf(((dataref_rep_t *)hashmap_get(datarefs_map, SPEED_VNE))->dataref);

    msg->airplane = airplane;

    airplane->plane_num = plane_num;
    airplane->tailnum = callsign;
    airplane->has_vso = true;
    airplane->vso = vso;
    airplane->has_vs = true;
    airplane->vs = vs;
    airplane->has_vfe = true;
    airplane->vfe = vfe;
    airplane->has_vno = true;
    airplane->vno = vno;
    airplane->has_vne = true;
    airplane->vne = vne;

    len = zeroplane__message__get_packed_size(msg);
    buf = malloc(len);
    zeroplane__message__pack(msg, buf);
    zmq_msg_t *zmqmsg = (zmq_msg_t *)malloc(sizeof(zmq_msg_t));
    int a = zmq_msg_init_size(zmqmsg, len);
    void *data = zmq_msg_data(zmqmsg);
    memcpy(data, buf, len);

    return zmqmsg;
}