# Integrating new DUNE maneuver "Bottom Up Search" in LSTS software toolchain

## Description
This project integrates a new maneuver in the existing LSTS software toolchain. The maneuver "Bottom Up Search" steers an AUV from a specified depth towards the surface, while maintaining low speed and high pitch. The project is part of the course TTK22 at NTNU and includes integration of the new maneuver, definition of a corresponding IMC message and synchronization of the new message with DUNE and NEPTUS.

## Installation

### Prerequisites

git, cmake, g++, ant


### IMC

Clone the LTS/IMC forked repository

```bash
git clone --single-branch --branch bottomUpSearch https://github.com/ivanhkingman/imc
```


### DUNE

Clone the LSTS/Dune forked repository

```bash
git clone --single-branch --branch bottomUpSearch https://github.com/ivanhkingman/dune
```

Create a link to IMC and compile IMC library
```bash
cd dune
mkdir build
cd build
ln -s path_to_imc IMC
cmake ..
make imc
```

Compile DUNE from build folder (may take some time)
```bash
make
```


### NEPTUS

Clone the official LSTS/neptus repository. Make sure to clone the courses/ttk22 branch.

```bash
git clone --single-branch --branch courses/ttk22 https://github.com/LSTS/neptus
```
Note: If you get the following error message

```bash
error: RPC failed; curl 56 GnuTLS recv error (-24): Decryption has failed.
fatal: The remote end hung up unexpectedly
fatal: early EOF
fatal: index-pack failed
```
try using a different internet connection or a VPN.


### Synchronize IMC with Neptus

Before compiling Neptus, however, we need to synchronize with IMC

Clone the official LSTS/imcjava:

```bash
git clone https://github.com/LSTS/imcjava
```

Open the file settings.gradle. Line 10 should read

`gradle.ext.imcFilePath = '../imc`

Make sure the path matches the relative path to the IMC folder. (Simply copy the above line if no changes has been made)

Update with IMC and generate libimc.jar file.

```bash
cd imcjava
./gradlew updateIMCFromFolder
./gradlew dist
```

Rename the generated library file **libimc-6.0.0.jar** to **libimc.jar** located in `imcjava/dist/` and paste it into neptus library folder `neptus/lib/`. This should replace the currently existing libimc.jar file


### Generating parameters of the new DUNE task and update it on NEPTUS

To generate parameters for lauv-xplore-1 in simulation profile, do the following from the DUNE build folder:

```bash
./dune -c lauv-xplore-1 -p Simulation -X path_to_neptus/conf/params
cd path_to_neptus
ant
```


## Verify

With IMC, Dune, Neptus and imcjava, the setup should now be complete. The folder structure should look something like this:

- workspace
    - dune
    - neptus
    - imc
    - imcjava

For a minimum working example, clone the example from this repository

```bash
git clone https://github.com/ivanhkingman/project_TTK22
```

Build the project by doing the following

```bash
cd project_TTK22
mkdir build
cd build
cmake ..
make
```
In a seperate terminal, start an instance of DUNE, running the lauv-xplore-1:
```bash
cd path-to-dune
cd build
./dune -c lauv-xplore-1 -p Simulation
```
Open Neptus GUI. This can be done from a new terminal by running
```bash
cd path-to-neptus
./neptus.sh
```
Then, open any Neptus console

Navigate back to the example and execute it. Specify the port number at wich your instance of lauv-xplore-1 listens to UDP messages, by default 6002. This creates an IMC message plan database containing a single example maneuver of type bottomUpSearch, and sends it to the specified port. 

```bash
cd path-to-project_TTK22/build
./example 6002
```
The plan is sent to the lauv-xplore-1, and can be started from the Neptus console.

In the Neptus console. Select the lauv-xplore-1, right click the plan view panel at click **Reload Panel**, then right klick the plan **test_plan** and select **Get test_plan from lauv-xplore-1**. This is to bypass the fact that Neptus does not currently know of the IMC::Message for bottomUpSearch. The plan should now appear as red, meaning the plan as seen by Neptus differs from the version on the lauv-xplore-1. Execute the plan by clicking **Start Plan** (green, runny man). If a dialogue box pops up warning about the plan not being syncronized. Hit **Yes**.

The maneuver should now execute, and can be viewed in Neptus.

## Documentation

Source and documentation for the original LSTS libraries can be found at https://github.com/LSTS and https://www.lsts.pt/docs/

Documentation specific to this project includes the IMC message bottomUpSearch and its implementation in DUNE. The IMC documentation are available in the project wiki.

The Maneuver Documentation and its relation to the rest of the DUNE library can be obtained by

```bash
git clone https://github.com/ivanhkingman/maneuver-documentation
```
Open any of the HTML files using an internet browser.
