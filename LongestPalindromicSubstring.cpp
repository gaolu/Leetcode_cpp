// Make the string to look like $a#b#a#$
string preProcess(string input){
	int length = input.length();
	if (length == 0)
		return "^$";
	string result = "^";
	for (int i = 0; i < length; i++){
		result += "#" + input.substr(i, 1);
	}
	result += "#$";
	return result;
}

string longestPalindrome(string s) {
	string T = preProcess(s);
	int n = T.length();
	int C = 0, R = 0;
	int *P = new int[n];
	for (int i = 1; i < n - 1; i++){
		int i_mirror = 2 * C - i;
		// We get the lowest possible P[i]
		P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
			P[i]++;

		if (i + P[i] > R){
			R = i + P[i];
			C = i;
		}
	}

	int maxLen = 0;
	int centerIndex = 0;
	for (int i = 1; i < n - 1; i++){
		if (P[i] > maxLen){
			maxLen = P[i];
			centerIndex = i;
		}
	}
	delete[] P;

	//return s.substr((centerIndex - maxLen - 1) / 2, maxLen);
	return s.substr((centerIndex - 1 - maxLen) / 2, maxLen);
}