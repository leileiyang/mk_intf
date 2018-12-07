#ifndef DEPEND_STRUCT_HH_
#define DEPEND_STRUCT_HH_

#define LINELEN 255

// The below three macro define are from machinekit/src/emc/nml_intf/emcglb.h
#define EMC_AXIS_MAX 9
#define EMC_MAX_DIO 128
#define EMC_MAX_AIO 64

// The below three macro define are from machinekit/src/emc/rs274ngc/Inter_base.hh"
#define ACTIVE_G_CODES 16
#define ACTIVE_M_CODES 10
#define ACTIVE_SETTINGS 3

// Steal from machinekit/src/emc/nml_intf/emcglb.h
extern char emc_nmlfile[LINELEN];
extern int emc_debug;

// This rest of the file is from machinekit/src/emc/task/nml_intf/canon.hh

#define OFF 0
#define ON 1

typedef struct {          /* type for NURBS control points */
      double X,
             Y,
             W;
      } CONTROL_POINT;

typedef struct {
      double X,
             Y;
      } PLANE_POINT;


typedef int CANON_PLANE;
#define CANON_PLANE_XY 1
#define CANON_PLANE_YZ 2
#define CANON_PLANE_XZ 3
#define CANON_PLANE_UV 4
#define CANON_PLANE_VW 5
#define CANON_PLANE_UW 6

typedef int CANON_UNITS;
#define CANON_UNITS_INCHES 1
#define CANON_UNITS_MM 2
#define CANON_UNITS_CM 3

typedef int CANON_MOTION_MODE;
#define CANON_EXACT_STOP 1
#define CANON_EXACT_PATH 2
#define CANON_CONTINUOUS 3

typedef int CANON_SPEED_FEED_MODE;
#define CANON_SYNCHED 1
#define CANON_INDEPENDENT 2

typedef int CANON_DIRECTION;
#define CANON_STOPPED 1
#define CANON_CLOCKWISE 2
#define CANON_COUNTERCLOCKWISE 3

typedef int CANON_FEED_REFERENCE;
#define CANON_WORKPIECE 1
#define CANON_XYZ 2

typedef int CANON_SIDE;
#define CANON_SIDE_RIGHT 1
#define CANON_SIDE_LEFT 2
#define CANON_SIDE_OFF 3

typedef int CANON_AXIS;
#define CANON_AXIS_X 1
#define CANON_AXIS_Y 2
#define CANON_AXIS_Z 3
#define CANON_AXIS_A 4
#define CANON_AXIS_B 5
#define CANON_AXIS_C 6
#define CANON_AXIS_U 7
#define CANON_AXIS_V 8
#define CANON_AXIS_W 9

struct CANON_VECTOR {
    CANON_VECTOR() {
    } CANON_VECTOR(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    double x, y, z;
};

#endif
