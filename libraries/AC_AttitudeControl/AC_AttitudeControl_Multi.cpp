#include "AC_AttitudeControl_Multi.h"
#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>
<<<<<<< HEAD
#include <AC_PID/AC_PID.h>
=======
#include <iostream>
#include <fstream> 

using namespace std;
>>>>>>> 4966fcd133 (first commit)

// table of user settable parameters
const AP_Param::GroupInfo AC_AttitudeControl_Multi::var_info[] = {
    // parameters from parent vehicle
    AP_NESTEDGROUPINFO(AC_AttitudeControl, 0),

    // @Param: RAT_RLL_P
    // @DisplayName: Roll axis rate controller P gain
    // @Description: Roll axis rate controller P gain.  Corrects in proportion to the difference between the desired roll rate vs actual roll rate
    // @Range: 0.01 0.5
    // @Increment: 0.005
    // @User: Standard

    // @Param: RAT_RLL_I
    // @DisplayName: Roll axis rate controller I gain
    // @Description: Roll axis rate controller I gain.  Corrects long-term difference in desired roll rate vs actual roll rate
    // @Range: 0.01 2.0
    // @Increment: 0.01
    // @User: Standard

    // @Param: RAT_RLL_IMAX
    // @DisplayName: Roll axis rate controller I gain maximum
    // @Description: Roll axis rate controller I gain maximum.  Constrains the maximum that the I term will output
    // @Range: 0 1
    // @Increment: 0.01
    // @User: Standard

    // @Param: RAT_RLL_D
    // @DisplayName: Roll axis rate controller D gain
    // @Description: Roll axis rate controller D gain.  Compensates for short-term change in desired roll rate vs actual roll rate
    // @Range: 0.0 0.05
    // @Increment: 0.001
    // @User: Standard

    // @Param: RAT_RLL_FF
    // @DisplayName: Roll axis rate controller feed forward
    // @Description: Roll axis rate controller feed forward
    // @Range: 0 0.5
    // @Increment: 0.001
    // @User: Standard

    // @Param: RAT_RLL_FLTT
    // @DisplayName: Roll axis rate controller target frequency in Hz
    // @Description: Roll axis rate controller target frequency in Hz
    // @Range: 5 100
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_RLL_FLTE
    // @DisplayName: Roll axis rate controller error frequency in Hz
    // @Description: Roll axis rate controller error frequency in Hz
    // @Range: 0 100
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_RLL_FLTD
    // @DisplayName: Roll axis rate controller derivative frequency in Hz
    // @Description: Roll axis rate controller derivative frequency in Hz
    // @Range: 5 100
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_RLL_SMAX
    // @DisplayName: Roll slew rate limit
    // @Description: Sets an upper limit on the slew rate produced by the combined P and D gains. If the amplitude of the control action produced by the rate feedback exceeds this value, then the D+P gain is reduced to respect the limit. This limits the amplitude of high frequency oscillations caused by an excessive gain. The limit should be set to no more than 25% of the actuators maximum slew rate to allow for load effects. Note: The gain will not be reduced to less than 10% of the nominal value. A value of zero will disable this feature.
    // @Range: 0 200
    // @Increment: 0.5
    // @User: Advanced

    // @Param: RAT_RLL_PDMX
    // @DisplayName: Roll axis rate controller PD sum maximum
    // @Description: Roll axis rate controller PD sum maximum.  The maximum/minimum value that the sum of the P and D term can output
    // @Range: 0 1
    // @Increment: 0.01
    // @User: Advanced

    AP_SUBGROUPINFO(_pid_rate_roll, "RAT_RLL_", 1, AC_AttitudeControl_Multi, AC_PID),

    // @Param: RAT_PIT_P
    // @DisplayName: Pitch axis rate controller P gain
    // @Description: Pitch axis rate controller P gain.  Corrects in proportion to the difference between the desired pitch rate vs actual pitch rate output
    // @Range: 0.01 0.50
    // @Increment: 0.005
    // @User: Standard

    // @Param: RAT_PIT_I
    // @DisplayName: Pitch axis rate controller I gain
    // @Description: Pitch axis rate controller I gain.  Corrects long-term difference in desired pitch rate vs actual pitch rate
    // @Range: 0.01 2.0
    // @Increment: 0.01
    // @User: Standard

    // @Param: RAT_PIT_IMAX
    // @DisplayName: Pitch axis rate controller I gain maximum
    // @Description: Pitch axis rate controller I gain maximum.  Constrains the maximum that the I term will output
    // @Range: 0 1
    // @Increment: 0.01
    // @User: Standard

    // @Param: RAT_PIT_D
    // @DisplayName: Pitch axis rate controller D gain
    // @Description: Pitch axis rate controller D gain.  Compensates for short-term change in desired pitch rate vs actual pitch rate
    // @Range: 0.0 0.05
    // @Increment: 0.001
    // @User: Standard

    // @Param: RAT_PIT_FF
    // @DisplayName: Pitch axis rate controller feed forward
    // @Description: Pitch axis rate controller feed forward
    // @Range: 0 0.5
    // @Increment: 0.001
    // @User: Standard

    // @Param: RAT_PIT_FLTT
    // @DisplayName: Pitch axis rate controller target frequency in Hz
    // @Description: Pitch axis rate controller target frequency in Hz
    // @Range: 5 100
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_PIT_FLTE
    // @DisplayName: Pitch axis rate controller error frequency in Hz
    // @Description: Pitch axis rate controller error frequency in Hz
    // @Range: 0 100
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_PIT_FLTD
    // @DisplayName: Pitch axis rate controller derivative frequency in Hz
    // @Description: Pitch axis rate controller derivative frequency in Hz
    // @Range: 5 100
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_PIT_SMAX
    // @DisplayName: Pitch slew rate limit
    // @Description: Sets an upper limit on the slew rate produced by the combined P and D gains. If the amplitude of the control action produced by the rate feedback exceeds this value, then the D+P gain is reduced to respect the limit. This limits the amplitude of high frequency oscillations caused by an excessive gain. The limit should be set to no more than 25% of the actuators maximum slew rate to allow for load effects. Note: The gain will not be reduced to less than 10% of the nominal value. A value of zero will disable this feature.
    // @Range: 0 200
    // @Increment: 0.5
    // @User: Advanced

    // @Param: RAT_PIT_PDMX
    // @DisplayName: Pitch axis rate controller PD sum maximum
    // @Description: Pitch axis rate controller PD sum maximum.  The maximum/minimum value that the sum of the P and D term can output
    // @Range: 0 1
    // @Increment: 0.01
    // @User: Advanced

    AP_SUBGROUPINFO(_pid_rate_pitch, "RAT_PIT_", 2, AC_AttitudeControl_Multi, AC_PID),

    // @Param: RAT_YAW_P
    // @DisplayName: Yaw axis rate controller P gain
    // @Description: Yaw axis rate controller P gain.  Corrects in proportion to the difference between the desired yaw rate vs actual yaw rate
    // @Range: 0.10 2.50
    // @Increment: 0.005
    // @User: Standard

    // @Param: RAT_YAW_I
    // @DisplayName: Yaw axis rate controller I gain
    // @Description: Yaw axis rate controller I gain.  Corrects long-term difference in desired yaw rate vs actual yaw rate
    // @Range: 0.010 1.0
    // @Increment: 0.01
    // @User: Standard

    // @Param: RAT_YAW_IMAX
    // @DisplayName: Yaw axis rate controller I gain maximum
    // @Description: Yaw axis rate controller I gain maximum.  Constrains the maximum that the I term will output
    // @Range: 0 1
    // @Increment: 0.01
    // @User: Standard

    // @Param: RAT_YAW_D
    // @DisplayName: Yaw axis rate controller D gain
    // @Description: Yaw axis rate controller D gain.  Compensates for short-term change in desired yaw rate vs actual yaw rate
    // @Range: 0.000 0.02
    // @Increment: 0.001
    // @User: Standard

    // @Param: RAT_YAW_FF
    // @DisplayName: Yaw axis rate controller feed forward
    // @Description: Yaw axis rate controller feed forward
    // @Range: 0 0.5
    // @Increment: 0.001
    // @User: Standard

    // @Param: RAT_YAW_FLTT
    // @DisplayName: Yaw axis rate controller target frequency in Hz
    // @Description: Yaw axis rate controller target frequency in Hz
    // @Range: 1 50
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_YAW_FLTE
    // @DisplayName: Yaw axis rate controller error frequency in Hz
    // @Description: Yaw axis rate controller error frequency in Hz
    // @Range: 0 20
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_YAW_FLTD
    // @DisplayName: Yaw axis rate controller derivative frequency in Hz
    // @Description: Yaw axis rate controller derivative frequency in Hz
    // @Range: 5 50
    // @Increment: 1
    // @Units: Hz
    // @User: Standard

    // @Param: RAT_YAW_SMAX
    // @DisplayName: Yaw slew rate limit
    // @Description: Sets an upper limit on the slew rate produced by the combined P and D gains. If the amplitude of the control action produced by the rate feedback exceeds this value, then the D+P gain is reduced to respect the limit. This limits the amplitude of high frequency oscillations caused by an excessive gain. The limit should be set to no more than 25% of the actuators maximum slew rate to allow for load effects. Note: The gain will not be reduced to less than 10% of the nominal value. A value of zero will disable this feature.
    // @Range: 0 200
    // @Increment: 0.5
    // @User: Advanced

    // @Param: RAT_YAW_PDMX
    // @DisplayName: Yaw axis rate controller PD sum maximum
    // @Description: Yaw axis rate controller PD sum maximum.  The maximum/minimum value that the sum of the P and D term can output
    // @Range: 0 1
    // @Increment: 0.01
    // @User: Advanced

    AP_SUBGROUPINFO(_pid_rate_yaw, "RAT_YAW_", 3, AC_AttitudeControl_Multi, AC_PID),

    // @Param: THR_MIX_MIN
    // @DisplayName: Throttle Mix Minimum
    // @Description: Throttle vs attitude control prioritisation used when landing (higher values mean we prioritise attitude control over throttle)
    // @Range: 0.1 0.25
    // @User: Advanced
    AP_GROUPINFO("THR_MIX_MIN", 4, AC_AttitudeControl_Multi, _thr_mix_min, AC_ATTITUDE_CONTROL_MIN_DEFAULT),

    // @Param: THR_MIX_MAX
    // @DisplayName: Throttle Mix Maximum
    // @Description: Throttle vs attitude control prioritisation used during active flight (higher values mean we prioritise attitude control over throttle)
    // @Range: 0.5 0.9
    // @User: Advanced
    AP_GROUPINFO("THR_MIX_MAX", 5, AC_AttitudeControl_Multi, _thr_mix_max, AC_ATTITUDE_CONTROL_MAX_DEFAULT),

    // @Param: THR_MIX_MAN
    // @DisplayName: Throttle Mix Manual
    // @Description: Throttle vs attitude control prioritisation used during manual flight (higher values mean we prioritise attitude control over throttle)
    // @Range: 0.1 0.9
    // @User: Advanced
    AP_GROUPINFO("THR_MIX_MAN", 6, AC_AttitudeControl_Multi, _thr_mix_man, AC_ATTITUDE_CONTROL_MAN_DEFAULT),

    // @Param: THR_G_BOOST
    // @DisplayName: Throttle-gain boost
    // @Description: Throttle-gain boost ratio. A value of 0 means no boosting is applied, a value of 1 means full boosting is applied. Describes the ratio increase that is applied to angle P and PD on pitch and roll.
    // @Range: 0 1
    // @User: Advanced
    AP_GROUPINFO("THR_G_BOOST", 7, AC_AttitudeControl_Multi, _throttle_gain_boost, 0.0f),

    AP_GROUPEND
};

