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
void ElevatorSubsystem::lowerElevatorSimple(double speed) {
        m_IntakeMotor.Set(speed);
}

void ElevatorSubsystem::raiseElevatorTiered() {
    int level = this->getLevel();
    if (level == 4) {
        return;
    }
    int nextLevel = level + 1;
      m_IntakeMotor.Set(10);
    while (level < nextLevel){
        level = this->getLevel();
    } 
    m_IntakeMotor.Set(0);
}
void ElevatorSubsystem::lowerElevatorTiered() {
    int level = this->getLevel();
    if (level == 1) {
        return;
    }
    int nextLevel = level - 1;
      m_IntakeMotor.Set(-10);
    while (level > nextLevel){
        level = this->getLevel();
    } 
    m_IntakeMotor.Set(0);
}

int ElevatorSubsystem::getLevel() {
// returns the level of elevator (1-4)
        return 0;
}