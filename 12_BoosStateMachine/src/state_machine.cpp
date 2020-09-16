#include <iostream>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/statechart/custom_reaction.hpp>

using namespace std;
namespace sc = boost::statechart;
// events
struct wp_received : sc::event<wp_received>
{
};
struct wp_reached : sc::event<wp_reached>
{
};
struct wait : sc::event<wait>
{
};
// states
struct takeoff_state;
struct hover_state;
struct wait_state;
struct land_state;

struct mission_phase_SM : sc::state_machine<mission_phase_SM, land_state>
{
};

struct land_state : sc ::simple_state<land_state, mission_phase_SM>
{
  land_state()
  {
    cout << "LAND state" << endl;
  }
  typedef sc::transition<wp_received, takeoff_state> reactions;
};

struct takeoff_state : sc ::simple_state<takeoff_state, mission_phase_SM>
{
  takeoff_state()
  {
    cout << "TAKEOFF state" << endl;
  }
  typedef sc::transition<wp_reached, hover_state> reactions;
};

struct hover_state : sc ::simple_state<hover_state, mission_phase_SM>
{
  hover_state()
  {
    cout << "HOVER state" << endl;
    typedef sc::transition<wait, land_state> reactions;
  }
};

int main()
{
  mission_phase_SM missionPhaseSM;

  missionPhaseSM.initiate();
  missionPhaseSM.process_event(wp_received());
  missionPhaseSM.process_event(wp_reached());
  missionPhaseSM.process_event(wait());

  // cout << "ciaone  " << endl;

  return (0);
}
