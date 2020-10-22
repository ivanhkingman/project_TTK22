# Integrating new DUNE maneuver "Bottom Up Search" in LSTS software toolchain

# Description
This project integrates a new maneuver in the existing LSTS software toolchain. The maneuver "Bottom Up Search" steers an AUV from a specified depth towards the surface, while maintaining low speed and high pitch. The project is part of the course TTK22 at NTNU and includes integration of the new maneuver, definition of a corresponding IMC message and synchronization of the new message with DUNE and NEPTUS.

# Installation

## Prerequisites

git, cmake, g++


## DUNE

Clone the LSTS/Dune forked repository

```bash
git clone https://github.com/ivanhkingman/dune
```

## IMC

Clone the LTS/IMC forked repository

```bash
git clone https://github.com/ivanhkingman/imc
```

## IMCJAVA

Clone the LSTS/IMCjava forked repository

```bash
git clone https://github.com/ivanhkingman/imc
```
Compile

## NEPTUS

Clone the LSTS/neptus forked repository

```bash
git clone https://github.com/ivanhkingman/imc
```
Compile

Verify

# Usage

For a minimum working example, clone the example from this repository

```bash
git clone https://github.com/ivanhkingman/imc
```

Buil the project by doing the following

```bash
mkdir build
cd build
cmake ..
make
```
Execute the example by running

```bash
./example
```
The maneuver should now be executed and can be viewed in the Neptus console

