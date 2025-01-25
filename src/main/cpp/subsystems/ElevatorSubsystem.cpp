#include "subsystems/ElevatorSubsystem.h"
#include "subsystems/MAXSwerveModule.h"
#include "Constants.h"
#include "Configs.h"
#include <frc/SmartDashboard/SmartDashboard.h>


ElevatorSubsystem::ElevatorSubsystem() {
    m_IntakeMotor.Configure(Configs::ElevatorConfig(),
                            SparkBase::ResetMode::kResetSafeParameters,
                            SparkBase::PersistMode::kPersistParameters);
}

void ElevatorSubsystem::raiseElevatorSimple(double speed) {
        m_IntakeMotor.Set(speed);
}