<<<<<<< HEAD
AC_AttitudeControl_Multi::AC_AttitudeControl_Multi(AP_AHRS_View &ahrs, const AP_MultiCopter &aparm, AP_MotorsMulticopter& motors) :
    AC_AttitudeControl(ahrs, aparm, motors),
    _motors_multi(motors)
=======
//********************************************************************************************************************************************************************
void AC_AttitudeControl_Multi::pso_read()
{
    FILE *fp;
        AP_Vehicle::st data;
        fp=fopen("data_orig.txt","rb");
        if(!fp)
        {
            printf("pso_read open data_orgi.txt error!\n");
            fclose(fp);
            exit(-1);
        }

       // fread(&data,sizeof(data),1,fp);
         size_t sizeRead =fread(&data,sizeof(data),1,fp);
        if (sizeRead != 1) {
    printf("error!\n");
    }
        fclose(fp);
        R_eita=data.roll_eita;
        R_miu=data.roll_miu;
        R_rou1=data.roll_rou;
        R_rou2=data.roll_rou;
        R_rou3=data.roll_rou;
        R_lamda=data.roll_lamda;

        P_eita=data.pitch_eita;
        P_miu=data.pitch_miu;
        P_rou1=data.pitch_rou;
        P_rou2=data.pitch_rou;
        P_rou3=data.pitch_rou;
        P_lamda=data.pitch_lamda;

        Y_eita=data.slip_eita;
        Y_miu=data.slip_miu;
        Y_rou1=data.slip_rou;
        Y_rou2=data.slip_rou;
        Y_rou3=data.slip_rou;
        Y_lamda=data.slip_lamda;
               
    printf("Roll_eita=%f,Roll_miu=%f,Roll_rho=%f,Roll_lamda=%f,Pitch_eita=%f,Pitch_miu=%f,Pitch_rho=%f,Pitch_lamda=%f,yaw_eita=%f,yaw_miu=%f,yaw_rho=%f,yaw_lamda=%f\n",R_eita,R_miu,R_rou1,R_lamda,P_eita,P_miu,P_rou1,P_lamda,Y_eita,Y_miu,Y_rou1,Y_lamda);
    //printf("Roll_eita=%f,Roll_miu=%f,Roll_rho=%f,Roll_lamda=%f,Pitch_eita=%f,Pitch_miu=%f,Pitch_rho=%f,Pitch_lamda=%f,yaw_eita=%f,yaw_miu=%f,yaw_rho=%f,yaw_lamda=%f\n",data.roll_eita,data.roll_miu,data.roll_rou,data.roll_lamda,data.pitch_eita,data.pitch_miu,data.pitch_rou,data.pitch_lamda,data.slip_eita,data.slip_miu,data.slip_rou,data.slip_lamda);
        return;
}

