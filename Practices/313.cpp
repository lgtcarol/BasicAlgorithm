int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int arr[100000] = {1};
    int* p = malloc(sizeof(int)*primesSize);
    
    for (int i = 0; i < primesSize; i++) 
        p[i] = 0;
    for (int i = 1; i < n; i++) {
        int min = INT_MAX;
        
        for (int j = 0; j < primesSize; j++) {
            if (primes[j]*arr[p[j]] < min)
                min = primes[j]*arr[p[j]];
        }
        
        arr[i] = min;
        
        for (int j = 0; j < primesSize; j++) {
            if (primes[j]*arr[p[j]] == min)
                p[j]++;
        }
    }
    
    return arr[n-1];
}
