#pragma once

#include <boost/mpl/list.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/transition.hpp>

#include <goby/middleware/transport/interprocess.h>

#include "messages/groups.h"
#include "messages/state.pb.h"

namespace statechart
{
using boost::statechart::event;
using boost::statechart::state;
using boost::statechart::state_machine;

// events
struct EvTurnOn : event<EvTurnOn>
{
};
struct EvTurnOff : event<EvTurnOff>
{
};

template <class App> struct Machine;
template <class App> struct On;
template <class App> struct Off;

// machine
template <class App> struct Machine : state_machine<Machine<App>, Off<App>>
{
  public:
    Machine(App& app) : app_(app) {}
    App& app() { return app_; }

  private:
    App& app_;
};

// gives shorthand access to "interprocess()" to allow states to publish directly
template <typename Derived> struct AppAccess
{
    goby::zeromq::InterProcessPortal<>& interprocess()
    {
        return static_cast<Derived*>(this)->outermost_context().app().interprocess();
    }
};

// states
template <class App> using OnBase = state<On<App>, Machine<App>>;
template <class App> struct On : OnBase<App>, AppAccess<On<App>>
{
    // state enter
    On(typename OnBase<App>::my_context c) : OnBase<App>(c)
    {
        protobuf::StateReport report;
        report.set_current_state(protobuf::ON);
        this->interprocess().template publish<groups::state_report>(report);

        std::cout << "Entering state: ON" << std::endl;
    }
    // state exit
    ~On() { std::cout << "Leaving state: ON" << std::endl; }

    // state reactions
    typedef boost::mpl::list<boost::statechart::transition<EvTurnOff, Off<App>>> reactions;
};

template <class App> using OffBase = state<Off<App>, Machine<App>>;
template <class App> struct Off : OffBase<App>, AppAccess<Off<App>>
{
    Off(typename OffBase<App>::my_context c) : OffBase<App>(c)
    {
        protobuf::StateReport report;
        report.set_current_state(protobuf::OFF);
        this->interprocess().template publish<groups::state_report>(report);

        std::cout << "Entering state: OFF" << std::endl;
    }
    ~Off() { std::cout << "Leaving state: OFF" << std::endl; }

    typedef boost::mpl::list<boost::statechart::transition<EvTurnOn, On<App>>> reactions;
};
} // namespace statechart
