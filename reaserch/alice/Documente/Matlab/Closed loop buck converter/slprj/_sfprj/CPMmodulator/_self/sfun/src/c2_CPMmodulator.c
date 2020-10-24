/* Include files */

#include "blascompat32.h"
#include "CPMmodulator_sfun.h"
#include "c2_CPMmodulator.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CPMmodulator_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c2_debug_family_names[11] = { "ic", "i", "m1", "m2", "fs",
  "ma", "b", "nargin", "nargout", "u", "d" };

/* Function Declarations */
static void initialize_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance);
static void initialize_params_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance);
static void enable_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance);
static void disable_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_CPMmodulator
  (SFc2_CPMmodulatorInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_CPMmodulator
  (SFc2_CPMmodulatorInstanceStruct *chartInstance);
static void set_sim_state_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance);
static void sf_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct *chartInstance);
static void c2_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c2_CPMmodulator
  (SFc2_CPMmodulatorInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static void c2_eml_scalar_eg(SFc2_CPMmodulatorInstanceStruct *chartInstance);
static void c2_eml_error(SFc2_CPMmodulatorInstanceStruct *chartInstance);
static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u);
static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[42]);
static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u);
static real_T c2_emlrt_marshallIn(SFc2_CPMmodulatorInstanceStruct *chartInstance,
  const mxArray *c2_d, const char_T *c2_name);
static uint8_T c2_b_emlrt_marshallIn(SFc2_CPMmodulatorInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CPMmodulator, const char_T
  *c2_name);
static void init_dsm_address_info(SFc2_CPMmodulatorInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_CPMmodulator = 0U;
}

static void initialize_params_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance)
{
}

static void enable_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_CPMmodulator
  (SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_CPMmodulator
  (SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_d;
  c2_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_hoistedGlobal = *c2_d;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_CPMmodulator;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_d;
  c2_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_d = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "d");
  chartInstance->c2_is_active_c2_CPMmodulator = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_CPMmodulator");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_CPMmodulator(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct
  *chartInstance)
{
}

