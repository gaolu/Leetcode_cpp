int lengthOfLongestSubstring(string s) {
	int hash[256];
	// Initialize the hash array to -1
	for (int i = 0; i < 256; i++)
		hash[i] = -1;

	int start = 0, result = 0, i;
	for (i = 0; i < s.size(); i++)
	{
		if (hash[s[i]] != -1) {
			if (result < i - start)
				result = i - start;
			for (int j = start; j < hash[s[i]]; j++)
				hash[s[j]] = -1;
			if (hash[s[i]] + 1 > start)
				start = hash[s[i]] + 1;
		}
		hash[s[i]] = i;
	}
	if (result < i - start)
		result = i - start;
	return result;
}