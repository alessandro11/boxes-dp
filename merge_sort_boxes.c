void 
merge_sort_boxes(box *a, int n, int d){
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

