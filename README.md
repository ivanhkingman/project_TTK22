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

Before compiling Neptus, however, we need to synchronize with IMC

### Synchronize IMC with Neptus

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

Compile neptus

```bash
cd path_to_neptus
ant
```

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

Navigate back to the example and execute it by sending a goto message as part of a plan on port 6001 (the port at which Neptus recieves UDP-messages)

```bash
cd path-to-project_TTK22/build
./example 2 bottomUpSearch 6001
```

To test with goto maneuver, do:

```bash
cd path-to-project_TTK22/build
./example 2 goto 6001
```

This sends the plan to the Neptus. If the plan does not appear, right click the plan view panel at click **Reload Panel**. Forward the plan to lauv-xplore-1 by selecting the vehicle, then selecting the plan, then clicking **Send Selected Plan** (blue arrow). Execute the plan by clicking **Start Plan** (green, runny man).

Note: Not working at the moment, as vehicle goes into teleoperation mode :(

## Documentation

Source and documentation for the original LSTS libraries can be found at https://github.com/LSTS and https://www.lsts.pt/docs/

Documentation specific to this project includes the IMC message bottomUpSearch and its implementation in DUNE. Both are available in the project wiki, or can be generated from the IMC or Dune forked repositories.

To generate IMC message documentation for IMC::BottomUpSearch

