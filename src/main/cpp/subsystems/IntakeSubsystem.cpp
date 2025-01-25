#include "subsystems/IntakeSubsystem.h"
#include "subsystems/MAXSwerveModule.h"
#include "Constants.h"
#include "Configs.h"
#include <frc/SmartDashboard/SmartDashboard.h>


IntakeSubsystem::IntakeSubsystem() {
    m_IntakeMotor.Configure(Configs::IntakeConfig(),
                            SparkBase::ResetMode::kResetSafeParameters,
                            SparkBase::PersistMode::kPersistParameters);
}

void IntakeSubsystem::SetIntakeMotorSpeed(double speed) {
        m_IntakeMotor.Set(speed);
}