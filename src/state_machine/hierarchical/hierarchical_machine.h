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
using std::cout;
using std::endl;


struct On;
namespace on
{
struct Idle;
struct Deploy;
struct Return;
}
struct Off;

struct EvTurnOn : event<EvTurnOn>{};
struct EvTurnOff : event<EvTurnOff>{};
struct EvDeploy : event<EvDeploy>{};
struct EvReturn : event<EvReturn>{};

struct Machine : state_machine<Machine, Off> {};
struct On : simple_state<On, Machine, on::Idle>
{
    On() { cout << "Entering state:\tON" << endl; }
    ~On() { cout << "Leaving state:\tON" << endl; }
    using reactions = transition<EvTurnOff, Off>;
};
namespace on {
struct Idle : simple_state<Idle, On>
{
    Idle() { cout << "Entering state:\tON::IDLE" << endl; }
    ~Idle() { cout << "Leaving state:\tON::IDLE" << endl; }
    using reactions = transition<EvDeploy, Deploy>;
};
struct Deploy : simple_state<Deploy, On>
{
    Deploy() { cout << "Entering state:\tON::DEPLOY" << endl; }
    ~Deploy() { cout << "Leaving state:\tON::DEPLOY" << endl; }
    using reactions = transition<EvReturn, Return>;
};
struct Return : simple_state<Return, On>
{
    Return() { cout << "Entering state:\tON::RETURN" << endl; }
    ~Return() { cout << "Leaving state:\tON::RETURN" << endl; }
};
} // namespace on

struct Off : simple_state<Off, Machine>
{
    Off() { cout << "Entering state:\tOFF" << endl; }
    ~Off() { cout << "Leaving state:\tOFF" << endl; }
    using reactions = transition<EvTurnOn, On>;
};
} // namespace statechart