AC_AttitudeControl_Multi::AC_AttitudeControl_Multi(AP_AHRS_View &ahrs, const AP_Vehicle::MultiCopter &aparm, AP_MotorsMulticopter& motors, float dt) :
    AC_AttitudeControl(ahrs, aparm, motors, dt),
    _motors_multi(motors),
    _pid_rate_roll(AC_ATC_MULTI_RATE_RP_P, AC_ATC_MULTI_RATE_RP_I, AC_ATC_MULTI_RATE_RP_D, 0.0f, AC_ATC_MULTI_RATE_RP_IMAX, AC_ATC_MULTI_RATE_RP_FILT_HZ, 0.0f, AC_ATC_MULTI_RATE_RP_FILT_HZ, dt),
    _pid_rate_pitch(AC_ATC_MULTI_RATE_RP_P, AC_ATC_MULTI_RATE_RP_I, AC_ATC_MULTI_RATE_RP_D, 0.0f, AC_ATC_MULTI_RATE_RP_IMAX, AC_ATC_MULTI_RATE_RP_FILT_HZ, 0.0f, AC_ATC_MULTI_RATE_RP_FILT_HZ, dt),
    _pid_rate_yaw(AC_ATC_MULTI_RATE_YAW_P, AC_ATC_MULTI_RATE_YAW_I, AC_ATC_MULTI_RATE_YAW_D, 0.0f, AC_ATC_MULTI_RATE_YAW_IMAX, AC_ATC_MULTI_RATE_RP_FILT_HZ, AC_ATC_MULTI_RATE_YAW_FILT_HZ, 0.0f, dt)
