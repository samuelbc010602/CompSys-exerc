#include <stdio.h>
#include <math.h>


int partition1(int *array, int p, int r) {
    int pivot = array[p];
    printf("pivot %d \n",pivot);
    int i=p-1;
    int j=r;
    while (1) {
        do { j--; printf("j--  %d \n",array[j]);} while (pivot < array[j]);
        do { i++; printf("i++  %d \n",array[i]);} while (array[i] < pivot);
        if (i < j) {
            printf("%d %d switch %d %d \n",i,j,array[i],array[j]);
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        } else {
            return j+1;
        }
    }
}

int partition2(int *array, int p, int r) {
/*for(int i = 0;i<r;i++){
    printf("%d \n",array[i]);
}*/
int pivot = array[p];
int i=p-1;
int j=r;
while (1) {
do { j--; } while (pivot < array[j]);
do { i++; } while (array[i] < pivot);
if (i < j) {
int tmp = array[i];
array[i] = array[j];
array[j] = tmp;
} else {
return j+1;
}
}
}


int main(){
    int arr[] = {5,1,1,6,6};
    int ret = partition1(arr,0,5);
    printf("%d ",ret);
    return 0;
}
