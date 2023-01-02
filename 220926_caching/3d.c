//You might want to use different values for L,M,N when performing benchmarks. */
#define L 10
#define M 10
#define N 100

long sum_array_3d(long a[L][M][N])
{
  long sum = 0;
  int i, j, k;
  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < L; k++) {
        sum += a[k][i][j];
      }
    }
  }
  return sum;
}

int main(){
    int arr[100][5][3];
    for(int first = 0;first<L;first++){
        for(int second = 0;second < M;second++){
            for(int third = 0;third<N;third++){
                arr[first][second][third] = (first+second)-third;
        }
    }
}
printf("%lu \n",sum_array_3d(arr));
}