>>>>>>> 4966fcd133 (first commit)
{
    AP_Param::setup_object_defaults(this, var_info);

//********************************************************
    pso_read();
}

// Update Alt_Hold angle maximum
void AC_AttitudeControl_Multi::update_althold_lean_angle_max(float throttle_in)
{
    // calc maximum tilt angle based on throttle
    float thr_max = _motors_multi.get_throttle_thrust_max();

    // divide by zero check
    if (is_zero(thr_max)) {
        _althold_lean_angle_max = 0.0f;
        return;
    }

    float althold_lean_angle_max = acosf(constrain_float(throttle_in / (AC_ATTITUDE_CONTROL_ANGLE_LIMIT_THROTTLE_MAX * thr_max), 0.0f, 1.0f));
    _althold_lean_angle_max = _althold_lean_angle_max + (_dt / (_dt + _angle_limit_tc)) * (althold_lean_angle_max - _althold_lean_angle_max);
}

void AC_AttitudeControl_Multi::set_throttle_out(float throttle_in, bool apply_angle_boost, float filter_cutoff)
{
    _throttle_in = throttle_in;
    update_althold_lean_angle_max(throttle_in);
    _motors.set_throttle_filter_cutoff(filter_cutoff);
    if (apply_angle_boost) {
        // Apply angle boost
        throttle_in = get_throttle_boosted(throttle_in);
    } else {
        // Clear angle_boost for logging purposes
        _angle_boost = 0.0f;
    }
    _motors.set_throttle(throttle_in);
    _motors.set_throttle_avg_max(get_throttle_avg_max(MAX(throttle_in, _throttle_in)));
}

