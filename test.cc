#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "rapidcsv.hh"
#include "timer.hh"

using namespace std;
using namespace rapidcsv;

Document readingTime(const string& filename ) {
  Timer timer;
  timer.Start();
  Document doc(filename);
  timer.Stop();
  cout << "Reading time: " << timer.GetLastDurationSec() << " s" << endl;
  return doc;
}

class Node {
public:
  Node(int id, int pclass, string name, int survived)
      : id(id), pclass(pclass), name(name), survived(survived) {}

  int id;
  int pclass;
  string name;
  int survived;
};

int main() {
  Document doc = readingTime("train.csv");
  vector<int> PassengerId = doc.GetColumn<int>("PassengerId");
  vector<int> Survived = doc.GetColumn<int>("Survived");
  vector<int> Pclass = doc.GetColumn<int>("Pclass");
  vector<string> Name = doc.GetColumn<string>("Name");

  cout << "Read " << PassengerId.size() << " values." << endl;
  cout << "Read " << Survived.size() << " values." << endl;
}
