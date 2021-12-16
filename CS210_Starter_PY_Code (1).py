import re

import string





def get_frequency_of_each_item(string = ""): 

	filename = "frequency.dat" 

	f = open(filename, "r" 

	data = f.read() 

	list_of_items = data.split() 

	frequency = {} 

	

	

	for item in list_of_items:

		frequency[item] = frequency.get(item, 0) + 1

	return_string = ""

	for item, freq in frequency.items():

		return_string += item + " : " + str(freq) + 'n' 

	return return_string 



def get_frequency_of_single_item(item_name):

	filename = "frequency.dat"

	f = open(filename, "r")

	data = f.read()

	list_of_items = data.split()

	frequency = {} 

	



	for item in list_of_items:

		frequency[item] = frequency.get(item, 0) + 1



	if item_name in frequency: 

		return frequency[item_name]

	return "Item does not exist. Please try again." 

	



def show_histogram(string = ""): 

	filename = "frequency.dat"

	f = open(filename, "r")

	data = f.read() 

	list_of_items = data.split() 

	frequency = {} 

	



	for item in list_of_items:

		frequency[item] = frequency.get(item, 0) + 1



		ans = ""

		for item, freq in frequency.items():

			ans += item + " " + '*' * freq + 'n'

		return ans 