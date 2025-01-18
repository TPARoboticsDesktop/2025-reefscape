// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/controller/PIDController.h>
#include <frc/geometry/Translation2d.h>
#include <frc/SmartDashboard/SmartDashboard.h>
#include <frc/trajectory/Trajectory.h>
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/SwerveControllerCommand.h>
#include <frc2/command/button/JoystickButton.h>
#include <units/angle.h>
#include <units/velocity.h>

#include <utility>

#include "Constants.h"
#include "LimelightHelpers.h"


using namespace DriveConstants;

RobotContainer::RobotContainer() {
        
  // Initialize all of your commands and subsystems here

  // Configure the button bindingsR
  ConfigureButtonBindings();

    // Set up default drive command
  // The left stick controls translation of the robot.
  // Turning is controlled by the X axis of the right stick.
  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this] {
        //set default values based on joysticks
        double y = -frc::ApplyDeadband(m_driverController.GetLeftY(), OIConstants::kDriveDeadband);
        if (y<0){
            y = -y*y*1.09;
        }
        else
        {
            y = y*y*y*1.09;
        }
        double x = -frc::ApplyDeadband(m_driverController.GetLeftX(), OIConstants::kDriveDeadband);
        if (x<0){
            x = -x*x*1.09;
        }
        else
        {
            x = x*x*1.09;
        }
        double theta = -frc::ApplyDeadband(m_driverController.GetRightX(), OIConstants::kDriveDeadband)*0.8;
      }
  ))
}

void RobotContainer::ConfigureButtonBindings() {
    //set wheels to the X configuration
    /*
    frc2::JoystickButton(&m_driverController,
                       frc::XboxController::Button::kRightBumper)
        .WhileTrue(new frc2::RunCommand([this] { m_drive.SetX(); }, {&m_drive}));
        */
    
   
}
    

frc2::Command* RobotContainer::GetAutonomousCommand() {
 return m_chooser.GetSelected();
}
