#! python
# -*- coding: UTF-8 -*-
 
import re

targetFile = "ans_namelist.txt"
tuple_names = ('戴骏翔', '张浩然', '高心咏', '杨可逸', '管丹辰', '王轶天',    \
        '奚著铭', '宣典村', '王志浩', '曲嘉骏', '赵禹芃', '田丞凯', '杜卓伦', \
        '温瑞程', '靳松朴', '索春祥', '韩雨萌', '李林珊', '黄心鹏', '安启迪', \
        '曹艺涵', '杜泽惠', '邓北', '刘芊寻', '王一宁', '张璋', '刘添添',     \
        '刘艺萱', '田沐秋', '智清盈', '周禹涵', '忻雨绮', '付兴', '马睿欣',   \
        '刘园青', '姚颖函', '张芷菁')

try:
    f_full = open('./'+targetFile, encoding='utf-8')

except FileNotFoundError:
    print("\tFile '" + targetFile + "' doesn't exist!")

else:
    str_names = f_full.read()
    f_full.close()

    print("The target name list:\n" + str_names)

    ''' Remove all the whitespaces from the string '''
    str_nospace = re.sub(r'\s', r'', str_names)

    """ Convert the string into list """
    ''' Replace all the numbers in the string with '\n' '''
    str_multilines = re.sub(r'(^|\D)\d+(\D)', r'\1\n\2', str_nospace)
    if str_multilines:
        ''' Split the modified multilines string into a list of strings '''
        #namestr_list = str_multilines.split('\n')
        namestr_list = str_multilines.splitlines()
        #print(namestr_list)
    else:
        print("\tFailed to substitute!\n")

    print("\n[CHK-1] Check for typos:")
    for name_item in namestr_list:
        if name_item:
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
            print("  -", 20151400 + sn, name_item, ": [", n, "]")
            ''' List out all the corresponding redundant items '''
            if n > 1:
                ret = re.findall('\D(\d+' + name_item + ')', str_nospace)
                if ret:
                    print("\t -", ret)
                else:
                    print("\tFailed to findall!\n")