static void sf_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_previousEvent;
  real_T *c2_d;
  real_T (*c2_u)[6];
  c2_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  for (c2_i0 = 0; c2_i0 < 6; c2_i0 = c2_i0 + 1) {
    _SFD_DATA_RANGE_CHECK((*c2_u)[c2_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_d, 1U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c2_c2_CPMmodulator(chartInstance);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_CPMmodulatorMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_c2_CPMmodulator(SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
  int32_T c2_i1;
  real_T c2_hoistedGlobal[6];
  int32_T c2_i2;
  real_T c2_u[6];
  uint32_T c2_debug_family_var_map[11];
  real_T c2_ic;
  real_T c2_i;
  real_T c2_m1;
  real_T c2_m2;
  real_T c2_fs;
  real_T c2_ma;
  real_T c2_b;
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  real_T c2_d;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_x;
  real_T c2_c_y;
  real_T c2_d_y;
  real_T c2_a;
  real_T c2_e_y;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_f_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_d_x;
  real_T c2_g_y;
  real_T c2_e_x;
  real_T c2_h_y;
  real_T c2_f_x;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_c_a;
  real_T c2_d_a;
  real_T c2_ak;
  real_T c2_c;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_g_x;
  real_T c2_k_y;
  real_T c2_h_x;
  real_T c2_l_y;
  real_T c2_i_x;
  real_T c2_m_y;
  real_T c2_n_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_e_a;
  real_T c2_c_b;
  real_T c2_o_y;
  real_T c2_varargin_2;
  real_T c2_p_y;
  real_T c2_q_y;
  real_T c2_yk;
  real_T c2_r_y;
  real_T c2_minval;
  real_T c2_b_varargin_2;
  real_T c2_s_y;
  real_T c2_t_y;
  real_T c2_b_yk;
  real_T c2_u_y;
  real_T *c2_b_d;
  real_T (*c2_b_u)[6];
  c2_b_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1 = c2_i1 + 1) {
    c2_hoistedGlobal[c2_i1] = (*c2_b_u)[c2_i1];
  }

  for (c2_i2 = 0; c2_i2 < 6; c2_i2 = c2_i2 + 1) {
    c2_u[c2_i2] = c2_hoistedGlobal[c2_i2];
  }

  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c2_ic, c2_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c2_i, c2_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c2_m1, c2_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c2_m2, c2_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c2_fs, c2_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c2_ma, c2_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c2_b, c2_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c2_nargin, c2_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c2_nargout, c2_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c2_u, c2_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c2_d, c2_sf_marshall, 10U);
  CV_EML_FCN(0, 0);

  /*  Current mode controller, using Tan's model */
  /*  No sampling dynamics included */
  _SFD_EML_CALL(0, 5);
  c2_ic = c2_u[0];

  /*  control current */
  _SFD_EML_CALL(0, 6);
  c2_i = c2_u[1];

  /*  average inductor current */
  _SFD_EML_CALL(0, 7);
  c2_m1 = c2_u[2];

  /*  inductor up slope */
  _SFD_EML_CALL(0, 8);
  c2_m2 = c2_u[3];

  /*  inductor down slope */
  _SFD_EML_CALL(0, 9);
  c2_fs = c2_u[4];

  /*  switching frequency */
  _SFD_EML_CALL(0, 10);
  c2_ma = c2_u[5];

  /*  slope of artificial ramp */
  _SFD_EML_CALL(0, 11);
  c2_A = c2_ma;
  c2_B = c2_m1 + c2_m2;
  c2_x = c2_A;
  c2_y = c2_B;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_c_x = c2_b_x;
  c2_c_y = c2_b_y;
  c2_d_y = c2_c_x / c2_c_y;
  c2_b = c2_d_y + 0.5;
  _SFD_EML_CALL(0, 12);
  c2_a = c2_ic - c2_i;
  c2_e_y = c2_a * 2.0;
  c2_b_a = c2_e_y;
  c2_b_b = c2_fs;
  c2_f_y = c2_b_a * c2_b_b;
  c2_b_A = c2_f_y;
  c2_b_B = c2_m1 + c2_m2;
  c2_d_x = c2_b_A;
  c2_g_y = c2_b_B;
  c2_e_x = c2_d_x;
  c2_h_y = c2_g_y;
  c2_f_x = c2_e_x;
  c2_i_y = c2_h_y;
  c2_j_y = c2_f_x / c2_i_y;
  c2_c_a = c2_b;
  c2_d_a = c2_c_a;
  c2_eml_scalar_eg(chartInstance);
  c2_ak = c2_d_a;
  c2_c = muDoubleScalarPower(c2_ak, 2.0);
  c2_c_A = c2_j_y;
  c2_c_B = c2_c;
  c2_g_x = c2_c_A;
  c2_k_y = c2_c_B;
  c2_h_x = c2_g_x;
  c2_l_y = c2_k_y;
  c2_i_x = c2_h_x;
  c2_m_y = c2_l_y;
  c2_n_y = c2_i_x / c2_m_y;
  c2_j_x = 1.0 - c2_n_y;
  c2_k_x = c2_j_x;
  if (c2_k_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_l_x = c2_k_x;
  c2_k_x = c2_l_x;
  c2_k_x = muDoubleScalarSqrt(c2_k_x);
  c2_e_a = c2_b;
  c2_c_b = 1.0 - c2_k_x;
  c2_o_y = c2_e_a * c2_c_b;
  c2_varargin_2 = c2_o_y;
  c2_p_y = c2_varargin_2;
  c2_q_y = c2_p_y;
  c2_eml_scalar_eg(chartInstance);
  c2_yk = c2_q_y;
  c2_r_y = c2_yk;
  c2_eml_scalar_eg(chartInstance);
  c2_minval = muDoubleScalarMin(0.9, c2_r_y);
  c2_b_varargin_2 = c2_minval;
  c2_s_y = c2_b_varargin_2;
  c2_t_y = c2_s_y;
  c2_eml_scalar_eg(chartInstance);
  c2_b_yk = c2_t_y;
  c2_u_y = c2_b_yk;
  c2_eml_scalar_eg(chartInstance);
  c2_d = muDoubleScalarMax(0.0, c2_u_y);

  /*  duty cycle computation, including modulator saturation limits */
  _SFD_EML_CALL(0, -12);
  sf_debug_symbol_scope_pop();
  *c2_b_d = c2_d;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
}

static void compInitSubchartSimstructsFcn_c2_CPMmodulator
  (SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static void c2_eml_scalar_eg(SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
}

static void c2_eml_error(SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  static char_T c2_cv0[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  int32_T c2_i4;
  static char_T c2_cv1[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c2_b_u[77];
  const mxArray *c2_b_y = NULL;
  for (c2_i3 = 0; c2_i3 < 31; c2_i3 = c2_i3 + 1) {
    c2_u[c2_i3] = c2_cv0[c2_i3];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c2_i4 = 0; c2_i4 < 77; c2_i4 = c2_i4 + 1) {
    c2_b_u[c2_i4] = c2_cv1[c2_i4];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c2_y, 14, c2_b_y);
}

static const mxArray *c2_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_CPMmodulatorInstanceStruct *chartInstance;
  chartInstance = (SFc2_CPMmodulatorInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static const mxArray *c2_b_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  int32_T c2_i5;
  real_T c2_b_u[6];
  int32_T c2_i6;
  real_T c2_c_u[6];
  const mxArray *c2_b_y = NULL;
  SFc2_CPMmodulatorInstanceStruct *chartInstance;
  chartInstance = (SFc2_CPMmodulatorInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  for (c2_i5 = 0; c2_i5 < 6; c2_i5 = c2_i5 + 1) {
    c2_b_u[c2_i5] = (*((real_T (*)[6])c2_u))[c2_i5];
  }

  for (c2_i6 = 0; c2_i6 < 6; c2_i6 = c2_i6 + 1) {
    c2_c_u[c2_i6] = c2_b_u[c2_i6];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_CPMmodulator_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[42];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i7;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 42));
  for (c2_i7 = 0; c2_i7 < 42; c2_i7 = c2_i7 + 1) {
    c2_r0 = &c2_info[c2_i7];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i7);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i7);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i7);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i7);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i7);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i7);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i7);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[42])
{
  c2_info[0].context = "";
  c2_info[0].name = "plus";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]plus";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "mrdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].fileLength = 432U;
  c2_info[1].fileTime1 = 1277744622U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[2].name = "nargin";
  c2_info[2].dominantType = "";
  c2_info[2].resolved = "[B]nargin";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[3].name = "ge";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]ge";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[4].name = "isscalar";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]isscalar";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].name = "rdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[5].fileLength = 403U;
  c2_info[5].fileTime1 = 1245098820U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].name = "gt";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]gt";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "isa";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]isa";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].name = "eml_div";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[8].fileLength = 4918U;
  c2_info[8].fileTime1 = 1267059810U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[9].name = "isinteger";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]isinteger";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c2_info[10].name = "isreal";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved = "[B]isreal";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "";
  c2_info[11].name = "minus";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved = "[B]minus";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "";
  c2_info[12].name = "mtimes";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[12].fileLength = 3425U;
  c2_info[12].fileTime1 = 1251028272U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[13].name = "strcmp";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved = "[B]strcmp";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[14].name = "size";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]size";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[15].name = "eq";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]eq";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[16].name = "class";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]class";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[17].name = "not";
  c2_info[17].dominantType = "logical";
  c2_info[17].resolved = "[B]not";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context = "";
  c2_info[18].name = "mpower";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[18].fileLength = 3710U;
  c2_info[18].fileTime1 = 1238430688U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[19].name = "ndims";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]ndims";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[20].name = "power";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[20].fileLength = 5380U;
  c2_info[20].fileTime1 = 1228090298U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[21].name = "eml_scalar_eg";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[21].fileLength = 3068U;
  c2_info[21].fileTime1 = 1240258410U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c2_info[22].name = "false";
  c2_info[22].dominantType = "";
  c2_info[22].resolved = "[B]false";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[23].name = "isstruct";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved = "[B]isstruct";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c2_info[24].name = "cast";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]cast";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[25].name = "eml_scalexp_alloc";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[25].fileLength = 932U;
  c2_info[25].fileTime1 = 1261948270U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[26].name = "lt";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved = "[B]lt";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[27].name = "eml_scalar_floor";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[27].fileLength = 260U;
  c2_info[27].fileTime1 = 1209327190U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[28].name = "ne";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved = "[B]ne";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[29].name = "eml_error";
  c2_info[29].dominantType = "char";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[29].fileLength = 315U;
  c2_info[29].fileTime1 = 1213923144U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "";
  c2_info[30].name = "sqrt";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[30].fileLength = 572U;
  c2_info[30].fileTime1 = 1203444444U;
  c2_info[30].fileTime2 = 0U;
  c2_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[31].name = "eml_scalar_sqrt";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[31].fileLength = 664U;
  c2_info[31].fileTime1 = 1209327194U;
  c2_info[31].fileTime2 = 0U;
  c2_info[32].context = "";
  c2_info[32].name = "min";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[32].fileLength = 362U;
  c2_info[32].fileTime1 = 1245098764U;
  c2_info[32].fileTime2 = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[33].name = "le";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved = "[B]le";
  c2_info[33].fileLength = 0U;
  c2_info[33].fileTime1 = 0U;
  c2_info[33].fileTime2 = 0U;
  c2_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[34].name = "nargout";
  c2_info[34].dominantType = "";
  c2_info[34].resolved = "[B]nargout";
  c2_info[34].fileLength = 0U;
  c2_info[34].fileTime1 = 0U;
  c2_info[34].fileTime2 = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[35].name = "eml_min_or_max";
  c2_info[35].dominantType = "char";
  c2_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[35].fileLength = 9967U;
  c2_info[35].fileTime1 = 1261948270U;
  c2_info[35].fileTime2 = 0U;
  c2_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[36].name = "ischar";
  c2_info[36].dominantType = "char";
  c2_info[36].resolved = "[B]ischar";
  c2_info[36].fileLength = 0U;
  c2_info[36].fileTime1 = 0U;
  c2_info[36].fileTime2 = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[37].name = "isnumeric";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved = "[B]isnumeric";
  c2_info[37].fileLength = 0U;
  c2_info[37].fileTime1 = 0U;
  c2_info[37].fileTime2 = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[38].name = "islogical";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved = "[B]islogical";
  c2_info[38].fileLength = 0U;
  c2_info[38].fileTime1 = 0U;
  c2_info[38].fileTime2 = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[39].name = "eml_index_class";
  c2_info[39].dominantType = "";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[39].fileLength = 909U;
  c2_info[39].fileTime1 = 1192463182U;
  c2_info[39].fileTime2 = 0U;
  c2_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[40].name = "ones";
  c2_info[40].dominantType = "char";
  c2_info[40].resolved = "[B]ones";
  c2_info[40].fileLength = 0U;
  c2_info[40].fileTime1 = 0U;
  c2_info[40].fileTime2 = 0U;
  c2_info[41].context = "";
  c2_info[41].name = "max";
  c2_info[41].dominantType = "double";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c2_info[41].fileLength = 362U;
  c2_info[41].fileTime1 = 1245098760U;
  c2_info[41].fileTime2 = 0U;
}

