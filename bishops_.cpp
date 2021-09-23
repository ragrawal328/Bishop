#include <bits/stdc++.h>
using namespace std;
#define int long long
int bishop()
{
    int n;
    double c, b, phi, rho;
    cin >> c >> n >> b >> phi >> rho;
//cohesion ,no. of slices,width of slice,i angle of internal
//friction,density
    double a[n], w[n], h[n], u[n], m[n];
//alpha[i],weight[i],height[i],pore pressure[i],m_alpha[i]..
//cin the input;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> u[i];
    }
//calculate all w[i}
    for (int i = 0; i < n; i++)
    {
        w[i] = rho * h[i] * b;
    }
    double fs, numerator = 0, denominator = 0, ans = INT_MAX;
    for (double j = 0.01; j < 10; j += 0.01)
    {
        for (int i = 0; i < n; i++)
        {
            m[i] = cos(a[i]) + ((tan(phi) * sin(a[i])) / j);
            numerator += (c * b / cos(a[i]) + (w[i] - u[i] * b / cos(a[i])) * tan(phi)) /
                         m[i];
            denominator += w[i] * sin(a[i]);
        }
        fs = numerator / denominator;
        if (abs(fs - j) / fs <= 0.01)
        {
            ans = fs;
            break;
        }
    }
    cout << ans;
    return 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    bishop();
    return 0;
}
