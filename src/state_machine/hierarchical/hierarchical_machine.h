#pragma once

#include <iostream>

#include <boost/mpl/list.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/transition.hpp>

namespace statechart
{
using boost::statechart::event;
using boost::statechart::simple_state;
using boost::statechart::state_machine;
using boost::statechart::transition;

// events
struct EvTurnOn : event<EvTurnOn> {};
struct EvTurnOff : event<EvTurnOff> {};

struct On; struct Off;

// machine
struct Machine : state_machine<Machine, Off> {};

// states
struct On : simple_state<On, Machine>
{
    On() { std::cout << "Entering state:\tON" << std::endl; }
    ~On() { std::cout << "Leaving state:\tON" << std::endl; }
    using reactions = transition<EvTurnOff, Off>;
};

struct Off : simple_state<Off, Machine>
{
    Off() { std::cout << "Entering state:\tOFF" << std::endl; }
    ~Off() { std::cout << "Leaving state:\tOFF" << std::endl; }
    using reactions = transition<EvTurnOn, On>;
};
} // namespace statechart
