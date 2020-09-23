#include "CUSketch.h"
#include "LF_CUSketch.h"

#include <stdio.h>
#include <ctime>
#include <set>
#include <cstdint>
#include <cstdlib>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <iterator>
#ifdef UNIX
#include <x86intrin.h>
#else
#include <intrin.h>
#endif

using namespace std;

void item_frequency()
{
	FILE *fs = fopen("raw_dataset_name", "r");
	FILE *fg = fopen("groundtruth_name", "r");

	if (!fs) {
		cerr << "stream file not found." << endl;
		exit(-1);
	}

	if (!fg) {
		cerr << "stream file not found." << endl;
		exit(-1);
	}

	auto lf_cu = new CUSketchWithLF<int(2 * 1024 * 1024), int(1 * 1024 * 1024)>();

	uint32_t ip;
	int size;

	while (fscanf(fs, "%u\t%d\n", &ip, &size) == 2)
	{
		lf_cu->insert(ip, size);
	}
	fclose(fs);

	cout << "file read finished" << endl;

	uint32_t key;
	int frequency;
	double tot_are_lf = 0.0;
	int itemnum = 0;
	while (fscanf(fg, "%u\t%d\n", &key, &frequency) == 2) {
		double fre_lf = lf_cu->query(key);
		tot_are_lf += abs(fre_lf - frequency) / (double)frequency;
		itemnum++;
	}
	fclose(fg);
	
	cout << "the number of items: " << itemnum << endl;
	cout << "LF+CU AARE: " << tot_are_lf / itemnum << endl;

	lf_cu->statistics();
}

int main()
{
	item_frequency();
	return 0;
}
