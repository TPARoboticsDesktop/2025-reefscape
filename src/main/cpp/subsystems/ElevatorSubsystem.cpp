#include "subsystems/IntakeSubsystem.h"
#include "subsystems/MAXSwerveModule.h"
#include "Constants.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include <frc/util/color.h>


ElevatorSubsystem::ElevatorSubsystem() {
    m_colorMatcher.AddColorMatch(kGamePiece);
    m_colorMatcher.AddColorMatch(kBackGround);

    m_IntakeMotor.RestoreFactoryDefaults();
    
    m_IntakePIDController.SetP(1.5e-5);
    m_IntakePIDController.SetI(3.3e-7);
    m_IntakePIDController.SetD(0);
    m_IntakePIDController.SetFF(0.000015);
    m_IntakePIDController.SetOutputRange(-1, 1);
    
    m_led.SetLength(kLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();

    SetColorLED(0, 0, 255);


}

void ElevatorSubsystem::raiseElevatorSimple(double speed) {
        m_IntakeMotor.Set(speed);
}