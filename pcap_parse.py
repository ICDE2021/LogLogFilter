#coding:utf-8

import struct


def ip_parse(filename):
    file = open(filename, 'rb')
    data = file.read()
    fwriter = open(filename.split('.')[2], 'wb')
    i = 24
    while(i < len(data)):
        length = struct.unpack('I', data[i+8:i+12])[0]
        sip_combined = struct.unpack('B', data[i + 28:i + 29])[0] * (255 ** 3) + \
                       struct.unpack('B', data[i + 29:i + 30])[0] * (255 ** 2) + \
                       struct.unpack('B', data[i + 30:i + 31])[0] * 255 + \
                       struct.unpack('B', data[i + 31:i + 32])[0]
        fwriter.write(str(sip_combined) + '\t' + str(length) + '\n')
        i = i + length + 16
    file.close()
    fwriter.close()


if __name__ == '__main__':
	pcap_file = ""
	ip_parse(pcap_file)