#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_2460299454592738255);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8995815424751717243);
void pose_H_mod_fun(double *state, double *out_172106315147157204);
void pose_f_fun(double *state, double dt, double *out_5576179949216863693);
void pose_F_fun(double *state, double dt, double *out_1077355707621539238);
void pose_h_4(double *state, double *unused, double *out_1380760196569112767);
void pose_H_4(double *state, double *unused, double *out_3943913524991064776);
void pose_h_10(double *state, double *unused, double *out_8331647754590399);
void pose_H_10(double *state, double *unused, double *out_4674971023882599542);
void pose_h_13(double *state, double *unused, double *out_7859661641013841480);
void pose_H_13(double *state, double *unused, double *out_7156187350323397577);
void pose_h_14(double *state, double *unused, double *out_9028607542587016950);
void pose_H_14(double *state, double *unused, double *out_861125092695692480);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}