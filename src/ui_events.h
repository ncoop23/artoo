#ifndef UI_EVENTS_H
#define UI_EVENTS_H

namespace Event {

enum ID {
    None,
    GimbalInput,
    PairingRequest,
    PairingInProgress,
    PairingSucceeded,
    PairingCanceled,
    PairingIncomplete,
    ChargerConnChanged,
    ButtonFunctionUpdated,
    AltitudeUpdated,
    RssiUpdated,
    ArmStateUpdated,
    SystemLockoutStateChanged,
    SystemShutdown,
    BatteryThermalLimitExceeded,
    GpsFixChanged,
    GpsNumSatellitesChanged,
    GpsPositionChanged,
    HomeLocationChanged,
    FlightBatteryChanged,
    ArtooBatteryChanged,
    SystemUpdateBegin,
    SystemUpdateComplete,
    SystemUpdateFail,
    VehicleConnectionChanged,
    FlightModeChanged,
    SoloGimbalAngleChanged,
    SystemEnteredRunningState,
    AlertRecovery,
    GimbalConnChanged,
    NonAlertEnd,

    // alerts
    AlertBegin                  = 100,
    AltitudeCalRequired         = AlertBegin,
    CompassCalRequired,
    CompassInterference,
    LevelError,
    CalibrationFailed,
    WaitingForNavChecks,
    CantArmWhileLeaning,
    VehicleCalibrating,
    CompassCalibrating,
    LevelCalibrating,
    CompassCalRecovery,
    ThrottleError,
    VehicleRequiresService,
    FlightBatteryTooLowForTakeoff,
    UnknownBattery,
    ControllerBatteryTooLowForTakeoff,
    SystemIdleWarning,
    SoloAppConnected,
    SoloAppDisconnected,
    ControllerValueOutOfRange,
    CamControlValueOutOfRange,
    RecordRequiresApp,
    GimbalConnected,
    GimbalNotConnected,
    RCFailsafe,
    RCFailsafeNoGPS,
    RCFailsafeRecovery,
    FlightBatteryLow,
    FlightBatteryCritical,
    FlightBatteryFailsafe,
    MaximumAltitude,
    CrashDetected,
    LandingComplete,
    GpsLost,
    GpsLostManual,
    GpsLostRecovery,
    ShotInfoUpdated,
    ShotInfoUpdateFail,      // TODO: delete if not using
    RTLWithoutGPS,
    SoloConnectionPoor,
    ControllerBatteryCritical,
    ControllerBatteryFailsafe,
    ControllerBatteryFailsafeNoGps,
    ChargerConnected,
    CH7low,
    CH7high,
    IdleTimeoutDisabled,
    CH8low,
    CH8high,
    TestAlert,
    AlertEnd,
};

bool isAlert(Event::ID id);
bool isValid(unsigned id);

} // namespace event

#endif // UI_EVENTS_H
