#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int arr[105];
int one[550];
int zero[550];
void output(int ans[])
{
int end = 550;
end --;
}
while (end >= 0) {
printf(%d,ans[end --]);
}
puts();
}

void mul(int ans[], int a[], int b)
{
for (int i = 0; i < 550; ++ i) {
ans[i] = a[i]*b;
}
for (int i = 0; i < 550; ++ i) {
if (ans[i] > 9 || ans[i] < -9) {
ans[i+1] += ans[i]/10;
ans[i]   %= 10;
}
}
}

int bigger(int a[], int b[])
{
for (int i = 550; i >= 0; -- i) {
if (a[i] != b[i]) {
return a[i] > b[i];
}
}
return 0;
}

int find_max(int (&max)[101][555], int (&min)[101][555], int count){
  // Variables to store maximum and minimum
    // product till ith index.

    int maxproduct[550];memset(maxproduct, 0, 550);
    mul(min[0], one, arr[0]);
    mul(max[0], one, arr[0]);
    for (int i = 1; i < count; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0){
          for(int j = 0; j < 550; j++){
            swap(max[i-1][j], min[i-1][j]);
          }
        }
            //swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        mul(max[i], max[i-1], arr[i]);
        mul(min[i], min[i-1], arr[i]);

        int arr_i[550];
        mul(arr_i, one, arr[i]);

        // now compare
        if(bigger(arr_i, max[i])){
          mul(max[i], one, arr[i]);
        }

        if(bigger(min[i], arr_i)){
          mul(min[i], one, arr[i]);
        }

        // maxVal = max(arr[i], maxVal * arr[i]);
        // minVal = min(arr[i], minVal * arr[i]);

        // Max Product of array.
        if(bigger(max[i], maxproduct)){
          mul(maxproduct, max[i], 1);
        }
      //  maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    output(maxproduct);

}

int main(){
  int data[10000];
  memset(one, 0, 550);one[0] = 1;
  memset(zero, 0, 550);
  int max[101][550];
  int min[101][550];
  memset(max, 0, sizeof(max)); memset(min,0, 550);
  int num;
  while(scanf(%d, &num) == 1){
    arr[0] = num;
    int count = 1;
    while(scanf(%d, &num) && num != -999999){
      arr[count] = num; count++;
    }

    find_max(max, min, count));
  }
  return 0;
}
