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
void car_err_fun(double *nom_x, double *delta_x, double *out_6558331658725415692);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2286434371380471195);
void car_H_mod_fun(double *state, double *out_4494148486631984893);
void car_f_fun(double *state, double dt, double *out_2803434308051461449);
void car_F_fun(double *state, double dt, double *out_8436199080957583888);
void car_h_25(double *state, double *unused, double *out_7825947921175481376);
void car_H_25(double *state, double *unused, double *out_9157764744149697614);
void car_h_24(double *state, double *unused, double *out_5352003658146268402);
void car_H_24(double *state, double *unused, double *out_6985115145144198048);
void car_h_30(double *state, double *unused, double *out_670712760088258616);
void car_H_30(double *state, double *unused, double *out_4630068414022089416);
void car_h_26(double *state, double *unused, double *out_3946560572835715205);
void car_H_26(double *state, double *unused, double *out_5416261425275641390);
void car_h_27(double *state, double *unused, double *out_5475906089418422703);
void car_H_27(double *state, double *unused, double *out_2455305102221664505);
void car_h_29(double *state, double *unused, double *out_4330960507572587029);
void car_H_29(double *state, double *unused, double *out_5140299758336481600);
void car_h_28(double *state, double *unused, double *out_3241930830450269623);
void car_H_28(double *state, double *unused, double *out_7103930029901807851);
void car_h_31(double *state, double *unused, double *out_7983134589526610521);
void car_H_31(double *state, double *unused, double *out_4790053323042289914);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}