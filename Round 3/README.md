## Round 3 Scrum Planning answers
### What are the specific goals for this round? Aside from meeting this round’s design review deliverables, what are your own goals?
Specific goals for this round include a fully integrated electrical circuit, functioning motor control system, and starting on the autonomous mode. We also need to create a power budget.

Our individual goals are to have a fully functional manipulator by the end of this round that reacts to the gamepad commands, along with the base of the robot laser cut. 

## What are the backlog items from last round?
tyre CAD and gearbox

## What are the tasks needed to achieve each goal, including the backlog items?
- Drivetrain CAD
- Wheel CAD
- Autonomous mode completion
- Servo motors working and integrated
- Ultrasonic sensors integrated
- Manipulator CAD 

## Who is responsible for each task/goal?
Documentation, CAD and assembly - Ariya
Component testing, logic and other coding - Samuel

# Power budget
The batteries are in series, so 4.8V is supplied to the circuit while the Pico W is connected and powered, which utilizes 50mA according to the raspberry pi forum.

The motor utilizes 300mA when running and the H-Bridge resistance is negligible so we canot calculate the current lost. Using 2 motors = 600mA. The robot will not be idle for too long so the stall current for all motors is not considered.

The HITEC Servo each uses 0.15A according to Sparkfun.com, and an ultrasound sensor utilizes 15mA according to MakerPortal.com. Using all 3 servos = 450mA.

Total = 0.6A + 0.015A + 0.05A + 0.45A = 1.115A 

Hours of testing = 2500mAh/1115A = 2.242h = 2h 14mins

