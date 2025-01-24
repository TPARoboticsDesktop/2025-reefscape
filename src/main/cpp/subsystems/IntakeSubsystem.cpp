#include "subsystems/IntakeSubsystem.h"
#include "subsystems/MAXSwerveModule.h"
#include "Constants.h"
#include <frc/SmartDashboard/SmartDashboard.h>
#include <frc/util/color.h>


IntakeSubsystem::IntakeSubsystem() {
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

void IntakeSubsystem::SetIntakeMotorSpeed(double speed) {
        m_IntakeMotor.Set(speed);
}

void IntakeSubsystem::SetColorLED(int R, int G, int B){
    for (int i = 0; i < kLength; i++) {
   m_ledBuffer[i].SetRGB(R, G, B);
    }

    m_led.SetData(m_ledBuffer);


}