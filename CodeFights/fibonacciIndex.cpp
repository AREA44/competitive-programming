int fibonacciIndex(int N) {
    int f[100000],p[11];
    f[0]=0;f[1]=1;
    for(int i=2;i<=100000;i++)
        f[i]=f[i-1]+f[i-2];
    p[0]=1;
    for(int i=1;i<=10;i++)
        p[i]=p[i-1]*10;
    for(int i=1;i<=100000;i++)
        if(f[i]>=p[N-1])
            return i;
}
