#! python
# -*- coding: UTF-8 -*-
 
import re

namesFile = "name_list_201514.txt"
 
try:
    f_full = open('./'+namesFile, encoding='utf-8')

except FileNotFoundError:
    print("\tFile '" + namesFile + "' doesn't exist!")

else:
    str_names = f_full.read()
    f_full.close()

    ''' Remove all the whitespaces, '男' & '女' from the string '''
    str_nospace = re.sub(r'\s|男|女', r'', str_names)

    """ Convert the string into list """
    ''' (1) Insert '\n' at the end of each name (except the last one) '''
    str_multilines = re.sub(r'(?<=\D)(\d)', r'\n\1', str_nospace)
    ''' (2) Drop all the numbers in the multi-line string '''
    str_multilines = re.sub(r'\d+', r'', str_multilines)
    
    ''' Split the multi-line string into a list of strings '''
    namestr_list = str_multilines.splitlines()
    print("\nParsed name list:")
    print(namestr_list)
    
    tuple_names = tuple(namestr_list)
    print("\nGenerated tuple name list:")
    print(tuple_names)