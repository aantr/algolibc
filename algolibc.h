#include <math.h>
#include <stdio.h>

long long min(long long a, long long b) {
	if (a < b) return a;
	return b;
}

long long max(long long a, long long b) {
	if (a > b) return a;
	return b;
}

long long nextLong(long long a, long long b, char* name) {
	long long x;
	if (scanf("%lld", &x) < 1) {
		printf("Wrong type or there is no input of variable '%s'\n", name);
		exit(1);
	}
	if (a <= b && (x < a || x > b)) {
		printf("The variable '%s' does not meet the constraints: [%lld, %lld]\n", name, a, b);
		exit(1);
	}
	return x;
}

long double nextDouble(long double a, long double b, char* name) {
	long double x;
	if (scanf("%Lf", &x) < 1) {
		printf("Wrong type or there is no input of variable '%s'\n", name);
		exit(1);
	}
	if (a <= b && (x < a || x > b)) {
		printf("The variable '%s' does not meet the constraints: [%Lf, %Lf]\n", name, a, b);
		exit(1);
	}
	return x;
}

void z_function(int *z, char *s, int n) {
	for (int i = 0; i < n; i++) {
		z[i] = 0;
	}
	for (int i = 1, l = 0, r = 1; i < n; i++) { // [l, r) 
		if (i < r) { // если внутри отрезка, пересчитаем используя равенство подстрок
			z[i] = fmin(r - i, z[i - l]);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) { // втупую увеличим
			z[i]++;
		}
		if (i + z[i] > r) { // обновим отрезок с макс правой границей
			l = i;
			r = i + z[i];
		}
	}
}