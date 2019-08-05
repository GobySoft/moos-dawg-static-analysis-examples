#include "hierarchical_machine.h"

int main()
{
    statechart::Machine machine;
    std::cout << "-- Hit key to Initiate "<< std::endl;
    std::cin.get();
    machine.initiate();
    
    std::cout << "-- Hit key to post TurnOn event" << std::endl;
    std::cin.get();
    machine.process_event(statechart::EvTurnOn());

    std::cout << "-- Hit key to post Deploy event" << std::endl;
    std::cin.get();
    machine.process_event(statechart::EvDeploy());

    std::cout << "-- Hit key to post Return event" << std::endl;
    std::cin.get();
    machine.process_event(statechart::EvReturn());

    std::cout << "-- Hit key to post TurnOff event" << std::endl;
    std::cin.get();
    machine.process_event(statechart::EvTurnOff());

    std::cout << "-- Hit key to Exit" << std::endl;
    std::cin.get();
}
