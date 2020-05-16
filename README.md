# HART_CS_2020
Repo for the backend of the GUI developed by the OSU HART rocketry team for CS capstone.

Backend is designed as a module that can be imported to a project and work out of the box for reading incoming data from the TeleMega altimeter.

## Building and Running
1. First, clone the repository to your local machine. This portion of the project is designed to be built using cmake. Clion has decent integration with cmake, we recommend you use clion to clone and build the repository, you can also use visual studio with the cmake extension installed.
2. After the repository is cloned, open the [AltosUI](https://altusmetrum.org/AltOS/) on your local machine.
3. Connect and set up the Teledongle to your computer, power on the telemega altimeter, and configure the altimeter within AltosUI.
4. Within configuration, set up logging for the telemetrum.
5. Initialize the parser with a string path to the logging file, this can be either an absolute or relative path.
6. Set up your toolchain to work with cmake on your local machine.
7. Build and run, this will be different based on your IDE and install.

## Future Development
This is a section for the things that we wish we could have completed, but did not have the time of resources. They are good starting points for anyone developing on this project in the future (requested by avionics team).
1. Add getters for the data types that you need to include within a GUI.
2. Remove the dependency on Altus Metrum software, instead read data from the serial port connected to the teledongle directly. This data is the same as the data in the .telem file.
3. Add testing (verification and validation) to the parser, creating a test suite could be an entire capstone project.
