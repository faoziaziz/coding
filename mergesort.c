#include<stdio.h>
/* Program mengurutkan dengan menggunakan 
 * mergesort */
main()
{
	int data[100], i,j,n,temp;
	/*  INPUT  */
	printf("Give n : ");
	scanf("%d", &n);
	/*jumlah yang di input */
	printf(" n = %d, \n", n);
	for(i=0;i<n;i++)
		scanf("%d", data+i);
	printf("\n Number read are : ");
	for(i=0; i<n;i++)
		printf("%d ", *(data+i));
		printf("\n");
	/* CALL*/
	mergesort(data, 0,n-1);
	/* print result */
	printf("\n Sorted number are : ");
	for(i=0;i<n;i++) printf("%d ", data[i]);
		printf("\n");
}
mergesort(a,i,j)
int a[], i,j;
{
	int  mid;
	if(i>=j) return;
	mid = (i+j)/2;
	mergesort(a,i, mid);
	mergesort(a,mid+1, j);
	merge(a,i,j);
}
merge(a,i,j)
int a[],i,j;

{
	int k, b[100],mid,l,start;
/* INITIAlIZE*/
	start = i;
	mid = (i+j)/2;
	k = mid +1;
	l =i;
/*From array b*/
	while (i<=mid && k<=j)
		if (a[i]>=a[k])
			b[l++]=a[i++];
		else
			b[l++]=a[k++];

	if(i>mid)
		for(;k<=j;) b[l++]=a[k++];
	else
		if (k>j)
		for (;i<=mid;) b[l++]=a[i++];
	/*copy back to aaray*/
	for(l=start;l<=j;l++)
	a[l]=b[l];
}