void AC_AttitudeControl_Multi::set_throttle_mix_max(float ratio)
{
    ratio = constrain_float(ratio, 0.0f, 1.0f);
    _throttle_rpy_mix_desired = (1.0f - ratio) * _thr_mix_min + ratio * _thr_mix_max;
}

// returns a throttle including compensation for roll/pitch angle
// throttle value should be 0 ~ 1
float AC_AttitudeControl_Multi::get_throttle_boosted(float throttle_in)
{
    if (!_angle_boost_enabled) {
        _angle_boost = 0;
        return throttle_in;
    }
    // inverted_factor is 1 for tilt angles below 60 degrees
    // inverted_factor reduces from 1 to 0 for tilt angles between 60 and 90 degrees

    float cos_tilt = _ahrs.cos_pitch() * _ahrs.cos_roll();
    float inverted_factor = constrain_float(10.0f * cos_tilt, 0.0f, 1.0f);
    float cos_tilt_target = cosf(_thrust_angle);
    float boost_factor = 1.0f / constrain_float(cos_tilt_target, 0.1f, 1.0f);

    float throttle_out = throttle_in * inverted_factor * boost_factor;
    _angle_boost = constrain_float(throttle_out - throttle_in, -1.0f, 1.0f);
    return throttle_out;
}

// returns a throttle including compensation for roll/pitch angle
// throttle value should be 0 ~ 1
float AC_AttitudeControl_Multi::get_throttle_avg_max(float throttle_in)
{
    throttle_in = constrain_float(throttle_in, 0.0f, 1.0f);
    return MAX(throttle_in, throttle_in * MAX(0.0f, 1.0f - _throttle_rpy_mix) + _motors.get_throttle_hover() * _throttle_rpy_mix);
}

// update_throttle_gain_boost - boost angle_p/pd each cycle on high throttle slew
void AC_AttitudeControl_Multi::update_throttle_gain_boost()
{
    // Boost PD and Angle P on very rapid throttle changes
    if (_motors.get_throttle_slew_rate() > AC_ATTITUDE_CONTROL_THR_G_BOOST_THRESH) {
        const float pd_boost = constrain_float(_throttle_gain_boost + 1.0f, 1.0, 2.0);
        set_PD_scale_mult(Vector3f(pd_boost, pd_boost, 1.0f));

        const float angle_p_boost = constrain_float((_throttle_gain_boost + 1.0f) * (_throttle_gain_boost + 1.0f), 1.0, 4.0);
        set_angle_P_scale_mult(Vector3f(angle_p_boost, angle_p_boost, 1.0f));
    }
}

// update_throttle_rpy_mix - slew set_throttle_rpy_mix to requested value
void AC_AttitudeControl_Multi::update_throttle_rpy_mix()
{
    // slew _throttle_rpy_mix to _throttle_rpy_mix_desired
    if (_throttle_rpy_mix < _throttle_rpy_mix_desired) {
        // increase quickly (i.e. from 0.1 to 0.9 in 0.4 seconds)
        _throttle_rpy_mix += MIN(2.0f * _dt, _throttle_rpy_mix_desired - _throttle_rpy_mix);
    } else if (_throttle_rpy_mix > _throttle_rpy_mix_desired) {
        // reduce more slowly (from 0.9 to 0.1 in 1.6 seconds)
        _throttle_rpy_mix -= MIN(0.5f * _dt, _throttle_rpy_mix - _throttle_rpy_mix_desired);

        // if the mix is still higher than that being used, reset immediately
        const float throttle_hover = _motors.get_throttle_hover();
        const float throttle_in = _motors.get_throttle();
        const float throttle_out = MAX(_motors.get_throttle_out(), throttle_in);
        float mix_used;
        // since throttle_out >= throttle_in at this point we don't need to check throttle_in < throttle_hover
        if (throttle_out < throttle_hover) {
            mix_used = (throttle_out - throttle_in) / (throttle_hover - throttle_in);
        } else {
            mix_used = throttle_out / throttle_hover;
        }

        _throttle_rpy_mix = MIN(_throttle_rpy_mix, MAX(mix_used, _throttle_rpy_mix_desired));
    }
    _throttle_rpy_mix = constrain_float(_throttle_rpy_mix, 0.1f, AC_ATTITUDE_CONTROL_MAX);
}

