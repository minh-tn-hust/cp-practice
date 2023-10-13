#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <climits>
#include <algorithm>


using namespace std;


void processOnRamp(int &low, int &high, int sensorMin, int sensorMax) {
  low += sensorMin;
  high += sensorMax;
}

void processOffRamp(int &low, int &high, int sensorMin, int sensorMax) {
  low -= sensorMax;
  high -= sensorMin;
  low = max(0, low);
}

void processNone(int &low, int &high, int sensorMin, int sensorMax) {
  low = max(low, sensorMin);
  high = min(high, sensorMax);
}

typedef struct SensorStatus {
  string status;
  int min;
  int max;
  SensorStatus(string status, int min, int max) : status(status), min(min), max(max) {}
} SensorStatus;

const string NONE = "none";
const string ON_RAMP = "on";
const string OFF_RAMP = "off";

void solve() {
  int N;

  cin >> N;


  vector<SensorStatus> sensorsPerMile;

  string status;
  int sensorMin, sensorMax;

  for (int i = 0; i < N; i++) {

    cin >> status >> sensorMin >> sensorMax;
    sensorsPerMile.push_back({status, sensorMin, sensorMax});
  }

  int low = -999999, high = 999999;

  for (int i = N - 1; i >= 0; i--) {
    SensorStatus &sensor = sensorsPerMile[i];
    if (sensor.status == NONE) {
      processNone(low, high, sensor.min, sensor.max);
    } 
    if (sensor.status == OFF_RAMP) {
      processOnRamp(low, high, sensor.min, sensor.max);
    } 
    if (sensor.status == ON_RAMP) {
      processOffRamp(low, high, sensor.min, sensor.max);
    }
  }

  cout << low << " " << high << "\n";



  for (int i = 0; i < N; i++) {
    SensorStatus &sensor = sensorsPerMile[i];

    if (sensor.status == NONE) {
      processNone(low, high, sensor.min, sensor.max);
    }

    if (sensor.status == ON_RAMP) {
      processOnRamp(low, high, sensor.min, sensor.max);
    }

    if (sensor.status == OFF_RAMP) {
      processOffRamp(low, high, sensor.min, sensor.max);
    }
  }

  cout << low << " " << high << "\n";

  
}

int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "traffic";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

