#ifndef DATAREFS_H_1B8551BF
#define DATAREFS_H_1B8551BF

// Lists all the XPlane datarefs we are interested in.
// At some point, we might want a more elegant way to generate this file.

// Stuff to add in the future:
//   - /sim/aircraft/limits (green arcs)
//   - /sim/cockpit/autopilot 
//   - /sim/cockpit/radios
//   - /sim/cockpit/warnings

// General Airplane Info
#define TAILNUM "pln_tailnum"
#define HAS_STALLWARN "pln_has_stallwarn"
// Ref speeds
#define SPEED_VSO "pln_spd_vso"
#define SPEED_VS "pln_spd_vs"
#define SPEED_VFE "pln_spd_vfe"
#define SPEED_VNO "pln_spd_vno"
#define SPEED_VNE "pln_spd_vne"
// Indicated date from gyro instruments
#define GYRO1_PITCH "g1_pitch"
#define GYRO1_HEADING "g1_heading"
#define GYRO1_ROLL "g1_roll"
// Cockpit stuff
#define BARO_SETTING "baro_setting"
#define COMPASS_INDICATED "compass_indic"
#define VERTICAL_SPEED "vertical_speed"

#define TURNRATE_ROLL "turnrate_roll" // Not too sure, this is flight model data


#define DATAREFS_TABLE {TAILNUM, "sim/aircraft/view/acf_tailnum"}, \
    {HAS_STALLWARN, "sim/aircraft/view/acf_has_stallwarn"}, \
    {SPEED_VSO, "sim/aircraft/view/acf_Vso"}, \
    {SPEED_VS, "sim/aircraft/view/acf_Vs"}, \
    {SPEED_VFE, "sim/aircraft/view/acf_Vfe"}, \
    {SPEED_VNO, "sim/aircraft/view/acf_Vno"}, \
    {SPEED_VNE, "sim/aircraft/view/acf_Vne"}, \
    {GYRO1_PITCH, "sim/cockpit/gyros/the_vac_ind_deg"}, \
    {GYRO1_HEADING, "sim/cockpit/gyros/psi_vac_ind_degm"}, \
    {GYRO1_ROLL, "sim/cockpit/gyros/phi_vac_ind_deg"}, \
    {BARO_SETTING, "sim/cockpit/misc/barometer_setting"}, \
    {COMPASS_INDICATED, "sim/cockpit/misc/compass_indicated"}, \
    {TURNRATE_ROLL, "sim/flightmodel/misc/turnrate_roll"}, \
    {VERTICAL_SPEED, "sim/flightmodel/position/vh_ind_fpm"}

static char *datarefs[][2] = { DATAREFS_TABLE };

#define DATAREFS_NUM (sizeof(datarefs) / sizeof(datarefs[0]))

#endif /* end of include guard: DATAREFS_H_1B8551BF */