AI - naive bayes algorithm for spam filter
===========================================

```C
#include <stdio.h>
#include <string.h>


void main() {
	char* dictionary[20] = { "artificial", "bug", "classification", "computer", "data", "fat", "human",
		"interface", "language", "loan", "man", "message", "promotion", "replica",
		"sale", "science", "system", "user", "viagra", "video" };
	//prior = spam이었던 확률, spam이 아니었던 확률
	double prior[2] = { 0.6, 0.4 };
	//spam인 확률
	double spam[20] = { 0.02, 0.1, 0.01, 0.02, 0.01, 0.3, 0.1, 0.03, 0.05, 0.3, 0.2, 0.2, 0.1, 0.2, 0.2, 0.1, 0.02, 0.1, 0.4, 0.2 };
	//ham인 확률
  ```
 
