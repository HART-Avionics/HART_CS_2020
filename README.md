# HART_CS_2020
Repo for the backend of the GUI developed by the OSU HART rocketry team for CS capstone.

Backend is designed as a module that can be imported to a project and work out of the box for reading incoming data from the TeleMega altimeter.

## Building and Running
1. First, clone the repository to your local machine. This portion of the project is designed to be built using cmake. Clion has decent integration with cmake, we recommend you use clion to clone and build the repository.
2. After the repository is cloned, open the [AltosUI](https://altusmetrum.org/AltOS/) on your local machine.
3. Connect and set up the Teledongle to your computer, power on the telemega altimeter, and configure the altimeter within AltosUI.
4. Within configuration, set up logging for the telemetrum.
5. Copy the path to the logging file into the project filename inside.
