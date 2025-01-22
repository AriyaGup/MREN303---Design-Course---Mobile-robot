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

## Design on Paper 
**Are you happy with these ideas?**

After mulling over the ideas, they seem tangible. We are happy with these ideas. The gripper is similar to that of a vending machine motion, so they are simple to construct although the programming will be a challenge for us. One problem we face is that we require a motor for the trapdoor to open and close, but 2 6V motors are being used for the wheels, and 3 motors are being used for the arm. we will have to change the mechanism of the arm without changing the design so that we can utilise one of its motors for the trapdoor.

**Instinct - is there an idea that you want to try based on your creative instincts and desire to learn?**

Using a scooping gripper that clasps at the top would be ideal for picking up dinos and minions, but not for ken in a ditch. We would have ideally used an arm with only 1 DOF and a scooping mechanism if there was no need to lift ken from a ditch.

**Analytical - is there an idea that you know from previous courses or your past experience that should work?**

We know the gripper will work, having worked with various grippers in MREN 103 and APSC 101. One challenge is that it needs to lift & swivel, which would be a combination of what we have done in the past.

**Are your ideas all high risk, low risk, or a combination of the two?**

Our ideas are a combination of the two. We are confident about certain aspects of the design and code but require lots of testing and more time. We have done each part of this project separately, but this project requires a combination of everything in greater depth.

**Choose one of the ideas to explore further. Does the chosen idea have prior art? What has been done that is similar to your idea? What are some of their shortcomings? What do you proposed to do differently, if anything?**

Using a AWD Differential drive with a claw gripper that picks up vertically and swivels 180 degrees while retracting upward simultaneously. Then places the prop intot he catcher which has a trapdoor so as to not use too much voltage to drop off the props. 

We have done a similar gripper design in previous years, and have used the exact wheel mechanism with a gamepad to maneuver a mobile robot. However, previously, we have picked and placed the prop onto a higher surface and the arm was fixed at a stationary frame, not moving on a mobile robot. 

We will need 2 set sof code to control the arm and the robot while using the same gamepad with limited buttons. We have already been given code where a button can swap functions between the other buttons. We will need to figure out how we can do this with our own functions, but changing them entirely instead of swapping them.

**What are some open questions for your mechanism?**

- Amount of torque required to lift the gripper with Ken and swivel at the same time?
- Do we need torque to grip the object or is it going to hang loosely in the grip?
- What is the strain on the beam, and how long ar we going to make it so that it is not too heavy?
- What is the range of motion of the arm vertically and tangentially?
- What is the counterweight required for button-press and lifting Ken?
- What speed can we move at without losing functionality or wasting our battery?
- What is the pace we need to be at to make sure we can accomplish the tasks?

**Perform a back-of-the-envelope calculation to arrive at an educated guess for one of your questions. Some examples include calculating torque, range of motion, or speed.**