void AC_AttitudeControl_Multi::rate_controller_run()
{
    // boost angle_p/pd each cycle on high throttle slew
    update_throttle_gain_boost();

    // move throttle vs attitude mixing towards desired (called from here because this is conveniently called on every iteration)
    update_throttle_rpy_mix();

    _ang_vel_body += _sysid_ang_vel_body;

    Vector3f gyro_latest = _ahrs.get_gyro_latest();

<<<<<<< HEAD
    _motors.set_roll(get_rate_roll_pid().update_all(_ang_vel_body.x, gyro_latest.x,  _dt, _motors.limit.roll, _pd_scale.x) + _actuator_sysid.x);
    _motors.set_roll_ff(get_rate_roll_pid().get_ff());

    _motors.set_pitch(get_rate_pitch_pid().update_all(_ang_vel_body.y, gyro_latest.y,  _dt, _motors.limit.pitch, _pd_scale.y) + _actuator_sysid.y);
    _motors.set_pitch_ff(get_rate_pitch_pid().get_ff());

    _motors.set_yaw(get_rate_yaw_pid().update_all(_ang_vel_body.z, gyro_latest.z,  _dt, _motors.limit.yaw, _pd_scale.z) + _actuator_sysid.z);
    _motors.set_yaw_ff(get_rate_yaw_pid().get_ff()*_feedforward_scalar);
=======
//***********************************************************
    float Roll_MFAC=MFAC(gyro_latest.x,_ang_vel_body.x,R_eita,R_miu,R_rou1,R_rou2,R_rou3,R_lamda); 

    //_motors.set_roll(get_rate_roll_pid().update_all(_ang_vel_body.x, gyro_latest.x, _motors.limit.roll) + _actuator_sysid.x);

    _motors.set_roll(get_rate_roll_pid().update_all(_ang_vel_body.x, gyro_latest.x, _motors.limit.roll) + _actuator_sysid.x+Roll_MFAC); 

    _motors.set_roll_ff(get_rate_roll_pid().get_ff());
    
//******************************************************************************************************************************
   float Pitch_MFAC=MFAC(gyro_latest.y,_ang_vel_body.y,P_eita,P_miu,P_rou1,P_rou2,P_rou3,P_lamda);

   // _motors.set_pitch(get_rate_pitch_pid().update_all(_ang_vel_body.y, gyro_latest.y, _motors.limit.pitch) + _actuator_sysid.y);

  _motors.set_pitch(get_rate_pitch_pid().update_all(_ang_vel_body.y, gyro_latest.y, _motors.limit.pitch) + _actuator_sysid.y+Pitch_MFAC);

    _motors.set_pitch_ff(get_rate_pitch_pid().get_ff());

//*********************************************************************************************************************************
    float Yaw_MFAC=MFAC(gyro_latest.z,_ang_vel_body.z,Y_eita,Y_miu,Y_rou1,Y_rou2,Y_rou3,Y_lamda); 
>>>>>>> 4966fcd133 (first commit)

    //_motors.set_yaw(get_rate_yaw_pid().update_all(_ang_vel_body.z, gyro_latest.z, _motors.limit.yaw) + _actuator_sysid.z);

   _motors.set_yaw(get_rate_yaw_pid().update_all(_ang_vel_body.z, gyro_latest.z, _motors.limit.yaw) + _actuator_sysid.z+Yaw_MFAC);

    _motors.set_yaw_ff(get_rate_yaw_pid().get_ff()*_feedforward_scalar);
//**********************************************************************************************************************************
    _sysid_ang_vel_body.zero();
    _actuator_sysid.zero();

    _pd_scale_used = _pd_scale;
    _pd_scale = VECTORF_111;

    control_monitor_update();


    //************************************************************************************************************************
    //calculate the cost
    static uint32_t num3=0;
    static uint32_t num4=0;
    static uint32_t num5=0;
	static double sum3=0;
	static double sum4=0;
    static double sum5=0;
	double cost3=0;
    double cost4=0;
    double cost5=0;
    uint64_t now =AP_HAL::millis();
	


    if (now>45000)
{
	// sum3+=250*abs(_motors.get_roll())+1000*abs(_ang_vel_body.x-gyro_latest.x);
    // sum4+=250*abs(_motors.get_pitch())+1000*abs(_ang_vel_body.y-gyro_latest.y);
    // sum5+=750*abs(_motors.get_yaw())+1500*abs(_ang_vel_body.z-gyro_latest.z);
    //0916
    sum3+=245.4457734*abs(_motors.get_roll())+1000*abs(_ang_vel_body.x-gyro_latest.x);
    sum4+=240.6178*abs(_motors.get_pitch())+1000*abs(_ang_vel_body.y-gyro_latest.y);
    sum5+=864.131*abs(_motors.get_yaw())+1500*abs(_ang_vel_body.z-gyro_latest.z);
    

    // //*****************************************************************************************************************************************
 if (now<85000)
{
    ofstream outfile;
	outfile.open("AttData1007.csv", ios::out | ios::app);
	outfile<<_motors.get_roll()<<","<<_motors.get_pitch()<<","<<_motors.get_yaw()<<","<<_ang_vel_body.x<<","<<gyro_latest.x<<","<<_ang_vel_body.y<<","<<gyro_latest.y<<","<<_ang_vel_body.z<<","<<gyro_latest.z<<endl;
    outfile.close();

}
    
	if (now>88000 && 0 == num3 && 0==num4 && 0==num5)
	{
        cost3 = sum3/(now-45000);
        cost4 = sum4/(now-45000);
        cost5 = sum5/(now-45000);
        
		num3++;
        num4++;
        num5++;

        // printf("Roll Cost is %f\n",cost3/1.021818571);
		// AP::vehicle()->update_pso_cost(cost3/1.021818571,3);
        // printf("Pitch Cost is %f\n",cost4/0.992822286);
		// AP::vehicle()->update_pso_cost(cost4/0.992822286,4);
        // printf("Yaw Cost is %f\n",cost5/1.212235);
		// AP::vehicle()->update_pso_cost(cost5/1.212235,5);

         printf("Roll Cost is %f\n",cost3/0.944860723);
		AP::vehicle()->update_pso_cost(cost3/0.944860723,3);
        printf("Pitch Cost is %f\n",cost4/0.854675439);
		AP::vehicle()->update_pso_cost(cost4/0.854675439,4);
        printf("Yaw Cost is %f\n",cost5/0.780897585);
		AP::vehicle()->update_pso_cost(cost5/0.780897585,5);


	}
    //************************************************************************************************************************
    
    } 
}



