## Overarching Design Problem
**Autonomous**: The robot line follows to a certain point, then navigates across the first arena for a button-press and successfully exits through a door in 30 seconds.

**Manual**: 60 seconds
- Robot picks up differently shaped dinosaurs and places them in a cage, 
- then picks and places minions in a fire pit 
- and then rescues a ken-doll from a ditch and places it on a helipad.

## Sub-objectives
- Maneuvering around mountains and minions until dinosaurs are caged (6 in total). There will be 5-7 minions to dispose of for 1 point each. They are bigger but lighter than dinos so smaller number of minions will fit in the catcher.
- The robot has to be small enough and agile enough to fit through the gates and around the props.
- Counterweight so the robot can successfully push the button and lift the heavier ken-doll prop. Ken is the heaviest prop to pick up.

## Constraints
- Button-press while having the gripper arm in front of the robot. Robot’s arm placement should be above the wall height or should be used to press the button.
- Robot can’t run into wall during button-press and needs to know where to stop so no damage is done.
- Need turns to be perfect so we can accomplish the button-press.
- The counterweight can't be too heavy otherwise it'll slow the robot down. 
- Limited motors for arm and wheel operations. Only 2 6V motors given.

## Top Ideas
- Use a fixed shoulder arm with a hinged elbow for ease of maneuvering the dinos into the catcher. L-Brace to lift catcher bucket that is used to corral the dinos.
_High voltage required for this. Need more DOF for the arm for unpreedicted challenges._ 
- Use a trapdoor for the catcher. String to lower and lift the gripper and the base will swivel to deposit dino into catcher.
_Low voltage required. Weight of motor on arm might be too heavy, but the range of motion of the arm is limited and the second motor will not pull the dino in any horizontal direction._
- RWD might give traction loss up the ramp to the fire pit and ken, so we decided on AWD differential drive.

We chose the design that we did because of the minimal risk of things that could go wrong. lesser heavy parts moving lowered the voltage needed and probability of things going wrong. Using simple mechanisms that are used in everyday machines, we were confident that the design we decided upon would work. 

We decided not to go with the fixed arm deesign because of the strain it would cause on the angled arm. We also wanted to add a DOF using minimal risk of something going wrong.

An AWD differential allows us to be able to be more agile - turn in place and not lose traction up the ramp.

Design process can be seen in "Ideas.jpg".

## Scrum Planning
**What are the specific goals for this round? Aside from meeting this round’s design review deliverables, what are your own goals?**
- Brainstorm tangible design ideas, sub-objectives, and constraints.
- The gamepad words as intended.
- The battery is correctly displayed.
- Complete our intended cardboard model of the robot.
- Get started with CAD using the measurements that we have so far.
- Overview of health and safety risks.

**What are the tasks needed to achieve each goal?**
- Take measurements of everything on the arena. 
- Get MAC ID and IP address. Mkae sure communication between the gamepad and the Pico W works.
- draw a detailed rendering of the prototype before starting the cardboard model.

**Who is responsible for each task/goal?**
- Design and wiring - Ariya
- Software - Samuel
- Cardboard prototype - Both

## Health & Safety 
- Personal 
- Electrical 
- Enviroment 

**Personal Safety**

Eye protection: Goggles should be used during activities like solder or hen using machinery to cut hard objects, fragments may fly into the eyes.

**Training**

Proper training should be required before using dangerous machinery like a laser cutter. We have planned to get training later in the semester for this. Also no one should be alone when work with dangerous machinery. There should be accompanied by a supervisor. 

**Electrical Safety**

Electrical circuit: Double check the wiring and make sure metal part of wires are not exposed before turing any electrical component on to avoid short circuit and electrical shock.

Batteries: Monitor batteries condition regularly to avoid using batteries that are damaged, also use the voltage divider to monitor batter level.

Overheating: Check if component are overheating, careful read datasheet before using, make sure components are wired correctly and with the appropriate current and resistance.

**Enviromental Safety**

Fire hazard precaution: Knowing location of fire alarm pull stations, portable fire extinguishers,emergency evacuation procedures

Ventilation: Work in well-ventilated area when soldering or using materials that emit fumes to avoid beathing in harmful gases.





**Autonomous**

- Line Following
- Sensors, Turning, Button-press & Exit
- Exit out of Autonomous Mode

**Manual**

- Gripper CAD
- Robo Body
- Dino catcher with trap-door 
- Motion control of robot using gamepad
- Motion control of arm using gamepad


### Autonomous Mode

**Process:**

Line following sensor to follow the line East to the door. 

Ultrasonic sensor to disable line-follower function and stop a short distance before the door.

Take a sharp left North and go straight to the wall.

Stop a short distance from the wall.

Take a sharp turn East and go forward to press the button. Need to know when to stop after pressing the button.

Go backwards a short distance and either exit the gate diagonally, or turn South and exit forming an arch.

### MANUAL MODE

- Make 3D print of gripper wider for Ken-doll.
- Add glue gun polymer for better grip on props.
- Using gamepad allows for minimal delay and accurate control.

### Top 3 ideas
See "Drafts" IMG in Branch Round1

### Risk 
1. Gripper not being able to hold all three type of objects due to different shape and weight
2. Not being able to open gate by pressing button, the button is stiff, it requires a significant amout of force
3. Unable to locate button, since the plan for button pressing is that the robot makes 90 degrees truns when the sensor detects the wall, therefore each turn has to be nearly perfect
4. Falling behind schedule
5. Exceed maximum CAD volume

### Prioritize risks
1. Battery Overheating
Impact: Moderate | Likelihood: possible  Priority: Low Med
2. 
Impact: Severe | Likelihood: possible  Priority: Med Hi
3. Impact: Severe | Likelihood: Likely  Priority: High
4. Impact: Moderate | Likelihood: unlikely  Priority: Low Med
5. Impact: Minor | Likelihood: Very unlikely  Priority: Low

