#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7140700699742653522);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2077130439032577489);
void car_H_mod_fun(double *state, double *out_1400617513923235535);
void car_f_fun(double *state, double dt, double *out_6169337671586411555);
void car_F_fun(double *state, double dt, double *out_1600017911472069397);
void car_h_25(double *state, double *unused, double *out_8558464601117929845);
void car_H_25(double *state, double *unused, double *out_7792570711989001702);
void car_h_24(double *state, double *unused, double *out_4537363549506217184);
void car_H_24(double *state, double *unused, double *out_5566862928010133140);
void car_h_30(double *state, double *unused, double *out_9159882758731293399);
void car_H_30(double *state, double *unused, double *out_875880370497384947);
void car_h_26(double *state, double *unused, double *out_4285188047317412572);
void car_H_26(double *state, double *unused, double *out_6912670042846493690);
void car_h_27(double *state, double *unused, double *out_2642833847384067509);
void car_H_27(double *state, double *unused, double *out_3050643682297809858);
void car_h_29(double *state, double *unused, double *out_7679954654156946439);
void car_H_29(double *state, double *unused, double *out_365649026182992763);
void car_h_28(double *state, double *unused, double *out_9041875364797916655);
void car_H_28(double *state, double *unused, double *out_5448048043252523337);
void car_h_31(double *state, double *unused, double *out_6940553482236136810);
void car_H_31(double *state, double *unused, double *out_7761924750112041274);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}