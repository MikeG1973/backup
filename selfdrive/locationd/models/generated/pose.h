#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_9028216625099161166);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2624079605359324205);
void pose_H_mod_fun(double *state, double *out_972334535441043815);
void pose_f_fun(double *state, double dt, double *out_7289866408532454147);
void pose_F_fun(double *state, double dt, double *out_5129072898910106972);
void pose_h_4(double *state, double *unused, double *out_274913422982768076);
void pose_H_4(double *state, double *unused, double *out_8736213306185518663);
void pose_h_10(double *state, double *unused, double *out_2711486389137712832);
void pose_H_10(double *state, double *unused, double *out_4755487058871820930);
void pose_h_13(double *state, double *unused, double *out_1411407947792615959);
void pose_H_13(double *state, double *unused, double *out_5523939480853185862);
void pose_h_14(double *state, double *unused, double *out_6092695006911058612);
void pose_H_14(double *state, double *unused, double *out_4772972449846034134);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}