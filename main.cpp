#include<bits/stdc++.h>
using namespace std;

int main() {
    long long number_of_floors, time_total = 0;
    int lift_place;
    vector<int> callings_total;
    map<int, int>statistic;
    int time_of_sim;
    cout << "*****Elevator Simulator*****" << endl << endl << endl;
    cout << "Input the number of floors: ";
    cin >> number_of_floors;
    cout << "Input simulation time duration: ";
    cin >> time_of_sim; cout << '\n';
    cout << "Time between floors (in seconds): ";
    int interval;
    cin >> interval;
    cout << "Simulating passengers calls..." << '\n';

    lift_place = number_of_floors;
    srand(time(NULL));
    for (int i = 0; i < time_of_sim; i++) {
        callings_total.push_back(1 + (rand() % number_of_floors));
    }

    for (auto e : callings_total) {
        statistic[e]++;
        cout << "Passenger calls from floor: " << e << "\n";
    }
    cout << endl;
    map<int, int>::iterator it;

    for (int i = 0; i < callings_total.size(); i++) {
        time_total += abs(lift_place - callings_total[i]) * interval;
        lift_place = callings_total[i];
    }

    cout << "Simulation completed." << "\n" << "Analyses..." << '\n';
    cout << "Total calls: " << callings_total.size() << '\n';
    if (time_total / 60 != 0) {
        cout << "Total time needed for all calls: " << time_total / 60 << " minutes" << '\n';
    }
    else {
        cout << "Total time needed for all calls: " << time_total << " seconds" << '\n';
    }
    cout << "Frequency of calls from each floor: " << endl;

    for (it = statistic.begin(); it != statistic.end(); it++) {
        cout << "Floor " << it->first << ": " << it->second << " calls" << '\n';
    }
    cout << "****************************" << endl;
    return 0;
}
