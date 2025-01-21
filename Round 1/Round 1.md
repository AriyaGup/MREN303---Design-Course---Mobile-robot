## Overarching Design Problem
Autonomous: The robot line follows to a certain point, then navigates across the first arena for a button-press and successfully exits through a door in 30 seconds.
Manual: Robot picks up dinosaurs and places them in a cage, then picks and places minions in a pit and then rescues a ken-doll from a ditch and places it on a helipad in 60 seconds.




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

**Constraints:**

- Button-press while having the gripper arm in front of the robot. Robot’s arm placement should be above the wall height or should be used to press the button.
- Robot can’t run into wall during button-press and needs to know where to stop so no damage is done.
- Need turns to be perfect so we can accomplish the button-press.
### MANUAL MODE
- 6 Dinos
- Some (5-7) Minions
- Ken is the heaviest prop to pick up.
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

