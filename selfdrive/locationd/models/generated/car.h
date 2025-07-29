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
void car_err_fun(double *nom_x, double *delta_x, double *out_7574148760540485215);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4932039358726872944);
void car_H_mod_fun(double *state, double *out_4324091162330527342);
void car_f_fun(double *state, double dt, double *out_5113511480340903076);
void car_F_fun(double *state, double dt, double *out_3834192190019353236);
void car_h_25(double *state, double *unused, double *out_5692390066218118877);
void car_H_25(double *state, double *unused, double *out_3019752052138555722);
void car_h_24(double *state, double *unused, double *out_2207205265673235772);
void car_H_24(double *state, double *unused, double *out_1800569452517432541);
void car_h_30(double *state, double *unused, double *out_3616636722807581557);
void car_H_30(double *state, double *unused, double *out_2890413104995315652);
void car_h_26(double *state, double *unused, double *out_7898200564051242065);
void car_H_26(double *state, double *unused, double *out_721751266735500502);
void car_h_27(double *state, double *unused, double *out_690716798557273232);
void car_H_27(double *state, double *unused, double *out_715649793194890741);
void car_h_29(double *state, double *unused, double *out_8583656293441796591);
void car_H_29(double *state, double *unused, double *out_3400644449309707836);
void car_h_28(double *state, double *unused, double *out_3503268901827126615);
void car_H_28(double *state, double *unused, double *out_1681754567759822738);
void car_h_31(double *state, double *unused, double *out_9116904479237410389);
void car_H_31(double *state, double *unused, double *out_3050398014015516150);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}