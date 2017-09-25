/*
 * =====================================================================================
 *
 *       Filename:  subconjuntos.c
 *
 *    Description:  Enumerate the subsequent set from {s1, s2, ... , sk} among the set
 *                  of size k from the set {1 .. n}
 *
 *        Version:  1.0
 *        Created:  05/09/17 16:25:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alessandro Elias (POS), ae11@c3sl.ufpr.br
 *        Company:  C3SL
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VINT;

VINT set;
VINT s;
VINT combinations;

void print(const VINT& v) {
  unsigned int i;
  static bool found = false;

  if( found ) {
    for( i = 0; i < v.size(); ++i )
      cout << v[i] << " ";
    cout << endl;
  }
  found = (v == s);
}

void generate(int offset, int k) {
  if (k == 0) {
    print(combinations);
    return;
  }

  for( unsigned int i = offset; i <= set.size() - k; ++i ) {
    combinations.push_back(set[i]);
    generate(i+1, k-1);
    combinations.pop_back();
  }
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]), k = atoi(argv[2]);

  for( int i = 0; i < n; ++i )
    set.push_back(i+1);
  for( int i = 3; i <= k+2; i++ )
    s.push_back(atoi(argv[i]));

  generate(0, k);

  return 0;
}
