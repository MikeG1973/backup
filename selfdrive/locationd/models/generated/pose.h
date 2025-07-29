#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6440378677991973763);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8435452332690122401);
void pose_H_mod_fun(double *state, double *out_1628235856044034963);
void pose_f_fun(double *state, double dt, double *out_1107553960820638423);
void pose_F_fun(double *state, double dt, double *out_3179843290782667155);
void pose_h_4(double *state, double *unused, double *out_7192102201959718662);
void pose_H_4(double *state, double *unused, double *out_4828645757145504987);
void pose_h_10(double *state, double *unused, double *out_490824599056935481);
void pose_H_10(double *state, double *unused, double *out_4112321393984730750);
void pose_h_13(double *state, double *unused, double *out_2205629499143245109);
void pose_H_13(double *state, double *unused, double *out_2781985451171195942);
void pose_h_14(double *state, double *unused, double *out_2144589771540007605);
void pose_H_14(double *state, double *unused, double *out_865404900806020458);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}