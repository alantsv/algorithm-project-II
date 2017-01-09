#!/usr/bin/env python3

def openFile():
	data = {}
	ref_File = open("Dominios_GovBR_basico.csv", encoding="iso-8859-1")
	ref_File.readline()
	for line in ref_File:
		info = line.split(";")
		print("Domínio: %s\nAcesso: %s" % (info[0], info[8]))
		data.update({info[0]:info[8]})
		print(data[info[0]])
	ref_File.close()

openFile()
