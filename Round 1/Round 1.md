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

We chose the design that we did because of the minimal risk of things that could go wrong. since there were heavy parts that were moving, that lowered the voltage needed and probability of something big going wrong. Using simple mechanisms that are used in everyday machines, we were confident that the design we decided upon would work. We decided not to go with the fixed arm deesign because of the strain it would cause on the angled arm. We also wanted to add a DOF using minimal risk of something going wrong.

Design drafts can be seen in the Image in this folder.



## Task Assignment
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

