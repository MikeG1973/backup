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
void err_fun(double *nom_x, double *delta_x, double *out_2460299454592738255) {
   out_2460299454592738255[0] = delta_x[0] + nom_x[0];
   out_2460299454592738255[1] = delta_x[1] + nom_x[1];
   out_2460299454592738255[2] = delta_x[2] + nom_x[2];
   out_2460299454592738255[3] = delta_x[3] + nom_x[3];
   out_2460299454592738255[4] = delta_x[4] + nom_x[4];
   out_2460299454592738255[5] = delta_x[5] + nom_x[5];
   out_2460299454592738255[6] = delta_x[6] + nom_x[6];
   out_2460299454592738255[7] = delta_x[7] + nom_x[7];
   out_2460299454592738255[8] = delta_x[8] + nom_x[8];
   out_2460299454592738255[9] = delta_x[9] + nom_x[9];
   out_2460299454592738255[10] = delta_x[10] + nom_x[10];
   out_2460299454592738255[11] = delta_x[11] + nom_x[11];
   out_2460299454592738255[12] = delta_x[12] + nom_x[12];
   out_2460299454592738255[13] = delta_x[13] + nom_x[13];
   out_2460299454592738255[14] = delta_x[14] + nom_x[14];
   out_2460299454592738255[15] = delta_x[15] + nom_x[15];
   out_2460299454592738255[16] = delta_x[16] + nom_x[16];
   out_2460299454592738255[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8995815424751717243) {
   out_8995815424751717243[0] = -nom_x[0] + true_x[0];
   out_8995815424751717243[1] = -nom_x[1] + true_x[1];
   out_8995815424751717243[2] = -nom_x[2] + true_x[2];
   out_8995815424751717243[3] = -nom_x[3] + true_x[3];
   out_8995815424751717243[4] = -nom_x[4] + true_x[4];
   out_8995815424751717243[5] = -nom_x[5] + true_x[5];
   out_8995815424751717243[6] = -nom_x[6] + true_x[6];
   out_8995815424751717243[7] = -nom_x[7] + true_x[7];
   out_8995815424751717243[8] = -nom_x[8] + true_x[8];
   out_8995815424751717243[9] = -nom_x[9] + true_x[9];
   out_8995815424751717243[10] = -nom_x[10] + true_x[10];
   out_8995815424751717243[11] = -nom_x[11] + true_x[11];
   out_8995815424751717243[12] = -nom_x[12] + true_x[12];
   out_8995815424751717243[13] = -nom_x[13] + true_x[13];
   out_8995815424751717243[14] = -nom_x[14] + true_x[14];
   out_8995815424751717243[15] = -nom_x[15] + true_x[15];
   out_8995815424751717243[16] = -nom_x[16] + true_x[16];
   out_8995815424751717243[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_172106315147157204) {
   out_172106315147157204[0] = 1.0;
   out_172106315147157204[1] = 0.0;
   out_172106315147157204[2] = 0.0;
   out_172106315147157204[3] = 0.0;
   out_172106315147157204[4] = 0.0;
   out_172106315147157204[5] = 0.0;
   out_172106315147157204[6] = 0.0;
   out_172106315147157204[7] = 0.0;
   out_172106315147157204[8] = 0.0;
   out_172106315147157204[9] = 0.0;
   out_172106315147157204[10] = 0.0;
   out_172106315147157204[11] = 0.0;
   out_172106315147157204[12] = 0.0;
   out_172106315147157204[13] = 0.0;
   out_172106315147157204[14] = 0.0;
   out_172106315147157204[15] = 0.0;
   out_172106315147157204[16] = 0.0;
   out_172106315147157204[17] = 0.0;
   out_172106315147157204[18] = 0.0;
   out_172106315147157204[19] = 1.0;
   out_172106315147157204[20] = 0.0;
   out_172106315147157204[21] = 0.0;
   out_172106315147157204[22] = 0.0;
   out_172106315147157204[23] = 0.0;
   out_172106315147157204[24] = 0.0;
   out_172106315147157204[25] = 0.0;
   out_172106315147157204[26] = 0.0;
   out_172106315147157204[27] = 0.0;
   out_172106315147157204[28] = 0.0;
   out_172106315147157204[29] = 0.0;
   out_172106315147157204[30] = 0.0;
   out_172106315147157204[31] = 0.0;
   out_172106315147157204[32] = 0.0;
   out_172106315147157204[33] = 0.0;
   out_172106315147157204[34] = 0.0;
   out_172106315147157204[35] = 0.0;
   out_172106315147157204[36] = 0.0;
   out_172106315147157204[37] = 0.0;
   out_172106315147157204[38] = 1.0;
   out_172106315147157204[39] = 0.0;
   out_172106315147157204[40] = 0.0;
   out_172106315147157204[41] = 0.0;
   out_172106315147157204[42] = 0.0;
   out_172106315147157204[43] = 0.0;
   out_172106315147157204[44] = 0.0;
   out_172106315147157204[45] = 0.0;
   out_172106315147157204[46] = 0.0;
   out_172106315147157204[47] = 0.0;
   out_172106315147157204[48] = 0.0;
   out_172106315147157204[49] = 0.0;
   out_172106315147157204[50] = 0.0;
   out_172106315147157204[51] = 0.0;
   out_172106315147157204[52] = 0.0;
   out_172106315147157204[53] = 0.0;
   out_172106315147157204[54] = 0.0;
   out_172106315147157204[55] = 0.0;
   out_172106315147157204[56] = 0.0;
   out_172106315147157204[57] = 1.0;
   out_172106315147157204[58] = 0.0;
   out_172106315147157204[59] = 0.0;
   out_172106315147157204[60] = 0.0;
   out_172106315147157204[61] = 0.0;
   out_172106315147157204[62] = 0.0;
   out_172106315147157204[63] = 0.0;
   out_172106315147157204[64] = 0.0;
   out_172106315147157204[65] = 0.0;
   out_172106315147157204[66] = 0.0;
   out_172106315147157204[67] = 0.0;
   out_172106315147157204[68] = 0.0;
   out_172106315147157204[69] = 0.0;
   out_172106315147157204[70] = 0.0;
   out_172106315147157204[71] = 0.0;
   out_172106315147157204[72] = 0.0;
   out_172106315147157204[73] = 0.0;
   out_172106315147157204[74] = 0.0;
   out_172106315147157204[75] = 0.0;
   out_172106315147157204[76] = 1.0;
   out_172106315147157204[77] = 0.0;
   out_172106315147157204[78] = 0.0;
   out_172106315147157204[79] = 0.0;
   out_172106315147157204[80] = 0.0;
   out_172106315147157204[81] = 0.0;
   out_172106315147157204[82] = 0.0;
   out_172106315147157204[83] = 0.0;
   out_172106315147157204[84] = 0.0;
   out_172106315147157204[85] = 0.0;
   out_172106315147157204[86] = 0.0;
   out_172106315147157204[87] = 0.0;
   out_172106315147157204[88] = 0.0;
   out_172106315147157204[89] = 0.0;
   out_172106315147157204[90] = 0.0;
   out_172106315147157204[91] = 0.0;
   out_172106315147157204[92] = 0.0;
   out_172106315147157204[93] = 0.0;
   out_172106315147157204[94] = 0.0;
   out_172106315147157204[95] = 1.0;
   out_172106315147157204[96] = 0.0;
   out_172106315147157204[97] = 0.0;
   out_172106315147157204[98] = 0.0;
   out_172106315147157204[99] = 0.0;
   out_172106315147157204[100] = 0.0;
   out_172106315147157204[101] = 0.0;
   out_172106315147157204[102] = 0.0;
   out_172106315147157204[103] = 0.0;
   out_172106315147157204[104] = 0.0;
   out_172106315147157204[105] = 0.0;
   out_172106315147157204[106] = 0.0;
   out_172106315147157204[107] = 0.0;
   out_172106315147157204[108] = 0.0;
   out_172106315147157204[109] = 0.0;
   out_172106315147157204[110] = 0.0;
   out_172106315147157204[111] = 0.0;
   out_172106315147157204[112] = 0.0;
   out_172106315147157204[113] = 0.0;
   out_172106315147157204[114] = 1.0;
   out_172106315147157204[115] = 0.0;
   out_172106315147157204[116] = 0.0;
   out_172106315147157204[117] = 0.0;
   out_172106315147157204[118] = 0.0;
   out_172106315147157204[119] = 0.0;
   out_172106315147157204[120] = 0.0;
   out_172106315147157204[121] = 0.0;
   out_172106315147157204[122] = 0.0;
   out_172106315147157204[123] = 0.0;
   out_172106315147157204[124] = 0.0;
   out_172106315147157204[125] = 0.0;
   out_172106315147157204[126] = 0.0;
   out_172106315147157204[127] = 0.0;
   out_172106315147157204[128] = 0.0;
   out_172106315147157204[129] = 0.0;
   out_172106315147157204[130] = 0.0;
   out_172106315147157204[131] = 0.0;
   out_172106315147157204[132] = 0.0;
   out_172106315147157204[133] = 1.0;
   out_172106315147157204[134] = 0.0;
   out_172106315147157204[135] = 0.0;
   out_172106315147157204[136] = 0.0;
   out_172106315147157204[137] = 0.0;
   out_172106315147157204[138] = 0.0;
   out_172106315147157204[139] = 0.0;
   out_172106315147157204[140] = 0.0;
   out_172106315147157204[141] = 0.0;
   out_172106315147157204[142] = 0.0;
   out_172106315147157204[143] = 0.0;
   out_172106315147157204[144] = 0.0;
   out_172106315147157204[145] = 0.0;
   out_172106315147157204[146] = 0.0;
   out_172106315147157204[147] = 0.0;
   out_172106315147157204[148] = 0.0;
   out_172106315147157204[149] = 0.0;
   out_172106315147157204[150] = 0.0;
   out_172106315147157204[151] = 0.0;
   out_172106315147157204[152] = 1.0;
   out_172106315147157204[153] = 0.0;
   out_172106315147157204[154] = 0.0;
   out_172106315147157204[155] = 0.0;
   out_172106315147157204[156] = 0.0;
   out_172106315147157204[157] = 0.0;
   out_172106315147157204[158] = 0.0;
   out_172106315147157204[159] = 0.0;
   out_172106315147157204[160] = 0.0;
   out_172106315147157204[161] = 0.0;
   out_172106315147157204[162] = 0.0;
   out_172106315147157204[163] = 0.0;
   out_172106315147157204[164] = 0.0;
   out_172106315147157204[165] = 0.0;
   out_172106315147157204[166] = 0.0;
   out_172106315147157204[167] = 0.0;
   out_172106315147157204[168] = 0.0;
   out_172106315147157204[169] = 0.0;
   out_172106315147157204[170] = 0.0;
   out_172106315147157204[171] = 1.0;
   out_172106315147157204[172] = 0.0;
   out_172106315147157204[173] = 0.0;
   out_172106315147157204[174] = 0.0;
   out_172106315147157204[175] = 0.0;
   out_172106315147157204[176] = 0.0;
   out_172106315147157204[177] = 0.0;
   out_172106315147157204[178] = 0.0;
   out_172106315147157204[179] = 0.0;
   out_172106315147157204[180] = 0.0;
   out_172106315147157204[181] = 0.0;
   out_172106315147157204[182] = 0.0;
   out_172106315147157204[183] = 0.0;
   out_172106315147157204[184] = 0.0;
   out_172106315147157204[185] = 0.0;
   out_172106315147157204[186] = 0.0;
   out_172106315147157204[187] = 0.0;
   out_172106315147157204[188] = 0.0;
   out_172106315147157204[189] = 0.0;
   out_172106315147157204[190] = 1.0;
   out_172106315147157204[191] = 0.0;
   out_172106315147157204[192] = 0.0;
   out_172106315147157204[193] = 0.0;
   out_172106315147157204[194] = 0.0;
   out_172106315147157204[195] = 0.0;
   out_172106315147157204[196] = 0.0;
   out_172106315147157204[197] = 0.0;
   out_172106315147157204[198] = 0.0;
   out_172106315147157204[199] = 0.0;
   out_172106315147157204[200] = 0.0;
   out_172106315147157204[201] = 0.0;
   out_172106315147157204[202] = 0.0;
   out_172106315147157204[203] = 0.0;
   out_172106315147157204[204] = 0.0;
   out_172106315147157204[205] = 0.0;
   out_172106315147157204[206] = 0.0;
   out_172106315147157204[207] = 0.0;
   out_172106315147157204[208] = 0.0;
   out_172106315147157204[209] = 1.0;
   out_172106315147157204[210] = 0.0;
   out_172106315147157204[211] = 0.0;
   out_172106315147157204[212] = 0.0;
   out_172106315147157204[213] = 0.0;
   out_172106315147157204[214] = 0.0;
   out_172106315147157204[215] = 0.0;
   out_172106315147157204[216] = 0.0;
   out_172106315147157204[217] = 0.0;
   out_172106315147157204[218] = 0.0;
   out_172106315147157204[219] = 0.0;
   out_172106315147157204[220] = 0.0;
   out_172106315147157204[221] = 0.0;
   out_172106315147157204[222] = 0.0;
   out_172106315147157204[223] = 0.0;
   out_172106315147157204[224] = 0.0;
   out_172106315147157204[225] = 0.0;
   out_172106315147157204[226] = 0.0;
   out_172106315147157204[227] = 0.0;
   out_172106315147157204[228] = 1.0;
   out_172106315147157204[229] = 0.0;
   out_172106315147157204[230] = 0.0;
   out_172106315147157204[231] = 0.0;
   out_172106315147157204[232] = 0.0;
   out_172106315147157204[233] = 0.0;
   out_172106315147157204[234] = 0.0;
   out_172106315147157204[235] = 0.0;
   out_172106315147157204[236] = 0.0;
   out_172106315147157204[237] = 0.0;
   out_172106315147157204[238] = 0.0;
   out_172106315147157204[239] = 0.0;
   out_172106315147157204[240] = 0.0;
   out_172106315147157204[241] = 0.0;
   out_172106315147157204[242] = 0.0;
   out_172106315147157204[243] = 0.0;
   out_172106315147157204[244] = 0.0;
   out_172106315147157204[245] = 0.0;
   out_172106315147157204[246] = 0.0;
   out_172106315147157204[247] = 1.0;
   out_172106315147157204[248] = 0.0;
   out_172106315147157204[249] = 0.0;
   out_172106315147157204[250] = 0.0;
   out_172106315147157204[251] = 0.0;
   out_172106315147157204[252] = 0.0;
   out_172106315147157204[253] = 0.0;
   out_172106315147157204[254] = 0.0;
   out_172106315147157204[255] = 0.0;
   out_172106315147157204[256] = 0.0;
   out_172106315147157204[257] = 0.0;
   out_172106315147157204[258] = 0.0;
   out_172106315147157204[259] = 0.0;
   out_172106315147157204[260] = 0.0;
   out_172106315147157204[261] = 0.0;
   out_172106315147157204[262] = 0.0;
   out_172106315147157204[263] = 0.0;
   out_172106315147157204[264] = 0.0;
   out_172106315147157204[265] = 0.0;
   out_172106315147157204[266] = 1.0;
   out_172106315147157204[267] = 0.0;
   out_172106315147157204[268] = 0.0;
   out_172106315147157204[269] = 0.0;
   out_172106315147157204[270] = 0.0;
   out_172106315147157204[271] = 0.0;
   out_172106315147157204[272] = 0.0;
   out_172106315147157204[273] = 0.0;
   out_172106315147157204[274] = 0.0;
   out_172106315147157204[275] = 0.0;
   out_172106315147157204[276] = 0.0;
   out_172106315147157204[277] = 0.0;
   out_172106315147157204[278] = 0.0;
   out_172106315147157204[279] = 0.0;
   out_172106315147157204[280] = 0.0;
   out_172106315147157204[281] = 0.0;
   out_172106315147157204[282] = 0.0;
   out_172106315147157204[283] = 0.0;
   out_172106315147157204[284] = 0.0;
   out_172106315147157204[285] = 1.0;
   out_172106315147157204[286] = 0.0;
   out_172106315147157204[287] = 0.0;
   out_172106315147157204[288] = 0.0;
   out_172106315147157204[289] = 0.0;
   out_172106315147157204[290] = 0.0;
   out_172106315147157204[291] = 0.0;
   out_172106315147157204[292] = 0.0;
   out_172106315147157204[293] = 0.0;
   out_172106315147157204[294] = 0.0;
   out_172106315147157204[295] = 0.0;
   out_172106315147157204[296] = 0.0;
   out_172106315147157204[297] = 0.0;
   out_172106315147157204[298] = 0.0;
   out_172106315147157204[299] = 0.0;
   out_172106315147157204[300] = 0.0;
   out_172106315147157204[301] = 0.0;
   out_172106315147157204[302] = 0.0;
   out_172106315147157204[303] = 0.0;
   out_172106315147157204[304] = 1.0;
   out_172106315147157204[305] = 0.0;
   out_172106315147157204[306] = 0.0;
   out_172106315147157204[307] = 0.0;
   out_172106315147157204[308] = 0.0;
   out_172106315147157204[309] = 0.0;
   out_172106315147157204[310] = 0.0;
   out_172106315147157204[311] = 0.0;
   out_172106315147157204[312] = 0.0;
   out_172106315147157204[313] = 0.0;
   out_172106315147157204[314] = 0.0;
   out_172106315147157204[315] = 0.0;
   out_172106315147157204[316] = 0.0;
   out_172106315147157204[317] = 0.0;
   out_172106315147157204[318] = 0.0;
   out_172106315147157204[319] = 0.0;
   out_172106315147157204[320] = 0.0;
   out_172106315147157204[321] = 0.0;
   out_172106315147157204[322] = 0.0;
   out_172106315147157204[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5576179949216863693) {
   out_5576179949216863693[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5576179949216863693[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5576179949216863693[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5576179949216863693[3] = dt*state[12] + state[3];
   out_5576179949216863693[4] = dt*state[13] + state[4];
   out_5576179949216863693[5] = dt*state[14] + state[5];
   out_5576179949216863693[6] = state[6];
   out_5576179949216863693[7] = state[7];
   out_5576179949216863693[8] = state[8];
   out_5576179949216863693[9] = state[9];
   out_5576179949216863693[10] = state[10];
   out_5576179949216863693[11] = state[11];
   out_5576179949216863693[12] = state[12];
   out_5576179949216863693[13] = state[13];
   out_5576179949216863693[14] = state[14];
   out_5576179949216863693[15] = state[15];
   out_5576179949216863693[16] = state[16];
   out_5576179949216863693[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1077355707621539238) {
   out_1077355707621539238[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1077355707621539238[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1077355707621539238[2] = 0;
   out_1077355707621539238[3] = 0;
   out_1077355707621539238[4] = 0;
   out_1077355707621539238[5] = 0;
   out_1077355707621539238[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1077355707621539238[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1077355707621539238[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1077355707621539238[9] = 0;
   out_1077355707621539238[10] = 0;
   out_1077355707621539238[11] = 0;
   out_1077355707621539238[12] = 0;
   out_1077355707621539238[13] = 0;
   out_1077355707621539238[14] = 0;
   out_1077355707621539238[15] = 0;
   out_1077355707621539238[16] = 0;
   out_1077355707621539238[17] = 0;
   out_1077355707621539238[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1077355707621539238[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1077355707621539238[20] = 0;
   out_1077355707621539238[21] = 0;
   out_1077355707621539238[22] = 0;
   out_1077355707621539238[23] = 0;
   out_1077355707621539238[24] = 0;
   out_1077355707621539238[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1077355707621539238[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1077355707621539238[27] = 0;
   out_1077355707621539238[28] = 0;
   out_1077355707621539238[29] = 0;
   out_1077355707621539238[30] = 0;
   out_1077355707621539238[31] = 0;
   out_1077355707621539238[32] = 0;
   out_1077355707621539238[33] = 0;
   out_1077355707621539238[34] = 0;
   out_1077355707621539238[35] = 0;
   out_1077355707621539238[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1077355707621539238[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1077355707621539238[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1077355707621539238[39] = 0;
   out_1077355707621539238[40] = 0;
   out_1077355707621539238[41] = 0;
   out_1077355707621539238[42] = 0;
   out_1077355707621539238[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1077355707621539238[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1077355707621539238[45] = 0;
   out_1077355707621539238[46] = 0;
   out_1077355707621539238[47] = 0;
   out_1077355707621539238[48] = 0;
   out_1077355707621539238[49] = 0;
   out_1077355707621539238[50] = 0;
   out_1077355707621539238[51] = 0;
   out_1077355707621539238[52] = 0;
   out_1077355707621539238[53] = 0;
   out_1077355707621539238[54] = 0;
   out_1077355707621539238[55] = 0;
   out_1077355707621539238[56] = 0;
   out_1077355707621539238[57] = 1;
   out_1077355707621539238[58] = 0;
   out_1077355707621539238[59] = 0;
   out_1077355707621539238[60] = 0;
   out_1077355707621539238[61] = 0;
   out_1077355707621539238[62] = 0;
   out_1077355707621539238[63] = 0;
   out_1077355707621539238[64] = 0;
   out_1077355707621539238[65] = 0;
   out_1077355707621539238[66] = dt;
   out_1077355707621539238[67] = 0;
   out_1077355707621539238[68] = 0;
   out_1077355707621539238[69] = 0;
   out_1077355707621539238[70] = 0;
   out_1077355707621539238[71] = 0;
   out_1077355707621539238[72] = 0;
   out_1077355707621539238[73] = 0;
   out_1077355707621539238[74] = 0;
   out_1077355707621539238[75] = 0;
   out_1077355707621539238[76] = 1;
   out_1077355707621539238[77] = 0;
   out_1077355707621539238[78] = 0;
   out_1077355707621539238[79] = 0;
   out_1077355707621539238[80] = 0;
   out_1077355707621539238[81] = 0;
   out_1077355707621539238[82] = 0;
   out_1077355707621539238[83] = 0;
   out_1077355707621539238[84] = 0;
   out_1077355707621539238[85] = dt;
   out_1077355707621539238[86] = 0;
   out_1077355707621539238[87] = 0;
   out_1077355707621539238[88] = 0;
   out_1077355707621539238[89] = 0;
   out_1077355707621539238[90] = 0;
   out_1077355707621539238[91] = 0;
   out_1077355707621539238[92] = 0;
   out_1077355707621539238[93] = 0;
   out_1077355707621539238[94] = 0;
   out_1077355707621539238[95] = 1;
   out_1077355707621539238[96] = 0;
   out_1077355707621539238[97] = 0;
   out_1077355707621539238[98] = 0;
   out_1077355707621539238[99] = 0;
   out_1077355707621539238[100] = 0;
   out_1077355707621539238[101] = 0;
   out_1077355707621539238[102] = 0;
   out_1077355707621539238[103] = 0;
   out_1077355707621539238[104] = dt;
   out_1077355707621539238[105] = 0;
   out_1077355707621539238[106] = 0;
   out_1077355707621539238[107] = 0;
   out_1077355707621539238[108] = 0;
   out_1077355707621539238[109] = 0;
   out_1077355707621539238[110] = 0;
   out_1077355707621539238[111] = 0;
   out_1077355707621539238[112] = 0;
   out_1077355707621539238[113] = 0;
   out_1077355707621539238[114] = 1;
   out_1077355707621539238[115] = 0;
   out_1077355707621539238[116] = 0;
   out_1077355707621539238[117] = 0;
   out_1077355707621539238[118] = 0;
   out_1077355707621539238[119] = 0;
   out_1077355707621539238[120] = 0;
   out_1077355707621539238[121] = 0;
   out_1077355707621539238[122] = 0;
   out_1077355707621539238[123] = 0;
   out_1077355707621539238[124] = 0;
   out_1077355707621539238[125] = 0;
   out_1077355707621539238[126] = 0;
   out_1077355707621539238[127] = 0;
   out_1077355707621539238[128] = 0;
   out_1077355707621539238[129] = 0;
   out_1077355707621539238[130] = 0;
   out_1077355707621539238[131] = 0;
   out_1077355707621539238[132] = 0;
   out_1077355707621539238[133] = 1;
   out_1077355707621539238[134] = 0;
   out_1077355707621539238[135] = 0;
   out_1077355707621539238[136] = 0;
   out_1077355707621539238[137] = 0;
   out_1077355707621539238[138] = 0;
   out_1077355707621539238[139] = 0;
   out_1077355707621539238[140] = 0;
   out_1077355707621539238[141] = 0;
   out_1077355707621539238[142] = 0;
   out_1077355707621539238[143] = 0;
   out_1077355707621539238[144] = 0;
   out_1077355707621539238[145] = 0;
   out_1077355707621539238[146] = 0;
   out_1077355707621539238[147] = 0;
   out_1077355707621539238[148] = 0;
   out_1077355707621539238[149] = 0;
   out_1077355707621539238[150] = 0;
   out_1077355707621539238[151] = 0;
   out_1077355707621539238[152] = 1;
   out_1077355707621539238[153] = 0;
   out_1077355707621539238[154] = 0;
   out_1077355707621539238[155] = 0;
   out_1077355707621539238[156] = 0;
   out_1077355707621539238[157] = 0;
   out_1077355707621539238[158] = 0;
   out_1077355707621539238[159] = 0;
   out_1077355707621539238[160] = 0;
   out_1077355707621539238[161] = 0;
   out_1077355707621539238[162] = 0;
   out_1077355707621539238[163] = 0;
   out_1077355707621539238[164] = 0;
   out_1077355707621539238[165] = 0;
   out_1077355707621539238[166] = 0;
   out_1077355707621539238[167] = 0;
   out_1077355707621539238[168] = 0;
   out_1077355707621539238[169] = 0;
   out_1077355707621539238[170] = 0;
   out_1077355707621539238[171] = 1;
   out_1077355707621539238[172] = 0;
   out_1077355707621539238[173] = 0;
   out_1077355707621539238[174] = 0;
   out_1077355707621539238[175] = 0;
   out_1077355707621539238[176] = 0;
   out_1077355707621539238[177] = 0;
   out_1077355707621539238[178] = 0;
   out_1077355707621539238[179] = 0;
   out_1077355707621539238[180] = 0;
   out_1077355707621539238[181] = 0;
   out_1077355707621539238[182] = 0;
   out_1077355707621539238[183] = 0;
   out_1077355707621539238[184] = 0;
   out_1077355707621539238[185] = 0;
   out_1077355707621539238[186] = 0;
   out_1077355707621539238[187] = 0;
   out_1077355707621539238[188] = 0;
   out_1077355707621539238[189] = 0;
   out_1077355707621539238[190] = 1;
   out_1077355707621539238[191] = 0;
   out_1077355707621539238[192] = 0;
   out_1077355707621539238[193] = 0;
   out_1077355707621539238[194] = 0;
   out_1077355707621539238[195] = 0;
   out_1077355707621539238[196] = 0;
   out_1077355707621539238[197] = 0;
   out_1077355707621539238[198] = 0;
   out_1077355707621539238[199] = 0;
   out_1077355707621539238[200] = 0;
   out_1077355707621539238[201] = 0;
   out_1077355707621539238[202] = 0;
   out_1077355707621539238[203] = 0;
   out_1077355707621539238[204] = 0;
   out_1077355707621539238[205] = 0;
   out_1077355707621539238[206] = 0;
   out_1077355707621539238[207] = 0;
   out_1077355707621539238[208] = 0;
   out_1077355707621539238[209] = 1;
   out_1077355707621539238[210] = 0;
   out_1077355707621539238[211] = 0;
   out_1077355707621539238[212] = 0;
   out_1077355707621539238[213] = 0;
   out_1077355707621539238[214] = 0;
   out_1077355707621539238[215] = 0;
   out_1077355707621539238[216] = 0;
   out_1077355707621539238[217] = 0;
   out_1077355707621539238[218] = 0;
   out_1077355707621539238[219] = 0;
   out_1077355707621539238[220] = 0;
   out_1077355707621539238[221] = 0;
   out_1077355707621539238[222] = 0;
   out_1077355707621539238[223] = 0;
   out_1077355707621539238[224] = 0;
   out_1077355707621539238[225] = 0;
   out_1077355707621539238[226] = 0;
   out_1077355707621539238[227] = 0;
   out_1077355707621539238[228] = 1;
   out_1077355707621539238[229] = 0;
   out_1077355707621539238[230] = 0;
   out_1077355707621539238[231] = 0;
   out_1077355707621539238[232] = 0;
   out_1077355707621539238[233] = 0;
   out_1077355707621539238[234] = 0;
   out_1077355707621539238[235] = 0;
   out_1077355707621539238[236] = 0;
   out_1077355707621539238[237] = 0;
   out_1077355707621539238[238] = 0;
   out_1077355707621539238[239] = 0;
   out_1077355707621539238[240] = 0;
   out_1077355707621539238[241] = 0;
   out_1077355707621539238[242] = 0;
   out_1077355707621539238[243] = 0;
   out_1077355707621539238[244] = 0;
   out_1077355707621539238[245] = 0;
   out_1077355707621539238[246] = 0;
   out_1077355707621539238[247] = 1;
   out_1077355707621539238[248] = 0;
   out_1077355707621539238[249] = 0;
   out_1077355707621539238[250] = 0;
   out_1077355707621539238[251] = 0;
   out_1077355707621539238[252] = 0;
   out_1077355707621539238[253] = 0;
   out_1077355707621539238[254] = 0;
   out_1077355707621539238[255] = 0;
   out_1077355707621539238[256] = 0;
   out_1077355707621539238[257] = 0;
   out_1077355707621539238[258] = 0;
   out_1077355707621539238[259] = 0;
   out_1077355707621539238[260] = 0;
   out_1077355707621539238[261] = 0;
   out_1077355707621539238[262] = 0;
   out_1077355707621539238[263] = 0;
   out_1077355707621539238[264] = 0;
   out_1077355707621539238[265] = 0;
   out_1077355707621539238[266] = 1;
   out_1077355707621539238[267] = 0;
   out_1077355707621539238[268] = 0;
   out_1077355707621539238[269] = 0;
   out_1077355707621539238[270] = 0;
   out_1077355707621539238[271] = 0;
   out_1077355707621539238[272] = 0;
   out_1077355707621539238[273] = 0;
   out_1077355707621539238[274] = 0;
   out_1077355707621539238[275] = 0;
   out_1077355707621539238[276] = 0;
   out_1077355707621539238[277] = 0;
   out_1077355707621539238[278] = 0;
   out_1077355707621539238[279] = 0;
   out_1077355707621539238[280] = 0;
   out_1077355707621539238[281] = 0;
   out_1077355707621539238[282] = 0;
   out_1077355707621539238[283] = 0;
   out_1077355707621539238[284] = 0;
   out_1077355707621539238[285] = 1;
   out_1077355707621539238[286] = 0;
   out_1077355707621539238[287] = 0;
   out_1077355707621539238[288] = 0;
   out_1077355707621539238[289] = 0;
   out_1077355707621539238[290] = 0;
   out_1077355707621539238[291] = 0;
   out_1077355707621539238[292] = 0;
   out_1077355707621539238[293] = 0;
   out_1077355707621539238[294] = 0;
   out_1077355707621539238[295] = 0;
   out_1077355707621539238[296] = 0;
   out_1077355707621539238[297] = 0;
   out_1077355707621539238[298] = 0;
   out_1077355707621539238[299] = 0;
   out_1077355707621539238[300] = 0;
   out_1077355707621539238[301] = 0;
   out_1077355707621539238[302] = 0;
   out_1077355707621539238[303] = 0;
   out_1077355707621539238[304] = 1;
   out_1077355707621539238[305] = 0;
   out_1077355707621539238[306] = 0;
   out_1077355707621539238[307] = 0;
   out_1077355707621539238[308] = 0;
   out_1077355707621539238[309] = 0;
   out_1077355707621539238[310] = 0;
   out_1077355707621539238[311] = 0;
   out_1077355707621539238[312] = 0;
   out_1077355707621539238[313] = 0;
   out_1077355707621539238[314] = 0;
   out_1077355707621539238[315] = 0;
   out_1077355707621539238[316] = 0;
   out_1077355707621539238[317] = 0;
   out_1077355707621539238[318] = 0;
   out_1077355707621539238[319] = 0;
   out_1077355707621539238[320] = 0;
   out_1077355707621539238[321] = 0;
   out_1077355707621539238[322] = 0;
   out_1077355707621539238[323] = 1;
}
void h_4(double *state, double *unused, double *out_1380760196569112767) {
   out_1380760196569112767[0] = state[6] + state[9];
   out_1380760196569112767[1] = state[7] + state[10];
   out_1380760196569112767[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3943913524991064776) {
   out_3943913524991064776[0] = 0;
   out_3943913524991064776[1] = 0;
   out_3943913524991064776[2] = 0;
   out_3943913524991064776[3] = 0;
   out_3943913524991064776[4] = 0;
   out_3943913524991064776[5] = 0;
   out_3943913524991064776[6] = 1;
   out_3943913524991064776[7] = 0;
   out_3943913524991064776[8] = 0;
   out_3943913524991064776[9] = 1;
   out_3943913524991064776[10] = 0;
   out_3943913524991064776[11] = 0;
   out_3943913524991064776[12] = 0;
   out_3943913524991064776[13] = 0;
   out_3943913524991064776[14] = 0;
   out_3943913524991064776[15] = 0;
   out_3943913524991064776[16] = 0;
   out_3943913524991064776[17] = 0;
   out_3943913524991064776[18] = 0;
   out_3943913524991064776[19] = 0;
   out_3943913524991064776[20] = 0;
   out_3943913524991064776[21] = 0;
   out_3943913524991064776[22] = 0;
   out_3943913524991064776[23] = 0;
   out_3943913524991064776[24] = 0;
   out_3943913524991064776[25] = 1;
   out_3943913524991064776[26] = 0;
   out_3943913524991064776[27] = 0;
   out_3943913524991064776[28] = 1;
   out_3943913524991064776[29] = 0;
   out_3943913524991064776[30] = 0;
   out_3943913524991064776[31] = 0;
   out_3943913524991064776[32] = 0;
   out_3943913524991064776[33] = 0;
   out_3943913524991064776[34] = 0;
   out_3943913524991064776[35] = 0;
   out_3943913524991064776[36] = 0;
   out_3943913524991064776[37] = 0;
   out_3943913524991064776[38] = 0;
   out_3943913524991064776[39] = 0;
   out_3943913524991064776[40] = 0;
   out_3943913524991064776[41] = 0;
   out_3943913524991064776[42] = 0;
   out_3943913524991064776[43] = 0;
   out_3943913524991064776[44] = 1;
   out_3943913524991064776[45] = 0;
   out_3943913524991064776[46] = 0;
   out_3943913524991064776[47] = 1;
   out_3943913524991064776[48] = 0;
   out_3943913524991064776[49] = 0;
   out_3943913524991064776[50] = 0;
   out_3943913524991064776[51] = 0;
   out_3943913524991064776[52] = 0;
   out_3943913524991064776[53] = 0;
}
void h_10(double *state, double *unused, double *out_8331647754590399) {
   out_8331647754590399[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_8331647754590399[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_8331647754590399[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4674971023882599542) {
   out_4674971023882599542[0] = 0;
   out_4674971023882599542[1] = 9.8100000000000005*cos(state[1]);
   out_4674971023882599542[2] = 0;
   out_4674971023882599542[3] = 0;
   out_4674971023882599542[4] = -state[8];
   out_4674971023882599542[5] = state[7];
   out_4674971023882599542[6] = 0;
   out_4674971023882599542[7] = state[5];
   out_4674971023882599542[8] = -state[4];
   out_4674971023882599542[9] = 0;
   out_4674971023882599542[10] = 0;
   out_4674971023882599542[11] = 0;
   out_4674971023882599542[12] = 1;
   out_4674971023882599542[13] = 0;
   out_4674971023882599542[14] = 0;
   out_4674971023882599542[15] = 1;
   out_4674971023882599542[16] = 0;
   out_4674971023882599542[17] = 0;
   out_4674971023882599542[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4674971023882599542[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4674971023882599542[20] = 0;
   out_4674971023882599542[21] = state[8];
   out_4674971023882599542[22] = 0;
   out_4674971023882599542[23] = -state[6];
   out_4674971023882599542[24] = -state[5];
   out_4674971023882599542[25] = 0;
   out_4674971023882599542[26] = state[3];
   out_4674971023882599542[27] = 0;
   out_4674971023882599542[28] = 0;
   out_4674971023882599542[29] = 0;
   out_4674971023882599542[30] = 0;
   out_4674971023882599542[31] = 1;
   out_4674971023882599542[32] = 0;
   out_4674971023882599542[33] = 0;
   out_4674971023882599542[34] = 1;
   out_4674971023882599542[35] = 0;
   out_4674971023882599542[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4674971023882599542[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4674971023882599542[38] = 0;
   out_4674971023882599542[39] = -state[7];
   out_4674971023882599542[40] = state[6];
   out_4674971023882599542[41] = 0;
   out_4674971023882599542[42] = state[4];
   out_4674971023882599542[43] = -state[3];
   out_4674971023882599542[44] = 0;
   out_4674971023882599542[45] = 0;
   out_4674971023882599542[46] = 0;
   out_4674971023882599542[47] = 0;
   out_4674971023882599542[48] = 0;
   out_4674971023882599542[49] = 0;
   out_4674971023882599542[50] = 1;
   out_4674971023882599542[51] = 0;
   out_4674971023882599542[52] = 0;
   out_4674971023882599542[53] = 1;
}
void h_13(double *state, double *unused, double *out_7859661641013841480) {
   out_7859661641013841480[0] = state[3];
   out_7859661641013841480[1] = state[4];
   out_7859661641013841480[2] = state[5];
}
void H_13(double *state, double *unused, double *out_7156187350323397577) {
   out_7156187350323397577[0] = 0;
   out_7156187350323397577[1] = 0;
   out_7156187350323397577[2] = 0;
   out_7156187350323397577[3] = 1;
   out_7156187350323397577[4] = 0;
   out_7156187350323397577[5] = 0;
   out_7156187350323397577[6] = 0;
   out_7156187350323397577[7] = 0;
   out_7156187350323397577[8] = 0;
   out_7156187350323397577[9] = 0;
   out_7156187350323397577[10] = 0;
   out_7156187350323397577[11] = 0;
   out_7156187350323397577[12] = 0;
   out_7156187350323397577[13] = 0;
   out_7156187350323397577[14] = 0;
   out_7156187350323397577[15] = 0;
   out_7156187350323397577[16] = 0;
   out_7156187350323397577[17] = 0;
   out_7156187350323397577[18] = 0;
   out_7156187350323397577[19] = 0;
   out_7156187350323397577[20] = 0;
   out_7156187350323397577[21] = 0;
   out_7156187350323397577[22] = 1;
   out_7156187350323397577[23] = 0;
   out_7156187350323397577[24] = 0;
   out_7156187350323397577[25] = 0;
   out_7156187350323397577[26] = 0;
   out_7156187350323397577[27] = 0;
   out_7156187350323397577[28] = 0;
   out_7156187350323397577[29] = 0;
   out_7156187350323397577[30] = 0;
   out_7156187350323397577[31] = 0;
   out_7156187350323397577[32] = 0;
   out_7156187350323397577[33] = 0;
   out_7156187350323397577[34] = 0;
   out_7156187350323397577[35] = 0;
   out_7156187350323397577[36] = 0;
   out_7156187350323397577[37] = 0;
   out_7156187350323397577[38] = 0;
   out_7156187350323397577[39] = 0;
   out_7156187350323397577[40] = 0;
   out_7156187350323397577[41] = 1;
   out_7156187350323397577[42] = 0;
   out_7156187350323397577[43] = 0;
   out_7156187350323397577[44] = 0;
   out_7156187350323397577[45] = 0;
   out_7156187350323397577[46] = 0;
   out_7156187350323397577[47] = 0;
   out_7156187350323397577[48] = 0;
   out_7156187350323397577[49] = 0;
   out_7156187350323397577[50] = 0;
   out_7156187350323397577[51] = 0;
   out_7156187350323397577[52] = 0;
   out_7156187350323397577[53] = 0;
}
void h_14(double *state, double *unused, double *out_9028607542587016950) {
   out_9028607542587016950[0] = state[6];
   out_9028607542587016950[1] = state[7];
   out_9028607542587016950[2] = state[8];
}
void H_14(double *state, double *unused, double *out_861125092695692480) {
   out_861125092695692480[0] = 0;
   out_861125092695692480[1] = 0;
   out_861125092695692480[2] = 0;
   out_861125092695692480[3] = 0;
   out_861125092695692480[4] = 0;
   out_861125092695692480[5] = 0;
   out_861125092695692480[6] = 1;
   out_861125092695692480[7] = 0;
   out_861125092695692480[8] = 0;
   out_861125092695692480[9] = 0;
   out_861125092695692480[10] = 0;
   out_861125092695692480[11] = 0;
   out_861125092695692480[12] = 0;
   out_861125092695692480[13] = 0;
   out_861125092695692480[14] = 0;
   out_861125092695692480[15] = 0;
   out_861125092695692480[16] = 0;
   out_861125092695692480[17] = 0;
   out_861125092695692480[18] = 0;
   out_861125092695692480[19] = 0;
   out_861125092695692480[20] = 0;
   out_861125092695692480[21] = 0;
   out_861125092695692480[22] = 0;
   out_861125092695692480[23] = 0;
   out_861125092695692480[24] = 0;
   out_861125092695692480[25] = 1;
   out_861125092695692480[26] = 0;
   out_861125092695692480[27] = 0;
   out_861125092695692480[28] = 0;
   out_861125092695692480[29] = 0;
   out_861125092695692480[30] = 0;
   out_861125092695692480[31] = 0;
   out_861125092695692480[32] = 0;
   out_861125092695692480[33] = 0;
   out_861125092695692480[34] = 0;
   out_861125092695692480[35] = 0;
   out_861125092695692480[36] = 0;
   out_861125092695692480[37] = 0;
   out_861125092695692480[38] = 0;
   out_861125092695692480[39] = 0;
   out_861125092695692480[40] = 0;
   out_861125092695692480[41] = 0;
   out_861125092695692480[42] = 0;
   out_861125092695692480[43] = 0;
   out_861125092695692480[44] = 1;
   out_861125092695692480[45] = 0;
   out_861125092695692480[46] = 0;
   out_861125092695692480[47] = 0;
   out_861125092695692480[48] = 0;
   out_861125092695692480[49] = 0;
   out_861125092695692480[50] = 0;
   out_861125092695692480[51] = 0;
   out_861125092695692480[52] = 0;
   out_861125092695692480[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_2460299454592738255) {
  err_fun(nom_x, delta_x, out_2460299454592738255);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8995815424751717243) {
  inv_err_fun(nom_x, true_x, out_8995815424751717243);
}
void pose_H_mod_fun(double *state, double *out_172106315147157204) {
  H_mod_fun(state, out_172106315147157204);
}
void pose_f_fun(double *state, double dt, double *out_5576179949216863693) {
  f_fun(state,  dt, out_5576179949216863693);
}
void pose_F_fun(double *state, double dt, double *out_1077355707621539238) {
  F_fun(state,  dt, out_1077355707621539238);
}
void pose_h_4(double *state, double *unused, double *out_1380760196569112767) {
  h_4(state, unused, out_1380760196569112767);
}
void pose_H_4(double *state, double *unused, double *out_3943913524991064776) {
  H_4(state, unused, out_3943913524991064776);
}
void pose_h_10(double *state, double *unused, double *out_8331647754590399) {
  h_10(state, unused, out_8331647754590399);
}
void pose_H_10(double *state, double *unused, double *out_4674971023882599542) {
  H_10(state, unused, out_4674971023882599542);
}
void pose_h_13(double *state, double *unused, double *out_7859661641013841480) {
  h_13(state, unused, out_7859661641013841480);
}
void pose_H_13(double *state, double *unused, double *out_7156187350323397577) {
  H_13(state, unused, out_7156187350323397577);
}
void pose_h_14(double *state, double *unused, double *out_9028607542587016950) {
  h_14(state, unused, out_9028607542587016950);
}
void pose_H_14(double *state, double *unused, double *out_861125092695692480) {
  H_14(state, unused, out_861125092695692480);
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
