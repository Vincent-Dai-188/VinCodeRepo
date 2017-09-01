#! python
# -*- coding: UTF-8 -*-
 
import re

tuple_names = ('戴骏翔', '张浩然', '高心咏', '杨可逸', '管丹辰', '王轶天',    \
        '奚著铭', '宣典村', '王志浩', '曲嘉骏', '赵禹芃', '田丞凯', '杜卓伦', \
        '温瑞程', '靳松朴', '索春祥', '韩雨萌', '李林珊', '黄心鹏', '安启迪', \
        '曹艺涵', '杜泽惠', '邓北', '刘芊寻', '王一宁', '张璋', '刘添添',     \
        '刘艺萱', '田沐秋', '智清盈', '周禹涵', '忻雨绮', '付兴', '马睿欣',   \
        '刘园青', '姚颖函', '张芷菁')

f_full = open('./ans_namelist.txt', encoding='utf-8')
str_names = f_full.read()
f_full.close()

print("All the names:", str_names)



''' Remove all whitespaces from the string '''
ret_nospace = re.sub(r'\s', r'', str_names)
if ret_nospace:
    #print(ret_nospace)
    pass
else:
    print("\tNot found any whitespace!\n")
    ret_nospace = str_names

"""
''' Insert '\n' at the end of each name in the string '''
ret = re.sub(r'(\D)(?=\d)', r'\1\n', ret_nospace)
if ret:
    ''' Convert the result string into list '''
    ans_list = ret.split('\n')
    print(ans_list)
else:
    print("\tFailed to substitude!\n")
"""

print("\nMatching the offical name list for absence/redundance:")
#namePattern = re.compile(r'\D(\d+)\D', re.IGNORECASE);
sn = 0
for name_item in tuple_names:
    sn += 1
    n = ret_nospace.count(name_item)
    if n != 1:
        print("  -", 20151400 + sn, name_item, ": [", n, "]")
        ''' List out all the corresponding redundant items '''
        if n > 1:
            ret = re.findall('\D(\d+' + name_item + ')', ret_nospace)
            if ret:
                print("\t -", ret)
            else:
                print("\tFailed to findall!\n")
