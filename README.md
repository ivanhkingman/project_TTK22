# Integrating new DUNE maneuver "Bottom Up Search" in LSTS software toolchain

## Description
This project integrates a new maneuver in the existing LSTS software toolchain. The maneuver "Bottom Up Search" steers an AUV from a specified depth towards the surface, while maintaining low speed and high pitch. The project is part of the course TTK22 at NTNU and includes integration of the new maneuver, definition of a corresponding IMC message and synchronization of the new message with DUNE and NEPTUS.

## Installation

### Prerequisites

git, cmake, g++, ant


### IMC

Clone the LTS/IMC forked repository

```bash
git clone -single-branch --branch bottomUpSearch https://github.com/ivanhkingman/imc
```


### DUNE

Clone the LSTS/Dune forked repository

```bash
git clone -single-branch --branch bottomUpSearch https://github.com/ivanhkingman/dune
```

Create a link to IMC and compile IMC library
```bash
cd dune
mkdir build
cd build
ln -s path_to_imc IMC
make imc
```

Compile DUNE from build folder (may take some time)
```bash
cmake ..
make
```


### IMCJAVA (optional)

Clone the LSTS/IMCjava forked repository

```bash
git clone https://github.com/ivanhkingman/imcjava
```

### NEPTUS

Clone the LSTS/neptus forked repository

```bash
git clone https://github.com/ivanhkingman/neptus
```
Note: If you get the following error message

```bash
error: RPC failed; curl 56 GnuTLS recv error (-24): Decryption has failed.
fatal: The remote end hung up unexpectedly
fatal: early EOF
fatal: index-pack failed
```
try using a different internet connection or a VPN.

Compile Neptus with Ant

```bash
cd neptus
ant
```


## Usage

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

Navigate back to the example and execute it by running

```bash
cd path-to-project_TTK22/build
./example 2 goto 6001
```
The maneuver should now be executed and can be viewed in the Neptus console

## Documentation

Source and documentation for the original LSTS libraries can be found at https://github.com/LSTS and https://www.lsts.pt/docs/

Documentation specific to this project includes the IMC message bottomUpSearch and its implementation in DUNE. Both are available in the project wiki, or can be generated from the IMC or Dune forked repositories.

To generate IMC message documentation for IMC::BottomUpSearch

