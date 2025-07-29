#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6440378677991973763) {
   out_6440378677991973763[0] = delta_x[0] + nom_x[0];
   out_6440378677991973763[1] = delta_x[1] + nom_x[1];
   out_6440378677991973763[2] = delta_x[2] + nom_x[2];
   out_6440378677991973763[3] = delta_x[3] + nom_x[3];
   out_6440378677991973763[4] = delta_x[4] + nom_x[4];
   out_6440378677991973763[5] = delta_x[5] + nom_x[5];
   out_6440378677991973763[6] = delta_x[6] + nom_x[6];
   out_6440378677991973763[7] = delta_x[7] + nom_x[7];
   out_6440378677991973763[8] = delta_x[8] + nom_x[8];
   out_6440378677991973763[9] = delta_x[9] + nom_x[9];
   out_6440378677991973763[10] = delta_x[10] + nom_x[10];
   out_6440378677991973763[11] = delta_x[11] + nom_x[11];
   out_6440378677991973763[12] = delta_x[12] + nom_x[12];
   out_6440378677991973763[13] = delta_x[13] + nom_x[13];
   out_6440378677991973763[14] = delta_x[14] + nom_x[14];
   out_6440378677991973763[15] = delta_x[15] + nom_x[15];
   out_6440378677991973763[16] = delta_x[16] + nom_x[16];
   out_6440378677991973763[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8435452332690122401) {
   out_8435452332690122401[0] = -nom_x[0] + true_x[0];
   out_8435452332690122401[1] = -nom_x[1] + true_x[1];
   out_8435452332690122401[2] = -nom_x[2] + true_x[2];
   out_8435452332690122401[3] = -nom_x[3] + true_x[3];
   out_8435452332690122401[4] = -nom_x[4] + true_x[4];
   out_8435452332690122401[5] = -nom_x[5] + true_x[5];
   out_8435452332690122401[6] = -nom_x[6] + true_x[6];
   out_8435452332690122401[7] = -nom_x[7] + true_x[7];
   out_8435452332690122401[8] = -nom_x[8] + true_x[8];
   out_8435452332690122401[9] = -nom_x[9] + true_x[9];
   out_8435452332690122401[10] = -nom_x[10] + true_x[10];
   out_8435452332690122401[11] = -nom_x[11] + true_x[11];
   out_8435452332690122401[12] = -nom_x[12] + true_x[12];
   out_8435452332690122401[13] = -nom_x[13] + true_x[13];
   out_8435452332690122401[14] = -nom_x[14] + true_x[14];
   out_8435452332690122401[15] = -nom_x[15] + true_x[15];
   out_8435452332690122401[16] = -nom_x[16] + true_x[16];
   out_8435452332690122401[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_1628235856044034963) {
   out_1628235856044034963[0] = 1.0;
   out_1628235856044034963[1] = 0.0;
   out_1628235856044034963[2] = 0.0;
   out_1628235856044034963[3] = 0.0;
   out_1628235856044034963[4] = 0.0;
   out_1628235856044034963[5] = 0.0;
   out_1628235856044034963[6] = 0.0;
   out_1628235856044034963[7] = 0.0;
   out_1628235856044034963[8] = 0.0;
   out_1628235856044034963[9] = 0.0;
   out_1628235856044034963[10] = 0.0;
   out_1628235856044034963[11] = 0.0;
   out_1628235856044034963[12] = 0.0;
   out_1628235856044034963[13] = 0.0;
   out_1628235856044034963[14] = 0.0;
   out_1628235856044034963[15] = 0.0;
   out_1628235856044034963[16] = 0.0;
   out_1628235856044034963[17] = 0.0;
   out_1628235856044034963[18] = 0.0;
   out_1628235856044034963[19] = 1.0;
   out_1628235856044034963[20] = 0.0;
   out_1628235856044034963[21] = 0.0;
   out_1628235856044034963[22] = 0.0;
   out_1628235856044034963[23] = 0.0;
   out_1628235856044034963[24] = 0.0;
   out_1628235856044034963[25] = 0.0;
   out_1628235856044034963[26] = 0.0;
   out_1628235856044034963[27] = 0.0;
   out_1628235856044034963[28] = 0.0;
   out_1628235856044034963[29] = 0.0;
   out_1628235856044034963[30] = 0.0;
   out_1628235856044034963[31] = 0.0;
   out_1628235856044034963[32] = 0.0;
   out_1628235856044034963[33] = 0.0;
   out_1628235856044034963[34] = 0.0;
   out_1628235856044034963[35] = 0.0;
   out_1628235856044034963[36] = 0.0;
   out_1628235856044034963[37] = 0.0;
   out_1628235856044034963[38] = 1.0;
   out_1628235856044034963[39] = 0.0;
   out_1628235856044034963[40] = 0.0;
   out_1628235856044034963[41] = 0.0;
   out_1628235856044034963[42] = 0.0;
   out_1628235856044034963[43] = 0.0;
   out_1628235856044034963[44] = 0.0;
   out_1628235856044034963[45] = 0.0;
   out_1628235856044034963[46] = 0.0;
   out_1628235856044034963[47] = 0.0;
   out_1628235856044034963[48] = 0.0;
   out_1628235856044034963[49] = 0.0;
   out_1628235856044034963[50] = 0.0;
   out_1628235856044034963[51] = 0.0;
   out_1628235856044034963[52] = 0.0;
   out_1628235856044034963[53] = 0.0;
   out_1628235856044034963[54] = 0.0;
   out_1628235856044034963[55] = 0.0;
   out_1628235856044034963[56] = 0.0;
   out_1628235856044034963[57] = 1.0;
   out_1628235856044034963[58] = 0.0;
   out_1628235856044034963[59] = 0.0;
   out_1628235856044034963[60] = 0.0;
   out_1628235856044034963[61] = 0.0;
   out_1628235856044034963[62] = 0.0;
   out_1628235856044034963[63] = 0.0;
   out_1628235856044034963[64] = 0.0;
   out_1628235856044034963[65] = 0.0;
   out_1628235856044034963[66] = 0.0;
   out_1628235856044034963[67] = 0.0;
   out_1628235856044034963[68] = 0.0;
   out_1628235856044034963[69] = 0.0;
   out_1628235856044034963[70] = 0.0;
   out_1628235856044034963[71] = 0.0;
   out_1628235856044034963[72] = 0.0;
   out_1628235856044034963[73] = 0.0;
   out_1628235856044034963[74] = 0.0;
   out_1628235856044034963[75] = 0.0;
   out_1628235856044034963[76] = 1.0;
   out_1628235856044034963[77] = 0.0;
   out_1628235856044034963[78] = 0.0;
   out_1628235856044034963[79] = 0.0;
   out_1628235856044034963[80] = 0.0;
   out_1628235856044034963[81] = 0.0;
   out_1628235856044034963[82] = 0.0;
   out_1628235856044034963[83] = 0.0;
   out_1628235856044034963[84] = 0.0;
   out_1628235856044034963[85] = 0.0;
   out_1628235856044034963[86] = 0.0;
   out_1628235856044034963[87] = 0.0;
   out_1628235856044034963[88] = 0.0;
   out_1628235856044034963[89] = 0.0;
   out_1628235856044034963[90] = 0.0;
   out_1628235856044034963[91] = 0.0;
   out_1628235856044034963[92] = 0.0;
   out_1628235856044034963[93] = 0.0;
   out_1628235856044034963[94] = 0.0;
   out_1628235856044034963[95] = 1.0;
   out_1628235856044034963[96] = 0.0;
   out_1628235856044034963[97] = 0.0;
   out_1628235856044034963[98] = 0.0;
   out_1628235856044034963[99] = 0.0;
   out_1628235856044034963[100] = 0.0;
   out_1628235856044034963[101] = 0.0;
   out_1628235856044034963[102] = 0.0;
   out_1628235856044034963[103] = 0.0;
   out_1628235856044034963[104] = 0.0;
   out_1628235856044034963[105] = 0.0;
   out_1628235856044034963[106] = 0.0;
   out_1628235856044034963[107] = 0.0;
   out_1628235856044034963[108] = 0.0;
   out_1628235856044034963[109] = 0.0;
   out_1628235856044034963[110] = 0.0;
   out_1628235856044034963[111] = 0.0;
   out_1628235856044034963[112] = 0.0;
   out_1628235856044034963[113] = 0.0;
   out_1628235856044034963[114] = 1.0;
   out_1628235856044034963[115] = 0.0;
   out_1628235856044034963[116] = 0.0;
   out_1628235856044034963[117] = 0.0;
   out_1628235856044034963[118] = 0.0;
   out_1628235856044034963[119] = 0.0;
   out_1628235856044034963[120] = 0.0;
   out_1628235856044034963[121] = 0.0;
   out_1628235856044034963[122] = 0.0;
   out_1628235856044034963[123] = 0.0;
   out_1628235856044034963[124] = 0.0;
   out_1628235856044034963[125] = 0.0;
   out_1628235856044034963[126] = 0.0;
   out_1628235856044034963[127] = 0.0;
   out_1628235856044034963[128] = 0.0;
   out_1628235856044034963[129] = 0.0;
   out_1628235856044034963[130] = 0.0;
   out_1628235856044034963[131] = 0.0;
   out_1628235856044034963[132] = 0.0;
   out_1628235856044034963[133] = 1.0;
   out_1628235856044034963[134] = 0.0;
   out_1628235856044034963[135] = 0.0;
   out_1628235856044034963[136] = 0.0;
   out_1628235856044034963[137] = 0.0;
   out_1628235856044034963[138] = 0.0;
   out_1628235856044034963[139] = 0.0;
   out_1628235856044034963[140] = 0.0;
   out_1628235856044034963[141] = 0.0;
   out_1628235856044034963[142] = 0.0;
   out_1628235856044034963[143] = 0.0;
   out_1628235856044034963[144] = 0.0;
   out_1628235856044034963[145] = 0.0;
   out_1628235856044034963[146] = 0.0;
   out_1628235856044034963[147] = 0.0;
   out_1628235856044034963[148] = 0.0;
   out_1628235856044034963[149] = 0.0;
   out_1628235856044034963[150] = 0.0;
   out_1628235856044034963[151] = 0.0;
   out_1628235856044034963[152] = 1.0;
   out_1628235856044034963[153] = 0.0;
   out_1628235856044034963[154] = 0.0;
   out_1628235856044034963[155] = 0.0;
   out_1628235856044034963[156] = 0.0;
   out_1628235856044034963[157] = 0.0;
   out_1628235856044034963[158] = 0.0;
   out_1628235856044034963[159] = 0.0;
   out_1628235856044034963[160] = 0.0;
   out_1628235856044034963[161] = 0.0;
   out_1628235856044034963[162] = 0.0;
   out_1628235856044034963[163] = 0.0;
   out_1628235856044034963[164] = 0.0;
   out_1628235856044034963[165] = 0.0;
   out_1628235856044034963[166] = 0.0;
   out_1628235856044034963[167] = 0.0;
   out_1628235856044034963[168] = 0.0;
   out_1628235856044034963[169] = 0.0;
   out_1628235856044034963[170] = 0.0;
   out_1628235856044034963[171] = 1.0;
   out_1628235856044034963[172] = 0.0;
   out_1628235856044034963[173] = 0.0;
   out_1628235856044034963[174] = 0.0;
   out_1628235856044034963[175] = 0.0;
   out_1628235856044034963[176] = 0.0;
   out_1628235856044034963[177] = 0.0;
   out_1628235856044034963[178] = 0.0;
   out_1628235856044034963[179] = 0.0;
   out_1628235856044034963[180] = 0.0;
   out_1628235856044034963[181] = 0.0;
   out_1628235856044034963[182] = 0.0;
   out_1628235856044034963[183] = 0.0;
   out_1628235856044034963[184] = 0.0;
   out_1628235856044034963[185] = 0.0;
   out_1628235856044034963[186] = 0.0;
   out_1628235856044034963[187] = 0.0;
   out_1628235856044034963[188] = 0.0;
   out_1628235856044034963[189] = 0.0;
   out_1628235856044034963[190] = 1.0;
   out_1628235856044034963[191] = 0.0;
   out_1628235856044034963[192] = 0.0;
   out_1628235856044034963[193] = 0.0;
   out_1628235856044034963[194] = 0.0;
   out_1628235856044034963[195] = 0.0;
   out_1628235856044034963[196] = 0.0;
   out_1628235856044034963[197] = 0.0;
   out_1628235856044034963[198] = 0.0;
   out_1628235856044034963[199] = 0.0;
   out_1628235856044034963[200] = 0.0;
   out_1628235856044034963[201] = 0.0;
   out_1628235856044034963[202] = 0.0;
   out_1628235856044034963[203] = 0.0;
   out_1628235856044034963[204] = 0.0;
   out_1628235856044034963[205] = 0.0;
   out_1628235856044034963[206] = 0.0;
   out_1628235856044034963[207] = 0.0;
   out_1628235856044034963[208] = 0.0;
   out_1628235856044034963[209] = 1.0;
   out_1628235856044034963[210] = 0.0;
   out_1628235856044034963[211] = 0.0;
   out_1628235856044034963[212] = 0.0;
   out_1628235856044034963[213] = 0.0;
   out_1628235856044034963[214] = 0.0;
   out_1628235856044034963[215] = 0.0;
   out_1628235856044034963[216] = 0.0;
   out_1628235856044034963[217] = 0.0;
   out_1628235856044034963[218] = 0.0;
   out_1628235856044034963[219] = 0.0;
   out_1628235856044034963[220] = 0.0;
   out_1628235856044034963[221] = 0.0;
   out_1628235856044034963[222] = 0.0;
   out_1628235856044034963[223] = 0.0;
   out_1628235856044034963[224] = 0.0;
   out_1628235856044034963[225] = 0.0;
   out_1628235856044034963[226] = 0.0;
   out_1628235856044034963[227] = 0.0;
   out_1628235856044034963[228] = 1.0;
   out_1628235856044034963[229] = 0.0;
   out_1628235856044034963[230] = 0.0;
   out_1628235856044034963[231] = 0.0;
   out_1628235856044034963[232] = 0.0;
   out_1628235856044034963[233] = 0.0;
   out_1628235856044034963[234] = 0.0;
   out_1628235856044034963[235] = 0.0;
   out_1628235856044034963[236] = 0.0;
   out_1628235856044034963[237] = 0.0;
   out_1628235856044034963[238] = 0.0;
   out_1628235856044034963[239] = 0.0;
   out_1628235856044034963[240] = 0.0;
   out_1628235856044034963[241] = 0.0;
   out_1628235856044034963[242] = 0.0;
   out_1628235856044034963[243] = 0.0;
   out_1628235856044034963[244] = 0.0;
   out_1628235856044034963[245] = 0.0;
   out_1628235856044034963[246] = 0.0;
   out_1628235856044034963[247] = 1.0;
   out_1628235856044034963[248] = 0.0;
   out_1628235856044034963[249] = 0.0;
   out_1628235856044034963[250] = 0.0;
   out_1628235856044034963[251] = 0.0;
   out_1628235856044034963[252] = 0.0;
   out_1628235856044034963[253] = 0.0;
   out_1628235856044034963[254] = 0.0;
   out_1628235856044034963[255] = 0.0;
   out_1628235856044034963[256] = 0.0;
   out_1628235856044034963[257] = 0.0;
   out_1628235856044034963[258] = 0.0;
   out_1628235856044034963[259] = 0.0;
   out_1628235856044034963[260] = 0.0;
   out_1628235856044034963[261] = 0.0;
   out_1628235856044034963[262] = 0.0;
   out_1628235856044034963[263] = 0.0;
   out_1628235856044034963[264] = 0.0;
   out_1628235856044034963[265] = 0.0;
   out_1628235856044034963[266] = 1.0;
   out_1628235856044034963[267] = 0.0;
   out_1628235856044034963[268] = 0.0;
   out_1628235856044034963[269] = 0.0;
   out_1628235856044034963[270] = 0.0;
   out_1628235856044034963[271] = 0.0;
   out_1628235856044034963[272] = 0.0;
   out_1628235856044034963[273] = 0.0;
   out_1628235856044034963[274] = 0.0;
   out_1628235856044034963[275] = 0.0;
   out_1628235856044034963[276] = 0.0;
   out_1628235856044034963[277] = 0.0;
   out_1628235856044034963[278] = 0.0;
   out_1628235856044034963[279] = 0.0;
   out_1628235856044034963[280] = 0.0;
   out_1628235856044034963[281] = 0.0;
   out_1628235856044034963[282] = 0.0;
   out_1628235856044034963[283] = 0.0;
   out_1628235856044034963[284] = 0.0;
   out_1628235856044034963[285] = 1.0;
   out_1628235856044034963[286] = 0.0;
   out_1628235856044034963[287] = 0.0;
   out_1628235856044034963[288] = 0.0;
   out_1628235856044034963[289] = 0.0;
   out_1628235856044034963[290] = 0.0;
   out_1628235856044034963[291] = 0.0;
   out_1628235856044034963[292] = 0.0;
   out_1628235856044034963[293] = 0.0;
   out_1628235856044034963[294] = 0.0;
   out_1628235856044034963[295] = 0.0;
   out_1628235856044034963[296] = 0.0;
   out_1628235856044034963[297] = 0.0;
   out_1628235856044034963[298] = 0.0;
   out_1628235856044034963[299] = 0.0;
   out_1628235856044034963[300] = 0.0;
   out_1628235856044034963[301] = 0.0;
   out_1628235856044034963[302] = 0.0;
   out_1628235856044034963[303] = 0.0;
   out_1628235856044034963[304] = 1.0;
   out_1628235856044034963[305] = 0.0;
   out_1628235856044034963[306] = 0.0;
   out_1628235856044034963[307] = 0.0;
   out_1628235856044034963[308] = 0.0;
   out_1628235856044034963[309] = 0.0;
   out_1628235856044034963[310] = 0.0;
   out_1628235856044034963[311] = 0.0;
   out_1628235856044034963[312] = 0.0;
   out_1628235856044034963[313] = 0.0;
   out_1628235856044034963[314] = 0.0;
   out_1628235856044034963[315] = 0.0;
   out_1628235856044034963[316] = 0.0;
   out_1628235856044034963[317] = 0.0;
   out_1628235856044034963[318] = 0.0;
   out_1628235856044034963[319] = 0.0;
   out_1628235856044034963[320] = 0.0;
   out_1628235856044034963[321] = 0.0;
   out_1628235856044034963[322] = 0.0;
   out_1628235856044034963[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_1107553960820638423) {
   out_1107553960820638423[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_1107553960820638423[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_1107553960820638423[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_1107553960820638423[3] = dt*state[12] + state[3];
   out_1107553960820638423[4] = dt*state[13] + state[4];
   out_1107553960820638423[5] = dt*state[14] + state[5];
   out_1107553960820638423[6] = state[6];
   out_1107553960820638423[7] = state[7];
   out_1107553960820638423[8] = state[8];
   out_1107553960820638423[9] = state[9];
   out_1107553960820638423[10] = state[10];
   out_1107553960820638423[11] = state[11];
   out_1107553960820638423[12] = state[12];
   out_1107553960820638423[13] = state[13];
   out_1107553960820638423[14] = state[14];
   out_1107553960820638423[15] = state[15];
   out_1107553960820638423[16] = state[16];
   out_1107553960820638423[17] = state[17];
}
void F_fun(double *state, double dt, double *out_3179843290782667155) {
   out_3179843290782667155[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3179843290782667155[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3179843290782667155[2] = 0;
   out_3179843290782667155[3] = 0;
   out_3179843290782667155[4] = 0;
   out_3179843290782667155[5] = 0;
   out_3179843290782667155[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3179843290782667155[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3179843290782667155[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_3179843290782667155[9] = 0;
   out_3179843290782667155[10] = 0;
   out_3179843290782667155[11] = 0;
   out_3179843290782667155[12] = 0;
   out_3179843290782667155[13] = 0;
   out_3179843290782667155[14] = 0;
   out_3179843290782667155[15] = 0;
   out_3179843290782667155[16] = 0;
   out_3179843290782667155[17] = 0;
   out_3179843290782667155[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3179843290782667155[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3179843290782667155[20] = 0;
   out_3179843290782667155[21] = 0;
   out_3179843290782667155[22] = 0;
   out_3179843290782667155[23] = 0;
   out_3179843290782667155[24] = 0;
   out_3179843290782667155[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3179843290782667155[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_3179843290782667155[27] = 0;
   out_3179843290782667155[28] = 0;
   out_3179843290782667155[29] = 0;
   out_3179843290782667155[30] = 0;
   out_3179843290782667155[31] = 0;
   out_3179843290782667155[32] = 0;
   out_3179843290782667155[33] = 0;
   out_3179843290782667155[34] = 0;
   out_3179843290782667155[35] = 0;
   out_3179843290782667155[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3179843290782667155[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3179843290782667155[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3179843290782667155[39] = 0;
   out_3179843290782667155[40] = 0;
   out_3179843290782667155[41] = 0;
   out_3179843290782667155[42] = 0;
   out_3179843290782667155[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3179843290782667155[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_3179843290782667155[45] = 0;
   out_3179843290782667155[46] = 0;
   out_3179843290782667155[47] = 0;
   out_3179843290782667155[48] = 0;
   out_3179843290782667155[49] = 0;
   out_3179843290782667155[50] = 0;
   out_3179843290782667155[51] = 0;
   out_3179843290782667155[52] = 0;
   out_3179843290782667155[53] = 0;
   out_3179843290782667155[54] = 0;
   out_3179843290782667155[55] = 0;
   out_3179843290782667155[56] = 0;
   out_3179843290782667155[57] = 1;
   out_3179843290782667155[58] = 0;
   out_3179843290782667155[59] = 0;
   out_3179843290782667155[60] = 0;
   out_3179843290782667155[61] = 0;
   out_3179843290782667155[62] = 0;
   out_3179843290782667155[63] = 0;
   out_3179843290782667155[64] = 0;
   out_3179843290782667155[65] = 0;
   out_3179843290782667155[66] = dt;
   out_3179843290782667155[67] = 0;
   out_3179843290782667155[68] = 0;
   out_3179843290782667155[69] = 0;
   out_3179843290782667155[70] = 0;
   out_3179843290782667155[71] = 0;
   out_3179843290782667155[72] = 0;
   out_3179843290782667155[73] = 0;
   out_3179843290782667155[74] = 0;
   out_3179843290782667155[75] = 0;
   out_3179843290782667155[76] = 1;
   out_3179843290782667155[77] = 0;
   out_3179843290782667155[78] = 0;
   out_3179843290782667155[79] = 0;
   out_3179843290782667155[80] = 0;
   out_3179843290782667155[81] = 0;
   out_3179843290782667155[82] = 0;
   out_3179843290782667155[83] = 0;
   out_3179843290782667155[84] = 0;
   out_3179843290782667155[85] = dt;
   out_3179843290782667155[86] = 0;
   out_3179843290782667155[87] = 0;
   out_3179843290782667155[88] = 0;
   out_3179843290782667155[89] = 0;
   out_3179843290782667155[90] = 0;
   out_3179843290782667155[91] = 0;
   out_3179843290782667155[92] = 0;
   out_3179843290782667155[93] = 0;
   out_3179843290782667155[94] = 0;
   out_3179843290782667155[95] = 1;
   out_3179843290782667155[96] = 0;
   out_3179843290782667155[97] = 0;
   out_3179843290782667155[98] = 0;
   out_3179843290782667155[99] = 0;
   out_3179843290782667155[100] = 0;
   out_3179843290782667155[101] = 0;
   out_3179843290782667155[102] = 0;
   out_3179843290782667155[103] = 0;
   out_3179843290782667155[104] = dt;
   out_3179843290782667155[105] = 0;
   out_3179843290782667155[106] = 0;
   out_3179843290782667155[107] = 0;
   out_3179843290782667155[108] = 0;
   out_3179843290782667155[109] = 0;
   out_3179843290782667155[110] = 0;
   out_3179843290782667155[111] = 0;
   out_3179843290782667155[112] = 0;
   out_3179843290782667155[113] = 0;
   out_3179843290782667155[114] = 1;
   out_3179843290782667155[115] = 0;
   out_3179843290782667155[116] = 0;
   out_3179843290782667155[117] = 0;
   out_3179843290782667155[118] = 0;
   out_3179843290782667155[119] = 0;
   out_3179843290782667155[120] = 0;
   out_3179843290782667155[121] = 0;
   out_3179843290782667155[122] = 0;
   out_3179843290782667155[123] = 0;
   out_3179843290782667155[124] = 0;
   out_3179843290782667155[125] = 0;
   out_3179843290782667155[126] = 0;
   out_3179843290782667155[127] = 0;
   out_3179843290782667155[128] = 0;
   out_3179843290782667155[129] = 0;
   out_3179843290782667155[130] = 0;
   out_3179843290782667155[131] = 0;
   out_3179843290782667155[132] = 0;
   out_3179843290782667155[133] = 1;
   out_3179843290782667155[134] = 0;
   out_3179843290782667155[135] = 0;
   out_3179843290782667155[136] = 0;
   out_3179843290782667155[137] = 0;
   out_3179843290782667155[138] = 0;
   out_3179843290782667155[139] = 0;
   out_3179843290782667155[140] = 0;
   out_3179843290782667155[141] = 0;
   out_3179843290782667155[142] = 0;
   out_3179843290782667155[143] = 0;
   out_3179843290782667155[144] = 0;
   out_3179843290782667155[145] = 0;
   out_3179843290782667155[146] = 0;
   out_3179843290782667155[147] = 0;
   out_3179843290782667155[148] = 0;
   out_3179843290782667155[149] = 0;
   out_3179843290782667155[150] = 0;
   out_3179843290782667155[151] = 0;
   out_3179843290782667155[152] = 1;
   out_3179843290782667155[153] = 0;
   out_3179843290782667155[154] = 0;
   out_3179843290782667155[155] = 0;
   out_3179843290782667155[156] = 0;
   out_3179843290782667155[157] = 0;
   out_3179843290782667155[158] = 0;
   out_3179843290782667155[159] = 0;
   out_3179843290782667155[160] = 0;
   out_3179843290782667155[161] = 0;
   out_3179843290782667155[162] = 0;
   out_3179843290782667155[163] = 0;
   out_3179843290782667155[164] = 0;
   out_3179843290782667155[165] = 0;
   out_3179843290782667155[166] = 0;
   out_3179843290782667155[167] = 0;
   out_3179843290782667155[168] = 0;
   out_3179843290782667155[169] = 0;
   out_3179843290782667155[170] = 0;
   out_3179843290782667155[171] = 1;
   out_3179843290782667155[172] = 0;
   out_3179843290782667155[173] = 0;
   out_3179843290782667155[174] = 0;
   out_3179843290782667155[175] = 0;
   out_3179843290782667155[176] = 0;
   out_3179843290782667155[177] = 0;
   out_3179843290782667155[178] = 0;
   out_3179843290782667155[179] = 0;
   out_3179843290782667155[180] = 0;
   out_3179843290782667155[181] = 0;
   out_3179843290782667155[182] = 0;
   out_3179843290782667155[183] = 0;
   out_3179843290782667155[184] = 0;
   out_3179843290782667155[185] = 0;
   out_3179843290782667155[186] = 0;
   out_3179843290782667155[187] = 0;
   out_3179843290782667155[188] = 0;
   out_3179843290782667155[189] = 0;
   out_3179843290782667155[190] = 1;
   out_3179843290782667155[191] = 0;
   out_3179843290782667155[192] = 0;
   out_3179843290782667155[193] = 0;
   out_3179843290782667155[194] = 0;
   out_3179843290782667155[195] = 0;
   out_3179843290782667155[196] = 0;
   out_3179843290782667155[197] = 0;
   out_3179843290782667155[198] = 0;
   out_3179843290782667155[199] = 0;
   out_3179843290782667155[200] = 0;
   out_3179843290782667155[201] = 0;
   out_3179843290782667155[202] = 0;
   out_3179843290782667155[203] = 0;
   out_3179843290782667155[204] = 0;
   out_3179843290782667155[205] = 0;
   out_3179843290782667155[206] = 0;
   out_3179843290782667155[207] = 0;
   out_3179843290782667155[208] = 0;
   out_3179843290782667155[209] = 1;
   out_3179843290782667155[210] = 0;
   out_3179843290782667155[211] = 0;
   out_3179843290782667155[212] = 0;
   out_3179843290782667155[213] = 0;
   out_3179843290782667155[214] = 0;
   out_3179843290782667155[215] = 0;
   out_3179843290782667155[216] = 0;
   out_3179843290782667155[217] = 0;
   out_3179843290782667155[218] = 0;
   out_3179843290782667155[219] = 0;
   out_3179843290782667155[220] = 0;
   out_3179843290782667155[221] = 0;
   out_3179843290782667155[222] = 0;
   out_3179843290782667155[223] = 0;
   out_3179843290782667155[224] = 0;
   out_3179843290782667155[225] = 0;
   out_3179843290782667155[226] = 0;
   out_3179843290782667155[227] = 0;
   out_3179843290782667155[228] = 1;
   out_3179843290782667155[229] = 0;
   out_3179843290782667155[230] = 0;
   out_3179843290782667155[231] = 0;
   out_3179843290782667155[232] = 0;
   out_3179843290782667155[233] = 0;
   out_3179843290782667155[234] = 0;
   out_3179843290782667155[235] = 0;
   out_3179843290782667155[236] = 0;
   out_3179843290782667155[237] = 0;
   out_3179843290782667155[238] = 0;
   out_3179843290782667155[239] = 0;
   out_3179843290782667155[240] = 0;
   out_3179843290782667155[241] = 0;
   out_3179843290782667155[242] = 0;
   out_3179843290782667155[243] = 0;
   out_3179843290782667155[244] = 0;
   out_3179843290782667155[245] = 0;
   out_3179843290782667155[246] = 0;
   out_3179843290782667155[247] = 1;
   out_3179843290782667155[248] = 0;
   out_3179843290782667155[249] = 0;
   out_3179843290782667155[250] = 0;
   out_3179843290782667155[251] = 0;
   out_3179843290782667155[252] = 0;
   out_3179843290782667155[253] = 0;
   out_3179843290782667155[254] = 0;
   out_3179843290782667155[255] = 0;
   out_3179843290782667155[256] = 0;
   out_3179843290782667155[257] = 0;
   out_3179843290782667155[258] = 0;
   out_3179843290782667155[259] = 0;
   out_3179843290782667155[260] = 0;
   out_3179843290782667155[261] = 0;
   out_3179843290782667155[262] = 0;
   out_3179843290782667155[263] = 0;
   out_3179843290782667155[264] = 0;
   out_3179843290782667155[265] = 0;
   out_3179843290782667155[266] = 1;
   out_3179843290782667155[267] = 0;
   out_3179843290782667155[268] = 0;
   out_3179843290782667155[269] = 0;
   out_3179843290782667155[270] = 0;
   out_3179843290782667155[271] = 0;
   out_3179843290782667155[272] = 0;
   out_3179843290782667155[273] = 0;
   out_3179843290782667155[274] = 0;
   out_3179843290782667155[275] = 0;
   out_3179843290782667155[276] = 0;
   out_3179843290782667155[277] = 0;
   out_3179843290782667155[278] = 0;
   out_3179843290782667155[279] = 0;
   out_3179843290782667155[280] = 0;
   out_3179843290782667155[281] = 0;
   out_3179843290782667155[282] = 0;
   out_3179843290782667155[283] = 0;
   out_3179843290782667155[284] = 0;
   out_3179843290782667155[285] = 1;
   out_3179843290782667155[286] = 0;
   out_3179843290782667155[287] = 0;
   out_3179843290782667155[288] = 0;
   out_3179843290782667155[289] = 0;
   out_3179843290782667155[290] = 0;
   out_3179843290782667155[291] = 0;
   out_3179843290782667155[292] = 0;
   out_3179843290782667155[293] = 0;
   out_3179843290782667155[294] = 0;
   out_3179843290782667155[295] = 0;
   out_3179843290782667155[296] = 0;
   out_3179843290782667155[297] = 0;
   out_3179843290782667155[298] = 0;
   out_3179843290782667155[299] = 0;
   out_3179843290782667155[300] = 0;
   out_3179843290782667155[301] = 0;
   out_3179843290782667155[302] = 0;
   out_3179843290782667155[303] = 0;
   out_3179843290782667155[304] = 1;
   out_3179843290782667155[305] = 0;
   out_3179843290782667155[306] = 0;
   out_3179843290782667155[307] = 0;
   out_3179843290782667155[308] = 0;
   out_3179843290782667155[309] = 0;
   out_3179843290782667155[310] = 0;
   out_3179843290782667155[311] = 0;
   out_3179843290782667155[312] = 0;
   out_3179843290782667155[313] = 0;
   out_3179843290782667155[314] = 0;
   out_3179843290782667155[315] = 0;
   out_3179843290782667155[316] = 0;
   out_3179843290782667155[317] = 0;
   out_3179843290782667155[318] = 0;
   out_3179843290782667155[319] = 0;
   out_3179843290782667155[320] = 0;
   out_3179843290782667155[321] = 0;
   out_3179843290782667155[322] = 0;
   out_3179843290782667155[323] = 1;
}
void h_4(double *state, double *unused, double *out_7192102201959718662) {
   out_7192102201959718662[0] = state[6] + state[9];
   out_7192102201959718662[1] = state[7] + state[10];
   out_7192102201959718662[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4828645757145504987) {
   out_4828645757145504987[0] = 0;
   out_4828645757145504987[1] = 0;
   out_4828645757145504987[2] = 0;
   out_4828645757145504987[3] = 0;
   out_4828645757145504987[4] = 0;
   out_4828645757145504987[5] = 0;
   out_4828645757145504987[6] = 1;
   out_4828645757145504987[7] = 0;
   out_4828645757145504987[8] = 0;
   out_4828645757145504987[9] = 1;
   out_4828645757145504987[10] = 0;
   out_4828645757145504987[11] = 0;
   out_4828645757145504987[12] = 0;
   out_4828645757145504987[13] = 0;
   out_4828645757145504987[14] = 0;
   out_4828645757145504987[15] = 0;
   out_4828645757145504987[16] = 0;
   out_4828645757145504987[17] = 0;
   out_4828645757145504987[18] = 0;
   out_4828645757145504987[19] = 0;
   out_4828645757145504987[20] = 0;
   out_4828645757145504987[21] = 0;
   out_4828645757145504987[22] = 0;
   out_4828645757145504987[23] = 0;
   out_4828645757145504987[24] = 0;
   out_4828645757145504987[25] = 1;
   out_4828645757145504987[26] = 0;
   out_4828645757145504987[27] = 0;
   out_4828645757145504987[28] = 1;
   out_4828645757145504987[29] = 0;
   out_4828645757145504987[30] = 0;
   out_4828645757145504987[31] = 0;
   out_4828645757145504987[32] = 0;
   out_4828645757145504987[33] = 0;
   out_4828645757145504987[34] = 0;
   out_4828645757145504987[35] = 0;
   out_4828645757145504987[36] = 0;
   out_4828645757145504987[37] = 0;
   out_4828645757145504987[38] = 0;
   out_4828645757145504987[39] = 0;
   out_4828645757145504987[40] = 0;
   out_4828645757145504987[41] = 0;
   out_4828645757145504987[42] = 0;
   out_4828645757145504987[43] = 0;
   out_4828645757145504987[44] = 1;
   out_4828645757145504987[45] = 0;
   out_4828645757145504987[46] = 0;
   out_4828645757145504987[47] = 1;
   out_4828645757145504987[48] = 0;
   out_4828645757145504987[49] = 0;
   out_4828645757145504987[50] = 0;
   out_4828645757145504987[51] = 0;
   out_4828645757145504987[52] = 0;
   out_4828645757145504987[53] = 0;
}
void h_10(double *state, double *unused, double *out_490824599056935481) {
   out_490824599056935481[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_490824599056935481[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_490824599056935481[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4112321393984730750) {
   out_4112321393984730750[0] = 0;
   out_4112321393984730750[1] = 9.8100000000000005*cos(state[1]);
   out_4112321393984730750[2] = 0;
   out_4112321393984730750[3] = 0;
   out_4112321393984730750[4] = -state[8];
   out_4112321393984730750[5] = state[7];
   out_4112321393984730750[6] = 0;
   out_4112321393984730750[7] = state[5];
   out_4112321393984730750[8] = -state[4];
   out_4112321393984730750[9] = 0;
   out_4112321393984730750[10] = 0;
   out_4112321393984730750[11] = 0;
   out_4112321393984730750[12] = 1;
   out_4112321393984730750[13] = 0;
   out_4112321393984730750[14] = 0;
   out_4112321393984730750[15] = 1;
   out_4112321393984730750[16] = 0;
   out_4112321393984730750[17] = 0;
   out_4112321393984730750[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4112321393984730750[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4112321393984730750[20] = 0;
   out_4112321393984730750[21] = state[8];
   out_4112321393984730750[22] = 0;
   out_4112321393984730750[23] = -state[6];
   out_4112321393984730750[24] = -state[5];
   out_4112321393984730750[25] = 0;
   out_4112321393984730750[26] = state[3];
   out_4112321393984730750[27] = 0;
   out_4112321393984730750[28] = 0;
   out_4112321393984730750[29] = 0;
   out_4112321393984730750[30] = 0;
   out_4112321393984730750[31] = 1;
   out_4112321393984730750[32] = 0;
   out_4112321393984730750[33] = 0;
   out_4112321393984730750[34] = 1;
   out_4112321393984730750[35] = 0;
   out_4112321393984730750[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4112321393984730750[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4112321393984730750[38] = 0;
   out_4112321393984730750[39] = -state[7];
   out_4112321393984730750[40] = state[6];
   out_4112321393984730750[41] = 0;
   out_4112321393984730750[42] = state[4];
   out_4112321393984730750[43] = -state[3];
   out_4112321393984730750[44] = 0;
   out_4112321393984730750[45] = 0;
   out_4112321393984730750[46] = 0;
   out_4112321393984730750[47] = 0;
   out_4112321393984730750[48] = 0;
   out_4112321393984730750[49] = 0;
   out_4112321393984730750[50] = 1;
   out_4112321393984730750[51] = 0;
   out_4112321393984730750[52] = 0;
   out_4112321393984730750[53] = 1;
}
void h_13(double *state, double *unused, double *out_2205629499143245109) {
   out_2205629499143245109[0] = state[3];
   out_2205629499143245109[1] = state[4];
   out_2205629499143245109[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2781985451171195942) {
   out_2781985451171195942[0] = 0;
   out_2781985451171195942[1] = 0;
   out_2781985451171195942[2] = 0;
   out_2781985451171195942[3] = 1;
   out_2781985451171195942[4] = 0;
   out_2781985451171195942[5] = 0;
   out_2781985451171195942[6] = 0;
   out_2781985451171195942[7] = 0;
   out_2781985451171195942[8] = 0;
   out_2781985451171195942[9] = 0;
   out_2781985451171195942[10] = 0;
   out_2781985451171195942[11] = 0;
   out_2781985451171195942[12] = 0;
   out_2781985451171195942[13] = 0;
   out_2781985451171195942[14] = 0;
   out_2781985451171195942[15] = 0;
   out_2781985451171195942[16] = 0;
   out_2781985451171195942[17] = 0;
   out_2781985451171195942[18] = 0;
   out_2781985451171195942[19] = 0;
   out_2781985451171195942[20] = 0;
   out_2781985451171195942[21] = 0;
   out_2781985451171195942[22] = 1;
   out_2781985451171195942[23] = 0;
   out_2781985451171195942[24] = 0;
   out_2781985451171195942[25] = 0;
   out_2781985451171195942[26] = 0;
   out_2781985451171195942[27] = 0;
   out_2781985451171195942[28] = 0;
   out_2781985451171195942[29] = 0;
   out_2781985451171195942[30] = 0;
   out_2781985451171195942[31] = 0;
   out_2781985451171195942[32] = 0;
   out_2781985451171195942[33] = 0;
   out_2781985451171195942[34] = 0;
   out_2781985451171195942[35] = 0;
   out_2781985451171195942[36] = 0;
   out_2781985451171195942[37] = 0;
   out_2781985451171195942[38] = 0;
   out_2781985451171195942[39] = 0;
   out_2781985451171195942[40] = 0;
   out_2781985451171195942[41] = 1;
   out_2781985451171195942[42] = 0;
   out_2781985451171195942[43] = 0;
   out_2781985451171195942[44] = 0;
   out_2781985451171195942[45] = 0;
   out_2781985451171195942[46] = 0;
   out_2781985451171195942[47] = 0;
   out_2781985451171195942[48] = 0;
   out_2781985451171195942[49] = 0;
   out_2781985451171195942[50] = 0;
   out_2781985451171195942[51] = 0;
   out_2781985451171195942[52] = 0;
   out_2781985451171195942[53] = 0;
}
void h_14(double *state, double *unused, double *out_2144589771540007605) {
   out_2144589771540007605[0] = state[6];
   out_2144589771540007605[1] = state[7];
   out_2144589771540007605[2] = state[8];
}
void H_14(double *state, double *unused, double *out_865404900806020458) {
   out_865404900806020458[0] = 0;
   out_865404900806020458[1] = 0;
   out_865404900806020458[2] = 0;
   out_865404900806020458[3] = 0;
   out_865404900806020458[4] = 0;
   out_865404900806020458[5] = 0;
   out_865404900806020458[6] = 1;
   out_865404900806020458[7] = 0;
   out_865404900806020458[8] = 0;
   out_865404900806020458[9] = 0;
   out_865404900806020458[10] = 0;
   out_865404900806020458[11] = 0;
   out_865404900806020458[12] = 0;
   out_865404900806020458[13] = 0;
   out_865404900806020458[14] = 0;
   out_865404900806020458[15] = 0;
   out_865404900806020458[16] = 0;
   out_865404900806020458[17] = 0;
   out_865404900806020458[18] = 0;
   out_865404900806020458[19] = 0;
   out_865404900806020458[20] = 0;
   out_865404900806020458[21] = 0;
   out_865404900806020458[22] = 0;
   out_865404900806020458[23] = 0;
   out_865404900806020458[24] = 0;
   out_865404900806020458[25] = 1;
   out_865404900806020458[26] = 0;
   out_865404900806020458[27] = 0;
   out_865404900806020458[28] = 0;
   out_865404900806020458[29] = 0;
   out_865404900806020458[30] = 0;
   out_865404900806020458[31] = 0;
   out_865404900806020458[32] = 0;
   out_865404900806020458[33] = 0;
   out_865404900806020458[34] = 0;
   out_865404900806020458[35] = 0;
   out_865404900806020458[36] = 0;
   out_865404900806020458[37] = 0;
   out_865404900806020458[38] = 0;
   out_865404900806020458[39] = 0;
   out_865404900806020458[40] = 0;
   out_865404900806020458[41] = 0;
   out_865404900806020458[42] = 0;
   out_865404900806020458[43] = 0;
   out_865404900806020458[44] = 1;
   out_865404900806020458[45] = 0;
   out_865404900806020458[46] = 0;
   out_865404900806020458[47] = 0;
   out_865404900806020458[48] = 0;
   out_865404900806020458[49] = 0;
   out_865404900806020458[50] = 0;
   out_865404900806020458[51] = 0;
   out_865404900806020458[52] = 0;
   out_865404900806020458[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_6440378677991973763) {
  err_fun(nom_x, delta_x, out_6440378677991973763);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8435452332690122401) {
  inv_err_fun(nom_x, true_x, out_8435452332690122401);
}
void pose_H_mod_fun(double *state, double *out_1628235856044034963) {
  H_mod_fun(state, out_1628235856044034963);
}
void pose_f_fun(double *state, double dt, double *out_1107553960820638423) {
  f_fun(state,  dt, out_1107553960820638423);
}
void pose_F_fun(double *state, double dt, double *out_3179843290782667155) {
  F_fun(state,  dt, out_3179843290782667155);
}
void pose_h_4(double *state, double *unused, double *out_7192102201959718662) {
  h_4(state, unused, out_7192102201959718662);
}
void pose_H_4(double *state, double *unused, double *out_4828645757145504987) {
  H_4(state, unused, out_4828645757145504987);
}
void pose_h_10(double *state, double *unused, double *out_490824599056935481) {
  h_10(state, unused, out_490824599056935481);
}
void pose_H_10(double *state, double *unused, double *out_4112321393984730750) {
  H_10(state, unused, out_4112321393984730750);
}
void pose_h_13(double *state, double *unused, double *out_2205629499143245109) {
  h_13(state, unused, out_2205629499143245109);
}
void pose_H_13(double *state, double *unused, double *out_2781985451171195942) {
  H_13(state, unused, out_2781985451171195942);
}
void pose_h_14(double *state, double *unused, double *out_2144589771540007605) {
  h_14(state, unused, out_2144589771540007605);
}
void pose_H_14(double *state, double *unused, double *out_865404900806020458) {
  H_14(state, unused, out_865404900806020458);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
