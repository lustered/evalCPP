/* **************************************** */
/* obsolete testing file */
/* **************************************** */

/* this is working properly */
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> build_table(int gate, int p, int q);
int logic_gate(int gate, int a, int b);

int main() {
  /* values to pass */
  int gate = 1;
  int p = 0;
  int q = 1;
  vector<vector<int>> truth_tab =
      build_table(gate, p, q); // gate, P, Q || 0 for not, 1 for T eg. not p = 0

  cout << "gate value: " << gate << "\tP value: " << p << "\tQ value: " << q
       << endl
       << endl;

  cout << "P \tQ \tP0Q" << endl;

  for (int y = 0; y < 4; y++) {
    cout << truth_tab[0][y] << "\t" << truth_tab[1][y] << "\t"
         << truth_tab[2][y] << endl;
  }

  return 0;
}

int logic_gate(int gate, int a, int b) {
  int ret = 0;
  switch (gate) {
  /* and */
  case 1:
    if (a == b) {
      ret = a;
    }
    break;
  /* or */
  case 2:
    if (a == 1 || b == 1) {
      ret = 1;
    }
    break;
  }

  return ret;
}
/* this will build p, q and filter through gate */
vector<vector<int>> build_table(int gate, int p, int q) {
  /* default truth table hard coded */
  vector<vector<int>> default_table{{1, 1, 0, 0},  // p
                                    {1, 0, 1, 0},  // q
                                    {0, 0, 0, 0}}; // comparison with gate
  vector<vector<int>> ret = default_table;

  for (int x = 0; x < 4; x++) {
    if (p == 0)
      ret[0][x] = 1 - ret[0][x];

    if (q == 0)
      ret[1][x] = 1 - ret[1][x];

    /* adding the result of the current index P and Q to the gated val table */
    ret[2][x] = logic_gate(gate, ret[0][x], ret[1][x]);
  }

  return ret;
}
