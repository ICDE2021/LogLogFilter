# LogLogFilter

The source code of LogLogFilter is developed based on that of ColdFilter (https://github.com/zhouyangpkuer/ColdFilter)

The main differences between these two projects are data structure, update procedure, and computation procedure of the filter.

Similarly, the project is built upon cmake. You can use the following commands to build and run.
Also, LogLogFilter-FastUpdate utilize the distribution to fast update each item with its weight. A library "boost" should be installed in advance.

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
cd ../bin
./demo
```

Note:
Due to the large-scale of the datasets, we do not upload the raw_dataset and the groundtruth dataset.
The datasets that we use in this project is downloaded from CAIDA (sanjose and chicago).
The format of the raw_dataset is (item, weight) and the format of the groundtruth dataset is (item, frequency).

Also we upload the code of parse pcap datasets, i.e., "pcap-parse.py".
