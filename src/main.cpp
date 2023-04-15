#include<stdio.h>
#define N 5009
#define mod 1000000007
inline char nc() {
    static char buf[99999],*l,*r;
    return l==r&&(r=(l=buf)+fread(buf,1,99999,stdin),l==r)?EOF:*l++;
}
inline void read(int&x) {
    char c=nc();for(;c<'0'||'9'<c;c=nc());
    for(x=0;'0'<=c&&c<='9';x=(x<<3)+(x<<1)+(c^48),c=nc());
}

int t,n,m,a[N],f[N][N];bool g[N][N];
struct __readt__{inline __readt__(){read(t);}}_readt___;

int main() {
    read(n);read(m);
    for(int i=1;i<=n;read(a[i]),--a[i++]);
    for(int i=0;i<n;++i)
    for(int j=0;j<=n;g[i][j]=0,f[i][j++]=0);
    f[0][0]=1;g[0][0]=1;
    for(int i=1;i<=n;++i)for(int j=i,x;j;--j) {
        if(j%m==1)
            x=f[0][j-1];
        else
            x=f[a[i]][j-1];
        if(!(j%m))
            f[0][j]+=x-mod,f[0][j]>>31&&(f[0][j]+=mod);
        else
            f[a[i]][j]+=x-mod,f[a[i]][j]>>31&&(f[a[i]][j]+=mod);
        if(j%m==1)
            x=g[0][j-1];
        else
            x=g[a[i]][j-1];
        if(!(j%m))
            g[0][j]|=x;
        else
            g[a[i]][j]|=x;
    }
    for(int i=n/m*m;;i-=m)
        if(g[0][i]) {
            printf("%d\n",f[0][i]);
            break;
        }
    if(--t)main();
}
