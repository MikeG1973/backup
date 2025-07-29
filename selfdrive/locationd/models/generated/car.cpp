#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7140700699742653522) {
   out_7140700699742653522[0] = delta_x[0] + nom_x[0];
   out_7140700699742653522[1] = delta_x[1] + nom_x[1];
   out_7140700699742653522[2] = delta_x[2] + nom_x[2];
   out_7140700699742653522[3] = delta_x[3] + nom_x[3];
   out_7140700699742653522[4] = delta_x[4] + nom_x[4];
   out_7140700699742653522[5] = delta_x[5] + nom_x[5];
   out_7140700699742653522[6] = delta_x[6] + nom_x[6];
   out_7140700699742653522[7] = delta_x[7] + nom_x[7];
   out_7140700699742653522[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2077130439032577489) {
   out_2077130439032577489[0] = -nom_x[0] + true_x[0];
   out_2077130439032577489[1] = -nom_x[1] + true_x[1];
   out_2077130439032577489[2] = -nom_x[2] + true_x[2];
   out_2077130439032577489[3] = -nom_x[3] + true_x[3];
   out_2077130439032577489[4] = -nom_x[4] + true_x[4];
   out_2077130439032577489[5] = -nom_x[5] + true_x[5];
   out_2077130439032577489[6] = -nom_x[6] + true_x[6];
   out_2077130439032577489[7] = -nom_x[7] + true_x[7];
   out_2077130439032577489[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1400617513923235535) {
   out_1400617513923235535[0] = 1.0;
   out_1400617513923235535[1] = 0.0;
   out_1400617513923235535[2] = 0.0;
   out_1400617513923235535[3] = 0.0;
   out_1400617513923235535[4] = 0.0;
   out_1400617513923235535[5] = 0.0;
   out_1400617513923235535[6] = 0.0;
   out_1400617513923235535[7] = 0.0;
   out_1400617513923235535[8] = 0.0;
   out_1400617513923235535[9] = 0.0;
   out_1400617513923235535[10] = 1.0;
   out_1400617513923235535[11] = 0.0;
   out_1400617513923235535[12] = 0.0;
   out_1400617513923235535[13] = 0.0;
   out_1400617513923235535[14] = 0.0;
   out_1400617513923235535[15] = 0.0;
   out_1400617513923235535[16] = 0.0;
   out_1400617513923235535[17] = 0.0;
   out_1400617513923235535[18] = 0.0;
   out_1400617513923235535[19] = 0.0;
   out_1400617513923235535[20] = 1.0;
   out_1400617513923235535[21] = 0.0;
   out_1400617513923235535[22] = 0.0;
   out_1400617513923235535[23] = 0.0;
   out_1400617513923235535[24] = 0.0;
   out_1400617513923235535[25] = 0.0;
   out_1400617513923235535[26] = 0.0;
   out_1400617513923235535[27] = 0.0;
   out_1400617513923235535[28] = 0.0;
   out_1400617513923235535[29] = 0.0;
   out_1400617513923235535[30] = 1.0;
   out_1400617513923235535[31] = 0.0;
   out_1400617513923235535[32] = 0.0;
   out_1400617513923235535[33] = 0.0;
   out_1400617513923235535[34] = 0.0;
   out_1400617513923235535[35] = 0.0;
   out_1400617513923235535[36] = 0.0;
   out_1400617513923235535[37] = 0.0;
   out_1400617513923235535[38] = 0.0;
   out_1400617513923235535[39] = 0.0;
   out_1400617513923235535[40] = 1.0;
   out_1400617513923235535[41] = 0.0;
   out_1400617513923235535[42] = 0.0;
   out_1400617513923235535[43] = 0.0;
   out_1400617513923235535[44] = 0.0;
   out_1400617513923235535[45] = 0.0;
   out_1400617513923235535[46] = 0.0;
   out_1400617513923235535[47] = 0.0;
   out_1400617513923235535[48] = 0.0;
   out_1400617513923235535[49] = 0.0;
   out_1400617513923235535[50] = 1.0;
   out_1400617513923235535[51] = 0.0;
   out_1400617513923235535[52] = 0.0;
   out_1400617513923235535[53] = 0.0;
   out_1400617513923235535[54] = 0.0;
   out_1400617513923235535[55] = 0.0;
   out_1400617513923235535[56] = 0.0;
   out_1400617513923235535[57] = 0.0;
   out_1400617513923235535[58] = 0.0;
   out_1400617513923235535[59] = 0.0;
   out_1400617513923235535[60] = 1.0;
   out_1400617513923235535[61] = 0.0;
   out_1400617513923235535[62] = 0.0;
   out_1400617513923235535[63] = 0.0;
   out_1400617513923235535[64] = 0.0;
   out_1400617513923235535[65] = 0.0;
   out_1400617513923235535[66] = 0.0;
   out_1400617513923235535[67] = 0.0;
   out_1400617513923235535[68] = 0.0;
   out_1400617513923235535[69] = 0.0;
   out_1400617513923235535[70] = 1.0;
   out_1400617513923235535[71] = 0.0;
   out_1400617513923235535[72] = 0.0;
   out_1400617513923235535[73] = 0.0;
   out_1400617513923235535[74] = 0.0;
   out_1400617513923235535[75] = 0.0;
   out_1400617513923235535[76] = 0.0;
   out_1400617513923235535[77] = 0.0;
   out_1400617513923235535[78] = 0.0;
   out_1400617513923235535[79] = 0.0;
   out_1400617513923235535[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6169337671586411555) {
   out_6169337671586411555[0] = state[0];
   out_6169337671586411555[1] = state[1];
   out_6169337671586411555[2] = state[2];
   out_6169337671586411555[3] = state[3];
   out_6169337671586411555[4] = state[4];
   out_6169337671586411555[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6169337671586411555[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6169337671586411555[7] = state[7];
   out_6169337671586411555[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1600017911472069397) {
   out_1600017911472069397[0] = 1;
   out_1600017911472069397[1] = 0;
   out_1600017911472069397[2] = 0;
   out_1600017911472069397[3] = 0;
   out_1600017911472069397[4] = 0;
   out_1600017911472069397[5] = 0;
   out_1600017911472069397[6] = 0;
   out_1600017911472069397[7] = 0;
   out_1600017911472069397[8] = 0;
   out_1600017911472069397[9] = 0;
   out_1600017911472069397[10] = 1;
   out_1600017911472069397[11] = 0;
   out_1600017911472069397[12] = 0;
   out_1600017911472069397[13] = 0;
   out_1600017911472069397[14] = 0;
   out_1600017911472069397[15] = 0;
   out_1600017911472069397[16] = 0;
   out_1600017911472069397[17] = 0;
   out_1600017911472069397[18] = 0;
   out_1600017911472069397[19] = 0;
   out_1600017911472069397[20] = 1;
   out_1600017911472069397[21] = 0;
   out_1600017911472069397[22] = 0;
   out_1600017911472069397[23] = 0;
   out_1600017911472069397[24] = 0;
   out_1600017911472069397[25] = 0;
   out_1600017911472069397[26] = 0;
   out_1600017911472069397[27] = 0;
   out_1600017911472069397[28] = 0;
   out_1600017911472069397[29] = 0;
   out_1600017911472069397[30] = 1;
   out_1600017911472069397[31] = 0;
   out_1600017911472069397[32] = 0;
   out_1600017911472069397[33] = 0;
   out_1600017911472069397[34] = 0;
   out_1600017911472069397[35] = 0;
   out_1600017911472069397[36] = 0;
   out_1600017911472069397[37] = 0;
   out_1600017911472069397[38] = 0;
   out_1600017911472069397[39] = 0;
   out_1600017911472069397[40] = 1;
   out_1600017911472069397[41] = 0;
   out_1600017911472069397[42] = 0;
   out_1600017911472069397[43] = 0;
   out_1600017911472069397[44] = 0;
   out_1600017911472069397[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1600017911472069397[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1600017911472069397[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1600017911472069397[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1600017911472069397[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1600017911472069397[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1600017911472069397[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1600017911472069397[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1600017911472069397[53] = -9.8000000000000007*dt;
   out_1600017911472069397[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1600017911472069397[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1600017911472069397[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1600017911472069397[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1600017911472069397[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1600017911472069397[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1600017911472069397[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1600017911472069397[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1600017911472069397[62] = 0;
   out_1600017911472069397[63] = 0;
   out_1600017911472069397[64] = 0;
   out_1600017911472069397[65] = 0;
   out_1600017911472069397[66] = 0;
   out_1600017911472069397[67] = 0;
   out_1600017911472069397[68] = 0;
   out_1600017911472069397[69] = 0;
   out_1600017911472069397[70] = 1;
   out_1600017911472069397[71] = 0;
   out_1600017911472069397[72] = 0;
   out_1600017911472069397[73] = 0;
   out_1600017911472069397[74] = 0;
   out_1600017911472069397[75] = 0;
   out_1600017911472069397[76] = 0;
   out_1600017911472069397[77] = 0;
   out_1600017911472069397[78] = 0;
   out_1600017911472069397[79] = 0;
   out_1600017911472069397[80] = 1;
}
void h_25(double *state, double *unused, double *out_8558464601117929845) {
   out_8558464601117929845[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7792570711989001702) {
   out_7792570711989001702[0] = 0;
   out_7792570711989001702[1] = 0;
   out_7792570711989001702[2] = 0;
   out_7792570711989001702[3] = 0;
   out_7792570711989001702[4] = 0;
   out_7792570711989001702[5] = 0;
   out_7792570711989001702[6] = 1;
   out_7792570711989001702[7] = 0;
   out_7792570711989001702[8] = 0;
}
void h_24(double *state, double *unused, double *out_4537363549506217184) {
   out_4537363549506217184[0] = state[4];
   out_4537363549506217184[1] = state[5];
}
void H_24(double *state, double *unused, double *out_5566862928010133140) {
   out_5566862928010133140[0] = 0;
   out_5566862928010133140[1] = 0;
   out_5566862928010133140[2] = 0;
   out_5566862928010133140[3] = 0;
   out_5566862928010133140[4] = 1;
   out_5566862928010133140[5] = 0;
   out_5566862928010133140[6] = 0;
   out_5566862928010133140[7] = 0;
   out_5566862928010133140[8] = 0;
   out_5566862928010133140[9] = 0;
   out_5566862928010133140[10] = 0;
   out_5566862928010133140[11] = 0;
   out_5566862928010133140[12] = 0;
   out_5566862928010133140[13] = 0;
   out_5566862928010133140[14] = 1;
   out_5566862928010133140[15] = 0;
   out_5566862928010133140[16] = 0;
   out_5566862928010133140[17] = 0;
}
void h_30(double *state, double *unused, double *out_9159882758731293399) {
   out_9159882758731293399[0] = state[4];
}
void H_30(double *state, double *unused, double *out_875880370497384947) {
   out_875880370497384947[0] = 0;
   out_875880370497384947[1] = 0;
   out_875880370497384947[2] = 0;
   out_875880370497384947[3] = 0;
   out_875880370497384947[4] = 1;
   out_875880370497384947[5] = 0;
   out_875880370497384947[6] = 0;
   out_875880370497384947[7] = 0;
   out_875880370497384947[8] = 0;
}
void h_26(double *state, double *unused, double *out_4285188047317412572) {
   out_4285188047317412572[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6912670042846493690) {
   out_6912670042846493690[0] = 0;
   out_6912670042846493690[1] = 0;
   out_6912670042846493690[2] = 0;
   out_6912670042846493690[3] = 0;
   out_6912670042846493690[4] = 0;
   out_6912670042846493690[5] = 0;
   out_6912670042846493690[6] = 0;
   out_6912670042846493690[7] = 1;
   out_6912670042846493690[8] = 0;
}
void h_27(double *state, double *unused, double *out_2642833847384067509) {
   out_2642833847384067509[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3050643682297809858) {
   out_3050643682297809858[0] = 0;
   out_3050643682297809858[1] = 0;
   out_3050643682297809858[2] = 0;
   out_3050643682297809858[3] = 1;
   out_3050643682297809858[4] = 0;
   out_3050643682297809858[5] = 0;
   out_3050643682297809858[6] = 0;
   out_3050643682297809858[7] = 0;
   out_3050643682297809858[8] = 0;
}
void h_29(double *state, double *unused, double *out_7679954654156946439) {
   out_7679954654156946439[0] = state[1];
}
void H_29(double *state, double *unused, double *out_365649026182992763) {
   out_365649026182992763[0] = 0;
   out_365649026182992763[1] = 1;
   out_365649026182992763[2] = 0;
   out_365649026182992763[3] = 0;
   out_365649026182992763[4] = 0;
   out_365649026182992763[5] = 0;
   out_365649026182992763[6] = 0;
   out_365649026182992763[7] = 0;
   out_365649026182992763[8] = 0;
}
void h_28(double *state, double *unused, double *out_9041875364797916655) {
   out_9041875364797916655[0] = state[0];
}
void H_28(double *state, double *unused, double *out_5448048043252523337) {
   out_5448048043252523337[0] = 1;
   out_5448048043252523337[1] = 0;
   out_5448048043252523337[2] = 0;
   out_5448048043252523337[3] = 0;
   out_5448048043252523337[4] = 0;
   out_5448048043252523337[5] = 0;
   out_5448048043252523337[6] = 0;
   out_5448048043252523337[7] = 0;
   out_5448048043252523337[8] = 0;
}
void h_31(double *state, double *unused, double *out_6940553482236136810) {
   out_6940553482236136810[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7761924750112041274) {
   out_7761924750112041274[0] = 0;
   out_7761924750112041274[1] = 0;
   out_7761924750112041274[2] = 0;
   out_7761924750112041274[3] = 0;
   out_7761924750112041274[4] = 0;
   out_7761924750112041274[5] = 0;
   out_7761924750112041274[6] = 0;
   out_7761924750112041274[7] = 0;
   out_7761924750112041274[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7140700699742653522) {
  err_fun(nom_x, delta_x, out_7140700699742653522);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2077130439032577489) {
  inv_err_fun(nom_x, true_x, out_2077130439032577489);
}
void car_H_mod_fun(double *state, double *out_1400617513923235535) {
  H_mod_fun(state, out_1400617513923235535);
}
void car_f_fun(double *state, double dt, double *out_6169337671586411555) {
  f_fun(state,  dt, out_6169337671586411555);
}
void car_F_fun(double *state, double dt, double *out_1600017911472069397) {
  F_fun(state,  dt, out_1600017911472069397);
}
void car_h_25(double *state, double *unused, double *out_8558464601117929845) {
  h_25(state, unused, out_8558464601117929845);
}
void car_H_25(double *state, double *unused, double *out_7792570711989001702) {
  H_25(state, unused, out_7792570711989001702);
}
void car_h_24(double *state, double *unused, double *out_4537363549506217184) {
  h_24(state, unused, out_4537363549506217184);
}
void car_H_24(double *state, double *unused, double *out_5566862928010133140) {
  H_24(state, unused, out_5566862928010133140);
}
void car_h_30(double *state, double *unused, double *out_9159882758731293399) {
  h_30(state, unused, out_9159882758731293399);
}
void car_H_30(double *state, double *unused, double *out_875880370497384947) {
  H_30(state, unused, out_875880370497384947);
}
void car_h_26(double *state, double *unused, double *out_4285188047317412572) {
  h_26(state, unused, out_4285188047317412572);
}
void car_H_26(double *state, double *unused, double *out_6912670042846493690) {
  H_26(state, unused, out_6912670042846493690);
}
void car_h_27(double *state, double *unused, double *out_2642833847384067509) {
  h_27(state, unused, out_2642833847384067509);
}
void car_H_27(double *state, double *unused, double *out_3050643682297809858) {
  H_27(state, unused, out_3050643682297809858);
}
void car_h_29(double *state, double *unused, double *out_7679954654156946439) {
  h_29(state, unused, out_7679954654156946439);
}
void car_H_29(double *state, double *unused, double *out_365649026182992763) {
  H_29(state, unused, out_365649026182992763);
}
void car_h_28(double *state, double *unused, double *out_9041875364797916655) {
  h_28(state, unused, out_9041875364797916655);
}
void car_H_28(double *state, double *unused, double *out_5448048043252523337) {
  H_28(state, unused, out_5448048043252523337);
}
void car_h_31(double *state, double *unused, double *out_6940553482236136810) {
  h_31(state, unused, out_6940553482236136810);
}
void car_H_31(double *state, double *unused, double *out_7761924750112041274) {
  H_31(state, unused, out_7761924750112041274);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
