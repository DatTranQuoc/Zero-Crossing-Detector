/*This code is used to calculate Resistor values in the Zero-crossing Detector,
topology:
Vin-R-R-Opto-R-R-Vin 
*/
#include <iostream>
#include <string>


int Rmin = 10; // resistor value minimum
int Rmax = 100000000; // resistor value maximum 10M Ohm

float currentMin = 0.011; // Minimum current pass through the circuit
float currentMax = 0.05; // Maximum current pass through the circuit
float powerRate = 0.5; // Power rating of Resistor, this is the power resistor able to alive
float inputVoltage = 320.0; // Vin
int numberR = 4;

//This function is used to calculate current pass through the circuit
// Input: Resistor values, input voltage
// Output: current value in float type
//
float current(int R){
    return (inputVoltage/(numberR*R));
}

//This function is used to calculate current pass through the circuit
// Input: Resistor value, current value
// Output: power rating on a resistor
//
float powerR(int R, float current) {
    return (R*(current*current));
}

int main()
{
    for (int i=Rmin; i<=Rmax; i=i+10 ) {
        if ((current(i) > currentMin) && (current(i) < currentMax)) {
            if (powerR(i, current(i)) < powerRate) {
                std::cout <<"R = "<<i;
                std::cout <<"\n\n";   
            }
        }
    }
}