        #include <stdio.h>
        #include <stdlib.h>

int max(int a, int b) { return (a > b)? a : b; }

int** knapsack(int W, int wt[], int val[], int n)
{
 int i, w;
 int** K = (int **)malloc((n+1) * sizeof(int*));
 for (i = 0; i <= n; i++)
 {
   K[i]=(int *)malloc((W+1) * sizeof(int));
   for (w = 0; w <= W; w++)
   {
     if (i==0 || w==0)
       K[i][w] = 0;
     else if (wt[i-1] <= w)
       K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
     else
       K[i][w] = K[i-1][w];
   }
 }


 return K;
}


int maxValue(int myArray[], size_t size) {
  size_t i;
  int maxValue = myArray[0];

  for (i = 1; i < size; ++i) {
    if ( myArray[i] > maxValue ) {
      maxValue = myArray[i];
    }
  }
  return maxValue;
}


int** knapsackUnlimit(int W, int wt[], int val[], int n)
{
 int i, w;
 int** K = (int **)malloc((n+1) * sizeof(int*));

           // Build table K[][] in bottom up manner
 for (i = 0; i <= n; i++)
 {
   K[i]=(int *)malloc((W+1) * sizeof(int));
   for (w = 0; w <= W; w++)
   {
     if (i==0 || w==0)
       K[i][w] = 0;
     else if (wt[i-1] <= w){
      int p;
      int kk=w/wt[i-1];
      int* candidate=(int*) malloc(kk* sizeof(int));
      for(p=1;p<=kk;p++){
        candidate[p] = max(p*val[i-1] + K[i][w-p*(wt[i-1])],  K[i-1][w]);
      }
      K[i][w]=maxValue(candidate,p);
    }
    else
     K[i][w] = K[i-1][w];

 }
}


return K;
}

int** knapsackQt(int W, int wt[], int val[], int qt[], int n)
{
 int i, w;
 int** K = (int **)malloc((n+1) * sizeof(int*));

           // Build table K[][] in bottom up manner
 for (i = 0; i <= n; i++)
 {
   K[i]=(int *)malloc((W+1) * sizeof(int));
   for (w = 0; w <= W; w++)
   {
     if (i==0 || w==0)
       K[i][w] = 0;
     else if (wt[i-1] <= w){
      int p;
      int kk=w/wt[i-1];
      int* candidate=(int*) malloc(kk* sizeof(int));
      for(p=1;p<=kk;p++){
        if(p<=qt[i-1])
          candidate[p] = max(p*val[i-1] + K[i-1][w-p*(wt[i-1])],  K[i-1][w]);
      }
      K[i][w]=maxValue(candidate,p);
    }
    else
     K[i][w] = K[i-1][w];

 }
}
return K;
}


int  invertMatrix(int** matrix,int row, int col){
  int i,j;
  for(j=0;j<col; j++){
    for(i=0;i<row;i++){
      printf("%d ",matrix[i][j]);
    }
    printf("\n");
  }
  return 0;



}

int main(void){
  int i,W,n,option;
  printf("select the knapsack modality typing: 1 for knapsack01, 2 for knapsackQt, 3 for knapsackUnlimited ");
  scanf("%d", &option);
  printf("Please input the sack capacity: ");
  scanf("%d", &W);
  printf("Please input the number of items: ");
  scanf("%d", &n);
  int val[n];
  int wt[n];
  int qt[n];
  for(i=0;i<n;i++){
    int currP,currW;
    if(option==2){
      int currQ;
      printf("Please input the Value, the Weigth, the Quantity of the item #%d: ",(i+1));
      scanf( "%i %i %i", &currP, &currW,&currQ);
      qt[i]=currQ;
    }
    else{
      printf("Please input the Value and the Weigth of the item #%d: ",(i+1));
      scanf( "%i %i", &currP, &currW);
    }
    val[i]=currP;
    wt[i]=currW;
  }

  printf("the table generated is above: \n");
  switch (option){
    case 1:
    invertMatrix(knapsack(W, wt, val, n),n+1,W+1);
    break;
    case 2:
    invertMatrix(knapsackQt(W, wt, val,qt,n),n+1,W+1);
    break;
    case 3:
    invertMatrix(knapsackUnlimit(W, wt, val, n),n+1,W+1);
    break;

  }

  return 0;
}