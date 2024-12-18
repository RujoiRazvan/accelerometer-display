# accelerometer-display

## Description
This project uses the **Altera DE10 Lite** development board to display the inclination of the board using six hex seven-segment displays and ten LEDs. The inclination data is obtained from an **ADXL345** accelerometer.

The sensitivity of the x and y axes can be changed using a potentiometer connected to Channel 0 of the integrated ADC on the MAX10 FPGA. By adjusting the potentiometer, the voltage read by the ADC will change, which in turn will modify the scaling factor applied to the accelerometer readings for both the x and y axes.

Using a push button, the x and y axes can be calibrated for setting a new reference point, where pressing the button will save the current values of the accelerometer's x and y axes as the new zero (0, 0) values. This calibration process allows the accelerometer to be reset to a known orientation, making it easier to interpret subsequent sensor readings relative to this reference.

## Components Used
- **Development Board**: Altera DE10 Lite
- **Displays**: 6 x 7SegmentDisplays
- **LEDs**: 10 LEDs
- **Accelerometer**: ADXL345
- **Integrated Analog to Digital Converter**
- **Potentiometer**: 500k ohms
- **Switches**: 2 x switches
- **Push buttons**: 1 x push button
