#define NO_PARENT -1

typedef struct box {
  int d[MAX_DIM];
  int original_position;
} box;

...

int
box_fits(box *this,
box *into_this, int d) {
  int i;
  for(i = 0; i < d; i++)
    if(this->d[i] >= into_this->d[i])
      return 0;
  return 1;
}

...
int main() {
  int n, d=3, i, j;
  static box box[MAX_BOX];
  static int longest_here_parent[MAX_BOX];
  static int longest_here_length[MAX_BOX];
...
  i = 0;
  while(Si(n) != EOF) {
...
    /* For each position, compute one
       longest increasing subsequence
       that ends in the position. */
    for(i = 0; i < n; i++) {
      longest_here_parent[i] = NO_PARENT;
      longest_here_length[i] = 1;
    }
    for(i = 0; i < n; i++)
      for(j = 0; j < i; j++)
  if(box_fits(box + j, box + i, d) &&
     longest_here_length[i] <
     longest_here_length[j] + 1) {
    longest_here_parent[i] = j;
    longest_here_length[i] =
    longest_here_length[j] + 1;
  }

...
