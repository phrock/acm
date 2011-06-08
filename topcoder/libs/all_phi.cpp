vector<int> all_phi(int n)
{
    vector<int> phi(n+1);
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
	if (!phi[i]) {          // phi[i] is prime
	    for (int j = i; j <= n; j += i) {
		if (!phi[j]) phi[j] = j;
		phi[j] = phi[j] / i * (i - 1);
	    }
	}
    }
    return phi;
}
