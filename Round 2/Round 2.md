## Reflection on Cardboard Prototyping
### What did you set out to do?
We wanted to make a cardboard prototype of the arm and gripper mechanism, however, we were more concerned about the arm and not the gripper because we already have the draft CAD prepared for the gripper and will be adding more width to it. We were concerned about the arm since we require more servo motors than we have and need a new mechanism which will be able to rotate the arm to deposit the dinosaur into the catcher and turn the spool to lift the gripper vertically up at the same time.

### What did you learn from your prototype?
We learned the proper measurements required for the catcher to function properly and deposit the dinosaurs into the cage and how we would accomplish each individual task outlined in the competition.

### What changes do you propose based on these insights?
We do not need to change much, except the mechanism of the arm rotation. The catcher is relatively simple and will work with no risks. 

## Design Round 2 Scrum Planning
### What are the specific goals for this round? Aside from meeting this round’s design review deliverables, what are your own goals?
- Motors running (servo and DC)
- Ultrasonic sensors working (1 sensor was faulty, got replaced)
- CAD for the overall body of the robot so adding the arm and chassis is easier to place.
### What are the backlog items from last round?
The CAD for the base is not yet designed, but we reckoned that once we have the wheels and dimensions of the robot is when we should start the placements of the components. We are still trying to figure out the optimum height of lifting the dinosours while keeping the robot agile enough to have a high speed and not be off-balance.

### What are the tasks needed to achieve each goal, including the backlog items?
- Begin by connecting the servo motor to the Raspberry Pi Pico W. 
- Utilize the test code provided by Arduino to initialize and control the servo. 
- Use the myservo.write(angle) function to adjust the servo’s angle.
- Wheels: Implement the H-bridge motor driver to control DC motors. Connect the motor driver to the Pico W and the DC motors. Write and upload code to manage the motor’s direction and speed in forward, turning and strsight reverse modes. Test the setup and refine the code as needed.
- Failproof Gripper CAD and use linkage to ensure that it works.
- Review parts that need to be laser cut and CAD that needs to be revised.


### Who is responsible for each task/goal?
Samuel is in charge of most of the software, while i am responsible for most of the design and hardware.

The rest is outlined in **Project Overview**

> @Samuel Place the servo sketch in the round 2 folder AND the code folder. name the ino file in the round 2 folder as a copy version!

