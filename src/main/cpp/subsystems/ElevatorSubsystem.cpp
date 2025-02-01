#include "subsystems/ElevatorSubsystem.h"
#include "subsystems/MAXSwerveModule.h"
#include "Constants.h"
#include "Configs.h"
#include <frc/SmartDashboard/SmartDashboard.h>

using namespace ElevatorConstants;


ElevatorSubsystem::ElevatorSubsystem() {
    m_ElevatorMotor.Configure(Configs::ElevatorConfig(),
                            SparkBase::ResetMode::kResetSafeParameters,
                            SparkBase::PersistMode::kPersistParameters);
}

void ElevatorSubsystem::raiseElevatorSimple(double speed) {
        m_ElevatorMotor.Set(speed);
}
void ElevatorSubsystem::lowerElevatorSimple(double speed) {
        m_ElevatorMotor.Set(speed);
}

void ElevatorSubsystem::raiseElevatorTiered() {
    int level = this->getLevel();
    if (level == 4) {
        return;
    }
    int nextLevel = level + 1;

    double encoderPosition = ElevatorConstants::encoderTiers[nextLevel];
    this->m_ElevatorPIDController.SetReference(encoderPosition, SparkMax::ControlType::kPosition);

    /*
    m_ElevatorMotor.Set(100);
    while (level < nextLevel){
        level = this->getLevel();
    } 
    m_ElevatorMotor.Set(0);
    */
}
void ElevatorSubsystem::lowerElevatorTiered() {
    int level = this->getLevel();
    if (level == 1) {
        return;
    }
    int nextLevel = level - 1;

    double encoderPosition = ElevatorConstants::encoderTiers[nextLevel];
    this->m_ElevatorPIDController.SetReference(encoderPosition, SparkMax::ControlType::kPosition);

    /*
    m_ElevatorMotor.Set(-100);
    while (level > nextLevel){
        level = this->getLevel();
    } 
    m_ElevatorMotor.Set(0);
    */
}

int ElevatorSubsystem::getLevel() {
// returns the level of elevator (1-4)
    double encoderPosition = this->m_Encoder.GetPosition();
    if (encoderPosition < ElevatorConstants::encoderTiers[1]) {
        return 0;
    }
    else if (encoderPosition < ElevatorConstants::encoderTiers[2]) {
        return 1;
    }
    else if (encoderPosition < ElevatorConstants::encoderTiers[3]) {
        return 2;
    }
    else if (encoderPosition < ElevatorConstants::encoderTiers[4]) {
        return 3;
    }
    else if (encoderPosition < ElevatorConstants::encoderTiers[5]){
        return 4;
    }
    else {
        return 5;
    }
}