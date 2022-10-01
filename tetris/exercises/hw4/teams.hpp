#include <map>
#include <vector>
#include "string"
using namespace std;

map<int, vector<string> > createTeams(int teamSize);
map<string, vector<string> > readFile();
void printToFile(map<int, vector<string> > assignments, int teamSize);