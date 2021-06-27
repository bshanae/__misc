# avaj-launcher

The goal of this project is to implemented small simulation of airport and aircrafts intercation.
We have to follow a UML-diagram.
Here are the most important objects on this diagram :

* Tower - for registering aircrafts and providing weather
* Aircraft - abstract class for aircraft
* Helicopter, JetPlane, Balloon - implementations of Aircraft
* WeatherProvider - a thing for generating weather conditions for given coordinates

When program starts, it read list of aircraft from a scenario file.

## MD5 decryption bonus

There is a bonus in this project : read scenario file, encrypted with MD5 algorithm.
This task is impossible to implement completely, so implemented it partially :
I encrypt not all file, but each individual token. Then, when reading this file, I try to decode aircrafts
descriptions considering these constraints :
1.  First token is a number of program iterations.
    We consider it to be an integer from 0 to an arbitrary big number.
2. Types of aircraft are known : 'Balloon', 'Helicopter' 'JetPlane'.
3. Names of aircraft are build as \[first letter of type\]+\[index\].
   For example, a balloon may have a name 'B1', and a helicopter may have a name 'H12'.
4. Coordinates are also integers from 0 to an arbitrary big number.
