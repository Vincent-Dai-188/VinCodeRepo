#! python
# -*- coding: UTF-8 -*-
 
import re

namesFile = "name_list_201514.txt"
targetFile = "ans_namelist.txt"

def gen_namelist():
    try:
        f_namelist = open('./'+namesFile, encoding='utf-8')

    except FileNotFoundError:
        print("\tFile '" + namesFile + "' doesn't exist!")

    else:
        str_names = f_namelist.read()
        f_namelist.close()

        ''' Remove all the whitespaces, '男' & '女' from the string '''
        str_nospace = re.sub(r'\s|男|女', r'', str_names)

        """ Convert the string into list """
        ''' (1) Insert '\n' at the end of each name (except the last one) '''
        str_multilines = re.sub(r'(?<=\D)(\d)', r'\n\1', str_nospace)
        ''' (2) Drop all the numbers in the multi-line string '''
        str_multilines = re.sub(r'\d+', r'', str_multilines)
        
        ''' Split the multi-line string into a list of strings '''
        namestr_list = str_multilines.splitlines()
        #print("\nParsed name list:")
        #print(namestr_list)
        
        tuple_ret = tuple(namestr_list)
        print("\nTuple_namelist (len =", len(tuple_ret), "):")
        print(tuple_ret)
        return tuple_ret
            
if __name__ == "__main__":

    tuple_names = gen_namelist()

    try:
        f_full = open('./'+targetFile, encoding='utf-8')

    except FileNotFoundError:
        print("\tFile '" + targetFile + "' doesn't exist!")

    else:
        str_names = f_full.read()
        f_full.close()

        print("\nTarget name string:\n" + str_names)

        ''' Remove all the whitespaces from the string '''
        str_nospace = re.sub(r'\s', r'', str_names)

        """ Convert the string into list """
        ''' METHOD-1 '''
        ''' 1.1 Replace all the numbers (except the first one) with '\n' '''
        #str_multilines = re.sub(r'(\D)\d+(\D)', r'\1\n\2', str_nospace)
        ''' 1.2 Drop the first '\n' at the start of the multi-line string '''
        #str_multilines = re.sub(r'^\d+', r'', str_multilines)
        
        ''' METHOD-2 '''
        ''' 2.1 Insert '\n' at the end of each name (except the last one) '''
        str_multilines = re.sub(r'(?<=\D)(\d)', r'\n\1', str_nospace)
        ''' 2.2 Drop all the numbers in the multi-line string '''
        str_multilines = re.sub(r'\d+', r'', str_multilines)
        
        ''' Split the multi-line string into a list of strings '''
        #namestr_list = str_multilines.split('\n')
        namestr_list = str_multilines.splitlines()
        print("\nParsed name list:")
        print(namestr_list)

        print("\n[CHK-1] Check for typos:")
        for name_item in namestr_list:
            n = tuple_names.count(name_item)
            if n == 0:
                print("  -", name_item)

        print("\n[CHK-2] Check for absence/redundance:")
        #namePattern = re.compile(r'\D(\d+)\D', re.IGNORECASE);
        sn = 0
        for name_item in tuple_names:
            sn += 1
            n = str_nospace.count(name_item)
            if n != 1:
                print("  -", 20151400 + sn, name_item, "\t[", n, "]")
                ''' List out all the corresponding redundant items '''
                if n > 1:
                    ret = re.findall('\D(\d+' + name_item + ')', str_nospace)
                    if ret:
                        print("\t -", ret)
                    else:
                        print("\tFailed to findall!\n")
