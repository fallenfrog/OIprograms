const char name[] = "P1947";

extern "C" int Seniorious(int);

extern "C" int Chtholly(int n, int c){
	int l = 1, r = n, mid, res;
	while(1){
		mid = l + r >> 1;
		res = Seniorious(mid);
		if(res == 0)  return mid;
		if(res == 1)  r = mid - 1;
		else  l = mid + 1;
	}
}