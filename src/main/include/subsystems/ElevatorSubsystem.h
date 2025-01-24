#pragma once

#include <rev/ColorSensorV3.h>
#include <frc/Timer.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/SparkAbsoluteEncoder.h>
#include <rev/SparkClosedLoopController.h>
#include <rev/SparkRelativeEncoder.h>
#include <rev/colorMatch.h>
#include <frc/AddressableLED.h>

class ElevatorSubsystem : public frc2::SubsystemBase {
public:
    ElevatorSubsystem();
    void raiseElevatorSimple(double speed);

private:
    rev::SparkMax m_IntakeMotor{20, rev::SparkMax::MotorType::kBrushless};  // Replace '20' with the CAN ID of the Spark MAX

    rev::RelativeEncoder m_Encoder =
        m_IntakeMotor.GetEncoder(rev::RelativeEncoder::Type::kHallSensor);
    rev::SparkClosedLoopController m_IntakePIDController =
        m_IntakeMotor.GetPIDController();

    rev::ColorSensorV3 m_colorSensor{frc::I2C::Port::kOnboard};

    rev::ColorMatch m_colorMatcher;
    frc::Color kGamePiece = frc::Color(0.666626, 0.299927, 0.047729);
    frc::Color kBackGround = frc::Color(0.380981, 0.441772, 0.170776);
   
    static constexpr int kLength = 46;

    // PWM port 9
    // Must be a PWM header, not MXP or DIO
    frc::AddressableLED m_led{0};
    std::array<frc::AddressableLED::LEDData, kLength>
      m_ledBuffer;  // Reuse the buffer
    // Store what the last hue of the first pixel is
    int firstPixelHue = 0;

    
};