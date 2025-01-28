from machine import Pin, PWM
import time

# Motor A pins
AIN1 = Pin(16, Pin.OUT)  # Direction control 1 for Motor A
AIN2 = Pin(17, Pin.OUT)  # Direction control 2 for Motor A
PWMA = PWM(Pin(20))      # Speed control for Motor A

# Motor B pins
BIN1 = Pin(18, Pin.OUT)  # Direction control 1 for Motor B
BIN2 = Pin(19, Pin.OUT)  # Direction control 2 for Motor B
PWMB = PWM(Pin(21))      # Speed control for Motor B

# Set PWM frequency
PWMA.freq(1000)
PWMB.freq(1000)

def stop_motors():
    """Stop both motors"""
    AIN1.value(0)
    AIN2.value(0)
    BIN1.value(0)
    BIN2.value(0)
    PWMA.duty_u16(0)
    PWMB.duty_u16(0)

def set_motor_speed(pwm, speed):
    """Convert speed percentage (0-100) to PWM duty cycle"""
    if speed < 0:
        speed = 0
    elif speed > 100:
        speed = 100
    duty = int(speed * 65535 / 100)  # Convert to 16-bit duty cycle
    pwm.duty_u16(duty)

def motor_a_forward(speed):
    """Run motor A forward at specified speed (0-100)"""
    AIN1.value(1)
    AIN2.value(0)
    set_motor_speed(PWMA, speed)

def motor_a_backward(speed):
    """Run motor A backward at specified speed (0-100)"""
    AIN1.value(0)
    AIN2.value(1)
    set_motor_speed(PWMA, speed)

def motor_b_forward(speed):
    """Run motor B forward at specified speed (0-100)"""
    BIN1.value(1)
    BIN2.value(0)
    set_motor_speed(PWMB, speed)

def motor_b_backward(speed):
    """Run motor B backward at specified speed (0-100)"""
    BIN1.value(0)
    BIN2.value(1)
    set_motor_speed(PWMB, speed)

# Example usage
try:
    while True:
        # Run both motors forward at 50% speed
        print("Running motors forward")
        motor_a_forward(50)
        motor_b_forward(50)
        time.sleep(2)
        
        # Stop motors
        print("Stopping motors")
        stop_motors()
        time.sleep(1)
        
        # Run both motors backward at 75% speed
        print("Running motors backward")
        motor_a_backward(75)
        motor_b_backward(75)
        time.sleep(2)
        
        # Stop motors
        print("Stopping motors")
        stop_motors()
        time.sleep(1)

except KeyboardInterrupt:
    stop_motors()
    print("Program stopped")