// sanity check parameters.  should be called once before takeoff
void AC_AttitudeControl_Multi::parameter_sanity_check()
{
    // sanity check throttle mix parameters
    if (_thr_mix_man < 0.1f || _thr_mix_man > AC_ATTITUDE_CONTROL_MAN_LIMIT) {
        // parameter description recommends thr-mix-man be no higher than 0.9 but we allow up to 4.0
        // which can be useful for very high powered copters with very low hover throttle
        _thr_mix_man.set_and_save(constrain_float(_thr_mix_man, 0.1, AC_ATTITUDE_CONTROL_MAN_LIMIT));
    }
    if (_thr_mix_min < 0.1f || _thr_mix_min > AC_ATTITUDE_CONTROL_MIN_LIMIT) {
        _thr_mix_min.set_and_save(constrain_float(_thr_mix_min, 0.1, AC_ATTITUDE_CONTROL_MIN_LIMIT));
    }
    if (_thr_mix_max < 0.5f || _thr_mix_max > AC_ATTITUDE_CONTROL_MAX) {
        // parameter description recommends thr-mix-max be no higher than 0.9 but we allow up to 5.0
        // which can be useful for very high powered copters with very low hover throttle
        _thr_mix_max.set_and_save(constrain_float(_thr_mix_max, 0.5, AC_ATTITUDE_CONTROL_MAX));
    }
    if (_thr_mix_min > _thr_mix_max) {
        _thr_mix_min.set_and_save(AC_ATTITUDE_CONTROL_MIN_DEFAULT);
        _thr_mix_max.set_and_save(AC_ATTITUDE_CONTROL_MAX_DEFAULT);
    }
}

