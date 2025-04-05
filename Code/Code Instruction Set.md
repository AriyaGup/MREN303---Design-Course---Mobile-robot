## Gamepad
- A: switch to auto mode
- B: switch to manual mode
- X: Break
- Y: switch to idle mode
- Start: Monitor Battery
- L stick: Movement control 
- R stick Y: Joint 1 movement 
- R stick X: Joint 2 movement
- Left: Open Gripper
- Right: Close Gripper

Controller setup will only work when the switch on the back is in the “X” position (not “D”).
Pressing the “mode” button will switch the functionality of the dpad and left analog stick.

## Motor Function
|AIN1 |AIN2 |PWM |Function|
|---|---|---|---|
|High |High |High/Low |Short brake|
|Low |High |High |Turn one direction
|Low |High |Low |Short brake
|High |Low |High |Turn other direction
|High |Low |Low| Short brake
|Low |Low |High |Stop
-------------------------------
**IP**: 192.168.1.45

**MAC**: D8:3A:DD:27:5E:2B