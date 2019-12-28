#include <iostream>
using namespace std;
int main ()
{
    const int sit_pl = 20;
    const int stand_pl = 10;
    const int cost = 2;
    int trip, trip50, trip30, trip20, sum_cost, S, S_trip, gas, cost_gas, gas_cons,Cost_g;;

    cout << "Enter number of trips per day: ";
    cin >> trip;
    cout << "Enter distance of one trip: ";
    cin >> S_trip;
    cout << "Enter cost of gas per one trip: ";
    cin >> cost_gas;
    cout << "Enter gas consumption per one trip: ";
    cin >> gas_cons;

    trip50 = (trip*(sit_pl + stand_pl)) * 0.5 * cost;
    trip30 = trip * sit_pl * 0.3 * cost;
    trip20 = trip * (sit_pl / 2) * 0.2 * cost;
    S = trip * S_trip;
    gas = S * gas_cons;
    Cost_g = gas * cost_gas;
    sum_cost = trip50 + trip30 + trip20 - Cost_g;
    cout << "trip50 = " << trip50 << endl;
    cout << "trip30 = " << trip30 << endl;
    cout << "trip20 = " << trip20 << endl;
    cout << "All cost of trips = " << sum_cost << endl;

    return 0;
}
