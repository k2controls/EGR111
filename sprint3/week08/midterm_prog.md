---
layout: default
---

## EGR 111 - Introduction to Computer Science (C Programming)

### Midterm - Programming Activity

**Problem Statement:**
Create a solution in C named **bike_gear_speed_calc.c** that Calculate your bike speed in kilometers per hour (km/h) based on wheel dimensions, gear ratio, aand pedal cadence.

*REQUIREMENTS*
- Review online solution available [here](https://cyclingroad.com/bicycle-gear-ratio-cadence-and-speed-calculator/){:target='_blank'}. You will duplicate this calculator except that specific values for chainring and gear will be specified. 
- Review user entry and solution requirements for your solution by viewing this [solution video](bike_gear_speed_video.mp4){:target='_blank'}.
- Note the sample data in the video uses the default data on the web form with 52 entered for the Chainring size and 11 entered as the number of teeth for the selected gear. The resulting speed is 50.9 km/h as shown in the first entry in the speed table.

*SOLUTION*
1.  Create a week08 directory along with the bike_gear_speed_calc.c file.

2.  Create a *get_circumference* function.
    - The webpage provides the following equation for wheel circumference.
        - "If the type of your wheel is 700c (622 mm diameter) and the width of your tire is 23 mm, then:"

        - **Wheel circumference = (622 + 23 × 2) × pi = 2098.58 mm**
    - Pass the wheel diameter to your function as a parameter. Assume millimeters (mm) is the unit.
    - Pass width of the tire to your function as a parameter. 
    - Use a pre-processor define statement to create the label **PI** with a value of 3.14. Use this in your circumference calculation.
    - Your function must return the correct value for wheel circumference using appropriate data type definitions.

3. Create a *get_speed* function.
    - The webpage provides the following equation for speed.
        - "The formula for speed is:"

        - **Speed = Wheel circumference × Gear ratio × RPM**
    - Pass the wheel circumference to your function as a parameter. 
    - Pass the gear ratio to your function as a parameter.
    - Pass the pedal cadence to your function as a an rpm parameter.

4. Create a *main* function.
    - declare required variables using appropriate data types base on website and solution video.
    - Print welcome and direction messaging for the user. See the solution video for example start up messaging.
    - **Determine a wheel circumference**
        - Prompt the user for rim size and tire dimensions in mm as shown on the website and in the 0solution video.
        - Determine a wheel circumference by calling your *get_circumference* function and passing in user specified value.
    
    - **Determine gear ratio**
        - Prompt the user for the number of teeth in the chainring.
        - Prompt the user for the number of teeth on the selected gear.
        - See the solution video for an example.
        - Caculate a gear ratio dividing the number of teeth on the chainring by the number of teeth on the selected gear.

    - **Determine pedal cadence**
        - Prompt the user for their pedal cadence in rpms.
        - See the solution video for an example. 

    - **Determine the speed**
        - Calculate the speed based on the user's input by calling your *get_speed* function and passing in your values for circumference, gear ratio, and rpms.
        - Output the resulting calculated speed in km/h to the user.
        - Test your solution using the data shown in the solution video and on the website.

- Commit your final code to your week08 directory and push your code to your remote repository. You must push/submit by the end of the class period. Check your GitHub repository to validate your code is submitted. 

<!-- **Grading**

| # | Requirement                           | Pts | Score  |
|---|---------------------------------------|-----|---|
| 1 | C source code submitted and compiles  |  5  |   |
| 2 | Welcome and directions displayed      |  5  |   |
| 3 | User input - gallons and odometer     |  5  |   |
| 4 | Data types - per demo                 |  5  |   |
| 5 | MPG function declaration/definition   | 10  |   |
| 6 | MPG function call                     |  5  |   |
| 7 | Looping/iteration with control        | 10  |   |
| 8 | Selection of max value                | 10  |   |
| 9 | Results output as shown in demo       |  5  |   |
|10 | Coding format and style               | 10  |   |
|   |                             TOTAL     | 70  |   | -->
