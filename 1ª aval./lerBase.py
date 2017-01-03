#!/usr/bin/env python3

def openFile():
	ref_File = open("Dominios_GovBR_basico.csv", encoding="iso-8859-1")
	ref_File.readline()
	for line in ref_File:
		info = line.split(";")
		print("Local: %-20s Domínio: %s" % (info[4], info[0]))
	ref_File.close()

openFile()
