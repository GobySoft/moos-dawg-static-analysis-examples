#include <iostream>

#include <boost/units/base_units/imperial/yard.hpp>
#include <boost/units/base_units/metric/knot.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/angle/degrees.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/prefixes.hpp>

using namespace boost::units;
using std::cout;
using std::endl;

// uncomment int main() to compile this code normally, otherwise use Cling (https://github.com/root-project/cling)
//int main()
//{

auto speed = 2.5 * si::meters_per_second;
auto dtime = 100 * si::seconds;
auto distance = speed * dtime;
cout << distance << endl;

// explicit construction allows conversions
quantity<decltype(si::kilo * si::meters)> distance_km(distance);
cout << distance_km << endl;

// try to add distance and speed
// auto invalid = distance + speed;

// do some number math
quantity<si::length> range = 100 * si::meters;
quantity<si::plane_angle> bearing(60 * degree::degrees);

auto x_comp = range * cos(bearing);
auto y_comp = range * sin(bearing);
cout << "(x,y) = " << "(" << x_comp << ", " << y_comp << ")" << endl;

// or in yards?
imperial::yard_base_unit::unit_type yards;
cout << "(x,y) = " << "(" << quantity<decltype(yards)>(x_comp) << ", " << quantity<decltype(yards)>(y_comp) << ")" << endl;

//}
