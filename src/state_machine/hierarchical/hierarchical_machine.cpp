#include "minimal_machine.h"

int main()
{
    statechart::Machine machine;
    std::cout << "-- Initiate "<< std::endl;
    machine.initiate();
    
    sleep(1);
    // turn on
    std::cout << "-- Posting TurnOn event" << std::endl;
    machine.process_event(statechart::EvTurnOn());
    sleep(1);
    // turn on again is ignored 
    std::cout << "-- Posting TurnOn event" << std::endl;
    machine.process_event(statechart::EvTurnOn());
    sleep(1);
    // turn off
    std::cout << "-- Posting TurnOff event" << std::endl;
    machine.process_event(statechart::EvTurnOff());

    sleep(1);
    std::cout << "-- Exit" << std::endl;
}
