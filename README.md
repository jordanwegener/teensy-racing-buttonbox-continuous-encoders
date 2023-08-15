# Teensy LC Button Box for Racing and Flight Simulators

## Description

This project provides code for a button box interface with rotary encoders, specifically designed for racing and flight simulators. Utilizing the Teensy LC microcontroller, the button box reads input from physical buttons and rotary encoders and translates it into joystick inputs using the Joystick library. This code has been successfully used to build a fully functioning button box, with some considerations regarding the rotary encoders' sensitivity to rapid turns.

## Features

- **Simulator Compatibility**: Ideal for racing or flight simulator controls.
- **4 Rotary Encoders**: With associated push buttons for more precise control.
- **9 Additional Input Buttons**: For various functions within the simulator.
- **Configurable Delay**: To adjust the sensitivity of rotary inputs.

## Hardware Requirements

- Teensy LC microcontroller
- 4 Rotary encoders (with 4 push buttons)
- 9 Additional push buttons
- Appropriate resistors and wiring

## Dependencies

- Encoder Library: To read the rotary encoders.
- Joystick Library: To emulate joystick input.

## Usage

### Wiring

Connect the rotary encoders and push buttons according to the pin definitions in the code:

- Rotary encoders to pins (2, 3), (5, 6), (8, 9), (11, 12)
- Push buttons to pins 4, 7, 10, 13, 14, 15, 20, 21, 22

### Uploading the Code

1. Install the required libraries (Encoder and Joystick) through your Arduino IDE.
2. Connect the Teensy LC microcontroller to your computer.
3. Upload the provided code to the Teensy LC.

### Customization

- Modify the `rot_delay` constant to change the delay between rotary clicks registering.

## Known Issues

- **Encoder Sensitivity**: If the rotary encoders are turned too quickly, they may not register most of the clicks. Adjusting the `rot_delay` constant can help alleviate this issue to some extent.

## Contributing

Feel free to modify and improve the code. If you encounter any issues or have suggestions, please open an issue or submit a pull request.

## License

This code is available under the MIT License. See the LICENSE file for more details.

## Contact

For further information, support, or customization, please contact the project maintainer.

---

This version of the README includes more specific details about the project's application in racing and flight simulators and highlights your success in building a button box with this code. It also acknowledges the known issue with the rotary encoders when turned too quickly.
