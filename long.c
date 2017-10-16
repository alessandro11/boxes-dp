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
...
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

