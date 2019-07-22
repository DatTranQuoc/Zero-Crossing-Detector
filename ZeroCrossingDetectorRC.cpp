/*This code is used to calculate Resistor values and Capacitor values in the Zero-crossing Detector,
topology:
Vin-R-C-Opto-C-R-Vin 
*/
#include <iostream>
#include <string>


int Rmin = 10; // resistor value minimum
int Rmax = 100000; // resistor value maximum
// Capacitor values
float C[25] = {0.001, 0.0015, 0.0022, 0.0033, 0.0047, 0.0068, 0.01, 0.015, 0,022, 0.033, 0.047, 0.068, 0.1, 0.15, 0.22, 0.33, 0.47, 0.68, 1.0, 1.5, 2.2, 3.3, 4.7, 6.8};
float voltageMax = 150.0; //Voltage rating of Capacitor, this is the voltage capacitor able to alive
float currentMin = 0.005; // Minimum current pass through the circuit
float currentMax = 0.05; // Maximum current pass through the circuit
float powerRate = 0.15; // Power rating of Resistor, this is the power resistor able to alive
float inputVoltage = 320.0; // Vin

//This function is used to calculate current pass through the circuit
// Input: Resistor, capacitor values, input voltage
// Output: current value in float type
//
float current(int R, float C){
    return (inputVoltage/(2*(1/(2*3.14*50*C*0.000001)) + 2*R));
}

//This function is used to calculate current pass through the circuit
// Input: Resistor value, current value
// Output: power rating on a resistor
//
float powerR(int R, float current) {
    return (R*(current*current));
}

//This function is used to calculate voltage drop on a capacitor
// Input: input voltage, current 
// Output: voltage drop on a capcitor
float voltageC(int R, float current) {
    return ((inputVoltage-(2*R*current))/2);
}

int main()
{
    for (int i=Rmin; i<=Rmax; i=i+10 ){
        for (int j=0; j<19; j++){
            if ((current(i, C[j]) > currentMin) && (current(i, C[j]) < currentMax)) {
                if (powerR(i, current(i, C[j])) < powerRate) {
                    if (voltageC(i, current(i, C[j])) < voltageMax){
                        std::cout <<"R = "<<i;
                        std::cout <<"\n";
                        std::cout <<"Power on R = "<<powerR(i, current(i, C[j]));
                        std::cout <<"\n";
                        std::cout <<"C = "<<C[j];
                        std::cout <<"\n";   
                        std::cout <<"Voltage on C = "<<voltageC(i, current(i, C[j]));
                        std::cout <<"\n\n";
                    }
                }
            }
        }
    }
}