static const mxArray *c2_c_sf_marshall(void *chartInstanceVoid, void *c2_u)
{
  const mxArray *c2_y = NULL;
  boolean_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  SFc2_CPMmodulatorInstanceStruct *chartInstance;
  chartInstance = (SFc2_CPMmodulatorInstanceStruct *)chartInstanceVoid;
  c2_y = NULL;
  c2_b_u = *((boolean_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

static real_T c2_emlrt_marshallIn(SFc2_CPMmodulatorInstanceStruct *chartInstance,
  const mxArray *c2_d, const char_T *c2_name)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_d), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_d);
  return c2_y;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_CPMmodulatorInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_CPMmodulator,
  const char_T *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_CPMmodulator), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_CPMmodulator);
  return c2_y;
}

static void init_dsm_address_info(SFc2_CPMmodulatorInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_CPMmodulator_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1899520131U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4041485444U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(646179869U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2694940343U);
}

mxArray *sf_c2_CPMmodulator_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2349918147U);
    pr[1] = (double)(1239694621U);
    pr[2] = (double)(4063270051U);
    pr[3] = (double)(1737685785U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_CPMmodulator(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"d\",},{M[8],M[0],T\"is_active_c2_CPMmodulator\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CPMmodulator_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_CPMmodulatorInstanceStruct *chartInstance;
    chartInstance = (SFc2_CPMmodulatorInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CPMmodulatorMachineNumber_,
           2,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_CPMmodulatorMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_CPMmodulatorMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_CPMmodulatorMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"d");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,389);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshall);

        {
          real_T *c2_d;
          real_T (*c2_u)[6];
          c2_d = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_u = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_d);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_CPMmodulatorMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_CPMmodulator(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_CPMmodulatorInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*)
    chartInstanceVar);
  initialize_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_CPMmodulator(void *chartInstanceVar)
{
  enable_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_CPMmodulator(void *chartInstanceVar)
{
  disable_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_CPMmodulator(void *chartInstanceVar)
{
  sf_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c2_CPMmodulator(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_CPMmodulator
    ((SFc2_CPMmodulatorInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c2_CPMmodulator();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

static void sf_internal_set_sim_state_c2_CPMmodulator(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CPMmodulator();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c2_CPMmodulator(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_CPMmodulator(S);
}

static void sf_opaque_set_sim_state_c2_CPMmodulator(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c2_CPMmodulator(S, st);
}

static void sf_opaque_terminate_c2_CPMmodulator(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CPMmodulatorInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CPMmodulator(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CPMmodulator((SFc2_CPMmodulatorInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_CPMmodulator(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"CPMmodulator","CPMmodulator",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"CPMmodulator","CPMmodulator",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"CPMmodulator",
      "CPMmodulator",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"CPMmodulator","CPMmodulator",2,1);
      sf_mark_chart_reusable_outputs(S,"CPMmodulator","CPMmodulator",2,1);
    }

    sf_set_rtw_dwork_info(S,"CPMmodulator","CPMmodulator",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3429389064U));
  ssSetChecksum1(S,(443228316U));
  ssSetChecksum2(S,(1876090201U));
  ssSetChecksum3(S,(1683414723U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_CPMmodulator(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "CPMmodulator", "CPMmodulator",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_CPMmodulator(SimStruct *S)
{
  SFc2_CPMmodulatorInstanceStruct *chartInstance;
  chartInstance = (SFc2_CPMmodulatorInstanceStruct *)malloc(sizeof
    (SFc2_CPMmodulatorInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_CPMmodulatorInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_CPMmodulator;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_CPMmodulator;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_CPMmodulator;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_CPMmodulator;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_CPMmodulator;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_CPMmodulator;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_CPMmodulator;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_CPMmodulator;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CPMmodulator;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_CPMmodulator;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_CPMmodulator;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_CPMmodulator_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_CPMmodulator(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CPMmodulator(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CPMmodulator(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CPMmodulator_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
