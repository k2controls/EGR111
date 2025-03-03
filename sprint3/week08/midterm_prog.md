---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### Midterm - Programming Activity

**Problem Statement:**
Create a solution in C named **bike_gear_speed_calc.c** that calculates your bike speed in kilometers per hour (km/h) based on wheel dimensions, gear ratio, and pedal cadence.

**REQUIREMENTS**
- Review the online solution available [here](https://cyclingroad.com/bicycle-gear-ratio-cadence-and-speed-calculator/){:target='_blank'}. You will duplicate this calculator except that specific values for chainring and gear will be specified by the user in the program.
- Watch the solution video provided [bike_gear_speed_video.mp4]{:target='_blank'} to understand the user entry and solution requirements. This video will demonstrate how to enter values like the chainring size (52 teeth) and gear size (11 teeth), leading to a resulting speed of 50.9 km/h, as seen in the speed table.

**SOLUTION**
1. **Create a week08 directory and the bike_gear_speed_calc.c file.**

2. **Create a `get_circumference` function.**
    - The webpage provides the following equation for wheel circumference:
      - "If the type of your wheel is 700c (622 mm diameter) and the width of your tire is 23 mm, then:"
      - **Wheel circumference = (622 + 23 × 2) × pi = 2098.58 mm**
    - Pass the wheel diameter to your function as a parameter. Assume millimeters (mm) as the unit.
    - Pass the width of the tire to your function as a parameter.
    - Use a pre-processor `#define` statement to create the constant **PI** with a value of 3.1416 and use this in your circumference calculation.
    - Your function should return the correct value for the wheel circumference, and it must use an appropriate data type (e.g., `double`) for the return value.

3. **Create a `get_speed` function.**
    - The webpage provides the following equation for speed:
      - **Speed = Wheel circumference × Gear ratio × RPM**
    - Pass the wheel circumference to your function as a parameter.
    - Pass the gear ratio to your function as a parameter.
    - Pass the pedal cadence as an RPM parameter.
    - Your function should return the calculated speed in kilometers per hour (km/h).

4. **Create a `main` function.**
    - Declare required variables using appropriate data types based on the website and solution video.
    - Print welcome and instruction messages for the user (see the solution video for example messaging).
    
    **Determine a Wheel Circumference:**
    - Prompt the user for the rim size and tire dimensions in mm as shown on the website and in the solution video.
    - Calculate the wheel circumference by calling the `get_circumference` function, passing in the user-specified values.

    **Determine Gear Ratio:**
    - Prompt the user for the number of teeth on the chainring.
    - Prompt the user for the number of teeth on the selected gear.
    - Calculate the gear ratio by dividing the number of teeth on the chainring by the number of teeth on the selected gear (gear ratio = chainring teeth / gear teeth).

    **Determine Pedal Cadence:**
    - Prompt the user for their pedal cadence in RPM (revolutions per minute).
    
    **Determine the Speed:**
    - Calculate the speed based on the user's input by calling the `get_speed` function and passing in the values for circumference, gear ratio, and RPM.
    - Output the resulting calculated speed in km/h to the user.
    - Test your solution using the data shown in the solution video and on the website to verify correctness.

5. **Final Submission Instructions:**
    - Commit your final code to your week08 directory and push the code to your remote GitHub repository. You must push/submit by the end of the class period. Check your GitHub repository to ensure the code is submitted properly.

---

**Grading Criteria**:

| #  | Requirement                                   | Points |
|----|-----------------------------------------------|--------|
| 1  | C source code is submitted and compiles       |  5     |
| 2  | Welcome and directions displayed              |  5     |
| 3  | User input - wheel diameter, tire width, gear ratio, and cadence |  10    |
| 4  | Data types used as per demo                   |  5     |
| 5  | `get_circumference` function correctly implemented | 10     |
| 6  | `get_speed` function correctly implemented     | 10     |
| 7  | Correct output formatting (km/h speed)        | 10     |
| 8  | Clear, professional code formatting and style |  10    |
| 9  | Code is modular (proper use of functions)     |  5     |
| **Total** | **Final Score**                             | **70** |

---

**Notes and Tips:**
- Ensure your functions are well-organized and use clear variable names.
- Follow the formatting conventions provided in the solution video (e.g., for printed output).
- Test your program using the values given in the solution video to ensure that your speed calculation is correct.
