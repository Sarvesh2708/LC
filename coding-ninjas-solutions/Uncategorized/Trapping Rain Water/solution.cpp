long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    int left=0;
    int right=n-1;
    long long lmax =0;
    long long rmax =0;
    long long total =0;

    while(left<right){

        if(arr[left]<=arr[right]){
            if(arr[left]<lmax){
            total+=lmax-arr[left];
        }
        else{
            lmax = arr[left];
        }
        left++;
        }

        else{
            if(rmax>arr[right]){
                
                total+=rmax-arr[right];
                
            }
            else{
                rmax=arr[right];
            }
            right--;
        }
    }
    return total;

}