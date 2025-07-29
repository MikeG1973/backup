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
void err_fun(double *nom_x, double *delta_x, double *out_9028216625099161166) {
   out_9028216625099161166[0] = delta_x[0] + nom_x[0];
   out_9028216625099161166[1] = delta_x[1] + nom_x[1];
   out_9028216625099161166[2] = delta_x[2] + nom_x[2];
   out_9028216625099161166[3] = delta_x[3] + nom_x[3];
   out_9028216625099161166[4] = delta_x[4] + nom_x[4];
   out_9028216625099161166[5] = delta_x[5] + nom_x[5];
   out_9028216625099161166[6] = delta_x[6] + nom_x[6];
   out_9028216625099161166[7] = delta_x[7] + nom_x[7];
   out_9028216625099161166[8] = delta_x[8] + nom_x[8];
   out_9028216625099161166[9] = delta_x[9] + nom_x[9];
   out_9028216625099161166[10] = delta_x[10] + nom_x[10];
   out_9028216625099161166[11] = delta_x[11] + nom_x[11];
   out_9028216625099161166[12] = delta_x[12] + nom_x[12];
   out_9028216625099161166[13] = delta_x[13] + nom_x[13];
   out_9028216625099161166[14] = delta_x[14] + nom_x[14];
   out_9028216625099161166[15] = delta_x[15] + nom_x[15];
   out_9028216625099161166[16] = delta_x[16] + nom_x[16];
   out_9028216625099161166[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2624079605359324205) {
   out_2624079605359324205[0] = -nom_x[0] + true_x[0];
   out_2624079605359324205[1] = -nom_x[1] + true_x[1];
   out_2624079605359324205[2] = -nom_x[2] + true_x[2];
   out_2624079605359324205[3] = -nom_x[3] + true_x[3];
   out_2624079605359324205[4] = -nom_x[4] + true_x[4];
   out_2624079605359324205[5] = -nom_x[5] + true_x[5];
   out_2624079605359324205[6] = -nom_x[6] + true_x[6];
   out_2624079605359324205[7] = -nom_x[7] + true_x[7];
   out_2624079605359324205[8] = -nom_x[8] + true_x[8];
   out_2624079605359324205[9] = -nom_x[9] + true_x[9];
   out_2624079605359324205[10] = -nom_x[10] + true_x[10];
   out_2624079605359324205[11] = -nom_x[11] + true_x[11];
   out_2624079605359324205[12] = -nom_x[12] + true_x[12];
   out_2624079605359324205[13] = -nom_x[13] + true_x[13];
   out_2624079605359324205[14] = -nom_x[14] + true_x[14];
   out_2624079605359324205[15] = -nom_x[15] + true_x[15];
   out_2624079605359324205[16] = -nom_x[16] + true_x[16];
   out_2624079605359324205[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_972334535441043815) {
   out_972334535441043815[0] = 1.0;
   out_972334535441043815[1] = 0.0;
   out_972334535441043815[2] = 0.0;
   out_972334535441043815[3] = 0.0;
   out_972334535441043815[4] = 0.0;
   out_972334535441043815[5] = 0.0;
   out_972334535441043815[6] = 0.0;
   out_972334535441043815[7] = 0.0;
   out_972334535441043815[8] = 0.0;
   out_972334535441043815[9] = 0.0;
   out_972334535441043815[10] = 0.0;
   out_972334535441043815[11] = 0.0;
   out_972334535441043815[12] = 0.0;
   out_972334535441043815[13] = 0.0;
   out_972334535441043815[14] = 0.0;
   out_972334535441043815[15] = 0.0;
   out_972334535441043815[16] = 0.0;
   out_972334535441043815[17] = 0.0;
   out_972334535441043815[18] = 0.0;
   out_972334535441043815[19] = 1.0;
   out_972334535441043815[20] = 0.0;
   out_972334535441043815[21] = 0.0;
   out_972334535441043815[22] = 0.0;
   out_972334535441043815[23] = 0.0;
   out_972334535441043815[24] = 0.0;
   out_972334535441043815[25] = 0.0;
   out_972334535441043815[26] = 0.0;
   out_972334535441043815[27] = 0.0;
   out_972334535441043815[28] = 0.0;
   out_972334535441043815[29] = 0.0;
   out_972334535441043815[30] = 0.0;
   out_972334535441043815[31] = 0.0;
   out_972334535441043815[32] = 0.0;
   out_972334535441043815[33] = 0.0;
   out_972334535441043815[34] = 0.0;
   out_972334535441043815[35] = 0.0;
   out_972334535441043815[36] = 0.0;
   out_972334535441043815[37] = 0.0;
   out_972334535441043815[38] = 1.0;
   out_972334535441043815[39] = 0.0;
   out_972334535441043815[40] = 0.0;
   out_972334535441043815[41] = 0.0;
   out_972334535441043815[42] = 0.0;
   out_972334535441043815[43] = 0.0;
   out_972334535441043815[44] = 0.0;
   out_972334535441043815[45] = 0.0;
   out_972334535441043815[46] = 0.0;
   out_972334535441043815[47] = 0.0;
   out_972334535441043815[48] = 0.0;
   out_972334535441043815[49] = 0.0;
   out_972334535441043815[50] = 0.0;
   out_972334535441043815[51] = 0.0;
   out_972334535441043815[52] = 0.0;
   out_972334535441043815[53] = 0.0;
   out_972334535441043815[54] = 0.0;
   out_972334535441043815[55] = 0.0;
   out_972334535441043815[56] = 0.0;
   out_972334535441043815[57] = 1.0;
   out_972334535441043815[58] = 0.0;
   out_972334535441043815[59] = 0.0;
   out_972334535441043815[60] = 0.0;
   out_972334535441043815[61] = 0.0;
   out_972334535441043815[62] = 0.0;
   out_972334535441043815[63] = 0.0;
   out_972334535441043815[64] = 0.0;
   out_972334535441043815[65] = 0.0;
   out_972334535441043815[66] = 0.0;
   out_972334535441043815[67] = 0.0;
   out_972334535441043815[68] = 0.0;
   out_972334535441043815[69] = 0.0;
   out_972334535441043815[70] = 0.0;
   out_972334535441043815[71] = 0.0;
   out_972334535441043815[72] = 0.0;
   out_972334535441043815[73] = 0.0;
   out_972334535441043815[74] = 0.0;
   out_972334535441043815[75] = 0.0;
   out_972334535441043815[76] = 1.0;
   out_972334535441043815[77] = 0.0;
   out_972334535441043815[78] = 0.0;
   out_972334535441043815[79] = 0.0;
   out_972334535441043815[80] = 0.0;
   out_972334535441043815[81] = 0.0;
   out_972334535441043815[82] = 0.0;
   out_972334535441043815[83] = 0.0;
   out_972334535441043815[84] = 0.0;
   out_972334535441043815[85] = 0.0;
   out_972334535441043815[86] = 0.0;
   out_972334535441043815[87] = 0.0;
   out_972334535441043815[88] = 0.0;
   out_972334535441043815[89] = 0.0;
   out_972334535441043815[90] = 0.0;
   out_972334535441043815[91] = 0.0;
   out_972334535441043815[92] = 0.0;
   out_972334535441043815[93] = 0.0;
   out_972334535441043815[94] = 0.0;
   out_972334535441043815[95] = 1.0;
   out_972334535441043815[96] = 0.0;
   out_972334535441043815[97] = 0.0;
   out_972334535441043815[98] = 0.0;
   out_972334535441043815[99] = 0.0;
   out_972334535441043815[100] = 0.0;
   out_972334535441043815[101] = 0.0;
   out_972334535441043815[102] = 0.0;
   out_972334535441043815[103] = 0.0;
   out_972334535441043815[104] = 0.0;
   out_972334535441043815[105] = 0.0;
   out_972334535441043815[106] = 0.0;
   out_972334535441043815[107] = 0.0;
   out_972334535441043815[108] = 0.0;
   out_972334535441043815[109] = 0.0;
   out_972334535441043815[110] = 0.0;
   out_972334535441043815[111] = 0.0;
   out_972334535441043815[112] = 0.0;
   out_972334535441043815[113] = 0.0;
   out_972334535441043815[114] = 1.0;
   out_972334535441043815[115] = 0.0;
   out_972334535441043815[116] = 0.0;
   out_972334535441043815[117] = 0.0;
   out_972334535441043815[118] = 0.0;
   out_972334535441043815[119] = 0.0;
   out_972334535441043815[120] = 0.0;
   out_972334535441043815[121] = 0.0;
   out_972334535441043815[122] = 0.0;
   out_972334535441043815[123] = 0.0;
   out_972334535441043815[124] = 0.0;
   out_972334535441043815[125] = 0.0;
   out_972334535441043815[126] = 0.0;
   out_972334535441043815[127] = 0.0;
   out_972334535441043815[128] = 0.0;
   out_972334535441043815[129] = 0.0;
   out_972334535441043815[130] = 0.0;
   out_972334535441043815[131] = 0.0;
   out_972334535441043815[132] = 0.0;
   out_972334535441043815[133] = 1.0;
   out_972334535441043815[134] = 0.0;
   out_972334535441043815[135] = 0.0;
   out_972334535441043815[136] = 0.0;
   out_972334535441043815[137] = 0.0;
   out_972334535441043815[138] = 0.0;
   out_972334535441043815[139] = 0.0;
   out_972334535441043815[140] = 0.0;
   out_972334535441043815[141] = 0.0;
   out_972334535441043815[142] = 0.0;
   out_972334535441043815[143] = 0.0;
   out_972334535441043815[144] = 0.0;
   out_972334535441043815[145] = 0.0;
   out_972334535441043815[146] = 0.0;
   out_972334535441043815[147] = 0.0;
   out_972334535441043815[148] = 0.0;
   out_972334535441043815[149] = 0.0;
   out_972334535441043815[150] = 0.0;
   out_972334535441043815[151] = 0.0;
   out_972334535441043815[152] = 1.0;
   out_972334535441043815[153] = 0.0;
   out_972334535441043815[154] = 0.0;
   out_972334535441043815[155] = 0.0;
   out_972334535441043815[156] = 0.0;
   out_972334535441043815[157] = 0.0;
   out_972334535441043815[158] = 0.0;
   out_972334535441043815[159] = 0.0;
   out_972334535441043815[160] = 0.0;
   out_972334535441043815[161] = 0.0;
   out_972334535441043815[162] = 0.0;
   out_972334535441043815[163] = 0.0;
   out_972334535441043815[164] = 0.0;
   out_972334535441043815[165] = 0.0;
   out_972334535441043815[166] = 0.0;
   out_972334535441043815[167] = 0.0;
   out_972334535441043815[168] = 0.0;
   out_972334535441043815[169] = 0.0;
   out_972334535441043815[170] = 0.0;
   out_972334535441043815[171] = 1.0;
   out_972334535441043815[172] = 0.0;
   out_972334535441043815[173] = 0.0;
   out_972334535441043815[174] = 0.0;
   out_972334535441043815[175] = 0.0;
   out_972334535441043815[176] = 0.0;
   out_972334535441043815[177] = 0.0;
   out_972334535441043815[178] = 0.0;
   out_972334535441043815[179] = 0.0;
   out_972334535441043815[180] = 0.0;
   out_972334535441043815[181] = 0.0;
   out_972334535441043815[182] = 0.0;
   out_972334535441043815[183] = 0.0;
   out_972334535441043815[184] = 0.0;
   out_972334535441043815[185] = 0.0;
   out_972334535441043815[186] = 0.0;
   out_972334535441043815[187] = 0.0;
   out_972334535441043815[188] = 0.0;
   out_972334535441043815[189] = 0.0;
   out_972334535441043815[190] = 1.0;
   out_972334535441043815[191] = 0.0;
   out_972334535441043815[192] = 0.0;
   out_972334535441043815[193] = 0.0;
   out_972334535441043815[194] = 0.0;
   out_972334535441043815[195] = 0.0;
   out_972334535441043815[196] = 0.0;
   out_972334535441043815[197] = 0.0;
   out_972334535441043815[198] = 0.0;
   out_972334535441043815[199] = 0.0;
   out_972334535441043815[200] = 0.0;
   out_972334535441043815[201] = 0.0;
   out_972334535441043815[202] = 0.0;
   out_972334535441043815[203] = 0.0;
   out_972334535441043815[204] = 0.0;
   out_972334535441043815[205] = 0.0;
   out_972334535441043815[206] = 0.0;
   out_972334535441043815[207] = 0.0;
   out_972334535441043815[208] = 0.0;
   out_972334535441043815[209] = 1.0;
   out_972334535441043815[210] = 0.0;
   out_972334535441043815[211] = 0.0;
   out_972334535441043815[212] = 0.0;
   out_972334535441043815[213] = 0.0;
   out_972334535441043815[214] = 0.0;
   out_972334535441043815[215] = 0.0;
   out_972334535441043815[216] = 0.0;
   out_972334535441043815[217] = 0.0;
   out_972334535441043815[218] = 0.0;
   out_972334535441043815[219] = 0.0;
   out_972334535441043815[220] = 0.0;
   out_972334535441043815[221] = 0.0;
   out_972334535441043815[222] = 0.0;
   out_972334535441043815[223] = 0.0;
   out_972334535441043815[224] = 0.0;
   out_972334535441043815[225] = 0.0;
   out_972334535441043815[226] = 0.0;
   out_972334535441043815[227] = 0.0;
   out_972334535441043815[228] = 1.0;
   out_972334535441043815[229] = 0.0;
   out_972334535441043815[230] = 0.0;
   out_972334535441043815[231] = 0.0;
   out_972334535441043815[232] = 0.0;
   out_972334535441043815[233] = 0.0;
   out_972334535441043815[234] = 0.0;
   out_972334535441043815[235] = 0.0;
   out_972334535441043815[236] = 0.0;
   out_972334535441043815[237] = 0.0;
   out_972334535441043815[238] = 0.0;
   out_972334535441043815[239] = 0.0;
   out_972334535441043815[240] = 0.0;
   out_972334535441043815[241] = 0.0;
   out_972334535441043815[242] = 0.0;
   out_972334535441043815[243] = 0.0;
   out_972334535441043815[244] = 0.0;
   out_972334535441043815[245] = 0.0;
   out_972334535441043815[246] = 0.0;
   out_972334535441043815[247] = 1.0;
   out_972334535441043815[248] = 0.0;
   out_972334535441043815[249] = 0.0;
   out_972334535441043815[250] = 0.0;
   out_972334535441043815[251] = 0.0;
   out_972334535441043815[252] = 0.0;
   out_972334535441043815[253] = 0.0;
   out_972334535441043815[254] = 0.0;
   out_972334535441043815[255] = 0.0;
   out_972334535441043815[256] = 0.0;
   out_972334535441043815[257] = 0.0;
   out_972334535441043815[258] = 0.0;
   out_972334535441043815[259] = 0.0;
   out_972334535441043815[260] = 0.0;
   out_972334535441043815[261] = 0.0;
   out_972334535441043815[262] = 0.0;
   out_972334535441043815[263] = 0.0;
   out_972334535441043815[264] = 0.0;
   out_972334535441043815[265] = 0.0;
   out_972334535441043815[266] = 1.0;
   out_972334535441043815[267] = 0.0;
   out_972334535441043815[268] = 0.0;
   out_972334535441043815[269] = 0.0;
   out_972334535441043815[270] = 0.0;
   out_972334535441043815[271] = 0.0;
   out_972334535441043815[272] = 0.0;
   out_972334535441043815[273] = 0.0;
   out_972334535441043815[274] = 0.0;
   out_972334535441043815[275] = 0.0;
   out_972334535441043815[276] = 0.0;
   out_972334535441043815[277] = 0.0;
   out_972334535441043815[278] = 0.0;
   out_972334535441043815[279] = 0.0;
   out_972334535441043815[280] = 0.0;
   out_972334535441043815[281] = 0.0;
   out_972334535441043815[282] = 0.0;
   out_972334535441043815[283] = 0.0;
   out_972334535441043815[284] = 0.0;
   out_972334535441043815[285] = 1.0;
   out_972334535441043815[286] = 0.0;
   out_972334535441043815[287] = 0.0;
   out_972334535441043815[288] = 0.0;
   out_972334535441043815[289] = 0.0;
   out_972334535441043815[290] = 0.0;
   out_972334535441043815[291] = 0.0;
   out_972334535441043815[292] = 0.0;
   out_972334535441043815[293] = 0.0;
   out_972334535441043815[294] = 0.0;
   out_972334535441043815[295] = 0.0;
   out_972334535441043815[296] = 0.0;
   out_972334535441043815[297] = 0.0;
   out_972334535441043815[298] = 0.0;
   out_972334535441043815[299] = 0.0;
   out_972334535441043815[300] = 0.0;
   out_972334535441043815[301] = 0.0;
   out_972334535441043815[302] = 0.0;
   out_972334535441043815[303] = 0.0;
   out_972334535441043815[304] = 1.0;
   out_972334535441043815[305] = 0.0;
   out_972334535441043815[306] = 0.0;
   out_972334535441043815[307] = 0.0;
   out_972334535441043815[308] = 0.0;
   out_972334535441043815[309] = 0.0;
   out_972334535441043815[310] = 0.0;
   out_972334535441043815[311] = 0.0;
   out_972334535441043815[312] = 0.0;
   out_972334535441043815[313] = 0.0;
   out_972334535441043815[314] = 0.0;
   out_972334535441043815[315] = 0.0;
   out_972334535441043815[316] = 0.0;
   out_972334535441043815[317] = 0.0;
   out_972334535441043815[318] = 0.0;
   out_972334535441043815[319] = 0.0;
   out_972334535441043815[320] = 0.0;
   out_972334535441043815[321] = 0.0;
   out_972334535441043815[322] = 0.0;
   out_972334535441043815[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_7289866408532454147) {
   out_7289866408532454147[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_7289866408532454147[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_7289866408532454147[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_7289866408532454147[3] = dt*state[12] + state[3];
   out_7289866408532454147[4] = dt*state[13] + state[4];
   out_7289866408532454147[5] = dt*state[14] + state[5];
   out_7289866408532454147[6] = state[6];
   out_7289866408532454147[7] = state[7];
   out_7289866408532454147[8] = state[8];
   out_7289866408532454147[9] = state[9];
   out_7289866408532454147[10] = state[10];
   out_7289866408532454147[11] = state[11];
   out_7289866408532454147[12] = state[12];
   out_7289866408532454147[13] = state[13];
   out_7289866408532454147[14] = state[14];
   out_7289866408532454147[15] = state[15];
   out_7289866408532454147[16] = state[16];
   out_7289866408532454147[17] = state[17];
}
void F_fun(double *state, double dt, double *out_5129072898910106972) {
   out_5129072898910106972[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5129072898910106972[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5129072898910106972[2] = 0;
   out_5129072898910106972[3] = 0;
   out_5129072898910106972[4] = 0;
   out_5129072898910106972[5] = 0;
   out_5129072898910106972[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5129072898910106972[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5129072898910106972[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_5129072898910106972[9] = 0;
   out_5129072898910106972[10] = 0;
   out_5129072898910106972[11] = 0;
   out_5129072898910106972[12] = 0;
   out_5129072898910106972[13] = 0;
   out_5129072898910106972[14] = 0;
   out_5129072898910106972[15] = 0;
   out_5129072898910106972[16] = 0;
   out_5129072898910106972[17] = 0;
   out_5129072898910106972[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5129072898910106972[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5129072898910106972[20] = 0;
   out_5129072898910106972[21] = 0;
   out_5129072898910106972[22] = 0;
   out_5129072898910106972[23] = 0;
   out_5129072898910106972[24] = 0;
   out_5129072898910106972[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5129072898910106972[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_5129072898910106972[27] = 0;
   out_5129072898910106972[28] = 0;
   out_5129072898910106972[29] = 0;
   out_5129072898910106972[30] = 0;
   out_5129072898910106972[31] = 0;
   out_5129072898910106972[32] = 0;
   out_5129072898910106972[33] = 0;
   out_5129072898910106972[34] = 0;
   out_5129072898910106972[35] = 0;
   out_5129072898910106972[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5129072898910106972[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5129072898910106972[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5129072898910106972[39] = 0;
   out_5129072898910106972[40] = 0;
   out_5129072898910106972[41] = 0;
   out_5129072898910106972[42] = 0;
   out_5129072898910106972[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5129072898910106972[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_5129072898910106972[45] = 0;
   out_5129072898910106972[46] = 0;
   out_5129072898910106972[47] = 0;
   out_5129072898910106972[48] = 0;
   out_5129072898910106972[49] = 0;
   out_5129072898910106972[50] = 0;
   out_5129072898910106972[51] = 0;
   out_5129072898910106972[52] = 0;
   out_5129072898910106972[53] = 0;
   out_5129072898910106972[54] = 0;
   out_5129072898910106972[55] = 0;
   out_5129072898910106972[56] = 0;
   out_5129072898910106972[57] = 1;
   out_5129072898910106972[58] = 0;
   out_5129072898910106972[59] = 0;
   out_5129072898910106972[60] = 0;
   out_5129072898910106972[61] = 0;
   out_5129072898910106972[62] = 0;
   out_5129072898910106972[63] = 0;
   out_5129072898910106972[64] = 0;
   out_5129072898910106972[65] = 0;
   out_5129072898910106972[66] = dt;
   out_5129072898910106972[67] = 0;
   out_5129072898910106972[68] = 0;
   out_5129072898910106972[69] = 0;
   out_5129072898910106972[70] = 0;
   out_5129072898910106972[71] = 0;
   out_5129072898910106972[72] = 0;
   out_5129072898910106972[73] = 0;
   out_5129072898910106972[74] = 0;
   out_5129072898910106972[75] = 0;
   out_5129072898910106972[76] = 1;
   out_5129072898910106972[77] = 0;
   out_5129072898910106972[78] = 0;
   out_5129072898910106972[79] = 0;
   out_5129072898910106972[80] = 0;
   out_5129072898910106972[81] = 0;
   out_5129072898910106972[82] = 0;
   out_5129072898910106972[83] = 0;
   out_5129072898910106972[84] = 0;
   out_5129072898910106972[85] = dt;
   out_5129072898910106972[86] = 0;
   out_5129072898910106972[87] = 0;
   out_5129072898910106972[88] = 0;
   out_5129072898910106972[89] = 0;
   out_5129072898910106972[90] = 0;
   out_5129072898910106972[91] = 0;
   out_5129072898910106972[92] = 0;
   out_5129072898910106972[93] = 0;
   out_5129072898910106972[94] = 0;
   out_5129072898910106972[95] = 1;
   out_5129072898910106972[96] = 0;
   out_5129072898910106972[97] = 0;
   out_5129072898910106972[98] = 0;
   out_5129072898910106972[99] = 0;
   out_5129072898910106972[100] = 0;
   out_5129072898910106972[101] = 0;
   out_5129072898910106972[102] = 0;
   out_5129072898910106972[103] = 0;
   out_5129072898910106972[104] = dt;
   out_5129072898910106972[105] = 0;
   out_5129072898910106972[106] = 0;
   out_5129072898910106972[107] = 0;
   out_5129072898910106972[108] = 0;
   out_5129072898910106972[109] = 0;
   out_5129072898910106972[110] = 0;
   out_5129072898910106972[111] = 0;
   out_5129072898910106972[112] = 0;
   out_5129072898910106972[113] = 0;
   out_5129072898910106972[114] = 1;
   out_5129072898910106972[115] = 0;
   out_5129072898910106972[116] = 0;
   out_5129072898910106972[117] = 0;
   out_5129072898910106972[118] = 0;
   out_5129072898910106972[119] = 0;
   out_5129072898910106972[120] = 0;
   out_5129072898910106972[121] = 0;
   out_5129072898910106972[122] = 0;
   out_5129072898910106972[123] = 0;
   out_5129072898910106972[124] = 0;
   out_5129072898910106972[125] = 0;
   out_5129072898910106972[126] = 0;
   out_5129072898910106972[127] = 0;
   out_5129072898910106972[128] = 0;
   out_5129072898910106972[129] = 0;
   out_5129072898910106972[130] = 0;
   out_5129072898910106972[131] = 0;
   out_5129072898910106972[132] = 0;
   out_5129072898910106972[133] = 1;
   out_5129072898910106972[134] = 0;
   out_5129072898910106972[135] = 0;
   out_5129072898910106972[136] = 0;
   out_5129072898910106972[137] = 0;
   out_5129072898910106972[138] = 0;
   out_5129072898910106972[139] = 0;
   out_5129072898910106972[140] = 0;
   out_5129072898910106972[141] = 0;
   out_5129072898910106972[142] = 0;
   out_5129072898910106972[143] = 0;
   out_5129072898910106972[144] = 0;
   out_5129072898910106972[145] = 0;
   out_5129072898910106972[146] = 0;
   out_5129072898910106972[147] = 0;
   out_5129072898910106972[148] = 0;
   out_5129072898910106972[149] = 0;
   out_5129072898910106972[150] = 0;
   out_5129072898910106972[151] = 0;
   out_5129072898910106972[152] = 1;
   out_5129072898910106972[153] = 0;
   out_5129072898910106972[154] = 0;
   out_5129072898910106972[155] = 0;
   out_5129072898910106972[156] = 0;
   out_5129072898910106972[157] = 0;
   out_5129072898910106972[158] = 0;
   out_5129072898910106972[159] = 0;
   out_5129072898910106972[160] = 0;
   out_5129072898910106972[161] = 0;
   out_5129072898910106972[162] = 0;
   out_5129072898910106972[163] = 0;
   out_5129072898910106972[164] = 0;
   out_5129072898910106972[165] = 0;
   out_5129072898910106972[166] = 0;
   out_5129072898910106972[167] = 0;
   out_5129072898910106972[168] = 0;
   out_5129072898910106972[169] = 0;
   out_5129072898910106972[170] = 0;
   out_5129072898910106972[171] = 1;
   out_5129072898910106972[172] = 0;
   out_5129072898910106972[173] = 0;
   out_5129072898910106972[174] = 0;
   out_5129072898910106972[175] = 0;
   out_5129072898910106972[176] = 0;
   out_5129072898910106972[177] = 0;
   out_5129072898910106972[178] = 0;
   out_5129072898910106972[179] = 0;
   out_5129072898910106972[180] = 0;
   out_5129072898910106972[181] = 0;
   out_5129072898910106972[182] = 0;
   out_5129072898910106972[183] = 0;
   out_5129072898910106972[184] = 0;
   out_5129072898910106972[185] = 0;
   out_5129072898910106972[186] = 0;
   out_5129072898910106972[187] = 0;
   out_5129072898910106972[188] = 0;
   out_5129072898910106972[189] = 0;
   out_5129072898910106972[190] = 1;
   out_5129072898910106972[191] = 0;
   out_5129072898910106972[192] = 0;
   out_5129072898910106972[193] = 0;
   out_5129072898910106972[194] = 0;
   out_5129072898910106972[195] = 0;
   out_5129072898910106972[196] = 0;
   out_5129072898910106972[197] = 0;
   out_5129072898910106972[198] = 0;
   out_5129072898910106972[199] = 0;
   out_5129072898910106972[200] = 0;
   out_5129072898910106972[201] = 0;
   out_5129072898910106972[202] = 0;
   out_5129072898910106972[203] = 0;
   out_5129072898910106972[204] = 0;
   out_5129072898910106972[205] = 0;
   out_5129072898910106972[206] = 0;
   out_5129072898910106972[207] = 0;
   out_5129072898910106972[208] = 0;
   out_5129072898910106972[209] = 1;
   out_5129072898910106972[210] = 0;
   out_5129072898910106972[211] = 0;
   out_5129072898910106972[212] = 0;
   out_5129072898910106972[213] = 0;
   out_5129072898910106972[214] = 0;
   out_5129072898910106972[215] = 0;
   out_5129072898910106972[216] = 0;
   out_5129072898910106972[217] = 0;
   out_5129072898910106972[218] = 0;
   out_5129072898910106972[219] = 0;
   out_5129072898910106972[220] = 0;
   out_5129072898910106972[221] = 0;
   out_5129072898910106972[222] = 0;
   out_5129072898910106972[223] = 0;
   out_5129072898910106972[224] = 0;
   out_5129072898910106972[225] = 0;
   out_5129072898910106972[226] = 0;
   out_5129072898910106972[227] = 0;
   out_5129072898910106972[228] = 1;
   out_5129072898910106972[229] = 0;
   out_5129072898910106972[230] = 0;
   out_5129072898910106972[231] = 0;
   out_5129072898910106972[232] = 0;
   out_5129072898910106972[233] = 0;
   out_5129072898910106972[234] = 0;
   out_5129072898910106972[235] = 0;
   out_5129072898910106972[236] = 0;
   out_5129072898910106972[237] = 0;
   out_5129072898910106972[238] = 0;
   out_5129072898910106972[239] = 0;
   out_5129072898910106972[240] = 0;
   out_5129072898910106972[241] = 0;
   out_5129072898910106972[242] = 0;
   out_5129072898910106972[243] = 0;
   out_5129072898910106972[244] = 0;
   out_5129072898910106972[245] = 0;
   out_5129072898910106972[246] = 0;
   out_5129072898910106972[247] = 1;
   out_5129072898910106972[248] = 0;
   out_5129072898910106972[249] = 0;
   out_5129072898910106972[250] = 0;
   out_5129072898910106972[251] = 0;
   out_5129072898910106972[252] = 0;
   out_5129072898910106972[253] = 0;
   out_5129072898910106972[254] = 0;
   out_5129072898910106972[255] = 0;
   out_5129072898910106972[256] = 0;
   out_5129072898910106972[257] = 0;
   out_5129072898910106972[258] = 0;
   out_5129072898910106972[259] = 0;
   out_5129072898910106972[260] = 0;
   out_5129072898910106972[261] = 0;
   out_5129072898910106972[262] = 0;
   out_5129072898910106972[263] = 0;
   out_5129072898910106972[264] = 0;
   out_5129072898910106972[265] = 0;
   out_5129072898910106972[266] = 1;
   out_5129072898910106972[267] = 0;
   out_5129072898910106972[268] = 0;
   out_5129072898910106972[269] = 0;
   out_5129072898910106972[270] = 0;
   out_5129072898910106972[271] = 0;
   out_5129072898910106972[272] = 0;
   out_5129072898910106972[273] = 0;
   out_5129072898910106972[274] = 0;
   out_5129072898910106972[275] = 0;
   out_5129072898910106972[276] = 0;
   out_5129072898910106972[277] = 0;
   out_5129072898910106972[278] = 0;
   out_5129072898910106972[279] = 0;
   out_5129072898910106972[280] = 0;
   out_5129072898910106972[281] = 0;
   out_5129072898910106972[282] = 0;
   out_5129072898910106972[283] = 0;
   out_5129072898910106972[284] = 0;
   out_5129072898910106972[285] = 1;
   out_5129072898910106972[286] = 0;
   out_5129072898910106972[287] = 0;
   out_5129072898910106972[288] = 0;
   out_5129072898910106972[289] = 0;
   out_5129072898910106972[290] = 0;
   out_5129072898910106972[291] = 0;
   out_5129072898910106972[292] = 0;
   out_5129072898910106972[293] = 0;
   out_5129072898910106972[294] = 0;
   out_5129072898910106972[295] = 0;
   out_5129072898910106972[296] = 0;
   out_5129072898910106972[297] = 0;
   out_5129072898910106972[298] = 0;
   out_5129072898910106972[299] = 0;
   out_5129072898910106972[300] = 0;
   out_5129072898910106972[301] = 0;
   out_5129072898910106972[302] = 0;
   out_5129072898910106972[303] = 0;
   out_5129072898910106972[304] = 1;
   out_5129072898910106972[305] = 0;
   out_5129072898910106972[306] = 0;
   out_5129072898910106972[307] = 0;
   out_5129072898910106972[308] = 0;
   out_5129072898910106972[309] = 0;
   out_5129072898910106972[310] = 0;
   out_5129072898910106972[311] = 0;
   out_5129072898910106972[312] = 0;
   out_5129072898910106972[313] = 0;
   out_5129072898910106972[314] = 0;
   out_5129072898910106972[315] = 0;
   out_5129072898910106972[316] = 0;
   out_5129072898910106972[317] = 0;
   out_5129072898910106972[318] = 0;
   out_5129072898910106972[319] = 0;
   out_5129072898910106972[320] = 0;
   out_5129072898910106972[321] = 0;
   out_5129072898910106972[322] = 0;
   out_5129072898910106972[323] = 1;
}
void h_4(double *state, double *unused, double *out_274913422982768076) {
   out_274913422982768076[0] = state[6] + state[9];
   out_274913422982768076[1] = state[7] + state[10];
   out_274913422982768076[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8736213306185518663) {
   out_8736213306185518663[0] = 0;
   out_8736213306185518663[1] = 0;
   out_8736213306185518663[2] = 0;
   out_8736213306185518663[3] = 0;
   out_8736213306185518663[4] = 0;
   out_8736213306185518663[5] = 0;
   out_8736213306185518663[6] = 1;
   out_8736213306185518663[7] = 0;
   out_8736213306185518663[8] = 0;
   out_8736213306185518663[9] = 1;
   out_8736213306185518663[10] = 0;
   out_8736213306185518663[11] = 0;
   out_8736213306185518663[12] = 0;
   out_8736213306185518663[13] = 0;
   out_8736213306185518663[14] = 0;
   out_8736213306185518663[15] = 0;
   out_8736213306185518663[16] = 0;
   out_8736213306185518663[17] = 0;
   out_8736213306185518663[18] = 0;
   out_8736213306185518663[19] = 0;
   out_8736213306185518663[20] = 0;
   out_8736213306185518663[21] = 0;
   out_8736213306185518663[22] = 0;
   out_8736213306185518663[23] = 0;
   out_8736213306185518663[24] = 0;
   out_8736213306185518663[25] = 1;
   out_8736213306185518663[26] = 0;
   out_8736213306185518663[27] = 0;
   out_8736213306185518663[28] = 1;
   out_8736213306185518663[29] = 0;
   out_8736213306185518663[30] = 0;
   out_8736213306185518663[31] = 0;
   out_8736213306185518663[32] = 0;
   out_8736213306185518663[33] = 0;
   out_8736213306185518663[34] = 0;
   out_8736213306185518663[35] = 0;
   out_8736213306185518663[36] = 0;
   out_8736213306185518663[37] = 0;
   out_8736213306185518663[38] = 0;
   out_8736213306185518663[39] = 0;
   out_8736213306185518663[40] = 0;
   out_8736213306185518663[41] = 0;
   out_8736213306185518663[42] = 0;
   out_8736213306185518663[43] = 0;
   out_8736213306185518663[44] = 1;
   out_8736213306185518663[45] = 0;
   out_8736213306185518663[46] = 0;
   out_8736213306185518663[47] = 1;
   out_8736213306185518663[48] = 0;
   out_8736213306185518663[49] = 0;
   out_8736213306185518663[50] = 0;
   out_8736213306185518663[51] = 0;
   out_8736213306185518663[52] = 0;
   out_8736213306185518663[53] = 0;
}
void h_10(double *state, double *unused, double *out_2711486389137712832) {
   out_2711486389137712832[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_2711486389137712832[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_2711486389137712832[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4755487058871820930) {
   out_4755487058871820930[0] = 0;
   out_4755487058871820930[1] = 9.8100000000000005*cos(state[1]);
   out_4755487058871820930[2] = 0;
   out_4755487058871820930[3] = 0;
   out_4755487058871820930[4] = -state[8];
   out_4755487058871820930[5] = state[7];
   out_4755487058871820930[6] = 0;
   out_4755487058871820930[7] = state[5];
   out_4755487058871820930[8] = -state[4];
   out_4755487058871820930[9] = 0;
   out_4755487058871820930[10] = 0;
   out_4755487058871820930[11] = 0;
   out_4755487058871820930[12] = 1;
   out_4755487058871820930[13] = 0;
   out_4755487058871820930[14] = 0;
   out_4755487058871820930[15] = 1;
   out_4755487058871820930[16] = 0;
   out_4755487058871820930[17] = 0;
   out_4755487058871820930[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4755487058871820930[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4755487058871820930[20] = 0;
   out_4755487058871820930[21] = state[8];
   out_4755487058871820930[22] = 0;
   out_4755487058871820930[23] = -state[6];
   out_4755487058871820930[24] = -state[5];
   out_4755487058871820930[25] = 0;
   out_4755487058871820930[26] = state[3];
   out_4755487058871820930[27] = 0;
   out_4755487058871820930[28] = 0;
   out_4755487058871820930[29] = 0;
   out_4755487058871820930[30] = 0;
   out_4755487058871820930[31] = 1;
   out_4755487058871820930[32] = 0;
   out_4755487058871820930[33] = 0;
   out_4755487058871820930[34] = 1;
   out_4755487058871820930[35] = 0;
   out_4755487058871820930[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4755487058871820930[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4755487058871820930[38] = 0;
   out_4755487058871820930[39] = -state[7];
   out_4755487058871820930[40] = state[6];
   out_4755487058871820930[41] = 0;
   out_4755487058871820930[42] = state[4];
   out_4755487058871820930[43] = -state[3];
   out_4755487058871820930[44] = 0;
   out_4755487058871820930[45] = 0;
   out_4755487058871820930[46] = 0;
   out_4755487058871820930[47] = 0;
   out_4755487058871820930[48] = 0;
   out_4755487058871820930[49] = 0;
   out_4755487058871820930[50] = 1;
   out_4755487058871820930[51] = 0;
   out_4755487058871820930[52] = 0;
   out_4755487058871820930[53] = 1;
}
void h_13(double *state, double *unused, double *out_1411407947792615959) {
   out_1411407947792615959[0] = state[3];
   out_1411407947792615959[1] = state[4];
   out_1411407947792615959[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5523939480853185862) {
   out_5523939480853185862[0] = 0;
   out_5523939480853185862[1] = 0;
   out_5523939480853185862[2] = 0;
   out_5523939480853185862[3] = 1;
   out_5523939480853185862[4] = 0;
   out_5523939480853185862[5] = 0;
   out_5523939480853185862[6] = 0;
   out_5523939480853185862[7] = 0;
   out_5523939480853185862[8] = 0;
   out_5523939480853185862[9] = 0;
   out_5523939480853185862[10] = 0;
   out_5523939480853185862[11] = 0;
   out_5523939480853185862[12] = 0;
   out_5523939480853185862[13] = 0;
   out_5523939480853185862[14] = 0;
   out_5523939480853185862[15] = 0;
   out_5523939480853185862[16] = 0;
   out_5523939480853185862[17] = 0;
   out_5523939480853185862[18] = 0;
   out_5523939480853185862[19] = 0;
   out_5523939480853185862[20] = 0;
   out_5523939480853185862[21] = 0;
   out_5523939480853185862[22] = 1;
   out_5523939480853185862[23] = 0;
   out_5523939480853185862[24] = 0;
   out_5523939480853185862[25] = 0;
   out_5523939480853185862[26] = 0;
   out_5523939480853185862[27] = 0;
   out_5523939480853185862[28] = 0;
   out_5523939480853185862[29] = 0;
   out_5523939480853185862[30] = 0;
   out_5523939480853185862[31] = 0;
   out_5523939480853185862[32] = 0;
   out_5523939480853185862[33] = 0;
   out_5523939480853185862[34] = 0;
   out_5523939480853185862[35] = 0;
   out_5523939480853185862[36] = 0;
   out_5523939480853185862[37] = 0;
   out_5523939480853185862[38] = 0;
   out_5523939480853185862[39] = 0;
   out_5523939480853185862[40] = 0;
   out_5523939480853185862[41] = 1;
   out_5523939480853185862[42] = 0;
   out_5523939480853185862[43] = 0;
   out_5523939480853185862[44] = 0;
   out_5523939480853185862[45] = 0;
   out_5523939480853185862[46] = 0;
   out_5523939480853185862[47] = 0;
   out_5523939480853185862[48] = 0;
   out_5523939480853185862[49] = 0;
   out_5523939480853185862[50] = 0;
   out_5523939480853185862[51] = 0;
   out_5523939480853185862[52] = 0;
   out_5523939480853185862[53] = 0;
}
void h_14(double *state, double *unused, double *out_6092695006911058612) {
   out_6092695006911058612[0] = state[6];
   out_6092695006911058612[1] = state[7];
   out_6092695006911058612[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4772972449846034134) {
   out_4772972449846034134[0] = 0;
   out_4772972449846034134[1] = 0;
   out_4772972449846034134[2] = 0;
   out_4772972449846034134[3] = 0;
   out_4772972449846034134[4] = 0;
   out_4772972449846034134[5] = 0;
   out_4772972449846034134[6] = 1;
   out_4772972449846034134[7] = 0;
   out_4772972449846034134[8] = 0;
   out_4772972449846034134[9] = 0;
   out_4772972449846034134[10] = 0;
   out_4772972449846034134[11] = 0;
   out_4772972449846034134[12] = 0;
   out_4772972449846034134[13] = 0;
   out_4772972449846034134[14] = 0;
   out_4772972449846034134[15] = 0;
   out_4772972449846034134[16] = 0;
   out_4772972449846034134[17] = 0;
   out_4772972449846034134[18] = 0;
   out_4772972449846034134[19] = 0;
   out_4772972449846034134[20] = 0;
   out_4772972449846034134[21] = 0;
   out_4772972449846034134[22] = 0;
   out_4772972449846034134[23] = 0;
   out_4772972449846034134[24] = 0;
   out_4772972449846034134[25] = 1;
   out_4772972449846034134[26] = 0;
   out_4772972449846034134[27] = 0;
   out_4772972449846034134[28] = 0;
   out_4772972449846034134[29] = 0;
   out_4772972449846034134[30] = 0;
   out_4772972449846034134[31] = 0;
   out_4772972449846034134[32] = 0;
   out_4772972449846034134[33] = 0;
   out_4772972449846034134[34] = 0;
   out_4772972449846034134[35] = 0;
   out_4772972449846034134[36] = 0;
   out_4772972449846034134[37] = 0;
   out_4772972449846034134[38] = 0;
   out_4772972449846034134[39] = 0;
   out_4772972449846034134[40] = 0;
   out_4772972449846034134[41] = 0;
   out_4772972449846034134[42] = 0;
   out_4772972449846034134[43] = 0;
   out_4772972449846034134[44] = 1;
   out_4772972449846034134[45] = 0;
   out_4772972449846034134[46] = 0;
   out_4772972449846034134[47] = 0;
   out_4772972449846034134[48] = 0;
   out_4772972449846034134[49] = 0;
   out_4772972449846034134[50] = 0;
   out_4772972449846034134[51] = 0;
   out_4772972449846034134[52] = 0;
   out_4772972449846034134[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_9028216625099161166) {
  err_fun(nom_x, delta_x, out_9028216625099161166);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_2624079605359324205) {
  inv_err_fun(nom_x, true_x, out_2624079605359324205);
}
void pose_H_mod_fun(double *state, double *out_972334535441043815) {
  H_mod_fun(state, out_972334535441043815);
}
void pose_f_fun(double *state, double dt, double *out_7289866408532454147) {
  f_fun(state,  dt, out_7289866408532454147);
}
void pose_F_fun(double *state, double dt, double *out_5129072898910106972) {
  F_fun(state,  dt, out_5129072898910106972);
}
void pose_h_4(double *state, double *unused, double *out_274913422982768076) {
  h_4(state, unused, out_274913422982768076);
}
void pose_H_4(double *state, double *unused, double *out_8736213306185518663) {
  H_4(state, unused, out_8736213306185518663);
}
void pose_h_10(double *state, double *unused, double *out_2711486389137712832) {
  h_10(state, unused, out_2711486389137712832);
}
void pose_H_10(double *state, double *unused, double *out_4755487058871820930) {
  H_10(state, unused, out_4755487058871820930);
}
void pose_h_13(double *state, double *unused, double *out_1411407947792615959) {
  h_13(state, unused, out_1411407947792615959);
}
void pose_H_13(double *state, double *unused, double *out_5523939480853185862) {
  H_13(state, unused, out_5523939480853185862);
}
void pose_h_14(double *state, double *unused, double *out_6092695006911058612) {
  h_14(state, unused, out_6092695006911058612);
}
void pose_H_14(double *state, double *unused, double *out_4772972449846034134) {
  H_14(state, unused, out_4772972449846034134);
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
