#pragma once

#include <rev/ColorSensorV3.h>
#include <frc/Timer.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/SparkAbsoluteEncoder.h>
#include <rev/SparkClosedLoopController.h>
#include <rev/SparkRelativeEncoder.h>

class IntakeSubsystem : public frc2::SubsystemBase {
public:
    IntakeSubsystem();
    void SetIntakeMotorSpeed(double speed);

private:
    rev::spark::SparkMax m_IntakeMotor{20, rev::spark::SparkMax::MotorType::kBrushless};  // Replace '20' with the CAN ID of the Spark MAX

    rev::spark::SparkRelativeEncoder m_Encoder =
        m_IntakeMotor.GetEncoder();
    rev::spark::SparkClosedLoopController m_IntakePIDController =
        m_IntakeMotor.GetClosedLoopController();
   
    static constexpr int kLength = 46;

};