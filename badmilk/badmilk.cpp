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

typedef struct TimeDrink {
  int person, milk;

  TimeDrink(int person, int milk) : person(person), milk(milk) {}

} TimeDrink;

typedef struct SickPerson {
  int person, time;

  SickPerson(int person, int time) : person(person), time(time) {};

} SickPerson;

vector<int> getListBadMilk(vector<vector<TimeDrink>> &timeline, vector<SickPerson> sickPeople, int numMilk, int numPerson) {
  vector<unordered_set<int>> sickPeopleDrinkMilk(numMilk + 1);
  vector<int> listBadMilk;

  int maximumPersonDrink = 0;
  for (auto sickPerson : sickPeople) {
    int sickTime = sickPerson.time;
    int personWhoSick = sickPerson.person;

    for (int time = sickTime - 1; time >= 1; time--) {
      for (auto drink : timeline[time]) {
        int person = drink.person;
        if (person == personWhoSick) {
          int milk = drink.milk;
          sickPeopleDrinkMilk[milk].insert(person);
          if (maximumPersonDrink < sickPeopleDrinkMilk[milk].size()) {
              maximumPersonDrink = sickPeopleDrinkMilk[milk].size();
          }
        }
      }
    }
  }

  for (int milk = 1; milk <= numMilk; milk++) {
    if (sickPeopleDrinkMilk[milk].size() == maximumPersonDrink) {
      listBadMilk.push_back(milk);
    }
  }
  return listBadMilk;
}

vector<int> getNumPersonDrinkPerMilk(vector<vector<TimeDrink>> &timeline, int numMilk) {
  vector<unordered_set<int>> numPersonDrinkMilk(numMilk + 1);
  vector<int> numPersonDrinkPerMilk(numMilk + 1);

  for (auto drinks : timeline) {
    for (auto drink : drinks) {
      int milk = drink.milk;
      int person = drink.person;
      numPersonDrinkMilk[milk].insert(person);
    }
  }

  for (int milk = 1; milk <= numMilk; milk++) {
    numPersonDrinkPerMilk[milk] = numPersonDrinkMilk[milk].size();
  }

  return numPersonDrinkPerMilk;
}


void solve() {
  int numPerson, numMilk, numDrinkTimeline, numSickPerson;
  cin >> numPerson >> numMilk >> numDrinkTimeline >> numSickPerson;

  int p, m, t;
  vector<vector<TimeDrink>> timeline(101);
  vector<SickPerson> sickPersons;

  for (int i = 0; i < numDrinkTimeline; i++) {
    cin >> p >> m >> t;
    timeline[t].push_back({p, m});
  }

  for (int i = 0; i < numSickPerson; i++) {
    cin >> p >> t;
    sickPersons.push_back({p, t});
  }

  vector<int> personsDrinkPerMilk = getNumPersonDrinkPerMilk(timeline, numMilk);
  vector<int> listBadMilk = getListBadMilk(timeline, sickPersons, numMilk, numPerson);

  int maximumMedicine = 0;
  for (auto milk : listBadMilk) {
    maximumMedicine = max(personsDrinkPerMilk[milk], maximumMedicine);
  }

  cout << maximumMedicine;
}


int main() {

#ifndef ONLINE_JUDGE
  string FILE_NAME = "badmilk";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();
}

