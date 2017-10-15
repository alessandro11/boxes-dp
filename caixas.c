/*
 * =====================================================================================
 *
 *       Filename:  caixas.c
 *
 *    Description:  Empilhando caixas de forma a maximizar a altura da pilha.
 *
 *        Version:  1.0
 *        Created:  11/10/17 16:25:38
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Alessandro Elias (POS), ae11@c3sl.ufpr.br
 *        Company:  C3SL
 *
 * =====================================================================================
 */

#include <stdio.h>

#define MAX_DIM 3
#define MAX_BOX 1000000
#define NO_PARENT -1

#define Si(i) scanf("%d", &i)

typedef struct box {
  int d[MAX_DIM];
  int original_position;
} box;

void merge_sort_ints(int *a, int n) {
  int i, j, k;
  int m = n / 2;
  int tmp[n];
  if(n <= 1)
    return;
  merge_sort_ints(a, m);
  merge_sort_ints(a + m, n - m);
  for(k = i = 0, j = m; k < n; k++)
    if(i < m && j < n)
      if(a[i] <= a[j])
	tmp[k] = a[i++];
      else
	tmp[k] = a[j++];
    else if(i < m)
      tmp[k] = a[i++];
    else
      tmp[k] = a[j++];
  for(i = 0; i < n; i++)
    a[i] = tmp[i];
}

int le_box(box a, box b, int d) {
  int i;
  for(i = 0; i < d; i++) {
    if(a.d[i] < b.d[i])
      return 1;
    else if(a.d[i] > b.d[i])
      return 0;
  }
  return 1;
}

void copy_box(box *to, box *from, int d) {
  int i = 0;
  to->original_position = from->original_position;
  for(i = 0; i < d; i++)
    to->d[i] = from->d[i];
}

void merge_sort_boxes(box *a, int n, int d) {
  int i, j, k;
  int m = n / 2;
  box tmp[n];
  if(n <= 1)
    return;
  merge_sort_boxes(a, m, d);
  merge_sort_boxes(a + m, n - m, d);
  for(k = i = 0, j = m; k < n; k++)
    if(i < m && j < n)
      if(le_box(a[i], a[j], d))
	copy_box(tmp + k , a + i++, d);
      else
	copy_box(tmp + k, a + j++, d);
    else if(i < m)
      copy_box(tmp + k , a + i++, d);
    else
      copy_box(tmp + k, a + j++, d);
  for(i = 0; i < n; i++)
    copy_box(a + i, tmp + i, d);
}

int box_fits(box *_this, box *into_this, int d) {
  int i;

  for(i = 0; i < d; i++)
    if(_this->d[i] >= into_this->d[i])
      return 0;
  return 1;
}

int main() {
  int n, d=3, i, j;
  static box box[MAX_BOX];
  static int longest_here_parent[MAX_BOX];
  static int longest_here_length[MAX_BOX];
  static int longest_last;
  static int longest_length;
  static int longest[MAX_BOX];

  i = 0;
  while(Si(n) != EOF) {
    /* Read input. */
    box[i].original_position = i + 1;
    box[i].d[0] = n;
    Si(box[i].d[1]);
    Si(box[i].d[2]);
    i++;
  }
  n = i;

  /* For each box, sort dimensions. */
  for(i = 0; i < n; i++)
    merge_sort_ints(box[i].d, d); /* ..................... SORT_DIMS */

  /* Sort boxes lexicographically. */
  merge_sort_boxes(box, n, d); /* ........................ SORT_BOXES */

  /* For each position, compute one longest increasing subsequence
     that ends in the position. */
  for(i = 0; i < n; i++) {
    longest_here_parent[i] = NO_PARENT;
    longest_here_length[i] = 1;
  }
  for(i = 0; i < n; i++)
    for(j = 0; j < i; j++)
      if(box_fits(box + j, box + i, d) &&
         longest_here_length[i] < longest_here_length[j] + 1) {
        longest_here_parent[i] = j;
        longest_here_length[i] = longest_here_length[j] + 1;
      }

  /* Compute the longest increasing subsequence. */
  longest_last = 0;
  longest_length = 1;
  for(i = 1; i < n; i++)
    if(longest_length < longest_here_length[i]) {
      longest_last = i;
      longest_length = longest_here_length[i];
    }
  i = longest_last;
  j = longest_length - 1;
  for( ; longest_here_length[i] != 1; j--) {
    longest[j] = i;
    i = longest_here_parent[i];
  }
  longest[j] = i;

  /* Output longest increasing subsequence. */
  for(i = 0; i < longest_length; i++)
    printf("%d\n", box[longest[i]].original_position);

  return 0;
}


/*
  https://en.wikipedia.org/wiki/Longest_increasing_subsequence
  http://www.geeksforgeeks.org/longest-increasing-subsequence/
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  return 0;
}
*/