float AC_AttitudeControl_Multi::MFAC(float achieved_rate,float desired_rate,float eita,float miu,float rou1,float rou2,float rou3,float lamda)
{

	float now_rate=achieved_rate;

	float _MFAC_now=0.0f;
	static float MFAC_last1=0.0f;
    static float MFAC_last2=0.0f;
   
    static float last1_rate=0.0f;
    static float last2_rate=0.0f;
    static float last3_rate=0.0f;

    static float fai1_last=0;
	static float fai2_last=0;
    static float fai3_last=0.01;

	float fai1_now = fai1_last +eita * (now_rate-last1_rate-fai1_last*(last1_rate-last2_rate)-fai2_last*(last2_rate-last3_rate)-fai3_last*(MFAC_last1 - MFAC_last2))*(last1_rate-last2_rate)/
			(miu + (last1_rate-last2_rate)*(last1_rate-last2_rate)+(last2_rate-last3_rate)*(last2_rate-last3_rate) +(MFAC_last1 - MFAC_last2) * (MFAC_last1 - MFAC_last2));
	
	if ((abs(fai1_now) <= epsilon) || (sqrtf((last1_rate-last2_rate)*(last1_rate-last2_rate)+(last2_rate-last3_rate)*(last2_rate-last3_rate) +(MFAC_last1 - MFAC_last2) * (MFAC_last1 - MFAC_last2))<= epsilon)||fai1_now<0)
		{
			// fai1_now = gains.fai1;
			fai1_now = 0;
		}
		
	
	float fai2_now = fai2_last +eita * (now_rate-last1_rate-fai1_last*(last1_rate-last2_rate)-fai2_last*(last2_rate-last3_rate)-fai3_last*(MFAC_last1 - MFAC_last2))*(last2_rate-last3_rate)/
			(miu + (last1_rate-last2_rate)*(last1_rate-last2_rate)+(last2_rate-last3_rate)*(last2_rate-last3_rate) +(MFAC_last1 - MFAC_last2) * (MFAC_last1 - MFAC_last2));
	if ((abs(fai2_now) <= epsilon) || (sqrtf((last1_rate-last2_rate)*(last1_rate-last2_rate)+(last2_rate-last3_rate)*(last2_rate-last3_rate) +(MFAC_last1 - MFAC_last2) * (MFAC_last1 - MFAC_last2))<= epsilon)||fai2_now<0)
		{
			fai2_now = 0;
		}

	
	float fai3_now = fai3_last +eita * (now_rate-last1_rate-fai1_last*(last1_rate-last2_rate)-fai2_last*(last2_rate-last3_rate)-fai3_last*(MFAC_last1 - MFAC_last2))*(MFAC_last1 - MFAC_last2)/
			(miu + (last1_rate-last2_rate)*(last1_rate-last2_rate)+(last2_rate-last3_rate)*(last2_rate-last3_rate) +(MFAC_last1 - MFAC_last2) * (MFAC_last1 - MFAC_last2));
	if ((abs(fai3_now) <= epsilon) || (sqrtf((last1_rate-last2_rate)*(last1_rate-last2_rate)+(last2_rate-last3_rate)*(last2_rate-last3_rate) +(MFAC_last1 - MFAC_last2) * (MFAC_last1 - MFAC_last2))<= epsilon)||fai3_now<0)
		{
			fai3_now = 0.01;
		}

	// float kesi=fai2_now/(lamda+fai2_now*fai2_now);
	_MFAC_now=MFAC_last1+fai3_now*(rou3*(desired_rate-now_rate)-rou1*fai1_now*(now_rate-last1_rate)-rou2*fai2_now*(last1_rate-last2_rate))/(lamda+fai3_now*fai3_now);


	//update prameters
	last3_rate=last2_rate;
	last2_rate=last1_rate;
	last1_rate=now_rate;

	fai1_last=fai1_now;
	fai2_last=fai2_now;
	fai3_last=fai3_now;

	
	MFAC_last2=MFAC_last1;
	MFAC_last1=_MFAC_now;

	return _MFAC_now;
}