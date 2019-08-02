#include "minimal_machine.h"

int main()
{
    statechart::Machine machine;
    std::cout << "-- Hit key to Initiate "<< std::endl;
    std::cin.get();
    machine.initiate();
    
    // turn on
    std::cout << "-- Hit key to post TurnOn event" << std::endl;
    std::cin.get();
    machine.process_event(statechart::EvTurnOn());
    // turn on again is ignored 
    std::cout << "-- Hit key to post TurnOn event" << std::endl;
    std::cin.get();
    machine.process_event(statechart::EvTurnOn());
    // turn off
    std::cout << "-- Hit key to post TurnOff event" << std::endl;
    std::cin.get();
    machine.process_event(statechart::EvTurnOff());

    std::cout << "-- Hit key to Exit" << std::endl;
    std::cin.get();
}
